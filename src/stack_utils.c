/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:25:51 by mkadri            #+#    #+#             */
/*   Updated: 2024/06/26 17:33:39 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_length(t_stack_node *stack)
{
	int	i;

	i = 0;
	if (stack == NULL)
		return (0);
	while (stack != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

t_stack_node	*ft_lst_last(t_stack_node *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	create_node(t_stack_node **stack_a, int number)
{
	t_stack_node	*current_node;
	t_stack_node	*last_node;

	if (!stack_a)
		return ;
	current_node = malloc(sizeof(t_stack_node));
	if (!current_node)
		return ;
	current_node->next = NULL;
	current_node->number = number;
	if (!(*stack_a))
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

void	copy_in_stack_a(t_args *args, t_stack_node **stack_a)
{
	int	i;

	i = 0;
	while (i < args->nb_params)
	{
		create_node(stack_a, args->params[i]);
		i++;
	}
	free(args->params);
}

void	free_stack(t_stack_node *head)
{
	t_stack_node	*current;
	t_stack_node	*next_node;

	current = head;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}
