/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 20:42:26 by jvan-kra      #+#    #+#                 */
/*   Updated: 2021/12/17 21:46:47 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_vars *vars)
{
	t_stack_idx	temp;

	temp = vars->stack->a[0];
	vars->stack->a[0] = vars->stack->a[1];
	vars->stack->a[1] = temp;
	ft_lstadd_back(&vars->instructions, ft_lstnew(SWAP_A));
}

void	rotate_a(t_vars *vars)
{
	int			i;
	t_stack_idx	temp;

	i = 0;
	temp = vars->stack->a[0];
	while (i < vars->stack->size - 1)
	{
		vars->stack->a[i] = vars->stack->a[i + 1];
		i++;
	}
	vars->stack->a[i] = temp;
	ft_lstadd_back(&vars->instructions, ft_lstnew(ROTATE_A));
}
