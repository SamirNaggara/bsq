/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveerara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:03:10 by nveerara          #+#    #+#             */
/*   Updated: 2022/08/31 22:35:43 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
/* Lit le fichier*/
int	read_bsq(t_bsq *bsq)
{
	while (bsq->ret)
	{
		while (bsq->bi < bsq->ret)
		{
			if (g_read_bsq[bsq->step](bsq))
				return (1);
		}
		bsq->ret = read(bsq->fd, bsq->buf, BUFF_SIZE);
		bsq->bi = 0;
	}
	return (0);
}

void	read_file(char *av)
{
	t_bsq	bsq;

	init_bsq(&bsq);
	bsq.fd = open(av, O_RDONLY);
	if (bsq.fd == -1)
	{
		print_error(&bsq);
		return ;
	}
	bsq.ret = read(bsq.fd, bsq.buf, BUFF_SIZE);
	if (read_bsq(&bsq))
	{
		print_error(&bsq);
		return ;
	}
	if (bsq.step != 6)
	{
		print_error(&bsq);
		return ;
	}
	close(bsq.fd);
	bsq.fd = open(av, O_RDONLY);
	write_bsq(&bsq);
	close(bsq.fd);
	free_all(&bsq);
}
