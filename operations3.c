#include "push_swap.h"

int	ft_atoi(const char *str)
{
	long	bet;
	int		cou;

	cou = 1;
	bet = 0;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str++ == '-')
			cou = -1;
	}
	while (str && ((*str >= '0') && (*str <= '9')))
	{
		bet = bet * 10 + (*str - '0');
		str++;
	}
	if ((bet * cou > 2147483647) || (bet * cou < -2147483648))
	{
		write(1, "Error\n", 6);
		exit (0);
	}
	return ((int)bet * cou);
}

void	chack(char *len)
{
	while (*len == ' ')
		len++;
	if (*len == '+' || *len == '-')
		len++;
	while (*len)
	{
		if (*len < '0' || *len > '9')
		{
			write(1, "Error\n", 6);
			exit (0);
		}
		len++;
	}
}

void	sort_inx(t_size *len)
{
	len->stk->glb_num = 0;
	len->tmp2 = len->a;
	while (len->tmp2)
	{
		len->j = 0;
		len->tmp = len->a;
		len->i = 0;
		while (len->tmp)
		{
			if (len->tmp2->nmr > len->tmp->nmr)
				len->i++;
			if (len->tmp2->nmr == len->tmp->nmr)
			{
				len->j++;
				if (len->j > 1)
					if (write(1, "Error\n", 6))
						exit (0);
			}
			len->tmp = len->tmp->nxt;
		}
		len->tmp2->inx = len->i;
		len->tmp2 = len->tmp2->nxt;
		len->stk->glb_num++;
	}
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t	dstsize)
{
	size_t	i;
	size_t	num;

	num = 0;
	i = 0;
	if (!src || !dst)
		return (0);
	num = (ft_strlen(src));
	if (dstsize == 0)
		return (num);
	while ((src[i]) && (dstsize-- > 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (num);
}
