/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 20:42:26 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/01/27 20:51:43 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_vars *vars)
{	
	int tmp;

	if(vars->stack_a == NULL)
		printf("error stack_a empty\n");
	if(vars->stack_a == vars->stack_a->next)
		printf("error only one item in stack_a\n");

	tmp = vars->stack_a->nr;
	vars->stack_a->nr = vars->stack_a->next->nr;
	vars->stack_a->next->nr = tmp;
	ft_lstadd_back(&vars->instructions, null_exit(ft_lstnew(SWAP_A)));
}

void	swap_b(t_vars *vars)
{	
	int tmp;

	if(vars->stack_b == NULL)
		printf("error stack_b empty\n");
	if(vars->stack_b == vars->stack_b->next)
		printf("error only one item in stack_b\n");

	tmp = vars->stack_b->nr;
	vars->stack_b->nr = vars->stack_b->next->nr;
	vars->stack_b->next->nr = tmp;
	ft_lstadd_back(&vars->instructions, null_exit(ft_lstnew(SWAP_B)));
}

void	swap_ab(t_vars *vars)
{	
	int tmp;

	if(vars->stack_a == NULL || vars->stack_b == NULL)
		printf("error stack_a or stack_b empty\n");
	if(vars->stack_a == vars->stack_a->next || vars->stack_b == vars->stack_b->next)
		printf("error only one item in stack_b\n");
	tmp = vars->stack_a->nr;
	vars->stack_a->nr = vars->stack_a->next->nr;
	vars->stack_a->next->nr = tmp;
	tmp = vars->stack_b->nr;
	vars->stack_b->nr = vars->stack_b->next->nr;
	vars->stack_b->next->nr = tmp;
	ft_lstadd_back(&vars->instructions, null_exit(ft_lstnew(SWAP_AB)));
}


void	push_a(t_vars *vars)
{
	t_lststack *tmp;
	t_lststack *last;
	
	if(vars->stack_b == NULL)
		printf("error stack_b empty\n");
	tmp = vars->stack_b;
	
	if (vars->stack_b != vars->stack_b->next)
	{
		vars->stack_b->prev->next = vars->stack_b->next;
		vars->stack_b->next->prev = vars->stack_b->prev;
		vars->stack_b = vars->stack_b->next;
		
	}
	else
		vars->stack_b = NULL;
	if (vars->stack_a == NULL)
	{
		vars->stack_a = tmp;
		vars->stack_a->next = vars->stack_a;
		vars->stack_a->prev = vars->stack_a;
	}
	else
	{
		last = vars->stack_a->prev;
		tmp->next = vars->stack_a;
		tmp->prev = last;
		vars->stack_a->prev = tmp;
		last->next = tmp;
		vars->stack_a = tmp;
	}
	ft_lstadd_back(&vars->instructions, null_exit(ft_lstnew(PUSH_A)));
}

void	push_b(t_vars *vars)
{
	t_lststack *tmp;
	t_lststack *last;
	
	if(vars->stack_a == NULL)
		printf("error stack_a empty\n");
	tmp = vars->stack_a;
	
	if (vars->stack_a != vars->stack_a->next)
	{
		vars->stack_a->prev->next = vars->stack_a->next;
		vars->stack_a->next->prev = vars->stack_a->prev;
		vars->stack_a = vars->stack_a->next;
	}
	else
		vars->stack_a = NULL;

	if (vars->stack_b == NULL)
	{
		vars->stack_b = tmp;
		vars->stack_b->next = vars->stack_b;
		vars->stack_b->prev = vars->stack_b;
	}
	else
	{
		last = vars->stack_b->prev;
		tmp->next = vars->stack_b;
		tmp->prev = last;
		vars->stack_b->prev = tmp;
		last->next = tmp;
		vars->stack_b = tmp;
	}
	ft_lstadd_back(&vars->instructions, null_exit(ft_lstnew(PUSH_B)));
}

void	rotate_a(t_vars *vars)
{
	if(vars->stack_a == NULL)
		printf("error stack_a empty\n");
	vars->stack_a = vars->stack_a->next;
	ft_lstadd_back(&vars->instructions, null_exit(ft_lstnew(ROTATE_A)));
}

void	rotate_b(t_vars *vars)
{
	if(vars->stack_b == NULL)
		printf("error stack_b empty\n");
	vars->stack_b = vars->stack_b->next;
	ft_lstadd_back(&vars->instructions, null_exit(ft_lstnew(ROTATE_B)));
}

void	rotate_ab(t_vars *vars)
{
	if(vars->stack_a == NULL || vars->stack_b == NULL)
		printf("error stack_a or stack_b empty\n");
	vars->stack_a = vars->stack_a->next;
	vars->stack_b = vars->stack_b->next;
	ft_lstadd_back(&vars->instructions, null_exit(ft_lstnew(ROTATE_AB)));
}


void	reverse_rotate_a(t_vars *vars)
{
	if(vars->stack_a == NULL)
		printf("error stack_a empty\n");
	vars->stack_a = vars->stack_a->prev;
	ft_lstadd_back(&vars->instructions, null_exit(ft_lstnew(REVERSE_ROTATE_A)));
}

void	reverse_rotate_b(t_vars *vars)
{
	if(vars->stack_b == NULL)
		printf("error stack_b empty\n");
	vars->stack_b = vars->stack_b->prev;
	ft_lstadd_back(&vars->instructions, null_exit(ft_lstnew(REVERSE_ROTATE_B)));
}

void	reverse_rotate_ab(t_vars *vars)
{
	if(vars->stack_a == NULL || vars->stack_b == NULL)
		printf("error stack_a or stack_b empty\n");
	vars->stack_a = vars->stack_a->prev;
	vars->stack_b = vars->stack_b->prev;
	ft_lstadd_back(&vars->instructions, null_exit(ft_lstnew(REVERSE_ROTATE_AB)));
}
