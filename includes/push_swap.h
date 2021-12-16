/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-kra <jvan-kra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:36:02 by jvan-kra          #+#    #+#             */
/*   Updated: 2021/12/16 18:50:52 by jvan-kra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libft.h>
# include <stdio.h>

typedef struct s_stack
{
	int			*a;
	int			*b;
}	t_stack;

typedef struct s_vars
{
	t_stack	*stack;
	t_list	*instructions;
}	t_vars;

//constructors
t_stack	*init_stack(int stack_size);
void	destroy_stack(t_stack *stack);

void	parse_input(t_vars *vars, int argc, const char *argv[]);

void	error_exit(void);
void	*null_exit(void *ptr);
int		ft_atoi_p(const char *str, int *number);

#endif