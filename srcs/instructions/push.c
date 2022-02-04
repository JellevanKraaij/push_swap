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

static void	delete_first_elem(t_lststack **head)
{
	if (*head != (*head)->next)
	{
		(*head)->prev->next = (*head)->next;
		(*head)->next->prev = (*head)->prev;
		*head = (*head)->next;
	}
	else
		(*head) = NULL;
}

void	push_a(t_vars *vars)
{
	t_lststack	*tmp;
	t_lststack	*last;

	tmp = vars->stack_b;
	delete_first_elem(&vars->stack_b);
	if (vars->stack_a == NULL)
	{
		vars->stack_a = tmp;
		vars->stack_a->next = vars->stack_a;
		vars->stack_a->prev = vars->stack_a;
	}
	else
	{
		last = vars->stack_a->prev;
		tmp->next = vars->stack_a;
		tmp->prev = last;
		vars->stack_a->prev = tmp;
		last->next = tmp;
		vars->stack_a = tmp;
	}
	ft_lstadd_back(&vars->instruc, null_exit(ft_lstnew(PUSH_A)));
}

void	push_b(t_vars *vars)
{
	t_lststack	*tmp;
	t_lststack	*last;

	tmp = vars->stack_a;
	delete_first_elem(&vars->stack_a);
	if (vars->stack_b == NULL)
	{
		vars->stack_b = tmp;
		vars->stack_b->next = vars->stack_b;
		vars->stack_b->prev = vars->stack_b;
	}
	else
	{
		last = vars->stack_b->prev;
		tmp->next = vars->stack_b;
		tmp->prev = last;
		vars->stack_b->prev = tmp;
		last->next = tmp;
		vars->stack_b = tmp;
	}
	ft_lstadd_back(&vars->instruc, null_exit(ft_lstnew(PUSH_B)));
}
