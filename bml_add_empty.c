/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bml_add_empty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveerara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:04:10 by nveerara          #+#    #+#             */
/*   Updated: 2022/08/29 15:28:19 by nveerara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	add_empt_empty(t_bsq *bsq)
{
	if (bsq->bm->start == NULL)
	{
		bsq->bm->start = malloc(sizeof(t_lmem));
		bsq->bml = bsq->bm->start;
		bsq->bml->empt_start = bsq->i;
		bsq->bml->next = NULL;
	}
	if (bsq->bml == NULL)
	{
		bsq->pbml->next = malloc(sizeof(t_lmem));
		bsq->bml = bsq->pbml->next;
		bsq->bml->empt_start = bsq->i;
		bsq->bml->next = NULL;
	}
	
}

void	add_empt_obst(t_bsq *bsq)
{
	if (bsq->bml != NULL)
	{
		bsq->bml->empt_end = bsq->i - 1;
		bsq->pbml = bsq->bml;
		bsq->bml = NULL;
	}
}
