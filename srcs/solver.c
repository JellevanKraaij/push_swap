/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-kra <jvan-kra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:51:18 by jvan-kra          #+#    #+#             */
/*   Updated: 2022/03/15 21:07:24 by jvan-kra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	count_bits(unsigned int n)
{
	unsigned int	ret;

	ret = 0;
	while (n)
	{
		ret++;
		n >>= 1;
	}
	return (ret);
}

void	solver_radix(t_vars *vars)
{
	const unsigned int	max_bit = count_bits(vars->arg_count);
	unsigned int		bitcnt;
	unsigned int		i;

	bitcnt = 0;
	lststack_idx(vars->stack_a);
	while (bitcnt < max_bit)
	{
		i = 0;
		while (i < vars->arg_count)
		{
			if (vars->stack_a->idx & (1 << bitcnt))
				rotate_a(vars);
			else
				push_b(vars);
			i++;
		}
		while (vars->stack_b != NULL)
			push_a(vars);
		bitcnt++;
	}
}

unsigned int biggest2(unsigned int a, unsigned int b)
{
	if(a > b)
		return (a);
	return (b);
}

void execute_rotate_a(t_vars *vars, int steps)
{
	while (steps < 0)
	{
		reverse_rotate_a(vars);
		steps++;
	}
	while (steps > 0)
	{
		rotate_a(vars);
		steps--;
	}
}

void execute_rotate_b(t_vars *vars, int steps)
{
	while (steps < 0)
	{
		reverse_rotate_b(vars);
		steps++;
	}
	while (steps > 0)
	{
		rotate_b(vars);
		steps--;
	}
}

void execute_rotate_ab(t_vars *vars, int steps)
{
	while (steps < 0)
	{
		reverse_rotate_ab(vars);
		steps++;
	}
	while (steps > 0)
	{
		rotate_ab(vars);
		steps--;
	}
}

void execute_steps(t_vars *vars, t_moves best_move)
{
	if ((best_move.a > 0 && best_move.b > 0) || (best_move.a < 0 && best_move.b < 0))
	{
		if (UINT_ABS(best_move.a) > UINT_ABS(best_move.b))
		{
			execute_rotate_ab(vars, best_move.b);
			execute_rotate_a(vars, best_move.a - best_move.b);
		}
		else
		{
			execute_rotate_ab(vars, best_move.a);
			execute_rotate_b(vars, best_move.b - best_move.a);
		}
	}
	else
	{
		execute_rotate_a(vars, best_move.a);
		execute_rotate_b(vars, best_move.b);
	}
}

int steps_to_pos(t_lststack *head, unsigned int idx)
{
	unsigned int	steps;
	unsigned int	reverse;

	steps = 0;
	if (head == head->next)
	{
		if (idx > head->idx)
			return (0);
		else
			return (1);
	}
	while(1)
	{
		if (idx > head->prev->idx && idx < head->idx)
			break ;
		if (head->prev->idx > head->idx && (idx > head->prev->idx || idx < head->idx))
			break ;
		head = head->next;
		steps++;
	}
	reverse = lststack_length(head) - steps;
	if (steps < reverse)
		return (steps);
	else
		return(reverse * -1);
}

void find_best_moves(t_vars *vars, t_moves *best_move)
{
	int steps_tmp;
	unsigned int b_len;
	unsigned int i;
	t_lststack *tmp;

	tmp = vars->stack_b;
	b_len = lststack_length(vars->stack_b);
	best_move->a = steps_to_pos(vars->stack_a, vars->stack_b->idx);
	best_move->b = 0;
	i = 0;
	while(i < b_len / 2)
	{
		steps_tmp = steps_to_pos(vars->stack_a, tmp->idx);
		if ((UINT_ABS(steps_tmp) + i < UINT_ABS(best_move->a)) || (steps_tmp > 0 && biggest2(UINT_ABS(steps_tmp), i) < UINT_ABS(best_move->a)))
		{
			best_move->a = steps_to_pos(vars->stack_a, tmp->idx);
			best_move->b = i;
		}
		tmp = tmp->next;
		i++;
	}
	tmp = vars->stack_b->prev;
	i = 1;
	while(i < b_len / 2)
	{
		steps_tmp = steps_to_pos(vars->stack_a, tmp->idx);
		if ((UINT_ABS(steps_tmp) + i < UINT_ABS(best_move->a)) || (steps_tmp < 0 && biggest2(UINT_ABS(steps_tmp), i) < UINT_ABS(best_move->a)))
		{
			best_move->a = steps_to_pos(vars->stack_a, tmp->idx);
			best_move->b = (int)i * -1;
		}
		tmp = tmp->prev;
		i++;
	}
}

void solver_insertion(t_vars *vars)
{
	t_moves best_move;
	unsigned int i;
	unsigned int prev;
	unsigned int stack_length;

	lststack_idx(vars->stack_a);
	stack_length = lststack_length(vars->stack_a);
	i = 0;
	prev = 0;

	while(i < stack_length)
	{
		if (vars->stack_a->idx < (i + (stack_length / 20)) && vars->stack_a->idx >= prev)
		{
			prev = vars->stack_a->idx;
			rotate_a(vars);
		}
		else
			push_b(vars);
		i++;
	}
	stack_length = lststack_length(vars->stack_b);
	i = 0;
	while(i < stack_length)
	{
		find_best_moves(vars, &best_move);
		execute_steps(vars, best_move);
		push_a(vars);
		i++;
	}
	rotate_to_a(vars, 0);
}
