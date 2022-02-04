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

void solver2(t_vars *vars)
{
	swap_a(vars);
}

void solver3(t_vars *vars)
{
	if (stack_a_idx(vars) == 1 && stack_a_next_idx(vars) == 0)
	{
		swap_a(vars);
		return ;
	}
	if (stack_a_idx(vars) == 1 && stack_a_next_idx(vars) == 2)
	{
		reverse_rotate_a(vars);
		return ;
	}
	if (stack_a_idx(vars) == 0 && stack_a_next_idx(vars) == 2)
	{
		reverse_rotate_a(vars);
		swap_a(vars);
		return ;
	}
	if (stack_a_idx(vars) == 2 && stack_a_next_idx(vars) == 0)
	{
		rotate_a(vars);
		return ;
	}
	if(stack_a_idx(vars) == 2 && stack_a_next_idx(vars) == 1)
	{
		swap_a(vars);
		reverse_rotate_a(vars);
		return ;
	}
}