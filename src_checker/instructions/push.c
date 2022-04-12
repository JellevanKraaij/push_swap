/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/04 21:24:26 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/02/04 21:24:26 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_a(t_vars *vars)
{
	if (lststack_length(vars->stack_b) < 1)
		return ;
	lststack_add_front(&vars->stack_a, lststack_remove_front(&vars->stack_b));
}

void	push_b(t_vars *vars)
{
	if (lststack_length(vars->stack_a) < 1)
		return ;
	lststack_add_front(&vars->stack_b, lststack_remove_front(&vars->stack_a));
}
