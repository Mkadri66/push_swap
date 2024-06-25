/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:01:26 by mkadri            #+#    #+#             */
/*   Updated: 2024/06/25 23:13:50 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_args	args;
	t_stack_node	*a;
	t_stack_node	*b;
	
	a = NULL;
	b = NULL;
	if (argc <= 1)
		exit (1);
	else if (argc == 2)
		split_args(argv[1], &args);
	else if (argc > 2)
		parsing_args(argc, argv, &args);
	check_input(&args);
	copy_in_stack_a(&args, &a);
    if(stack_length(a) == 2)
        sa(&a, false);
    else if (stack_length(a) == 3)
        sort_three(&a);
    else
        master_sort(&a, &b);
	free_stack(a);
	return (0);
}
