/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 15:36:02 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/03/15 20:14:26 by jvan-kra      ########   odam.nl         */
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
	int					idx;
	struct s_lststack	*next;
}	t_lststack;

typedef struct s_vars
{
	t_lststack		*stack_a;
	t_lststack		*stack_b;
	t_list			*instruc;
	int				arg_count;
}	t_vars;

typedef struct s_moves
{
	int	a;
	int	b;
	int	tot;
}	t_moves;

void			print_result(t_list *instructions);
void			solver2(t_vars *vars);
void			solver3(t_vars *vars);
void			solver5(t_vars *vars);
void			solver_radix(t_vars *vars);
void			solver_insertion(t_vars **vars);
void			rotate_to_a(t_vars *vars, int num);
int				calc_rotate_a(t_vars *vars, int num);

//lststack functions
t_lststack		*lststack_new(int nr, int idx);
void			lststack_add_front(t_lststack **head, t_lststack *node);
void			lststack_add_back(t_lststack **head, t_lststack *new);
t_lststack		*lststack_remove_front(t_lststack **head);
void			lststack_clear(t_lststack **stack);
int				lststack_length(t_lststack *head);
void			lststack_idx(t_lststack *head);
int				lststack_check_order(t_lststack *head);

//input parsing
int				parse_input(t_vars *vars, int argc, const char **argv);
int				ft_atoi_p(const char *str, int *number);

//errors
void			error_exit(void);
void			*null_exit(void *ptr);

//instructions
void			swap_a(t_vars *vars);
void			swap_b(t_vars *vars);
void			swap_ab(t_vars *vars);
void			push_a(t_vars *vars);
void			push_b(t_vars *vars);
void			rotate_a(t_vars *vars);
void			rotate_b(t_vars *vars);
void			rotate_ab(t_vars *vars);
void			reverse_rotate_a(t_vars *vars);
void			reverse_rotate_b(t_vars *vars);
void			reverse_rotate_ab(t_vars *vars);

//convert_steps
int				rot_conv_norm(int steps, int length);
int				rot_conv_rev(int steps, int length);
int				rot_conv_opt(int steps, int lenght);
int				rot_conv_comb(int steps, int lenght, int direction);

//execute steps
void			execute_rotate_a(t_vars *vars, int steps);
void			execute_rotate_b(t_vars *vars, int steps);
void			execute_rotate_ab(t_vars *vars, int steps);
void			execute_steps(t_vars *vars, t_moves best_move);

//vars

t_vars			*vars_init(void);
t_vars			*vars_destroy(t_vars *vars);
t_vars			*vars_copy(t_vars *vars);

#endif