#include "ft_common.h"
#include <string.h>

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
	size_t	j;
	int		res;
	int		gauche;

	if (len < 2)
		return (0);
	ref = 0;
	i = 0;
	j = len - 1;
	gauche = 1;
	while ((i < len / 2 && j > 0) || (j > len / 2 && i < len))
	{
		if (gauche && cmp(tab[ref], tab[j]) > 0)
		{
			ft_swap(tab, ref, j);
			ref = j;
			gauche = 0;
		}
		else if (!gauche && cmp(tab[i], tab[ref]) > 0)
		{
			ft_swap(tab, ref, i);
			ref = i;
			gauche = 1;
		}
		if (gauche)
			--j;
		else
			++i;
	}
	printf("ref : %ld\n", ref);
	printf("len - ref : %ld\n", len - ref);
	ft_sort_bis(tab, ref, cmp);
	ft_sort_bis(tab + ref + 1, len - ref - 1, cmp);
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
