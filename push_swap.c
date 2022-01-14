#include "push_swap.h"

void	print(t_size *len)
{
	len->tmp = len->a;
	while (len->tmp)
	{
		if (len->tmp)
		{
			printf("%d   %d", len->tmp->nmr, len->tmp->inx);
			len->tmp = len->tmp->nxt;
		}
		else
			printf("         ");
		printf("\n");
	}
	printf("-------------\n%d\n%d\n-------------\n", len->stk->glb_mov,
		   len->stk->glb_num);
	if (chek_order(len))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_size	len;

	len.stk = malloc(sizeof(t_stack));
	len.stk->glb_mov = 0;
	len.a = NULL;
	len.b = NULL;
	len.i = 1;
	if (argc == 1)
	{
		write(1, "Error\n", 6);
		exit (0);
	}
	while (--argc)
		make_list(argv, &len);
	sort_inx(&len);
	three_or_five(&len);
	sort_to_six(&len);
	while (len.b)
	{
		sort_order_b(&len);
		if (len.b)
			step_thr(&len, len.b->flg + 2);
	}
//	print(&len);
}
