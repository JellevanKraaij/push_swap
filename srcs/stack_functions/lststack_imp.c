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

void	lststack_idx(t_lststack *head)
{
	int					i;
	int					smallest_nr;
	t_lststack			*tmp;
	t_lststack			*smallest;
	const int			stack_a_lenght = lststack_length(head);

	smallest = NULL;
	smallest_nr = INT_MIN;
	i = 0;
	tmp = head;
	while (i < stack_a_lenght)
	{
		if ((smallest == NULL || tmp->nr < smallest->nr) \
		&& tmp->nr > smallest_nr)
			smallest = tmp;
		tmp = tmp->next;
		if (tmp == head)
		{
			smallest->idx = i;
			i++;
			smallest_nr = smallest->nr;
			smallest = NULL;
		}
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
