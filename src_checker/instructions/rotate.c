/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/04 21:25:08 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/02/04 21:25:08 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate_a(t_vars *vars)
{
	if (lststack_length(vars->stack_a) < 1)
		return ;
	vars->stack_a = vars->stack_a->next;
}

void	rotate_b(t_vars *vars)
{
	if (lststack_length(vars->stack_b) < 1)
		return ;
	vars->stack_b = vars->stack_b->next;
}

void	rotate_ab(t_vars *vars)
{
	if (lststack_length(vars->stack_a) < 1 || \
	lststack_length(vars->stack_b) < 1)
		return ;
	vars->stack_a = vars->stack_a->next;
	vars->stack_b = vars->stack_b->next;
}
