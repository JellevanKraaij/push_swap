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

void	print_stacks(t_stacks *stack)
{
	int	i;

	i = 0;
	printf("stackA  ");
	while (i < stack->size)
	{
		if (stack->a->filled)
			printf("%-5d", stack->a[i].num);
		else
			printf("X    ");
		i++;
	}
	printf("\nstackB  ");
	i = 0;
	while (i < stack->size)
	{
		if (stack->b[i].filled)
			printf("%-5d", stack->b[i].num);
		else
			printf("X    ");
		i++;
	}
	printf("\n");
}
