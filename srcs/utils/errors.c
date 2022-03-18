/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 16:58:44 by jvan-kra      #+#    #+#                 */
/*   Updated: 2021/12/17 16:57:39 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit (EXIT_FAILURE);
}

void	*null_exit(void *ptr)
{
	if (ptr == NULL)
	{
		printf("whoop whoop big error!\n");
		error_exit();
	}
	return (ptr);
}
