/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:01:26 by mkadri            #+#    #+#             */
/*   Updated: 2024/06/17 15:10:00 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_args	args;

	if (argc <= 1)
		exit (1);
	else if (argc == 2)
		split_args(argv[1], &args);
	else if (argc > 2)
		parsing_args(argc, argv, &args);
	check_input(&args);
	free(args.params);
	return (0);
}
