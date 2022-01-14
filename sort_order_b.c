#include "push_swap.h"

int	min_serch(t_num *stk)
{
	t_num	*tmp;
	int		min;

	tmp = stk->nxt;
	if (stk)
		min = stk->inx;
	while (stk->flg == tmp->flg && tmp->flg)
	{
		if (min > tmp->inx)
			min = tmp->inx;
		tmp = tmp->nxt;
		stk = stk->nxt;
	}
	return (min);
}

int	max_serch(t_num *stk)
{
	t_num	*tmp;
	int		max;

	tmp = stk->nxt;
	if (stk)
		max = stk->inx;
	while (tmp && stk->flg == tmp->flg)
	{
		if (max < tmp->inx)
			max = tmp->inx;
		tmp = tmp->nxt;
		stk = stk->nxt;
	}
	return (max);
}

void	get_ready_sort_b(t_size *len)
{
	len->tmp = len->b->nxt;
	len->stk->min2 = min_serch(len->b);
	len->stk->max1 = max_serch(len->b);
	len->stk->t_nm = (len->stk->max1 - len->stk->min2) / 2 + 1;
//	if ((len->stk->max1 - len->stk->min2) % 2 == 0)
//		len->stk->t_nm++;
	len->stk->min1 = (len->stk->max1 - len->stk->t_nm + 1);
	len->stk->max2 = len->stk->min1 - 1;
}

void	sort_order_b(t_size *len)
{
	while (check_two_arg(len->b))
		sb_two(len);
	len->i = 0;
	if (!len->b)
		return ;
	get_ready_sort_b(len);
	while ((len->tmp->flg == len->b->flg) && (len->stk->t_nm > 0))
	{
		if ((len->b->inx <= len->stk->max1) && (len->b->inx >= len->stk->min1))
		{
			pa(len);
			len->stk->t_nm--;
		}
		else if (len->b && len->b->nxt)
		{
			rb(len, 1);
			len->i++;
		}
	}
	if ((len->b->inx <= len->stk->max1) && (len->b->inx >= len->stk->min1))
		pa(len);
	while (len->i-- && len->b && len->b->nxt)
		rrb(len, 1);
}
