/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveerara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:03:10 by nveerara          #+#    #+#             */
/*   Updated: 2022/08/30 20:28:58 by nveerara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	end_read_first_test(t_bsq *bsq)
{
	printf("fill : %c empt : %c obst : %c lines : %d lsize : %d bsq x : %d bsq y : %d bsq size : %d\n", bsq->fill,
	bsq->empt, bsq->obst, bsq->lines, bsq->lsize, bsq->bsq[0], bsq->bsq[1], bsq->bsqsize);
}

void	read_file(char *av)
{
	t_bsq	bsq;

	init_bsq(&bsq);
	bsq.fd = open(av, O_RDONLY);
	if (bsq.fd == -1)
	{
		print_error();
		return ;
	}
	bsq.ret = read(bsq.fd, bsq.buf, BUFF_SIZE);
	while (bsq.ret)
	{
		while (bsq.bi < bsq.ret)
		{
			if (g_read_bsq[bsq.step](&bsq))
			{
				print_error();
				return ;
			}
		}
		bsq.ret = read(bsq.fd, bsq.buf, BUFF_SIZE);
		bsq.bi = 0;
	}
	if (bsq.step != 6)
	{
		print_error();
		return ;
	}
	close(bsq.fd);
	bsq.fd = open(av, O_RDONLY);
	write_bsq(&bsq);
	close(bsq.fd);
}
