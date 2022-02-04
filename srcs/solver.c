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

unsigned int count_bits(unsigned int n)
{
	unsigned int ret;

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
	unsigned int				bitcnt;
	const unsigned int	max_bit = count_bits(vars->arg_count);
	unsigned int	i;
	bitcnt  = 0;


	while (bitcnt < max_bit)
	{
		i = 0;
		while (i < vars->arg_count)
		{
			// printf("before lastbit_t\n");
			if (((stack_a_idx(vars)) & (1 << bitcnt))) 
			{
				// printf("rotate a\n");
				rotate_a(vars);
			}
			else
			{
				push_b(vars);
				// printf("push b\n");
			}
			i++;
			// printf("i = %d bitcnt = %d argc = %d\n", i, bitcnt, vars->arg_count);
		}
		while(vars->stack_b != NULL)
		{
			// printf("push a\n");
			push_a(vars);
		}
		bitcnt++;
	}
}

int	check_order_a(t_vars *vars)
{
	unsigned int i;
	t_lststack *tmp;

	i = 0;
	tmp = vars->stack_a;
	while (1)
	{
		if (tmp->idx != i)
			return (0);
		tmp = tmp->next;
		i++;
		if (tmp == vars->stack_a)
			return (1);
	}
}

int	check_order_b(t_vars *vars)
{
	unsigned int i;
	t_lststack *tmp;

	i = 0;
	tmp = vars->stack_a;
	while (1)
	{
		if (tmp->idx != i)
			return (0);
		tmp = tmp->next;
		i++;
		if (tmp == vars->stack_a)
			return (1);
	}
}