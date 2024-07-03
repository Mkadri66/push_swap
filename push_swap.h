/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:02:07 by mkadri            #+#    #+#             */
/*   Updated: 2024/07/03 13:01:33 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <sys/wait.h>
# include <limits.h>

/* Args struct */

typedef struct s_args
{
	int	*params;
	int	nb_params;
}	t_args;

/* Stack struct */

typedef struct s_stack_node
{
	int							number;
	int							index;
	int							push_cost;
	int							list_size;
	bool						above_median;
	bool						cheapest;
	struct s_stack_node			*next;
	struct s_stack_node			*previous;
	struct s_stack_node			*target_node;
}	t_stack_node;

/* Parsing functions */

int				verif_is_int(char *argv);
bool			is_sorted(t_stack_node *a);
int				is_sign(char c);
int				check_double(t_stack_node *a, int number);
int				array_len(char **array);
void			free_array(char **array);
void			display_error(char *str);
long			ft_atol(const char *str);
char			**custom_split(char *str, char separator);

/* Stack functions */

void			stack_init(t_stack_node **a, char **argv, bool flag);
void			set_curent_index(t_stack_node *stack);
void			create_node(t_stack_node **stack_a, int number);
void			free_stack(t_stack_node **head);
int				stack_length(t_stack_node *stack);
void			free_matrix(char **argv);
void			error_free(t_stack_node **a,  char **argv, bool flag);

/* Swap functions */

void			swap(t_stack_node **head);
void			sa(t_stack_node **a, bool checker);
void			sb(t_stack_node **b, bool checker);
void			ss(t_stack_node **a, t_stack_node **b, bool checker);

/* Rotate functions */

void			rotate(t_stack_node **stack);
void			ra(t_stack_node **a, bool checker);
void			rb(t_stack_node **b, bool checker);
void			rr(t_stack_node **a, t_stack_node **b, bool checker);

/* Push functions */

void			push(t_stack_node **dest, t_stack_node **src);
void			pa(t_stack_node **a, t_stack_node **b, bool checker);
void			pb(t_stack_node **b, t_stack_node **a, bool checker);
void			conclude_rotation(t_stack_node **stack,
					t_stack_node *top_node, char stack_name);

/* Reverse rotate functions */

void			reverse_rotate(t_stack_node **stack);
void			rra(t_stack_node **a, bool checker);
void			rrb(t_stack_node **b, bool checker);
void			rrr(t_stack_node **a, t_stack_node **b, bool checker);
void			reverse_rotate_both(t_stack_node **a,
					t_stack_node **b, t_stack_node *cheapest);

/* Sort functions */

void			sort_three(t_stack_node **a);
void			master_sort(t_stack_node **a, t_stack_node **b);

/* Set functions */

void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			set_current_index(t_stack_node *stack);
void			set_target_node(t_stack_node *a, t_stack_node *b);

/* Stack node functions*/

t_stack_node	*ft_lst_last(t_stack_node *lst);
t_stack_node	*find_cheapest(t_stack_node *stack);
t_stack_node	*smallest_in_stack(t_stack_node *stack);
t_stack_node	*find_highest(t_stack_node *stack);

#endif
