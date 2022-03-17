/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_solvers.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 14:51:50 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/02/03 14:51:50 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solver2(t_vars *vars)
{
	swap_a(vars);
}

void	solver3(t_vars *vars)
{
	lststack_idx(vars->stack_a);
	if (lststack_check_order(vars->stack_a))
		return ;
	if (vars->stack_a->idx == 1 && vars->stack_a->next->idx == 0)
		swap_a(vars);
	else if (vars->stack_a->idx == 1 && vars->stack_a->next->idx == 2)
		reverse_rotate_a(vars);
	else if (vars->stack_a->idx == 0 && vars->stack_a->next->idx == 2)
	{
		reverse_rotate_a(vars);
		swap_a(vars);
		return ;
	}
	else if (vars->stack_a->idx == 2 && vars->stack_a->next->idx == 0)
		rotate_a(vars);
	else
	{
		swap_a(vars);
		reverse_rotate_a(vars);
	}
}

void	solver5(t_vars *vars)
{
	lststack_idx(vars->stack_a);
	rotate_to_a(vars, 0);
	push_b(vars);
	rotate_to_a(vars, 1);
	push_b(vars);
	solver3(vars);
	push_a(vars);
	push_a(vars);
}

int	calc_rotate_a(t_vars *vars, int num)
{
	t_lststack		*tmp;
	int	ret;

	ret = 0;
	if (vars->stack_a->idx == num)
		return (ret);
	tmp = vars->stack_a->next;
	while (tmp != vars->stack_a)
	{
		ret++;
		if (tmp->idx == num)
			break ;
		tmp = tmp->next;
	}
	return (ret);
}

void	rotate_to_a(t_vars *vars, int num)
{
	int	i;
	int	normal;
	int	reverse;

	normal = calc_rotate_a(vars, num);
	reverse = lststack_length(vars->stack_a) - normal;
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
