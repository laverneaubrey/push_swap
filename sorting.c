#include "push_swap.h"

void	get_ready_sort_to_six(t_size *len)
{
	len->j = 2;
	len->stk->t_st = 6;
	len->stk->t_nm = len->stk->glb_num;
	if (len->stk->t_nm % 2)
		len->stk->t_nm++;
	len->stk->stk1 = len->stk->t_nm / len->stk->t_st;
	len->stk->max1 = len->stk->glb_num / 2 + len->stk->stk1;
	len->stk->min1 = len->stk->glb_num / 2;
	len->stk->t_nm = len->stk->t_nm - len->stk->stk1;
	len->stk->t_st--;
	len->stk->stk2 = len->stk->t_nm / len->stk->t_st;
	len->stk->max2 = len->stk->glb_num / 2;
	len->stk->min2 = len->stk->glb_num / 2 - len->stk->stk2;
	len->stk->t_nm = len->stk->t_nm - len->stk->stk2;
	len->stk->t_st--;
}

void	get_finish_sort_to_six(t_size *len)
{
	len->stk->stk1 = len->stk->t_nm / len->stk->t_st;
	len->stk->min1 = len->stk->max1;
	len->stk->max1 = len->stk->max1 + len->stk->stk1;
	len->stk->t_nm = len->stk->t_nm - len->stk->stk1;
	len->stk->t_st--;
	len->stk->stk2 = len->stk->t_nm / len->stk->t_st;
	len->stk->max2 = len->stk->min2;
	len->stk->min2 = len->stk->min2 - len->stk->stk2;
	len->stk->t_nm = len->stk->t_nm - len->stk->stk1;
	len->stk->t_st--;
}

int	sort_to_six_op(t_size *len)
{
	if (len->a)
	{
		if (len->a->inx >= len->stk->max1)
			return (1);
		else if (len->a->inx < len->stk->min2)
			return (1);
	}
	return (0);
}

void	while_in_sort_to_six(t_size *len)
{
	if ((len->a->inx < len->stk->max1) && (len->a->inx >= len->stk->min1))
	{
		if (len->j % 2 == 0)
			len->a->flg = 1;
		else
			len->a->flg = 0;
		pb(len);
		len->i++;
	}
	else if ((len->a->inx <= len->stk->max2) && (len->a->inx >= len->stk->min2))
	{
		if (len->j % 2 == 1)
			len->a->flg = 1;
		else
			len->a->flg = 0;
		pb(len);
		if (sort_to_six_op(len))
			rr(len);
		else
			rb(len, 1);
		len->i++;
	}
	else
		ra(len, 1);
}

void	sort_to_six(t_size *len)
{
	if (chek_order(len))
	{
		write(1, "OK\n", 3);
		exit (0);
	}
	get_ready_sort_to_six(len);
	while (len->stk->t_st >= 0 && len->a)
	{
		len->i = 0;
		while ((len->i != (len->stk->stk1 + len->stk->stk2)) && len->a)
			while_in_sort_to_six(len);
		if (len->stk->t_nm)
			get_finish_sort_to_six(len);
		else
			return ;
		len->j++;
	}
}
