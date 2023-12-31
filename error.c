/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveerara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:38:37 by nveerara          #+#    #+#             */
/*   Updated: 2022/08/31 22:38:31 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
/* Gere les messages d'erreurs  */
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	print_error(t_bsq *bsq)
{
	ft_putstr("map error\n");
	free_all(bsq);
}
