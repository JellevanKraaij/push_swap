/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lststack_ctors.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/04 20:22:45 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/02/04 20:22:45 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lststack_add_back(t_lststack **head, t_lststack *new)
{
	t_lststack	*last;

	if (*head == NULL)
	{
		new->next = new;
		new->prev = new;
		*head = new;
		return ;
	}
	last = (*head)->prev;
	new->next = *head;
	(*head)->prev = new;
	new->prev = last;
	last->next = new;
}

t_lststack	*lststack_new(int nr)
{
	t_lststack	*ret;

	ret = null_exit(malloc(sizeof(t_lststack)));
	ret->nr = nr;
	ret->idx = 0;
	ret->prev = ret;
	ret->next = ret;
	return (ret);
}

void	lststack_clear(t_lststack **stack)
{
	t_lststack	*tmp;
	t_lststack	*current;

	if (*stack == NULL)
		return ;
	current = (*stack)->next;
	while (current != *stack)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	free(*stack);
	*stack = NULL;
}

void	lststack_add_front(t_lststack **head, t_lststack *node)
{
	if (node == NULL)
		return ;
	if (*head == NULL)
	{
		node->next = node;
		node->prev = node;
		*head = node;
		return ;
	}
	node->next = *head;
	node->prev = (*head)->prev;
	(*head)->prev->next = node;
	(*head)->prev = node;
	*head = node;
}

//removes first element of list and returns it
t_lststack	*lststack_remove_front(t_lststack **head)
{
	t_lststack	*ret;

	if (*head == NULL)
		return (NULL);
	ret = *head;
	if (*head == (*head)->next)
	{
		*head = NULL;
		return (ret);
	}
	(*head)->prev->next = (*head)->next;
	(*head)->next->prev = (*head)->prev;
	*head = (*head)->next;
	return (ret);
}
