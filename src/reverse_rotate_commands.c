/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_commands.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:25:20 by mkadri            #+#    #+#             */
/*   Updated: 2024/06/29 12:33:24 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*latest_node;
	int				length;

	length = stack_length(*stack);
	if (*stack == NULL || stack == NULL || length == 1)
		return ;
	latest_node = ft_lst_last(*stack);
	latest_node->previous->next = NULL;
	latest_node->next = *stack;
	latest_node->previous = NULL;
	*stack = latest_node;
	latest_node->next->previous = latest_node;
}

void	rra(t_stack_node **a, bool checker)
{
	reverse_rotate(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, bool checker)
{
	reverse_rotate(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool checker)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!checker)
		write(1, "rrr\n", 4);
}
