#include "ft_common.h"

static void		ft_swap(char **tab, size_t i, size_t j)
{
	char	*str;

	str = tab[i];
	tab[i] = tab[j];
	tab[j] = str;
}

static void		ft_print_debug(char **tab)
{
	size_t	i;

	i = 0;
	printf("##DEBUG\n");
	while (tab[i])
	{
		printf("\t%s\n", tab[i]);
		++i;
	}
	printf("##ENDDEBUG\n");
}

static size_t	ft_sort_bis(char **tab, size_t len, int (*cmp)())
{
	size_t	ref;
	size_t	begin;
	size_t	i;
	int		res;

	ref = 0;
	i = 0;
	while (i < len / 2)
	{
		printf("cmp : \"%s\"(%ld) - \"%s\"(%ld)\n", tab[ref], ref, tab[len - i - 1], len - i - 1);
		if (((res = cmp(tab[ref], tab[len - i - 1])) > 0 && ref > len - i - 1)
			|| (res < 0 && ref < len - i - 1))
		{
			printf("in swap\n");
			ft_swap(tab, ref, len - i -1);
			ref = len - i - 1;
		}
		else
			printf("no swap : %d\n", cmp(tab[ref], tab[len - i - 1]));
		ft_print_debug(tab);
		++i;
		printf("cmp : \"%s\"(%ld) - \"%s\"(%ld)\n", tab[ref], ref, tab[i], i);
		if (((res = cmp(tab[ref], tab[i])) > 0 && ref > i)
			|| (res < 0 && ref < i))
		{
			printf("in swap\n");
			ft_swap(tab, ref, i);
			ref = i;
		}
		else
			printf("no swap : %d\n", cmp(tab[ref], tab[i]));
		ft_print_debug(tab);
	}
	return (0);
}

char	**ft_sort(char **tab, int (*cmp)())
{
	size_t	i;

	i = 0;
	while (tab[i])
		++i;
	if (cmp != NULL)
		ft_sort_bis(tab, i, cmp);
	else
		ft_sort_bis(tab, i, ft_strcmp);
	return (tab);
}
