/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_steps.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 21:06:20 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/03/17 21:06:20 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_rotate_a(t_vars *vars, int steps)
{
	while (steps < 0)
	{
		reverse_rotate_a(vars);
		steps++;
	}
	while (steps > 0)
	{
		rotate_a(vars);
		steps--;
	}
}

void	execute_rotate_b(t_vars *vars, int steps)
{
	while (steps < 0)
	{
		reverse_rotate_b(vars);
		steps++;
	}
	while (steps > 0)
	{
		rotate_b(vars);
		steps--;
	}
}

void	execute_rotate_ab(t_vars *vars, int steps)
{
	while (steps < 0)
	{
		reverse_rotate_ab(vars);
		steps++;
	}
	while (steps > 0)
	{
		rotate_ab(vars);
		steps--;
	}
}

void	execute_steps(t_vars *vars, t_moves best_move)
{
	if ((best_move.a > 0 && best_move.b > 0) || \
	(best_move.a < 0 && best_move.b < 0))
	{
		if (ft_abs(best_move.a) > ft_abs(best_move.b))
		{
			execute_rotate_ab(vars, best_move.b);
			execute_rotate_a(vars, best_move.a - best_move.b);
		}
		else
		{
			execute_rotate_ab(vars, best_move.a);
			execute_rotate_b(vars, best_move.b - best_move.a);
		}
	}
	else
	{
		execute_rotate_a(vars, best_move.a);
		execute_rotate_b(vars, best_move.b);
	}
}
