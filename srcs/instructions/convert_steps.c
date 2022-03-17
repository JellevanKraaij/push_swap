/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_steps.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 21:20:16 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/03/17 21:20:16 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rot_conv_norm(int steps, int length)
{
	if (steps >= 0)
		return (steps);
	return (length + steps);
}

int	rot_conv_rev(int steps, int length)
{
	if (steps < 0)
		return (steps);
	return ((length - steps) * -1);
}

int	rot_conv_opt(int steps, int lenght)
{
	if (rot_conv_norm(steps, lenght) < \
	rot_conv_rev(steps, lenght) * -1)
		return (rot_conv_norm(steps, lenght));
	return (rot_conv_rev(steps, lenght));
}

int	rot_conv_comb(int steps, int lenght, int direction)
{
	if (direction < 0)
		return (rot_conv_rev(steps, lenght));
	if (direction > 0)
		return (rot_conv_norm(steps, lenght));
	return (rot_conv_opt(steps, lenght));
}
