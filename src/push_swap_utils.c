/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 22:21:29 by mkadri            #+#    #+#             */
/*   Updated: 2024/06/18 15:16:25 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack_node	*ft_lst_last(t_stack_node *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

long	ft_atol(const char *str)
{
	int		sign;
	int		i;
	long	result;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		i++;
	}
	return (i);
}

char	**verif_split(char *argv, t_args *args)
{
	char	**args_split;
	int		len;

	args_split = ft_split(argv, ' ');
	if (!args_split)
		return (0);
	len = array_len(args_split);
	if (!verif_is_int(args_split))
	{
		free_array(args_split);
		display_error("error\n");
	}
	if (len == 1)
	{
		free_array(args_split);
		exit(1);
	}
	args->nb_params = array_len(args_split);
	return (args_split);
}

void create_node(t_stack_node **stack_a, int number)
{
	t_stack_node *current_node;
	t_stack_node *last_node;
	
	if(!stack_a)
		return ;
	current_node = malloc(sizeof(t_stack_node));
	if(!current_node)
		return ;
	current_node->next = NULL;
	current_node->number = number;
	if(!(*stack_a))
	{
		*stack_a = current_node;
		current_node->previous = NULL;
	}
	else 
	{
		last_node = ft_lst_last(*stack_a);
		last_node->next = current_node;
		current_node->previous = last_node;
	}
}
void copy_in_stack_a(t_args *args, t_stack_node **stack_a)
{
	int	i;

	i = 0;
	while(i < args->nb_params)
	{
		create_node(stack_a, args->params[i]);
		i++;
	}
	free(args->params);
}

void free_stack(t_stack_node* head) 
{
    t_stack_node*	current;
    t_stack_node* next_node;

	current = head;
    while (current != NULL) 
	{
        next_node = current->next;
        free(current);
        current = next_node;
    }
}

void print_node(t_stack_node* node)
{
    printf("Number: %d\n", node->number);
    printf("Index: %d\n", node->index);
    printf("Push Cost: %d\n", node->push_cost);
    printf("Above Median: %s\n", node->above_median ? "true" : "false");
    printf("Cheapest: %s\n", node->cheapest ? "true" : "false");
    printf("Next: %p\n", (void*)node->next);
    printf("Previous: %p\n", (void*)node->previous);
    printf("Target Node: %p\n", (void*)node->target_node);
    printf("-------------------\n");
}

void print_list(t_stack_node* head)
{
    t_stack_node* current;
	
	current = head;
    while (current != NULL)
	{
        print_node(current);
        current = current->next;
    }
}