/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nveerara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:04:42 by nveerara          #+#    #+#             */
/*   Updated: 2022/08/30 13:10:46 by nveerara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFF_SIZE 4096

typedef struct s_lmem
{
	struct s_lmem	*next;
	int				empt_start;
	int				empt_end;
}	t_lmem;

typedef struct s_mem
{
	struct s_mem	*prev;
	struct s_mem	*next;
	t_lmem			*start;
}	t_mem;

typedef struct s_red
{
	t_lmem	*pdown;
	t_lmem	*down;
	t_lmem	*up;
	t_mem	*bmo;
	int		i;
	int		min;
}	t_red;

typedef struct s_bsq
{
	int		ret;
	char	buf[BUFF_SIZE];
	int		fd;
	char	fill;
	char	obst;
	char	empt;
	int		lines;
	int		lsize;
	int		i;
	int		l;
	int		bi;
	int		step;
	int		bsq[2];
	int		bsqsize;
	int		lc;
	t_mem	*bm;
	t_lmem	*pbml;
	t_lmem	*bml;
}	t_bsq;

void	add_empt_empty(t_bsq *bsq);
void	add_empt_obst(t_bsq *bsq);
void	init_bm(t_bsq *bsq);
void	dellmem(t_lmem *start);
void	delallprev(t_mem *bm);
void	check_bsq(t_bsq *bsq);
int	read_lines(t_bsq *bsq);
void	read_file(char *av);
int	read_first_line_char(t_bsq *bsq);
int	read_first_line_lines(t_bsq *bsq);
int	read_first_line_lsize(t_bsq *bsq);
void	reduce(t_bsq *bsq, t_mem *bmo, t_mem *bm, int lc);
void	init_new_line(t_bsq *bsq);
void	print_error(void);
void	init_bsq(t_bsq *bsq, char *av);
void	init_bsq_write(t_bsq *bsq);

int		end_test(t_bsq *bsq);
void	print_tlmem(t_lmem *up);



extern int	((*g_read_bsq[4])(t_bsq *bsq));

#endif
