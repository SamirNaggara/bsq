/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSQ.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveerara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:03:39 by nveerara          #+#    #+#             */
/*   Updated: 2022/08/31 22:34:05 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
/* Je suis le fichier principal ! Read c'est pour lire l'entree standard*/
int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
		read_stdin();
	while (ac - i)
	{
		read_file(av[i]);
		i++;
		if (ac > 2 && i != ac)
			write(1, "\n", 1);
	}
}
