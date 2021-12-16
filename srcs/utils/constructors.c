/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-kra <jvan-kra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:01:36 by jvan-kra          #+#    #+#             */
/*   Updated: 2021/12/16 18:52:07 by jvan-kra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int stack_size)
{
	t_stack	*stack;

	stack = null_exit(malloc(sizeof(stack)));
	stack->a = null_exit(malloc(stack_size * sizeof(int)));
	stack->b = null_exit(malloc(stack_size * sizeof(int)));
	return (stack);
}

void	destroy_stack(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack);
}
