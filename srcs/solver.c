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

void execute_steps_a(t_vars *vars, int steps)
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

void execute_steps_b(t_vars *vars, int steps)
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

int steps_to_pos(t_lststack *head, unsigned int idx)
{
	int	steps;
	int reverse;

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


void find_best_moves(t_vars *vars, int *moves_a, int *moves_b)
{
	unsigned int b_len;
	unsigned int i;
	int best_moves_a;
	int best_moves_b;
	t_lststack *tmp;

	tmp = vars->stack_b;
	b_len = lststack_length(vars->stack_b);
	best_moves_a = steps_to_pos(vars->stack_a, vars->stack_b->idx);
	best_moves_b = 0;
	i = 0;
	while(i < b_len / 2)
	{
		if ((unsigned int)ft_abs(steps_to_pos(vars->stack_a, tmp->idx)) + i < (unsigned int)ft_abs(best_moves_a))
		{
			best_moves_a = steps_to_pos(vars->stack_a, tmp->idx);
			best_moves_b = i;
		}
		tmp = tmp->next;
		i++;
	}
	tmp = vars->stack_b->prev;
	i = 1;
	while(i < b_len / 2)
	{
		if ((unsigned int)ft_abs(steps_to_pos(vars->stack_a, tmp->idx)) + i < (unsigned int)ft_abs(best_moves_a))
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
	int moves_a;
	int moves_b;
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
	if (lststack_check_order(vars->stack_a) == 0)
	{
		printf("error");
		exit(1);
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
	rotate_to_a(vars, 0);
}
