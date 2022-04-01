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

#include "push_swap.h"

t_vars	*vars_init(void)
{
	return (null_exit(ft_calloc(1, sizeof(t_vars))));
}

static void	lstdelf(void *str)
{
	(void)str;
}

static void	*lstmapf(void *str)
{
	return (str);
}

t_vars	*vars_destroy(t_vars *vars)
{
	lststack_clear(&vars->stack_a);
	lststack_clear(&vars->stack_b);
	ft_lstclear(&vars->instruc, lstdelf);
	free(vars);
	return (NULL);
}

t_vars	*vars_copy(t_vars *vars)
{
	t_vars		*ret;
	t_lststack	*tmp;
	int			length;

	ret = vars_init();
	ret->arg_count = vars->arg_count;
	if (vars->instruc != NULL)
		ret->instruc = null_exit(ft_lstmap(vars->instruc, lstmapf, lstdelf));
	length = lststack_length(vars->stack_a);
	tmp = vars->stack_a;
	while (length)
	{
		lststack_add_back(&ret->stack_a, lststack_new(tmp->nr, tmp->idx));
		tmp = tmp->next;
		length--;
	}
	length = lststack_length(vars->stack_b);
	tmp = vars->stack_b;
	while (length)
	{
		lststack_add_back(&ret->stack_b, lststack_new(tmp->nr, tmp->idx));
		tmp = tmp->next;
		length--;
	}
	return (ret);
}
