/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   constructors.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 17:01:36 by jvan-kra      #+#    #+#                 */
/*   Updated: 2021/12/17 18:30:45 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lststack *stack_create_elem(int idx)
{
	t_lststack *ret;

	ret = null_exit(malloc(sizeof(t_lststack)));

	ret->idx = idx;
	ret->prev = ret;
	ret->next = ret;
	return (ret);
}

void	stack_clear_list(t_lststack *stack)
{
	t_lststack *tmp;

	tmp = stack->next;

	free(tmp->prev);
	while (stack != tmp)
	{
		tmp = tmp->next;
		free(tmp->prev);
	}
}
