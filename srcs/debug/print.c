/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 17:04:44 by jvan-kra      #+#    #+#                 */
/*   Updated: 2021/12/17 18:32:58 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_vars *vars)
{
	t_lststack *tmp;

	printf("stackA  ");
	if (vars->stack_a != NULL)
	{
		tmp = vars->stack_a->next;
		printf("%d:%d  ", vars->stack_a->nr, vars->stack_a->idx);
		while (vars->stack_a != tmp)
		{
			printf("%d:%d  ", tmp->nr, tmp->idx);
			tmp = tmp->next;
		}
	}
	printf("\nstackB  ");
	if (vars->stack_b != NULL)
	{
		tmp = vars->stack_b->next;

		printf("%-5d", vars->stack_b->nr);
		while (vars->stack_b != tmp)
		{
			printf("%-5d", tmp->nr);
			tmp = tmp->next;
		}
	}
	printf("\n");
}
