/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lststack_imp.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/04 18:13:08 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/02/04 18:13:08 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lststack_length(t_lststack *head)
{
	int				cnt;
	t_lststack		*tmp;

	cnt = 0;
	if (head == NULL)
		return (cnt);
	tmp = head;
	while (1)
	{
		cnt++;
		tmp = tmp->next;
		if (head == tmp)
			return (cnt);
	}
}

void	lststack_idx_prep(t_lststack *head)
{
	const int	stacklen = lststack_length(head);
	t_lststack	*tmp;
	int			i;

	i = 0;
	tmp = head;
	while (i < stacklen)
	{
		tmp->idx = -1;
		tmp = tmp->next;
		i++;
	}
}

void	lststack_idx(t_lststack *head)
{
	const int	stacklen = lststack_length(head);
	t_lststack	*tmp;
	t_lststack	*smallest;
	int			i;

	i = 0;
	tmp = head;
	smallest = NULL;
	lststack_idx_prep(head);
	while (i < stacklen)
	{
		if (tmp->idx == -1 && (smallest == NULL || tmp->nr < smallest->nr))
			smallest = tmp;
		if (tmp->next == head)
		{
			smallest->idx = i;
			i++;
			smallest = NULL;
		}
		tmp = tmp->next;
	}
}

int	lststack_check_order(t_lststack *head)
{
	t_lststack	*tmp;

	tmp = head->next;
	if (tmp == head)
		return (1);
	while (1)
	{
		if (tmp->nr < tmp->prev->nr)
			return (0);
		tmp = tmp->next;
		if (tmp == head)
			return (1);
	}
}
