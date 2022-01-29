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
	printf("Instructions:\n");
	ft_lstiter(vars->instructions, print_result_f);
}


int	main(int argc, char const *argv[])
{
	t_vars	vars;

	ft_bzero(&vars, sizeof(vars));
	parse_input(&vars, argc, argv);
	print_stacks(&vars);
	printf("------------\n");
	solver(&vars);
	print_stacks(&vars);
	print_result(&vars);
}
