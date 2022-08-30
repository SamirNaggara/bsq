/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveerara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:16:06 by nveerara          #+#    #+#             */
/*   Updated: 2022/08/30 20:50:13 by nveerara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	read_stdin(void)
{
	t_bsq	bsq;

	init_bsq(&bsq);
	bsq.fd = 0;
	bsq.ret = read(bsq.fd, bsq.buf, BUFF_SIZE);
	bsq.fdtmp = open("tmp", O_CREAT | O_RDWR, S_IRWXU);
	while (bsq.ret)
	{
		write(bsq.fdtmp, bsq.buf, bsq.ret);
		while (bsq.bi < bsq.ret)
		{
			if (g_read_bsq[bsq.step](&bsq))
			{
				print_error();
				return ;
			}
		}
		bsq.ret = read(bsq.fd, bsq.buf, BUFF_SIZE);
		bsq.bi = 0;
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
