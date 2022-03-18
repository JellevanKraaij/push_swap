/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver_insertion.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/29 19:51:18 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/03/15 21:07:24 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	biggest2(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	steps_to_pos(t_lststack *head, int idx)
{
	int	steps;

	steps = 0;
	if (head == head->next)
	{
		return (0);
	}
	while (1)
	{
		if (idx > head->prev->idx && idx < head->idx)
			break ;
		if (head->prev->idx > head->idx && \
		(idx > head->prev->idx || idx < head->idx))
			break ;
		head = head->next;
		steps++;
	}
	return (steps);
}

typedef struct s_rotations
{
	t_moves	norm;
	t_moves	rev;
	t_moves	opt;
}	t_rotations;

t_moves	fill_move(t_lststack *stack_a, t_lststack *stack_b, int steps_b)
{
	const int	alen = lststack_length(stack_a);
	const int	blen = lststack_length(stack_b);
	t_rotations	rots;

	rots.norm.a = steps_to_pos(stack_a, stack_b->idx);
	rots.norm.b = steps_b;
	rots.norm.tot = biggest2(rots.norm.a, rots.norm.b);
	rots.opt.a = rot_conv_opt(rots.norm.a, alen);
	rots.opt.b = rot_conv_opt(rots.norm.b, blen);
	rots.opt.tot = ft_abs(rots.opt.a) + ft_abs(rots.opt.b);
	rots.rev.a = rot_conv_rev(rots.norm.a, alen);
	rots.rev.b = rot_conv_rev(rots.norm.b, blen);
	rots.rev.tot = biggest2(rots.rev.a * -1, rots.rev.b * -1);
	if (rots.norm.tot <= rots.rev.tot && rots.norm.tot <= rots.opt.tot)
		return (rots.norm);
	if (rots.opt.tot <= rots.rev.tot && rots.opt.tot <= rots.norm.tot)
		return (rots.opt);
	return (rots.opt);
}

void	find_best_moves(t_vars *vars, t_moves *best_move)
{
	const int	stacklenb = lststack_length(vars->stack_b);
	t_moves		steps_tmp;
	int			i;
	t_lststack	*tmp;

	tmp = vars->stack_b;
	*best_move = fill_move(vars->stack_a, vars->stack_b, 0);
	i = 1;
	while (i < stacklenb)
	{
		tmp = tmp->next;
		steps_tmp = fill_move(vars->stack_a, tmp, i);
		if (steps_tmp.tot < best_move->tot)
			*best_move = steps_tmp;
		i++;
	}
}

int	prepare_stacks_exec(t_vars *vars, int divider)
{
	int i;
	int prev;

	i = 0;
	prev = 0;
	while (i < vars->arg_count)
	{
		if (vars->stack_a->idx < (i + (vars->arg_count / divider)) && vars->stack_a->idx >= prev)
		{
			prev = vars->stack_a->idx;
			rotate_a(vars);
		}
		else
			push_b(vars);
		i++;
	}
	return (lststack_length(vars->stack_b));
}

void prepare_stacks(t_vars **vars)
{
	t_vars *tmp;
	int		tmp_len;
	t_vars *best;
	int		bestlen;
	int		i;

	bestlen = (*vars)->arg_count;
	i = 1;
	while(i < 50)
	{
		tmp = vars_copy(*vars);
		tmp_len = prepare_stacks_exec(tmp, i);
		// printf("i = %d, steps = %d\n", i, tmp_len);
		if (tmp_len < bestlen)
		{
			best = tmp;
			bestlen = tmp_len;
		}
		else
			vars_destroy(tmp);
		i++;
	}
	vars_destroy(*vars);
	*vars = best;
}

void	solver_insertion(t_vars **vars)
{
	t_moves	best_move;
	int		i;
	int		stack_length;

	lststack_idx((*vars)->stack_a);
	prepare_stacks(vars);
	stack_length = lststack_length((*vars)->stack_b);
	i = 0;
	while (i < stack_length)
	{
		find_best_moves(*vars, &best_move);
		execute_steps(*vars, best_move);
		push_a(*vars);
		i++;
	}
	rotate_to_a(*vars, 0);
}
