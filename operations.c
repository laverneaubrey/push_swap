#include "push_swap.h"

void	sa(t_size *len, int i)
{
	len->tmp = len->a->nxt;
	len->a->nxt = len->tmp->nxt;
	len->tmp->nxt = len->a;
	len->a = len->tmp;
	if (i == 1)
	{
		write(1, "sa\n", 3);
		len->stk->glb_mov++;
	}
}

void	sb(t_size *len, int i)
{
	if (!len->b)
		return ;
	len->tmp = len->b->nxt;
	len->b->nxt = len->tmp->nxt;
	len->tmp->nxt = len->b;
	len->b = len->tmp;
	if (i == 1)
	{
		write(1, "sb\n", 3);
		len->stk->glb_mov++;
	}
}

void	pa(t_size *len)
{
	if (len->b)
	{
		len->tmp = len->b->nxt;
		len->b->nxt = len->a;
		len->a = len->b;
		len->b = len->tmp;
		write(1, "pa\n", 3);
		len->stk->glb_mov++;
	}
}

void	pb(t_size *len)
{
	if (len->a)
	{
		len->tmp = len->a->nxt;
		len->a->nxt = len->b;
		len->b = len->a;
		len->a = len->tmp;
		write(1, "pb\n", 3);
		len->stk->glb_mov++;
	}
}

void	ra(t_size *len, int i)
{
	if (len->a->nxt == NULL)
		return ;
	len->tmp = len->a->nxt;
	ft_lstadd_back(&len->a, len->a);
	len->a = len->tmp;
	if (i == 1)
	{
		write(1, "ra\n", 3);
		len->stk->glb_mov++;
	}
}
