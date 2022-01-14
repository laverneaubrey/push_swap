#include "push_swap.h"

void	then_three(t_size *len)
{
	if (len->a->inx == 1)
	{
		if (len->tmp->inx == 0)
			sa(len, 1);
		else
			rra(len, 1);
	}
	else
	{
		if (len->tmp->inx == 0)
			ra(len, 1);
		else
		{
			sa(len, 1);
			rra(len, 1);
		}
	}
}

int	if_three(t_size *len)
{
	len->i = 0;
	len->tmp = len->a;
	while (len->tmp)
	{
		len->i++;
		len->tmp = len->tmp->nxt;
	}
	len->tmp = len->a->nxt;
	if (len->i != 3)
		return (0);
	if (len->a->inx == 0)
	{
		if (len->tmp->inx == 2)
		{
			sa(len, 1);
			ra(len, 1);
		}
	}
	else
		then_three(len);
	return (1);
}

void	then_five(t_size *len)
{
	len->i = 0;
	while (len->i != 2)
	{
		if (len->a->inx == 0 || len->a->inx == 1)
		{
			len->i++;
			pb(len);
		}
		else
			ra(len, 1);
	}
	if (len->b->inx == 0)
		sb(len, 1);
	sort_inx(len);
	if_three(len);
	pa(len);
	pa(len);
}

int	if_five(t_size *len)
{
	len->i = 0;
	len->tmp = len->a;
	while (len->tmp)
	{
		len->i++;
		len->tmp = len->tmp->nxt;
	}
	if (len->i != 5)
		return (0);
	then_five(len);
	return (1);
}

void	three_or_five(t_size *len)
{
	if (chek_order(len))
		exit (0);
	if (if_three(len))
		exit (0);
	if (if_five(len))
		exit (0);
}
