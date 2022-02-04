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

#include "push_swap.h"

void	rotate_a(t_vars *vars)
{
	vars->stack_a = vars->stack_a->next;
	ft_lstadd_back(&vars->instruc, null_exit(ft_lstnew(ROTATE_A)));
}

void	rotate_b(t_vars *vars)
{
	vars->stack_b = vars->stack_b->next;
	ft_lstadd_back(&vars->instruc, null_exit(ft_lstnew(ROTATE_B)));
}

void	rotate_ab(t_vars *vars)
{
	vars->stack_a = vars->stack_a->next;
	vars->stack_b = vars->stack_b->next;
	ft_lstadd_back(&vars->instruc, null_exit(ft_lstnew(ROTATE_AB)));
}
