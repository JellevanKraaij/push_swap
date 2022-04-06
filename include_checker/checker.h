/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-kra <jvan-kra@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 13:16:33 by jvan-kra      #+#    #+#                 */
/*   Updated: 2022/04/06 13:16:33 by jvan-kra      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define SWAP_A 			"sa\n"
# define SWAP_B				"sb\n"
# define SWAP_AB			"ss\n"
# define PUSH_A				"pa\n"
# define PUSH_B				"pb\n"
# define ROTATE_A			"ra\n"
# define ROTATE_B			"rb\n"
# define ROTATE_AB			"rr\n"
# define REVERSE_ROTATE_A	"rra\n"
# define REVERSE_ROTATE_B	"rrb\n"
# define REVERSE_ROTATE_AB	"rrr\n"

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
	int				arg_count;
}	t_vars;

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

//vars
t_vars			*vars_init(void);
t_vars			*vars_destroy(t_vars *vars);
t_vars			*vars_copy(t_vars *vars);

//input parsing
int				parse_input(t_vars *vars, int argc, const char **argv);
int				ft_atoi_p(const char *str, int *number);

//errors
void			error_exit(void);
void			*null_exit(void *ptr);

//lststack functions
t_lststack		*lststack_new(int nr, int idx);
void			lststack_add_front(t_lststack **head, t_lststack *node);
void			lststack_add_back(t_lststack **head, t_lststack *new);
t_lststack		*lststack_remove_front(t_lststack **head);
void			lststack_clear(t_lststack **stack);
int				lststack_length(t_lststack *head);
void			lststack_idx(t_lststack *head);
int				lststack_check_order(t_lststack *head);

#endif