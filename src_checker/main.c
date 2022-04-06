/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 12:59:22 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/04/06 12:59:22 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"
#include <get_next_line.h>

#include <stdio.h>

char	*trim_get_next_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	if (*line == '\n')
		return (NULL);
	return (line);
}

void	exec_commands(t_vars *vars, char *line)
{
	if (!ft_strncmp(line, SWAP_A, 3))
		swap_a(vars);
	else if (!ft_strncmp(line, SWAP_B, 3))
		swap_b(vars);
	else if (!ft_strncmp(line, SWAP_AB, 3))
		swap_ab(vars);
	else if (!ft_strncmp(line, PUSH_A, 3))
		push_a(vars);
	else if (!ft_strncmp(line, PUSH_B, 3))
		push_b(vars);
	else if (!ft_strncmp(line, ROTATE_A, 3))
		rotate_a(vars);
	else if (!ft_strncmp(line, ROTATE_B, 3))
		rotate_b(vars);
	else if (!ft_strncmp(line, ROTATE_AB, 3))
		rotate_ab(vars);
	else if (!ft_strncmp(line, REVERSE_ROTATE_A, 4))
		reverse_rotate_a(vars);
	else if (!ft_strncmp(line, REVERSE_ROTATE_B, 4))
		reverse_rotate_b(vars);
	else if (!ft_strncmp(line, REVERSE_ROTATE_AB, 4))
		reverse_rotate_ab(vars);
	else
		error_exit();
}

void	parse_stdin(t_vars *vars)
{
	char	*line;

	while (1)
	{
		line = trim_get_next_line(0);
		if (line == NULL)
			break ;
		exec_commands(vars, line);
	}
}

int	main(int argc, const char *argv[])
{
	t_vars	*vars;

	vars = vars_init();
	vars->arg_count = parse_input(vars, argc, argv);
	if (vars->arg_count < 0)
	{
		vars_destroy(vars);
		error_exit();
	}
	if (vars->arg_count == 0)
	{
		vars_destroy(vars);
		return (0);
	}
	parse_stdin(vars);
	if (!lststack_check_order(vars->stack_a))
		ft_putendl_fd("KO", 1);
	else
		ft_putendl_fd("OK", 1);
	vars_destroy(vars);
}
