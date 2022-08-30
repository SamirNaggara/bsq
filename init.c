/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveerara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:28:59 by nveerara          #+#    #+#             */
/*   Updated: 2022/08/30 20:55:30 by nveerara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	init_bm(t_bsq *bsq)
{
	bsq->bm = (t_mem *)malloc(sizeof(t_mem));
	bsq->bm->next = NULL;
	bsq->bm->prev = NULL;
	bsq->bm->start = NULL;
	bsq->bml = bsq->bm->start;
	bsq->i = 0;
}

void	init_bsq(t_bsq *bsq)
{
	bsq->step = 0;
	bsq->i = 0;
	bsq->bi = 0;
	bsq->lines = 0;
	bsq->lsize = 0;
	bsq->l = 0;
	bsq->bsqsize = 0;
	bsq->bsq[0] = -1;
	bsq->bsq[1] = -1;
	bsq->first_line = NULL;
	bsq->fl_lo = NULL;
	bsq->bm = NULL;
	bsq->pbml = NULL;
	bsq->bml = NULL;
	bsq->fl_l = NULL;
	bsq->fl_c = 0;
}

void	init_new_line(t_bsq *bsq)
{
	t_mem	*bm;

	bsq->i = 0;
	bm = bsq->bm;
	bsq->bm->next = malloc(sizeof(t_mem));
	bsq->bm = bsq->bm->next;
	bsq->bm->prev = bm;
	bsq->bm->next = NULL;
	bsq->bm->start = NULL;
	bsq->bml = NULL;
	bsq->pbml = NULL;
}

void	init_bsq_write(t_bsq *bsq)
{
	bsq->i = 0;
	bsq->bi = 0;
	bsq->l = 0;
	bsq->step = 0;
	bsq->ret = read(bsq->fd, bsq->buf, BUFF_SIZE);
}
