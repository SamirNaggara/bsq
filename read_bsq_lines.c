/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bsq_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveerara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:03:20 by nveerara          #+#    #+#             */
/*   Updated: 2022/08/30 20:14:36 by nveerara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	read_lines_end(t_bsq *bsq)
{
	if (bsq->lsize == bsq->i)
	{
		bsq->bi++;
		add_empt_obst(bsq);
		bsq->l++;
		check_bsq(bsq);
		if (bsq->l == bsq->lines)
			bsq->step++;
		else
			init_new_line(bsq);
		return (0);
	}
	return (1);
}

int	read_lines(t_bsq *bsq)
{
	while (bsq->bi < bsq->ret)
	{
		if (bsq->buf[bsq->bi] != bsq->empt && bsq->buf[bsq->bi] != bsq->obst
			&& bsq->buf[bsq->bi] != '\n')
			return (1);
		if (bsq->buf[bsq->bi] == '\n')
			return (read_lines_end(bsq));
		if (bsq->buf[bsq->bi] == bsq->empt)
			add_empt_empty(bsq);
		else
			add_empt_obst(bsq);
		bsq->i++;
		bsq->bi++;
	}
	return (0);
}

int	end_check(t_bsq *bsq)
{
	if (bsq->bi < bsq->ret)
		return (1);
	if (bsq->bsq[0] == -1)
		return (1);
	return (0);
}
