/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 18:45:49 by jvan-kra      #+#    #+#                 */
/*   Updated: 2021/12/17 21:45:37 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char const *argv[])
{
	t_vars	vars;
	
	ft_bzero(&vars, sizeof(vars));
	parse_input(&vars, argc, argv);
	print_stacks(vars.stack);
	rotate_a(&vars);
	printf("------------\n");
	print_stacks(vars.stack);
}
