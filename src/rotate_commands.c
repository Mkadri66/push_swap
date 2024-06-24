/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:13:21 by mkadri            #+#    #+#             */
/*   Updated: 2024/06/23 14:20:52 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack_node **stack)
{
	t_stack_node	*lastest_node;
	int				length;

	length = stack_length(*stack);
	if (length == 1 || *stack == NULL || stack == NULL )
		return ;
	lastest_node = ft_lst_last(*stack);
	lastest_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	lastest_node->next->previous = lastest_node;
	lastest_node->next->next = NULL;
}

void	ra(t_stack_node **a, bool checker)
{
	rotate(a);
	if (!checker)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **b, bool checker)
{
	rotate(b);
	if (!checker)
		write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b, bool checker)
{
	rotate(a);
	rotate(b);
	if (!checker)
		write(1, "rr\n", 3);
}
