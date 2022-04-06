/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver_insertion_helpers.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/01 21:59:15 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/04/01 21:59:15 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	prepare_stack_a(t_vars *vars, int divider)
{
	int	i;
	int	prev;

	i = 0;
	prev = 0;
	while (i < vars->arg_count)
	{
		if (vars->stack_a->idx < (i + (vars->arg_count / divider)) \
		&& vars->stack_a->idx >= prev)
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
