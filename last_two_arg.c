#include "push_swap.h"

int	check_two_arg(t_num *a)
{
	int		i;
	t_num	*b;

	if (!a)
		return (0);
	i = 1;
	if (a->nxt)
	{
		b = a->nxt;
		if (b && a->flg == b->flg)
			i++;
		if (b && b->nxt)
		{
			b = b->nxt;
			if (a->flg == b->flg)
				return (0);
		}
	}
	return (i);
}

void	sa_two(t_size *len)
{
	if (len->a->nxt)
	{
		len->tmp = len->a->nxt;
		if ((len->tmp->inx < len->a->inx) && (len->tmp->flg == len->a->flg))
		{
			len->a->flg = 2;
			sa(len, 1);
		}
		else
			len->tmp->flg = 2;
	}
	len->a->flg = 2;
}

void	sb_two(t_size *len)
{
	if (len->b->nxt)
		len->tmp = len->b->nxt;
	if (len->tmp->flg == len->b->flg)
	{
		if ((len->tmp->inx > len->b->inx) && (len->tmp->flg == len->b->flg))
		{
			sb(len, 1);
			len->b->flg = 2;
			pa(len);
		}
		else
		{
			len->b->flg = 2;
			pa(len);
		}
	}
	if (len->b)
		len->b->flg = 2;
	pa(len);
}
