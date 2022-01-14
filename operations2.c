#include "push_swap.h"

void	rb(t_size *len, int i)
{
	if (len->b->nxt == NULL)
		return ;
	len->tmp = len->b->nxt;
	ft_lstadd_back(&len->b, len->b);
	len->b = len->tmp;
	if (i == 1)
	{
		write(1, "rb\n", 3);
		len->stk->glb_mov++;
	}
}

void	rr(t_size *len)
{
	ra(len, 0);
	rb(len, 0);
	write(1, "rr\n", 3);
	len->stk->glb_mov++;
}

void	rra(t_size *len, int i)
{
	t_num	*sort;

	len->tmp = len->a->nxt;
	sort = len->a;
	while (len->tmp->nxt)
	{
		len->tmp = len->tmp->nxt;
		sort = sort->nxt;
	}
	sort->nxt = NULL;
	len->tmp->nxt = len->a;
	len->a = len->tmp;
	if (i == 1)
	{
		write(1, "rra\n", 4);
		len->stk->glb_mov++;
	}
}

void	rrb(t_size *len, int i)
{
	t_num	*sort;

	len->tmp = len->b->nxt;
	sort = len->b;
	while (len->tmp->nxt)
	{
		len->tmp = len->tmp->nxt;
		sort = sort->nxt;
	}
	sort->nxt = NULL;
	len->tmp->nxt = len->b;
	len->b = len->tmp;
	if (i == 1)
	{
		write(1, "rrb\n", 4);
		len->stk->glb_mov++;
	}
}

void	rrr(t_size *len)
{
	rra(len, 0);
	rrb(len, 0);
	write(1, "rrr\n", 4);
	len->stk->glb_mov++;
}

void	ss(t_size *len)
{
	sa(len, 0);
	sb(len, 0);
	write(1, "ss\n", 3);
	len->stk->glb_mov++;
}
