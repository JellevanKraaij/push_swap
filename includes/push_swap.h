/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 15:36:02 by jvan-kra      #+#    #+#                 */
/*   Updated: 2021/12/17 21:08:05 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libft.h>
# include <stdio.h>

# define SWAP_A 			"sa"
# define SWAP_B				"sb"
# define SWAP_AB			"ss"
# define PUSH_A				"pa"
# define PUSH_B				"pb"
# define ROTATE_A			"ra"
# define ROTATE_B			"rb"
# define ROTATE_AB			"rr"
# define REVERSE_ROTATE_A	"rra"
# define REVERSE_ROTATE_B	"rrb"
# define REVERSE_ROTATE_AB	"rrr"

typedef struct u_stack_idx
{
	int		num;
	int8_t	filled;
}	t_stack_idx;

typedef struct s_stacks
{
	t_stack_idx	*a;
	t_stack_idx	*b;
	int			size;
}	t_stacks;

typedef struct s_vars
{
	t_stacks	*stack;
	t_list		*instructions;
}	t_vars;

//constructors
t_stacks	*init_stacks(int stack_size);
void		destroy_stacks(t_stacks *stack);

//input parsing
void		parse_input(t_vars *vars, int argc, const char *argv[]);
int			ft_atoi_p(const char *str, int *number);

//errors
void		error_exit(void);
void		*null_exit(void *ptr);

//debuggers
void		print_stacks(t_stacks *stack);

//instructions
void		swap_a(t_vars *vars);
void		rotate_a(t_vars *vars);

#endif