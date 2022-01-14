#include "push_swap.h"

int	chek_order(t_size *len)
{
	len->tmp = len->a;
	len->tmp2 = len->a->nxt;
	if (len->tmp->inx != 0)
		return (0);
	while (len->tmp2)
	{
		if (len->tmp->inx != len->tmp2->inx - 1)
			return (0);
		len->tmp = len->tmp->nxt;
		len->tmp2 = len->tmp2->nxt;
	}
	return (1);
}

t_num	*ft_lstnew(int num)
{
	t_num	*new;

	new = (t_num *)malloc(sizeof(t_num));
	if (!new)
		return (NULL);
	new->nmr = num;
	new->flg = 1;
	new->nxt = NULL;
	return (new);
}

void	ft_lstadd_back(t_num **stek, t_num *new)
{
	t_num	*tmp;

	tmp = *stek;
	if (tmp == NULL)
	{
		*stek = new;
		return ;
	}
	while (tmp->nxt != NULL)
		tmp = tmp->nxt;
	tmp->nxt = new;
	new->nxt = NULL;
}

void	make_list(char **argv, t_size *len)
{
	t_num	*new;
	char 	**mass;


	mass = split(argv[len->i], ' ');
	while (*mass)
	{
		chack(*mass);
		new = ft_lstnew(ft_atoi(*mass));
		ft_lstadd_back(&len->a, new);
		mass++;
	}
	len->i++;
}