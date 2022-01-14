#include "push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	int		clo;
	char	*fis;

	clo = 0;
	fis = (char *)s;
	while (fis[clo])
	{
		if (fis[clo] == (const char)c)
			return (fis + clo);
		clo++;
	}
	if (c == '\0')
		return (&fis[clo]);
	return (NULL);
}

void	makeclean(char **s, int	i)
{
	while (i > 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
}

void	line(char **stolb, int nW, const char *s, char cut)
{
	int	couL;
	int	i;

	i = 0;
	while ((s) && (nW > i))
	{
		while ((*s == cut) && (*s != '\0'))
			s++;
		couL = 0;
		while (*s && (*s != cut))
		{
			couL++;
			s++;
		}
		stolb[i] = (char *) malloc(sizeof(char) * (couL + 1));
		if (!*stolb)
		{
			makeclean(stolb, i);
			write(1, "Error\n", 6);
			exit (0);
		}
		ft_strlcpy(stolb[i], s - couL, couL + 1);
		i++;
	}
	stolb[nW] = NULL;
}

int	couWord(char const *str, char cut)
{
	int	cou;

	cou = 0;
	if (!(str[0]))
		return (cou);
	while (*str)
	{
		while (ft_strchr(&cut, *str) && *str)
			str++;
		while (*str && (*str != cut))
			str++;
		cou++;
	}
	if (*--str == cut)
		return (cou - 1);
	return (cou);
}

char	**split(char const *s, char c)
{
	int		nW;
	char	**stolb;

	if (s == NULL || (*s == 0))
	{
		write(1, "Error\n", 6);
		exit (0);
	}
	nW = couWord(s, c);
	stolb = (char **) malloc(sizeof(char *) * (nW + 1));
	if (!stolb)
	{
		write(1, "Error\n", 6);
		exit (0);
	}
	line(stolb, nW, s, c);
	return (stolb);
}
