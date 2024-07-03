/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:01:26 by mkadri            #+#    #+#             */
/*   Updated: 2024/07/03 19:51:00 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		exit(1);
	else if (argc == 2)
		argv = custom_split(argv[1], ' ');
	stack_init(&a, argv + 1, argc == 2);
	if (!is_sorted(a))
	{
		if (stack_length(a) == 2)
			sa(&a, false);
		else if (stack_length(a) == 3)
			sort_three(&a);
		else
			master_sort(&a, &b);
	}
	free_stack(&a);
	return (0);
}
