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
#include <stdio.h>

typedef struct s_stacklen
{
	int	a;
	int	b;
}	t_stacklen;

typedef struct s_rotations
{
	t_moves	norm;
	t_moves	rev;
	t_moves	opt;
}	t_rotations;

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

t_moves	fill_move(t_lststack *stack_a, t_lststack *stack_b, \
		int steps_b, t_stacklen len)
{
	t_rotations	rots;

	rots.norm.a = steps_to_pos(stack_a, stack_b->idx);
	rots.norm.b = steps_b;
	rots.norm.tot = biggest2(rots.norm.a, rots.norm.b);
	rots.opt.a = rot_conv_opt(rots.norm.a, len.a);
	rots.opt.b = rot_conv_opt(rots.norm.b, len.b);
	rots.opt.tot = ft_abs(rots.opt.a) + ft_abs(rots.opt.b);
	rots.rev.a = rot_conv_rev(rots.norm.a, len.a);
	rots.rev.b = rot_conv_rev(rots.norm.b, len.b);
	rots.rev.tot = biggest2(rots.rev.a * -1, rots.rev.b * -1);
	if (rots.norm.tot <= rots.rev.tot && rots.norm.tot <= rots.opt.tot)
		return (rots.norm);
	if (rots.opt.tot <= rots.rev.tot && rots.opt.tot <= rots.norm.tot)
		return (rots.opt);
	return (rots.opt);
}

void	find_best_moves(t_vars *vars, t_moves *best_move, t_stacklen len)
{
	t_moves		steps_tmp;
	int			i;
	t_lststack	*tmp;

	tmp = vars->stack_b;
	*best_move = fill_move(vars->stack_a, vars->stack_b, 0, len);
	i = 1;
	while (i < len.b)
	{
		tmp = tmp->next;
		steps_tmp = fill_move(vars->stack_a, tmp, i, len);
		if (steps_tmp.tot < best_move->tot)
			*best_move = steps_tmp;
		i++;
	}
}

void	execute_insertion(t_vars *vars)
{
	t_moves		best_move;
	t_stacklen	len;

	len.a = lststack_length(vars->stack_a);
	len.b = lststack_length(vars->stack_b);
	while (len.b)
	{
		find_best_moves(vars, &best_move, len);
		execute_steps(vars, best_move);
		push_a(vars);
		len.b--;
		len.a++;
	}
	rotate_to_a(vars, 0);
}

void	solver_insertion(t_vars **vars)
{
	t_vars	*tmp;
	t_vars	*best;
	int		bestlen;
	int		i;

	i = 1;
	bestlen = 0;
	lststack_idx((*vars)->stack_a);
	while (i < 50)
	{
		tmp = vars_copy(*vars);
		prepare_stack_a(tmp, i);
		execute_insertion(tmp);
		if (ft_lstsize(tmp->instruc) < bestlen || bestlen == 0)
		{
			best = tmp;
			bestlen = ft_lstsize(tmp->instruc);
		}
		else
			vars_destroy(tmp);
		i += 10;
	}
	vars_destroy(*vars);
	*vars = best;
}
