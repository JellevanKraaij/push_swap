/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/29 19:51:18 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/01/29 19:51:18 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int count_bits(unsigned int n)
{
	unsigned int ret;

	ret = 0;
	while (n)
	{
		ret++;
		n >>= 1;
	}
	return (ret);
}

void	solver_radix(t_vars *vars)
{
	unsigned int				bitcnt;
	const unsigned int	max_bit = count_bits(vars->arg_count);
	unsigned int	i;
	bitcnt  = 0;


	while (bitcnt < max_bit)
	{
		i = 0;
		while (i < vars->arg_count)
		{
			// printf("before lastbit_t\n");
			if (((stack_a_idx(vars)) & (1 << bitcnt))) 
			{
				// printf("rotate a\n");
				rotate_a(vars);
			}
			else
			{
				push_b(vars);
				// printf("push b\n");
			}
			i++;
			// printf("i = %d bitcnt = %d argc = %d\n", i, bitcnt, vars->arg_count);
		}
		while(vars->stack_b != NULL)
		{
			// printf("push a\n");
			push_a(vars);
		}
		bitcnt++;
	}
}

// void	my_solver(t_vars *vars)
// {
// 	size_t i;

// 	i = 0;
// 	while (i < vars->arg_count / 2)
// 	{
// 		if (stack_a_idx(vars) < vars->arg_count / 2)
// 		{
// 			push_b(vars);
// 			i++;
// 		}
// 		else
// 			rotate_a(vars);
// 	}
// 	i = 0;

// 	// while (i < (size_t)(vars->arg_count / 2) * (size_t)(vars->arg_count / 2))
// 	// {
// 	// 	if ()
// 	// 	i++;
// 	// }
// }

unsigned int	steps_to_idx_place_b(t_vars *vars)
{
	t_lststack *tmp;
	unsigned int i;

	tmp = vars->stack_b->next;
	if (vars->stack_a->idx > vars->stack_b->idx);
		return (i);
	while (vars->stack_b != tmp)
	{
		normal++;
		if (tmp->idx == start || tmp->idx == end)
			break ;
		tmp = tmp->next;
	}
}

void	rotate_to_match(t_vars *vars)
{

}

void	rotate_to_closest_a(t_vars *vars, unsigned int start, unsigned int end)
{
	t_lststack *tmp;

	unsigned int i;
	unsigned int normal;
	unsigned int reverse;

	tmp = vars->stack_a->next;
	normal = 0;
	reverse = 0;
	if (vars->stack_a->idx == start || vars->stack_a->idx == end)
		return ;
	while (tmp != vars->stack_a)
	{
		normal++;
		if (tmp->idx == start || tmp->idx == end)
			break ;
		tmp = tmp->next;
	}
	tmp = vars->stack_a->prev;
	while (tmp != vars->stack_a)
	{
		reverse++;
		if (tmp->idx == start || tmp->idx == end)
			break ;
		tmp = tmp->prev;
	}
	i = 0;
	if (normal <= reverse)
	{
		while(i < normal)
		{
			rotate_a(vars);
			i++;
		}
	}
	else
	{
		while(i < reverse)
		{
			reverse_rotate_a(vars);
			i++;
		}
	}

}

void	rotate_to_b(t_vars *vars, unsigned int num)
{
	t_lststack *tmp;

	unsigned int i;
	unsigned int normal;
	unsigned int reverse;

	tmp = vars->stack_b->next;
	normal = 0;
	reverse = 0;
	if (vars->stack_b->idx == num )
		return ;
	while (tmp != vars->stack_b)
	{
		normal++;
		if (tmp->idx == num)
			break ;
		tmp = tmp->next;
	}
	tmp = vars->stack_b->prev;
	while (tmp != vars->stack_b)
	{
		reverse++;
		if (tmp->idx == num)
			break ;
		tmp = tmp->prev;
	}
	i = 0;
	if (normal <= reverse)
	{
		while(i < normal)
		{
			rotate_b(vars);
			i++;
		}
	}
	else
	{
		while(i < reverse)
		{
			reverse_rotate_b(vars);
			i++;
		}
	}

}

void	my_solver(t_vars *vars)
{
	unsigned int start;
	unsigned int end;

	start = 0;
	end = vars->arg_count - 1;
	while(start <= end)
	{
		rotate_to_closest_a(vars, start, end);
		if(stack_a_idx(vars) == start)
		{
			push_b(vars);
			start++;
		}
		else if(stack_a_idx(vars) == end)
		{
			push_b(vars);
			rotate_b(vars);
			end--;
		}
	}
	rotate_to_b(vars, vars->arg_count - 1);
	start = 0;
	while(start < vars->arg_count)
	{
		push_a(vars);
		start++;
	}

}

int	check_order_a(t_vars *vars)
{
	unsigned int i;
	t_lststack *tmp;

	i = 0;
	tmp = vars->stack_a;
	while (1)
	{
		if (tmp->idx != i)
			return (0);
		tmp = tmp->next;
		i++;
		if (tmp == vars->stack_a)
			return (1);
	}
}

int	check_order_b(t_vars *vars)
{
	unsigned int i;
	t_lststack *tmp;

	i = 0;
	tmp = vars->stack_a;
	while (1)
	{
		if (tmp->idx != i)
			return (0);
		tmp = tmp->next;
		i++;
		if (tmp == vars->stack_a)
			return (1);
	}
}