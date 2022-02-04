/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/29 19:51:18 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/01/29 19:51:18 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	count_bits(unsigned int n)
{
	unsigned int	ret;

	ret = 0;
	while (n)
	{
		ret++;
		n >>= 1;
	}
	return (ret);
}

void	solver_radix(t_vars *vars)
{
	const unsigned int	max_bit = count_bits(vars->arg_count);
	unsigned int		bitcnt;
	unsigned int		i;

	bitcnt = 0;
	lststack_idx(vars->stack_a);
	while (bitcnt < max_bit)
	{
		i = 0;
		while (i < vars->arg_count)
		{
			if (vars->stack_a->idx & (1 << bitcnt))
				rotate_a(vars);
			else
				push_b(vars);
			i++;
		}
		while (vars->stack_b != NULL)
			push_a(vars);
		bitcnt++;
	}
}
