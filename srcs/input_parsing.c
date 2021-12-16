/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-kra <jvan-kra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:54:05 by jvan-kra          #+#    #+#             */
/*   Updated: 2021/12/16 18:54:14 by jvan-kra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_input(t_vars *vars, int argc, const char *argv[])
{
	int	i;

	if (argc < 2)
		error_exit();
	vars->stack = init_stack(argc - 1);
	i = 1;
	while (i < argc)
	{
		if (ft_atoi_p(argv[i], &vars->stack->a[i - 1]))
		{
			destroy_stack(vars->stack);
			error_exit();
		}
		else
			printf("num[%d] = %i\n", i - 1, vars->stack->a[i - 1]);
		i++;
	}
}
