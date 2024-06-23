/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:02:07 by mkadri            #+#    #+#             */
/*   Updated: 2024/06/23 14:20:37 by mkadri           ###   ########.fr       */
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

/* Args functions */

int		parsing_args(int argc, char **argv, t_args *args);
int		verif_is_int(char **argv);
int		is_sorted(t_args *args);
int		is_sign(char c);
int		check_double(t_args *args);
int		array_len(char **array);
int		split_args(char *argv, t_args *args);
void	free_array(char **array);
void	display_error(char *str);
void	check_input(t_args *args);
long	ft_atol(const char *str);
char	**verif_split(char *argv, t_args *args);

/* Stack struct */

typedef struct s_stack_node
{
	int	number;
	int	index;
	int	push_cost;
	int	list_size;
	bool	above_median;
	bool	cheapest;
	
	struct s_stack_node *next;
	struct s_stack_node *previous;
	struct s_stack_node *target_node;
    
}	t_stack_node;

/* Stack functions */

void copy_in_stack_a(t_args *args, t_stack_node **stack_a);
void create_node(t_stack_node **stack_a, int number);
void print_list(t_stack_node* head);
void print_node(t_stack_node* node);
void free_stack(t_stack_node* head);
int     stack_length(t_stack_node *stack);
t_stack_node	*ft_lst_last(t_stack_node *lst);

/* Swap functions */

void	swap(t_stack_node **head);
void	sa(t_stack_node **a, bool checker);
void	sa(t_stack_node **b, bool checker);
void	ss(t_stack_node **a, t_stack_node **b,bool checker);

/* Rotate functions */

void	rotate(t_stack_node **stack);
void	ra(t_stack_node **a, bool checker);
void	rb(t_stack_node **b, bool checker);
void	rr(t_stack_node **a, t_stack_node **b,bool checker);


#endif