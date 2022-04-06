/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/04 21:24:35 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/02/04 21:24:35 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	swap_stack(t_lststack **head)
{
	t_lststack	*tmp1;
	t_lststack	*tmp2;

	if (lststack_length(*head) < 2)
		return ;
	tmp1 = lststack_remove_front(head);
	tmp2 = lststack_remove_front(head);
	lststack_add_front(head, tmp1);
	lststack_add_front(head, tmp2);
}

void	swap_a(t_vars *vars)
{	
	swap_stack(&vars->stack_a);
}

void	swap_b(t_vars *vars)
{	
	swap_stack(&vars->stack_b);
}

void	swap_ab(t_vars *vars)
{	
	swap_stack(&vars->stack_a);
	swap_stack(&vars->stack_b);
}
