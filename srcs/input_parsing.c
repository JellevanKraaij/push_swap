/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_parsing.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 16:54:05 by jvan-kra      #+#    #+#                 */
/*   Updated: 2021/12/17 18:31:14 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_doubles(t_stacks *stack, int num)
{
	int	i;

	i = 0;
	while (stack->a[i].filled)
	{
		if (stack->a[i].num == num)
			return (1);
		i++;
	}
	return (0);
}

void	parse_input(t_vars *vars, int argc, const char *argv[])
{
	int	i;

	if (argc < 2)
		error_exit();
	vars->stack = init_stacks(argc - 1);
	i = 0;
	while (i < argc - 1)
	{
		if (ft_atoi_p(argv[i + 1], &vars->stack->a[i].num) || \
		check_doubles(vars->stack, vars->stack->a[i].num))
		{
			destroy_stacks(vars->stack);
			error_exit();
		}
		vars->stack->a[i].filled = 1;
		i++;
	}
}
