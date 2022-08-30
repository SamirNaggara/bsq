#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "includes/bsq.h"

t_lmem *create_tlmem(int nb, int rd);
void	print_tlmem(t_lmem *up);
void	reduce(t_bsq *bsq, t_mem *bmo, t_mem *bm, int lc);

void	del_link(int n, t_mem *k)
{
	t_lmem *tmp;
	t_lmem *ptmp;

	tmp = k->start;
	ptmp = tmp;
	while (n)
	{
		if (tmp != k->start)
			ptmp = ptmp->next;
		tmp = tmp->next;
		n--;
	}
	if (tmp == k->start)
		k->start = k->start->next;
	else
		ptmp->next = ptmp->next->next;	
}

int	main()
{
	t_mem u;
	t_mem d;
	t_bsq	bsq;
	bsq.lines = 0;
	bsq.bsqsize = 0;
	srand(time(NULL));
	t_lmem *up = create_tlmem(8, 5);
	t_lmem *down = create_tlmem(8, 5);
	print_tlmem(up);
	print_tlmem(down);
	d.start = down;
	u.start = up;
	reduce(&bsq, &d, &u, 1);
	del_link(0, &d);
	printf("\n");
	print_tlmem(u.start);
	print_tlmem(d.start);
}

t_lmem *create_tlmem(int nb, int rd)
{
	t_lmem	*o_up;
	t_lmem	*up;
	int n;

	o_up = malloc(sizeof(t_lmem));
	up = o_up;
	n = 0;
	while (nb)
	{
		n += rand() % rd + 2;
		up->empt_start = n;
		n += rand() % rd + 2;
		up->empt_end = n;
		nb--;
		if (nb)
		{
			up->next = malloc(sizeof(t_lmem));
			up = up->next;
			up->next = NULL;
		}
	}
	return (o_up);
}

void	print_tlmem(t_lmem *up)
{
	while (up != NULL)
	{
		printf("%d->%d, ", up->empt_start, up->empt_end);
		up = up->next;
	}
	printf("\n");
}
