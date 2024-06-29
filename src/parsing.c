/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 22:21:23 by mkadri            #+#    #+#             */
/*   Updated: 2024/06/29 16:38:21 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	correct_format(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	verif_is_int(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!correct_format(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parsing_args(int argc, char **argv, t_args *args)
{
	long	number;
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (verif_is_int(argv) == 0)
		display_error("error\n");
	args->params = (int *) malloc(sizeof (int) * (argc - 1));
	if (!args->params)
		return (0);
	while (argv[i])
	{
		number = ft_atol(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
		{
			free(args->params);
			display_error("error\n");
		}
		args->params[j] = number;
		j++;
		i++;
	}
	args->nb_params = argc - 1;
	return (0);
}

int	split_args(char *argv, t_args *args)
{
	int		i;
	int		j;
	char	**args_split;

	i = 0;
	j = 0;
	args_split = verif_split(argv, args);
	args->params = (int *) malloc(sizeof(int) * (array_len(args_split)));
	if (!args->params)
		return (0);
	while (args_split[i])
	{
		if (ft_atol(args_split[i]) > INT_MAX
			|| ft_atol(args_split[i]) < INT_MIN)
		{
			free_array(args_split);
			free(args->params);
			display_error("error\n");
		}
		args->params[j] = ft_atol(args_split[i]);
		j++;
		i++;
	}
	free_array(args_split);
	return (1);
}
