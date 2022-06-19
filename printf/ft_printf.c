#include "ft_printf.h"

t_flags	*ft_init_flags(void)
{
	t_flags	*p;

	p = NULL;
	p = (t_flags *)malloc(sizeof(t_flags));
	if (p != NULL)
	{
		p->width = -1;
		p->precision = -1;
		p->left = -1;
		p->hash = -1;
		p->sign = -1;
		p->len = 0;
		p->symbol = ' ';
		p->c = '0';
	}
	return (p);
}

t_type	*ft_init_list(void)
{
	t_type	*p;

	p = NULL;
	p = (t_type *)malloc(sizeof(t_type));
	if (p != NULL)
	{
		p->types = "cspudixX%";
		p->count = 0;
		p->i = 0;
	}
	return (p);
}

static void	ft_find_type(char c, va_list ap, t_flags *flags, t_type *list)
{
	flags->c = c;
	if (c == 'c')
		ft_work_char(va_arg(ap, int), flags, list);
	else if (c == '%')
		ft_work_char('%', flags, list);
	else if (c == 's')
		ft_work_str(va_arg(ap, char *), flags, list);
	else if (c == 'p')
		ft_work_ptr(va_arg(ap, long), flags, list);
	else if (c == 'd' || c == 'i')
		ft_work_nbr(va_arg(ap, long), flags, list);
	else if (c == 'u')
		ft_work_unbr(va_arg(ap, long), flags, list);
	else if (c == 'x' || c == 'X')
		ft_work_hex(va_arg(ap, long long), flags, list);
}

static void	ft_parse_format(const char *s, t_flags *flags, t_type *list)
{
	while (ft_strchr(list->types, s[list->i]) == NULL)
	{
		if (s[list->i] == ' ' && flags->sign != '+')
			flags->sign = ' ';
		else if (s[list->i] == '+')
			flags->sign = '+';
		else if (s[list->i] == '-')
		{
			flags->left = 1;
			flags->symbol = ' ';
		}
		else if (s[list->i] == '0' && flags->left != 1)
			flags->symbol = '0';
		else if (s[list->i] >= '0' && s[list->i] <= '9')
			flags->width = ft_get_width_or_prec(s, list);
		else if (s[list->i] == '.')
			flags->precision = ft_get_width_or_prec(s, list);
		else if (s[list->i] == '#')
			flags->hash = 1;
		list->i++;
	}
}

int	ft_printf(const char *fmt, ...)
{
	t_flags	*flags;
	t_type	*list;
	va_list	ap;
	int		count;

	list = ft_init_list();
	va_start(ap, fmt);
	while (fmt[list->i])
	{
		if (fmt[list->i] == '%')
		{
			flags = ft_init_flags();
			list->i++;
			ft_parse_format(fmt, flags, list);
			ft_find_type(fmt[list->i], ap, flags, list);
			free(flags);
		}
		else
			ft_print_char(fmt[list->i], list);
		list->i++;
	}
	count = list->count;
	free(list);
	va_end(ap);
	return (count);
}
