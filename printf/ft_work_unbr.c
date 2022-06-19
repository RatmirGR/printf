#include "ft_printf.h"

static void	ft_print_ptr(unsigned long nbr, t_flags *fl, t_type *list)
{
	unsigned long long	num;
	unsigned long long	num2;
	long				size;

	size = 1;
	num = nbr;
	while ((num / 16) != 0)
	{
		num /= 16;
		size *= 16;
	}
	ft_print_char('0', list);
	ft_print_char('x', list);
	num = nbr;
	while (size != 0)
	{
		num2 = num / size;
		num %= size;
		size /= 16;
		if (num2 > 9)
			ft_print_hex_sb(num2, fl->c, list);
		else
			ft_print_char(num2 + '0', list);
	}
}

void	ft_work_ptr(unsigned long long nbr, t_flags *fl, t_type *list)
{
	if (fl->precision > 0)
		fl->symbol = ' ';
	fl->width -= 2;
	fl->len = ft_count_unbr(nbr, 16);
	if (fl->precision == -1 || (nbr != 0 && fl->precision < fl->len))
		fl->precision = fl->len;
	if (fl->left == -1)
		ft_print_symbol(fl->symbol, fl->width - fl->precision, list);
	if (fl->precision != 0)
		ft_print_ptr(nbr, fl, list);
	if (fl->left == 1)
		ft_print_symbol(fl->symbol, fl->width - fl->precision, list);
}

static void	ft_print_hex(unsigned int nbr, int base, t_flags *fl, t_type *list)
{
	unsigned int	num;
	int				size;

	size = 1;
	num = nbr;
	while ((num / base) != 0)
	{
		num /= base;
		size *= base;
	}
	while (fl->precision - fl->len > 0 && fl->len++)
		ft_print_char('0', list);
	while (size != 0)
	{
		num = nbr / size;
		nbr %= size;
		size /= base;
		if (num > 9)
			ft_print_hex_sb(num, fl->c, list);
		else
			ft_print_char(num + '0', list);
	}
}

void	ft_work_hex(long long nbr, t_flags *fl, t_type *list)
{
	unsigned int	num;

	if (nbr == 0 || fl->precision > 0)
		fl->symbol = ' ';
	num = nbr;
	if (fl->hash == 1)
		fl->width -= 2;
	fl->len = ft_count_unbr(num, 16);
	if (fl->precision == -1 || (num != 0 && fl->precision < fl->len))
		fl->precision = fl->len;
	if (fl->left == -1)
		ft_print_symbol(fl->symbol, fl->width - fl->precision, list);
	if (fl->hash == 1 && num != 0)
	{
		ft_print_char('0', list);
		if (fl->c == 'x')
			ft_print_char('x', list);
		else if (fl->c == 'X')
			ft_print_char('X', list);
	}
	if (fl->precision != 0)
		ft_print_hex(num, 16, fl, list);
	if (fl->left == 1)
		ft_print_symbol(fl->symbol, fl->width - fl->precision, list);
}

void	ft_work_unbr(long nbr, t_flags *fl, t_type *list)
{
	unsigned int	num;

	if (nbr == 0 || fl->precision > 0)
		fl->symbol = ' ';
	num = nbr;
	if (fl->hash == 1)
		fl->width -= 2;
	fl->len = ft_count_unbr(num, 10);
	if (fl->precision == -1 || (num != 0 && fl->precision < fl->len))
		fl->precision = fl->len;
	if (fl->left == -1)
		ft_print_symbol(fl->symbol, fl->width - fl->precision, list);
	if (fl->precision != 0)
		ft_print_hex(num, 10, fl, list);
	if (fl->left == 1)
		ft_print_symbol(fl->symbol, fl->width - fl->precision, list);
}
