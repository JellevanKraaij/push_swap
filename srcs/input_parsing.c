/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_parsing.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 16:54:05 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/01/27 20:48:10 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_doubles(t_vars *vars, int num)
{
	t_lststack *tmp;

	if (vars->stack_a == NULL)
		return (0);

	tmp = vars->stack_a->next;

	if (vars->stack_a->idx == num)
	{
		return(1);
	}

	while (vars->stack_a != tmp)
	{
		if (tmp->idx == num)
			return(1);
		tmp = tmp->next;
	}
	return (0);
}

void	parse_input(t_vars *vars, int argc, const char *argv[])
{
	int	i;
	t_lststack *lsttmp;
	int tmp;

	if (argc < 2)
		error_exit();
	i = 1;

	if (ft_atoi_p(argv[i], &tmp) || \
		check_doubles(vars, tmp))
		{
			// stack_clear_list(vars->stack_a);
			error_exit();
		}
	vars->stack_a = stack_create_elem(tmp);
	lsttmp = vars->stack_a;
	i++;
	while (i < argc)
	{
		if (ft_atoi_p(argv[i], &tmp) || \
		check_doubles(vars, tmp))
			{
			printf("i = %d, num = %d\n", i, tmp);
			stack_clear_list(vars->stack_a);
			error_exit();
			}
		lsttmp->next = stack_create_elem(tmp);
		lsttmp->next->prev = lsttmp;
		lsttmp = lsttmp->next;
		vars->stack_a->prev = lsttmp;
		lsttmp->next = vars->stack_a;
		i++;
	}
	vars->arg_count = argc - 1;
}
