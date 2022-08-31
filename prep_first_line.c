/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_first_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveerara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:41:47 by nveerara          #+#    #+#             */
/*   Updated: 2022/08/31 14:31:15 by nveerara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	add_char(t_bsq *bsq, char c)
{
	if (bsq->fl_l == NULL)
	{
		bsq->fl_l = malloc(sizeof(t_cc));
		if (bsq->fl_l == NULL)
			exit(EXIT_FAILURE);
		bsq->fl_l->c = c;
		bsq->fl_l->next = NULL;
		bsq->fl_lo = bsq->fl_l;
	}
	else
	{
		bsq->fl_l->next = malloc(sizeof(t_cc));
		if (bsq->fl_l->next == NULL)
			exit(EXIT_FAILURE);
		bsq->fl_l = bsq->fl_l->next;
		bsq->fl_l->c = c;
		bsq->fl_l->next = NULL;
	}
}

int	array_first_line(t_bsq *bsq)
{
	int	i;

	bsq->first_line = malloc(sizeof(char) * bsq->fl_c);
	if (bsq->first_line == NULL)
		exit(EXIT_FAILURE);
	if (bsq->fl_c < 4)
		return (1);
	bsq->fl_l = bsq->fl_lo;
	i = 0;
	while (bsq->fl_l != NULL)
	{
		bsq->first_line[i] = bsq->fl_l->c;
		bsq->fl_l = bsq->fl_l->next;
		i++;
	}
	bsq->step++;
	return (0);
}
