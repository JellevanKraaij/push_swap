/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/29 19:51:18 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/01/29 19:51:18 by jvan-kra      ########   odam.nl         */
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

void execute_steps_a(t_vars *vars, unsigned int steps)
{
	unsigned int i;
	const unsigned int normal = steps;
	const unsigned int reverse = lststack_length(vars->stack_a) - steps;

	i = 0;
	while (i < normal && i < reverse)
	{
		if (normal < reverse)
			rotate_a(vars);
		else
			reverse_rotate_a(vars);
		i++;
	}
}

void execute_steps_b(t_vars *vars, unsigned int steps)
{
	unsigned int i;
	const unsigned int normal = steps;
	const unsigned int reverse = lststack_length(vars->stack_b) - steps;

	i = 0;
	while (i < normal && i < reverse)
	{
		if (normal < reverse)
			rotate_b(vars);
		else
			reverse_rotate_b(vars);
		i++;
	}
}

unsigned int steps_to_pos(t_lststack *head, unsigned int idx)
{
	unsigned int	steps;

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
		{
			// printf("head->idx = %d head->prev->idx = %d idx = %d", head->idx, head->prev->idx, idx);
			break ;
		}
		head = head->next;
		steps++;
	}
	return (steps);
}


void find_best_moves(t_vars *vars, unsigned int *moves_a, unsigned int *moves_b)
{
	unsigned int b_len;
	unsigned int i;
	unsigned int best_moves_a;
	unsigned int best_moves_b;
	t_lststack *tmp;

	tmp = vars->stack_b->next;
	b_len = lststack_length(vars->stack_b);
	best_moves_a = steps_to_pos(vars->stack_a, vars->stack_b->idx);
	best_moves_b = 0;
	i = 0;
	while(i <= b_len / 2)
	{
		if (steps_to_pos(vars->stack_a, tmp->idx) + i < best_moves_a)
		{
			best_moves_a = steps_to_pos(vars->stack_a, tmp->idx);
			best_moves_b = i;
		}
		tmp = tmp->next;
		i++;
	}
	tmp = vars->stack_b->prev;
	i = 0;
	while(i < b_len / 2)
	{
		if (steps_to_pos(vars->stack_a, tmp->idx) + i < best_moves_a)
		{
			best_moves_a = steps_to_pos(vars->stack_a, tmp->idx);
			best_moves_b = (int)i * -1;
		}
		tmp = tmp->prev;
		i++;
	}
	*moves_a = best_moves_a;
	*moves_b = best_moves_b;
}


void solver_insertion(t_vars *vars)
{
	unsigned int moves_a;
	unsigned int moves_b;
	unsigned int i;
	unsigned int prev;
	unsigned int stack_length;

	lststack_idx(vars->stack_a);
	stack_length = lststack_length(vars->stack_a);
	i = 0;
	prev = 0;

	while(i < stack_length)
	{
		if (vars->stack_a->idx < (i + (stack_length / 8))&& vars->stack_a->idx >= prev)
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
		find_best_moves(vars, &moves_a, &moves_b);
		execute_steps_a(vars, moves_a);
		execute_steps_b(vars, moves_b);
		push_a(vars);
		i++;
	}
}
