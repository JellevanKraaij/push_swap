/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 15:36:02 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/01/27 20:24:59 by jvan-kra      ########   odam.nl         */
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

typedef struct s_lststack
{
	struct s_lststack	*prev;
	int					nr;
	unsigned int		idx;
	struct s_lststack	*next;
}	t_lststack;

typedef struct s_vars
{
	t_lststack		*stack_a;
	t_lststack		*stack_b;
	t_list			*instructions;
	unsigned int	arg_count;
}	t_vars;

void		print_result(t_vars *vars);
void		my_solver(t_vars *vars);
void		solver2(t_vars *vars);
void		solver3(t_vars *vars);
void		solver_radix(t_vars *vars);


//constructors
t_lststack	*stack_create_elem(int nr);
void		stack_clear_list(t_lststack *stack);
unsigned int stack_a_idx(t_vars *vars);
unsigned int stack_b_idx(t_vars *vars);
unsigned int stack_a_next_idx(t_vars *vars);
unsigned int stack_b_next_idx(t_vars *vars);


//input parsing
void		parse_input(t_vars *vars, int argc, const char *argv[]);
int			ft_atoi_p(const char *str, int *number);

//errors
void		error_exit(void);
void		*null_exit(void *ptr);

//debuggers
void		print_stacks(t_vars *stack);

//instructions
void	swap_a(t_vars *vars);
void	swap_b(t_vars *vars);
void	swap_ab(t_vars *vars);
void	push_a(t_vars *vars);
void	push_b(t_vars *vars);
void	rotate_a(t_vars *vars);
void	rotate_b(t_vars *vars);
void	rotate_ab(t_vars *vars);
void	reverse_rotate_a(t_vars *vars);
void	reverse_rotate_b(t_vars *vars);
void	reverse_rotate_ab(t_vars *vars);
int		check_order_a(t_vars *vars);
int		check_order_b(t_vars *vars);

#endif