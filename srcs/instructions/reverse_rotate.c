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

#include "push_swap.h"

void	reverse_rotate_a(t_vars *vars)
{
	vars->stack_a = vars->stack_a->prev;
	ft_lstadd_front(&vars->instruc, null_exit(ft_lstnew(REVERSE_ROTATE_A)));
}

void	reverse_rotate_b(t_vars *vars)
{
	vars->stack_b = vars->stack_b->prev;
	ft_lstadd_front(&vars->instruc, null_exit(ft_lstnew(REVERSE_ROTATE_B)));
}

void	reverse_rotate_ab(t_vars *vars)
{
	vars->stack_a = vars->stack_a->prev;
	vars->stack_b = vars->stack_b->prev;
	ft_lstadd_front(&vars->instruc, null_exit(ft_lstnew(REVERSE_ROTATE_AB)));
}
