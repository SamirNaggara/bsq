/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveerara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:48:59 by nveerara          #+#    #+#             */
/*   Updated: 2022/08/30 14:10:19 by nveerara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	write_sqr(t_bsq *bsq, int n)
{
	char	*sqr;
	int		i;

	sqr = malloc(sizeof(char) * n);
	i = 0;
	while (i < n)
	{
		sqr[i] = bsq->fill;
		i++;
	}
	return (sqr);
}

void	write_bsq_buf(t_bsq *bsq)
{
	while (bsq->bi < bsq->ret)
	{
		if ((bsq->l + (bsq->i + bsq->ret)/ bsq->lsize <= bsq->bsq[1]))
		{
			if (bsq->l + (bsq->i + bsq->ret) / bsq->lsize == bsq->bsq[1] &&
			bsq->bsq[0] <= (bsq->i + bsq->ret) % bsq->bsq->lsize)
			{
			if (bsq->size <= bsq->bsq[0] - (bsq->i + bsq->ret) %bsq->bsq->lsize)
			{
				write(1, buf, bsq->ret - ((bsq->i + bsq->ret % - bsq->bsq[0]));
				write_sqr();
				bsq->bi = bsq->ret;
			}	
		}
	}
}
void	write_bsq(t_bsq *bsq)
{
	init_bsq_write(bsq);
	while (bsq->ret)
	{
		write_bsq_buf(bsq);
		bsq.ret = read(bsq.fd, bsq.buf, BUFF_SIZE);
		bsq.bi = 0;
	}

}
