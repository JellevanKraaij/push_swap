/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 18:45:49 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/03/15 17:57:09 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_result_f(void *data)
{
	ft_putendl_fd((char *)data, 1);
}

void	print_result(t_list *instructions)
{
	if (instructions == NULL)
		return ;
	print_result(instructions->next);
	print_result_f(instructions->content);
}

int	main(int argc, char const *argv[])
{
	t_vars	*vars;

	vars = vars_init();
	vars->arg_count = parse_input(vars, argc, argv);
	if (vars->arg_count < 1)
		error_exit();
	if (lststack_check_order(vars->stack_a))
		return (0);
	if (vars->arg_count == 2)
		solver2(vars);
	else if (vars->arg_count == 3)
		solver3(vars);
	else if (vars->arg_count == 5)
		solver5(vars);
	else
		solver_insertion(&vars);
	print_result(vars->instruc);
	vars_destroy(vars);
}
