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

#include "push_swap.h"

void	push_a(t_vars *vars)
{
	lststack_add_front(&vars->stack_a, lststack_remove_front(&vars->stack_b));
	ft_lstadd_back(&vars->instruc, null_exit(ft_lstnew(PUSH_A)));
}

void	push_b(t_vars *vars)
{
	lststack_add_front(&vars->stack_b, lststack_remove_front(&vars->stack_a));
	ft_lstadd_back(&vars->instruc, null_exit(ft_lstnew(PUSH_B)));
}
