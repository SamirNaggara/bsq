/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveerara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:05:20 by nveerara          #+#    #+#             */
/*   Updated: 2022/08/30 12:40:37 by nveerara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	reduce_del_link(t_red *red)
{
	t_lmem	*tmp;

	tmp = red->down;
	if (red->down == red->bmo->start)
	{
		red->bmo->start = red->bmo->start->next;
		red->pdown = red->bmo->start;
	}
	else
		red->pdown->next = red->pdown->next->next;
	red->down = red->down->next;
	free(tmp);
}

void	reduce_new_link(t_lmem *down, t_lmem *up)
{
	t_lmem	*tmp;

	tmp = (t_lmem *)malloc(sizeof(t_lmem));
	if (tmp == NULL)
		exit(EXIT_FAILURE);
	tmp->next = down->next;
	tmp->empt_start = up->empt_end;
	tmp->empt_end = down->empt_end;
	down->empt_end = up->empt_end;
	down->next = tmp;
}

void	reduce_split(t_red *red)
{	
	if (red->down->empt_end - red->down->empt_start < red->min
		|| red->down->empt_end - red->up->empt_start < red->min
		|| red->up->empt_end - red->down->empt_start < red->min
		|| red->up->empt_end - red->up->empt_start < red->min)
	{
		if (red->down->empt_end - red->up->empt_end >= red->min)
			reduce_new_link(red->down, red->up);
		reduce_del_link(red);
	}
	else
	{
		if (red->down->empt_start < red->up->empt_start)
		{
			red->down->empt_start = red->up->empt_start;
			if (red->down->empt_end > red->up->empt_end)
				reduce_new_link(red->down, red->up);
		}
		else if (red->down->empt_end > red->up->empt_end)
			reduce_new_link(red->down, red->up);
		if (red->down != red->bmo->start)
			red->pdown = red->pdown->next;
		red->down = red->down->next;
	}	
}

void	reduce_loop(t_red *red)
{
	while (red->up != NULL && red->down != NULL)
	{
		red->i = red->down->empt_end < red->up->empt_start;
		while (red->down != NULL && red->i)
		{
			reduce_del_link(red);
			if (red->down != NULL)
				red->i = red->down->empt_end < red->up->empt_start;
		}
		if (red->down != NULL)
			red->i = red->down->empt_start < red->up->empt_end;
		while (red->down != NULL && red->i)
		{
			reduce_split(red);
			if (red->down != NULL)
				red->i = red->down->empt_start < red->up->empt_end;
		}
		red->up = red->up->next;
	}
	while (red->down != NULL)
		reduce_del_link(red);
}

void	reduce(t_bsq *bsq, t_mem *bmo, t_mem *bm, int lc)
{
	t_red	red;

	red.up = bm->start;
	red.down = bmo->start;
	red.pdown = red.down;
	red.bmo = bmo;
	if (lc < bsq->bsqsize)
		red.min = bsq->bsqsize;
	else
		red.min = lc;
	reduce_loop(&red);
}
