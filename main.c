/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:01:26 by mkadri            #+#    #+#             */
/*   Updated: 2024/06/12 16:42:37 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_args  args;

    if(argc <= 2)
        exit(1);
    verif_is_int(argv);
    parsing_args(argc, argv, &args);
    if(is_sorted(argc, &args))
    {
        free(args.params);
        exit(1);
    }
    return(0);
}