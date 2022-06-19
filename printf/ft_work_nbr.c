#include "ft_printf.h"

static int	ft_count_nbr(long long nbr)
{
	int			count;
	long long	num;

	if (nbr < 0)
		num = nbr * (-1);
	else
		num = nbr;
	count = 1;
	while ((num / 10) != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

static void	ft_print_nbr(long long nbr, t_flags *fl, t_type *list)
{
	long long	num;
	long		size;

	size = 1;
	num = nbr;
	if (nbr < 0)
		size = -size;
	while ((num / 10) != 0)
	{
		num /= 10;
		size *= 10;
	}
	while (fl->precision - fl->len > 0 && fl->len++)
		ft_print_char('0', list);
	while (size != 0)
	{
		num = nbr / size;
		nbr %= size;
		size /= 10;
		ft_print_char(num + '0', list);
	}
}

void	ft_work_nbr(long long nbr, t_flags *fl, t_type *list)
{
	int	num;

	if (nbr == 0 || fl->precision > 0)
		fl->symbol = ' ';
	num = nbr;
	if (num < 0)
		fl->sign = '-';
	if (fl->sign == '-' || fl->sign == ' ' || fl->sign == '+')
		fl->width -= 1;
	if (fl->symbol == '0' && fl->sign != -1)
		ft_print_char(fl->sign, list);
	fl->len = ft_count_nbr(num);
	if (fl->precision == -1 || (num != 0 && fl->precision < fl->len))
		fl->precision = fl->len;
	if (fl->left == -1)
		ft_print_symbol(fl->symbol, fl->width - fl->precision, list);
	if (fl->symbol == ' ' && fl->sign != -1)
		ft_print_char(fl->sign, list);
	if (fl->precision != 0)
		ft_print_nbr(num, fl, list);
	if (fl->left == 1)
		ft_print_symbol(' ', fl->width - fl->precision, list);
}
