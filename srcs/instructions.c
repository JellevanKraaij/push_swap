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

	tmp = vars->stack_a->idx;
	vars->stack_a->idx = vars->stack_a->next->idx;
	vars->stack_a->next->idx = tmp;
	ft_lstadd_back(&vars->instructions, null_exit(ft_lstnew(SWAP_A)));
}

void	swap_b(t_vars *vars)
{	
	int tmp;

	tmp = vars->stack_b->idx;
	vars->stack_b->idx = vars->stack_b->next->idx;
	vars->stack_b->next->idx = tmp;
	ft_lstadd_back(&vars->instructions, null_exit(ft_lstnew(SWAP_B)));
}

void	swap_ab(t_vars *vars)
{	
	int tmp;

	tmp = vars->stack_a->idx;
	vars->stack_a->idx = vars->stack_a->next->idx;
	vars->stack_a->next->idx = tmp;
	tmp = vars->stack_b->idx;
	vars->stack_b->idx = vars->stack_b->next->idx;
	vars->stack_b->next->idx = tmp;
	ft_lstadd_back(&vars->instructions, null_exit(ft_lstnew(SWAP_AB)));
}


void	push_a(t_vars *vars)
{
	t_lststack *tmp;
	
	if(vars->stack_b == NULL)
		printf("error stack_b empty\n");
	tmp = vars->stack_b;
	
	vars->stack_b->prev->next = vars->stack_b->next;
	vars->stack_b = vars->stack_b->next;

	if (vars->stack_a == NULL)
	{
		vars->stack_a = tmp;
		vars->stack_a->next = vars->stack_a;
		vars->stack_a->prev = vars->stack_a;
	}
	else
	{
		vars->stack_a->prev = vars->stack_a;
		tmp->next = vars->stack_a;
		vars->stack_a = tmp;
	}
	ft_lstadd_back(&vars->instructions, null_exit(ft_lstnew(PUSH_A)));
}

void	push_b(t_vars *vars)
{
	t_lststack *tmp;
	
	if(vars->stack_a == NULL)
		printf("error stack_a empty\n");
	tmp = vars->stack_a;
	
	vars->stack_a->prev->next = vars->stack_a->next;
	vars->stack_a = vars->stack_a->next;

	if (vars->stack_b == NULL)
	{
		vars->stack_b = tmp;
		vars->stack_b->next = vars->stack_b;
		vars->stack_b->prev = vars->stack_b;
	}
	else
	{
		vars->stack_b->prev = vars->stack_b;
		tmp->next = vars->stack_b;
		vars->stack_b = tmp;
	}
	ft_lstadd_back(&vars->instructions, null_exit(ft_lstnew(PUSH_B)));
}

void	rotate_a(t_vars *vars)
{
	vars->stack_a = vars->stack_a->next;
	ft_lstadd_back(&vars->instructions, null_exit(ft_lstnew(ROTATE_A)));
}

void	rotate_b(t_vars *vars)
{
	vars->stack_b = vars->stack_b->next;
	ft_lstadd_back(&vars->instructions, null_exit(ft_lstnew(ROTATE_B)));
}

void	rotate_ab(t_vars *vars)
{
	vars->stack_a = vars->stack_a->next;
	vars->stack_b = vars->stack_b->next;
	ft_lstadd_back(&vars->instructions, null_exit(ft_lstnew(ROTATE_AB)));
}


void	reverse_rotate_a(t_vars *vars)
{
	vars->stack_a = vars->stack_a->prev;
	ft_lstadd_back(&vars->instructions, null_exit(ft_lstnew(REVERSE_ROTATE_A)));
}

void	reverse_rotate_b(t_vars *vars)
{
	vars->stack_b = vars->stack_b->prev;
	ft_lstadd_back(&vars->instructions, null_exit(ft_lstnew(REVERSE_ROTATE_B)));
}

void	reverse_rotate_ab(t_vars *vars)
{
	vars->stack_a = vars->stack_a->prev;
	vars->stack_b = vars->stack_b->prev;
	ft_lstadd_back(&vars->instructions, null_exit(ft_lstnew(REVERSE_ROTATE_AB)));
}
