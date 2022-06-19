#include "ft_printf.h"

void	ft_print_char(char c, t_type *list)
{
	write(1, &c, 1);
	list->count += 1;
}

void	ft_work_char(char c, t_flags *fl, t_type *list)
{
	if (fl->left == 1)
		ft_print_char(c, list);
	ft_print_symbol(fl->symbol, fl->width - 1, list);
	if (fl->left == -1)
		ft_print_char(c, list);
}

void	ft_print_str(char *s, t_flags *fl, t_type *list)
{
	int	i;

	i = 0;
	while (i < fl->precision)
	{
		ft_print_char(s[i], list);
		++i;
	}
}

void	ft_work_str(char *s, t_flags *fl, t_type *list)
{
	int	i;

	if (s == NULL)
		s = "(null)";
	i = 0;
	while (s[i] != '\0')
		++i;
	if (fl->precision > i || fl->precision == -1)
		fl->precision = i;
	if (fl->left == 1)
		ft_print_str(s, fl, list);
	ft_print_symbol(fl->symbol, fl->width - fl->precision, list);
	if (fl->left == -1)
		ft_print_str(s, fl, list);
}
