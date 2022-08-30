/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_first_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveerara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:05:07 by nveerara          #+#    #+#             */
/*   Updated: 2022/08/30 12:45:21 by nveerara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	read_first_line_char(t_bsq *bsq)
{
	if (bsq->i == 0)
	{
		bsq->empt = bsq->buf[bsq->bi];
		bsq->i++;
		bsq->bi++;
	}
	if (bsq->i == 1 && bsq->bi < bsq->ret)
	{
		bsq->obst = bsq->buf[bsq->bi];
		bsq->i++;
		bsq->bi++;
	}
	if (bsq->i == 2 && bsq->bi < bsq->ret)
	{
		bsq->fill = bsq->buf[bsq->bi];
		bsq->i++;
		bsq->bi++;
	}
	if (bsq->i == 3)
	{
		if (bsq->obst == bsq->fill || bsq->fill == bsq->empt
			|| bsq->empt == bsq->obst || bsq->buf[bsq->bi] != '\n'
			|| bsq->obst == '\n' || bsq->empt == '\n' || bsq->fill == '\n')
			return (1);
		if (bsq->buf[bsq->bi] == '\n')
		{
			bsq->bi++;
			bsq->step++;
			init_bm(bsq);
		}
	}
	return (0);
}

int	read_first_line_lines(t_bsq *bsq)
{
	while (bsq->bi < bsq->ret)
	{
		if (!('0' <= bsq->buf[bsq->bi] && bsq->buf[bsq->bi] <= '9'))
		{
			if (bsq->lines != 0)
			{
				bsq->i = 0;
				bsq->step++;
				return (0);
			}
			return (1);
		}
		bsq->lines *= 10;
		bsq->lines += bsq->buf[bsq->bi] - '0';
		bsq->bi++;
		bsq->i++;
	}
	return (0);
}

int	read_first_line_lsize(t_bsq *bsq)
{
	while (bsq->bi < bsq->ret)
	{
		if (bsq->buf[bsq->bi] != bsq->empt && bsq->buf[bsq->bi] != bsq->obst
			&& bsq->buf[bsq->bi] != '\n')
			return (1);
		if (bsq->buf[bsq->bi] == '\n')
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
