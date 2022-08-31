/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveerara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:10:02 by nveerara          #+#    #+#             */
/*   Updated: 2022/08/31 14:21:35 by nveerara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	free_lmem(t_lmem *mem)
{
	t_lmem	*tmp;

	while (mem != NULL)
	{
		tmp = mem;
		mem = mem->next;
		free(tmp);
	}
}

void	free_mem(t_mem *mem)
{
	t_mem	*tmp;

	while (mem != NULL)
	{
		tmp = mem;
		free_lmem(mem->start);
		mem = mem->prev;
		free(tmp);
	}
}

void	free_t_cc(t_cc *cc)
{
	t_cc	*tmp;

	while (cc != NULL)
	{
		tmp = cc;
		cc = cc->next;
		free(tmp);
	}
}

void	free_all(t_bsq *bsq)
{
	if (bsq->first_line != NULL)
		free(bsq->first_line);
	if (bsq->fl_lo != NULL)
		free_t_cc(bsq->fl_lo);
	if (bsq->bm != NULL)
		free_mem(bsq->bm);
}
