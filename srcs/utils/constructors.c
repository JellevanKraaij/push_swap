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

t_stacks	*init_stacks(int stack_size)
{
	t_stacks	*stack;

	stack = null_exit(malloc(sizeof(t_stacks)));
	stack->a = null_exit(ft_calloc(stack_size, sizeof(t_stack_idx)));
	stack->b = null_exit(ft_calloc(stack_size, sizeof(t_stack_idx)));
	stack->size = stack_size;
	return (stack);
}

void	destroy_stacks(t_stacks *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack);
}
