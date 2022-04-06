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

#include "checker.h"
#include <libft.h>

static int	check_doubles(t_vars *vars, int num)
{
	t_lststack	*tmp;

	if (vars->stack_a == NULL)
		return (0);
	tmp = vars->stack_a->next;
	if (vars->stack_a->nr == num)
	{
		return (1);
	}
	while (vars->stack_a != tmp)
	{
		if (tmp->nr == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	parse_input(t_vars *vars, int argc, const char **argv)
{
	int				i;
	int				j;
	int				nr;
	char			**arg_split;

	i = 1;
	while (i < argc)
	{
		arg_split = null_exit(ft_split(argv[i], ' '));
		j = 0;
		while (arg_split[j])
		{
			if (ft_atoi_p(arg_split[j], &nr) || check_doubles(vars, nr))
			{
				ft_split_free(arg_split);
				lststack_clear(&vars->stack_a);
				return (-1);
			}
			lststack_add_back(&vars->stack_a, lststack_new(nr, -1));
			j++;
		}
		ft_split_free(arg_split);
		i++;
	}
	return (lststack_length(vars->stack_a));
}
