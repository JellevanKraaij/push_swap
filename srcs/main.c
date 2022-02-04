/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 18:45:49 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/01/27 20:48:32 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void print_result_f(void *data)
{
	printf("%s\n", (char *)data);
}

void print_result(t_vars *vars)
{
	ft_lstiter(vars->instructions, print_result_f);
}


int	main(int argc, char const *argv[])
{
	t_vars	vars;

	ft_bzero(&vars, sizeof(t_vars));
	parse_input(&vars, argc, argv);
	if (check_order_a(&vars))
		return (0);
	if(vars.arg_count == 2)
		solver2(&vars);
	else if(vars.arg_count == 3)
		solver3(&vars);
	else
		solver_radix(&vars);
	solver_radix(&vars);
	print_result(&vars);
}
