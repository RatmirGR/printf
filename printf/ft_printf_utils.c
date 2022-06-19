#include "ft_printf.h"

void	ft_print_symbol(char c, int len, t_type *list)
{
	int	i;

	i = 0;
	while (i < len)
	{
		write(1, &c, 1);
		list->count++;
		++i;
	}
}

void	ft_print_hex_sb(int num, char c, t_type *list)
{
	char	*arr_lower;
	char	*arr_upper;

	arr_lower = "abcdef";
	arr_upper = "ABCDEF";
	if (c == 'x' || c == 'p')
		ft_print_char(arr_lower[num - 10], list);
	else if (c == 'X')
		ft_print_char(arr_upper[num - 10], list);
}

int	ft_count_unbr(unsigned long long nbr, int base)
{
	int	count;

	count = 1;
	while ((nbr / base) != 0)
	{
		nbr /= base;
		count++;
	}
	return (count);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		++i;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (0);
}

int	ft_get_width_or_prec(const char *s, t_type *list)
{
	long long	num;

	num = 0;
	if (s[list->i] == '.')
	{
		if (!(s[list->i + 1] >= '0' && s[list->i + 1] <= '9'))
			return (0);
		list->i++;
	}
	while (s[list->i] >= '0' && s[list->i] <= '9')
	{
		num = (num * 10) + (s[list->i] - '0');
		list->i++;
	}
	list->i--;
	return (num);
}
