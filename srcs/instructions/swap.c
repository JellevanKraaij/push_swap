/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/04 21:24:35 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/02/04 21:24:35 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_vars *vars)
{	
	int				tmp_nr;
	unsigned int	tmp_idx;

	tmp_nr = vars->stack_a->nr;
	tmp_idx = vars->stack_a->idx;
	vars->stack_a->nr = vars->stack_a->next->nr;
	vars->stack_a->next->nr = tmp_nr;
	vars->stack_a->idx = vars->stack_a->next->idx;
	vars->stack_a->next->idx = tmp_idx;
	ft_lstadd_back(&vars->instruc, null_exit(ft_lstnew(SWAP_A)));
}

void	swap_b(t_vars *vars)
{	
	int				tmp_nr;
	unsigned int	tmp_idx;

	tmp_nr = vars->stack_b->nr;
	tmp_idx = vars->stack_b->idx;
	vars->stack_b->nr = vars->stack_b->next->nr;
	vars->stack_b->next->nr = tmp_nr;
	vars->stack_b->idx = vars->stack_b->next->idx;
	vars->stack_b->next->idx = tmp_idx;
	ft_lstadd_back(&vars->instruc, null_exit(ft_lstnew(SWAP_B)));
}

void	swap_ab(t_vars *vars)
{	
	int				tmp_nr;
	unsigned int	tmp_idx;

	tmp_nr = vars->stack_a->nr;
	tmp_idx = vars->stack_a->idx;
	vars->stack_a->nr = vars->stack_a->next->nr;
	vars->stack_a->next->nr = tmp_nr;
	vars->stack_a->idx = vars->stack_a->next->idx;
	vars->stack_a->next->idx = tmp_idx;
	tmp_nr = vars->stack_b->nr;
	tmp_idx = vars->stack_b->idx;
	vars->stack_b->nr = vars->stack_b->next->nr;
	vars->stack_b->next->nr = tmp_nr;
	vars->stack_b->idx = vars->stack_b->next->idx;
	vars->stack_b->next->idx = tmp_idx;
	ft_lstadd_back(&vars->instruc, null_exit(ft_lstnew(SWAP_AB)));
}
