/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:56:28 by mkadri            #+#    #+#             */
/*   Updated: 2024/07/05 12:16:41 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
		rr(a, b, false);
	set_current_index(*a);
	set_current_index(*b);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*highest;

	highest = find_highest(*a);
	if (*a == highest)
		ra(a, false);
	else if ((*a)->next == highest)
		rra(a, false);
	if ((*a)->number > (*a)->next->number)
		sa(a, false);
}

static void	min_on_top(t_stack_node **a)
{
	while ((*a)->number != smallest_in_stack(*a)->number)
	{
		if (smallest_in_stack(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	master_sort(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_length(*a);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !is_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_node_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_node_to_a(a, b);
	}
	set_current_index(*a);
	min_on_top(a);
}
