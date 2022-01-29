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

void	solver(t_vars *vars)
{
	int			bitcnt;
	int			i;
	bitcnt  = 0;

	while (bitcnt < (int)sizeof(int) * 8)
	{
		i = 0;
		while (i < vars->arg_count)
		{
			printf("before lastbit_t\n");
			if ((LASTBIT_T(stack_a_idx(vars)) & (1 << bitcnt))) 
			{
				printf("rotate a\n");
				rotate_a(vars);
			}
			else
			{
				printf("push b\n");
				push_b(vars);
			}
			i++;
			printf("i = %d bitcnt = %d argc = %d\n", i, bitcnt, vars->arg_count);
		}
		while(vars->stack_b != NULL)
		{
			printf("push a\n");
			push_a(vars);
		}
		bitcnt++;
	}
}