/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveerara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:16:06 by nveerara          #+#    #+#             */
/*   Updated: 2022/08/31 13:55:02 by nveerara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	read_bsq_stdin(t_bsq *bsq)
{
	while (bsq->ret)
	{
		write(bsq->fdtmp, bsq->buf, bsq->ret);
		while (bsq->bi < bsq->ret)
		{
			if (g_read_bsq[bsq->step](bsq))
				return (1);
		}
		bsq->ret = read(bsq->fd, bsq->buf, BUFF_SIZE);
		bsq->bi = 0;
	}
	return (0);
}

void	read_stdin(void)
{
	t_bsq	bsq;

	init_bsq(&bsq);
	bsq.fd = 0;
	bsq.ret = read(bsq.fd, bsq.buf, BUFF_SIZE);
	bsq.fdtmp = open("tmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (read_bsq_stdin(&bsq))
	{
		print_error();
		return ;
	}
	if (bsq.step != 6)
	{
		print_error();
		return ;
	}
	close(bsq.fdtmp);
	bsq.fd = open("tmp", O_RDONLY);
	write_bsq(&bsq);
	close(bsq.fd);
}
