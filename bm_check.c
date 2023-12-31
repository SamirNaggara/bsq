/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bm_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveerara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:03:49 by nveerara          #+#    #+#             */
/*   Updated: 2022/08/31 14:07:59 by nveerara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/bsq.h"

void	dellmem(t_lmem *start)
{
	t_lmem	*tmp;

	while (start != NULL)
	{
		tmp = start;
		start = start->next;
		free(tmp);
	}
}

void	delallprev(t_mem *bm)
{
	t_mem	*bmo;
	t_mem	*tmp;

	bmo = bm->prev;
	while (bmo != NULL)
	{
		if (bmo->start != NULL)
		{	
			dellmem(bmo->start);
			bmo->start = NULL;
		}
		tmp = bmo;
		bmo = bmo->prev;
		free(tmp);
	}
	bm->prev = NULL;
}

void	check_bsq_end(t_bsq *bsq, t_mem *bm, int lc)
{
	if (bm->start != NULL && bsq->bsqsize < lc)
	{
		bsq->bsqsize = lc;
		bsq->bsq[0] = bm->start->empt_start;
		bsq->bsq[1] = bsq->l - lc;
	}
}

void	check_bsq(t_bsq *bsq)
{
	int		lc;
	t_mem	*bmo;
	t_mem	*bm;

	bmo = bsq->bm->prev;
	bm = bsq->bm;
	lc = 1;
	while (bmo != NULL)
	{
		reduce(bsq, bmo, bm, lc);
		if (bmo->start == NULL)
		{
			delallprev(bm);
			bmo = NULL;
		}
		else
		{
			bm = bm->prev;
			bmo = bmo->prev;
			lc++;
		}
	}
	check_bsq_end(bsq, bm, lc);
}
