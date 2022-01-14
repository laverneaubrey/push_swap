#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_num
{
	int				nmr;
	int				inx;
	int				flg;
	struct s_num	*nxt;
}				t_num;

typedef struct s_stack
{
	int				glb_mov;
	int				glb_num;
	int				t_nm;
	int				max1;
	int				min1;
	int				max2;
	int				min2;
	int				stk1;
	int				stk2;
	int				t_st;
}				t_stack;

typedef struct s_size
{
	t_num			*a;
	t_num			*b;
	t_num			*tmp;
	t_num			*tmp2;
	t_stack			*stk;
	int				i;
	int				j;
}				t_size;

void	sa(t_size *len, int i);
void	sb(t_size *len, int i);
void	ss(t_size *len);
void	pa(t_size *len);
void	pb(t_size *len);
void	ra(t_size *len, int i);
void	rb(t_size *len, int i);
void	rr(t_size *len);
void	rra(t_size *len, int i);
void	rrb(t_size *len, int i);
void	rrr(t_size *len);
int		ft_atoi(const char *str);
t_num	*ft_lstnew(int num);
void	ft_lstadd_back(t_num **stek, t_num *new);
void	then_three(t_size *len);
int		if_three(t_size *len);
void	then_five(t_size *len);
int		if_five(t_size *len);
void	three_or_five(t_size *len);
void	chack(char *len);
int		check_two_arg(t_num *a);
void	sa_two(t_size *len);
void	sb_two(t_size *len);
void	sort_inx(t_size *len);
void	sort_to_six(t_size *len);
int		min_serch(t_num *stk);
int		max_serch(t_num *stk);
void	sort_order_b(t_size *len);
void	get_ready_sort_b(t_size *len);
void	get_ready_sort_to_six(t_size *len);
void	get_finish_sort_to_six(t_size *len);
void	while_in_sort_to_six(t_size *len);
int		sort_to_six_op(t_size *len);
void	step_thr(t_size *len, int f);
void	inside_step(t_size *len, int f);
int		chek_order(t_size *len);
void	make_list(char **argv, t_size *len);
void	line(char **stolb, int nW, const char *s, char cut);
int		couWord(char const *str, char cut);
void	makeclean(char **s, int	i);
char	**split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t	dstsize);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

#endif
