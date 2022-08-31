/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_first_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveerara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:05:07 by nveerara          #+#    #+#             */
/*   Updated: 2022/08/31 15:39:47 by nveerara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	read_first_line_char(t_bsq *bsq)
{
	bsq->empt = bsq->first_line[bsq->fl_c - 3];
	bsq->obst = bsq->first_line[bsq->fl_c - 2];
	bsq->fill = bsq->first_line[bsq->fl_c - 1];
	if (bsq->obst == bsq->fill || bsq->fill == bsq->empt
		|| bsq->empt == bsq->obst || bsq->lines == 0)
		return (1);
	bsq->step++;
	init_bm(bsq);
	return (0);
}

int	read_end_fl(t_bsq *bsq)
{
	while (bsq->bi < bsq->ret)
	{
		if (bsq->buf[bsq->bi] == '\n')
		{
			bsq->bi++;
			bsq->step++;
			return (0);
		}
		add_char(bsq, bsq->buf[bsq->bi]);
		bsq->fl_c++;
		bsq->bi++;
	}
	return (0);
}

int	read_first_line_lines(t_bsq *bsq)
{
	int	i;

	i = 0;
	while (i < bsq->fl_c - 3)
	{
		if (!('0' <= bsq->first_line[i] && bsq->first_line[i] <= '9'))
			return (1);
		bsq->lines *= 10;
		bsq->lines += bsq->first_line[i] - '0';
		i++;
	}
	bsq->step++;
	return (0);
}

int	read_first_line_lsize_end(t_bsq *bsq)
{	
	if (bsq->lsize != 0)
	{
		add_empt_obst(bsq);
		bsq->l++;
		bsq->step++;
		bsq->bi++;
		check_bsq(bsq);
		if (bsq->l == bsq->lines)
			bsq->step++;
		else
			init_new_line(bsq);
		return (0);
	}
	return (1);
}

int	read_first_line_lsize(t_bsq *bsq)
{
	while (bsq->bi < bsq->ret)
	{
		if (bsq->buf[bsq->bi] != bsq->empt && bsq->buf[bsq->bi] != bsq->obst
			&& bsq->buf[bsq->bi] != '\n')
			return (1);
		if (bsq->buf[bsq->bi] == '\n')
			return (read_first_line_lsize_end(bsq));
		if (bsq->buf[bsq->bi] == bsq->empt)
			add_empt_empty(bsq);
		else
			add_empt_obst(bsq);
		bsq->lsize++;
		bsq->bi++;
		bsq->i++;
	}
	return (0);
}
