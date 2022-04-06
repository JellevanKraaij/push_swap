/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vars.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/18 15:51:12 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/03/18 15:51:12 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <libft.h>

t_vars	*vars_init(void)
{
	return (null_exit(ft_calloc(1, sizeof(t_vars))));
}

t_vars	*vars_destroy(t_vars *vars)
{
	lststack_clear(&vars->stack_a);
	lststack_clear(&vars->stack_b);
	free(vars);
	return (NULL);
}
