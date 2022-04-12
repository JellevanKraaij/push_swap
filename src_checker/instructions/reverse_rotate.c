/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/04 21:25:18 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/02/04 21:25:18 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reverse_rotate_a(t_vars *vars)
{
	if (lststack_length(vars->stack_a) < 1)
		return ;
	vars->stack_a = vars->stack_a->prev;
}

void	reverse_rotate_b(t_vars *vars)
{
	if (lststack_length(vars->stack_b) < 1)
		return ;
	vars->stack_b = vars->stack_b->prev;
}

void	reverse_rotate_ab(t_vars *vars)
{
	if (lststack_length(vars->stack_a) < 1 || \
	lststack_length(vars->stack_b) < 1)
	vars->stack_a = vars->stack_a->prev;
	vars->stack_b = vars->stack_b->prev;
}
