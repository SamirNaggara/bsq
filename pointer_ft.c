/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_ft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveerara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:41:59 by nveerara          #+#    #+#             */
/*   Updated: 2022/08/30 18:47:04 by nveerara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_tlmem(t_lmem *up)
{
	while (up != NULL)
	{
		printf("%d->%d, ", up->empt_start, up->empt_end);
		up = up->next;
	}
	printf("\n");
}

int	end_test(t_bsq *bsq)
{
	printf("end\n");
	bsq->ret = 0;
	return (0);
}

void	(*g_write_bsq[2])(t_bsq *bsq)
	= {
	&read_first_line,
	&write_bsq_buf
};

int	(*g_read_bsq[6])(t_bsq *bsq)
	= {
		&read_end_fl,
		&array_first_line,
		&read_first_line_lines,
		&read_first_line_char,
		&read_first_line_lsize,
		&read_lines
};
