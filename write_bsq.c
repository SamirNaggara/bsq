/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveerara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:48:59 by nveerara          #+#    #+#             */
/*   Updated: 2022/08/30 17:19:55 by nveerara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	alloc_sqr_line(t_bsq *bsq)
{
	int		i;

	bsq->sqr_lc = malloc(sizeof(char) * bsq->bsqsize);
	i = 0;
	while (i < bsq->bsqsize)
	{
		bsq->sqr_lc[i] = bsq->fill;
		i++;
	}
}

void	write_sqr(t_bsq *bsq, int n)
{
	write(1, bsq->sqr_lc, n);
}
/*
void	write_bsq_buf(t_bsq *bsq)
{
	while (bsq->bi < bsq->ret)
	{
		if ((bsq->l + (bsq->i + bsq->ret)/ bsq->lsize <= bsq->bsq[1]))
		{
			if (bsq->l + (bsq->i + bsq->ret) / bsq->lsize == bsq->bsq[1] &&
			bsq->bsq[0] <= (bsq->i + bsq->ret) % bsq->lsize)
			{
				if (bsq->size > (bsq->i + bsq->ret) % bsq->lsize - bsq->bsq[0])
				{
					write(1, bsq->buf, bsq->ret - ((bsq->i + bsq->ret) % bsq->lsize
									- bsq->bsq[0]));
					write_sqr((bsq->i + bsq->ret) % bsq->lsize - bsq->bsq[0]);
					bsq->bi = bsq->ret;
				}
				else
				{
					write(1, buf, bsq->ret - ((bsq->i + bsq->ret) % bsq->lsize - bsq->bsq[0] - bsq->bsqsize) - bsq->bsqsize);
					write_sqr(bsq->size);
					buf->bi += (bsq->ret - ((bsq->i + bsq->ret) % bsq->lsize - bsq->bsq[0] - bsq->bsqsize);
					write(1, &bsq->buf[buf->bi], (bsq->i + bsq->ret) % bsq->lsize - bsq->bsq[0] - bsq->bsqsize);
				}
			}
			else
			{
				write(1, bsq->buf, buf->ret);
				bsq->bi = bsq->ret;
			}
		bsq->i = (bsq->i + bsq->ret) % bsq->lsize;
		bsq->l += (bsq->i + bsq->re) / bsq->lsize;
		}
		else if (bsq->l + (bsq->i + bsq->ret) / bsq->lsize <= bsq->bsq[1] + bsq->bsqsize)
		{*/

void	read_first_line(t_bsq *bsq)
{
	while (bsq->bi < bsq->ret)
	{
		if (bsq->buf[bsq->bi] == '\n')
		{
			bsq->step++;
			bsq->bi++;
			return ;
		}
		bsq->bi++;
	}
}
void	write_bsq_buf(t_bsq *bsq)
{
	while (bsq->bi < bsq->ret)
	{
		if (bsq->bsq[1] <= bsq->l && bsq->l < (bsq->bsq[1] + bsq->bsqsize))
		{
			if (bsq->bsq[0] <= bsq->i && bsq->i < (bsq->bsq[0] + bsq->bsqsize))
				write(1, &bsq->fill, 1);
			else
				write(1, &bsq->buf[bsq->bi], 1);
		}
		else
			write(1, &bsq->buf[bsq->bi], 1);
		bsq->bi++;
		if (bsq->buf[bsq->bi] != '\n')
			bsq->i = (bsq->i + 1) % bsq->lsize;
		if (bsq->buf[bsq->bi] == '\n')
			bsq->l++;
	}
}
void	write_bsq(t_bsq *bsq)
{
	init_bsq_write(bsq);
	while (bsq->ret)
	{
	//	printf("test");
		while (bsq->bi < bsq->ret)
			g_write_bsq[bsq->step](bsq);
		bsq->ret = read(bsq->fd, bsq->buf, BUFF_SIZE);
		bsq->bi = 0;
	}

}
