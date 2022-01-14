#include "push_swap.h"

void	inside_step(t_size *len, int f)
{
	while (len->stk->t_nm)
	{
		if (len->a->inx <= len->stk->max2 && len->a->inx >= len->stk->min2)
		{
			if (f % 2 == 0)
				len->a->flg = 1;
			else
				len->a->flg = 0;
			pb(len);
			len->stk->t_nm--;
		}
		else if (len->a && len->a->nxt)
		{
			ra(len, 1);
			len->i++;
		}
	}
}

void	step_thr(t_size *len, int f)
{
	if (check_two_arg(len->a))
	{
		sa_two(len);
		return ;
	}
	len->stk->t_nm = (len->stk->max1 - len->stk->min1) / 2 + 1;
	len->stk->min2 = len->stk->min1;
	len->stk->max2 = len->stk->min2 + len->stk->t_nm - 1;
	len->stk->min1 = len->stk->max2 + 1;
	len->i = 0;
	inside_step(len, f);
	while (len->i-- && len->a && len->a->nxt)
		rra(len, 1);
	if (check_two_arg(len->a))
		sa_two(len);
	else
		step_thr(len, len->b->flg + 2);
}
