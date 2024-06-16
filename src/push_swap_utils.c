/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 22:21:29 by mkadri            #+#    #+#             */
/*   Updated: 2024/06/16 18:06:49 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
