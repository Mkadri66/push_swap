/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:25:51 by mkadri            #+#    #+#             */
/*   Updated: 2024/07/03 12:48:35 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_length(t_stack_node *stack)
{
	int	count;

	if (!stack) 
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_stack_node	*ft_lst_last(t_stack_node *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	create_node(t_stack_node **stack_a, int number)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (NULL == stack_a)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (NULL == node)
		return ;
	node->next = NULL;
	node->number = number;
	if (NULL == *stack_a)
	{
		*stack_a = node;
		node->previous = NULL;
	}
	else
	{
		last_node = ft_lst_last(*stack_a);
		last_node->next = node;
		node->previous = last_node;
	}
}

void	free_stack(t_stack_node **head)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (NULL == head)
		return ;
	current = *head;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*head = NULL;
}
