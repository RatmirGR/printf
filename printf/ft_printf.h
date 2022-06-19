#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
	int		width;
	int		precision;
	int		left;
	int		hash;
	int		sign;
	int		len;
	char	symbol;
	char	c;
}			t_flags;

typedef struct s_type
{
	char	*types;
	int		count;
	int		i;
}			t_type;

char	*ft_strchr(char *s, int c);
void	ft_print_char(char c, t_type *list);
void	ft_work_char(char c, t_flags *fl, t_type *list);
void	ft_print_str(char *s, t_flags *fl, t_type *list);
void	ft_work_str(char *s, t_flags *fl, t_type *list);
void	ft_print_symbol(char c, int len, t_type *list);
void	ft_print_hex_sb(int num, char c, t_type *list);
void	ft_work_ptr(unsigned long long nbr, t_flags *fl, t_type *list);
void	ft_work_hex(long long nbr, t_flags *fl, t_type *list);
void	ft_work_unbr(long nbr, t_flags *fl, t_type *list);
void	ft_work_nbr(long long nbr, t_flags *fl, t_type *list);
int		ft_get_width_or_prec(const char *s, t_type *list);
int		ft_count_unbr(unsigned long long nbr, int base);
int		ft_printf(const char *fmt, ...);

#endif
