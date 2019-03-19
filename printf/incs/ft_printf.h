/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:36:38 by mmeisson          #+#    #+#             */
/*   Updated: 2016/05/30 08:52:18 by mmeisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <locale.h>
# include <inttypes.h>

# define PRINT_BUFF_SIZE 4096

typedef struct		s_printconfig
{
	char				print[PRINT_BUFF_SIZE];
	int					len;
	int					ret;
	int					fd;
	int					size;
}					t_printconfig;

t_printconfig		g_conf;

typedef struct		s_printdatas
{
	int			l_align;
	int			min_size;
	int			precision;
	int			alternate;
	int			zero;
	int			blank;
	int			positiv;
	char		flags[3];
	char		conversion;
}					t_printdatas;

typedef struct		s_modif_function
{
	char		conversion;
	char		modifier[3];
	int			(*fct)();
}					t_modif_function;

typedef struct		s_conv_function
{
	char		conversion;
	int			(*fct)();
}					t_conv_function;

int					ft_printparsing(char **format, va_list ap);
int					ft_get_conversion(char **format, t_printdatas *d);
int					ft_get_flags(char **format, t_printdatas *d);
int					ft_get_width(char **format, t_printdatas *d);
int					ft_get_modif(char **format, t_printdatas *d);
int					ft_get_precision(char **format, t_printdatas *d);
void				ft_printflush(void);

void				ft_apply_precision(int origin_size, t_printdatas *d);
void				ft_apply_width(int origin, t_printdatas *d);

int					ft_printlen(char *str);
int					ft_printstrnequ(char *s1, char *s2, int size);
int					ft_printstrequ(char *s1, char *s2);
char				*ft_printstrchr(char *s1, char c);
void				ft_printbzero(void *ptr, int size);
void				ft_printstrcpy(char *dst, char *src);
char				*ft_printstrnover(char *origin, char *src, size_t size);

int					ft_printwchar_intern(wchar_t c, t_printdatas *d);
void				ft_mask_one(wchar_t c);
void				ft_mask_two(wchar_t c);
void				ft_mask_three(wchar_t c);
void				ft_mask_four(wchar_t c);
void				ft_mask_five(wchar_t c);
void				ft_mask_six(wchar_t c);

int					ft_printint(va_list ap, t_printdatas *d);
int					ft_printuint(va_list ap, t_printdatas *d);
int					ft_printoctal(va_list ap, t_printdatas *d);
int					ft_printlongoctal(va_list ap);
int					ft_printhexa_min(va_list ap, t_printdatas *d);
int					ft_printhexa_max(va_list ap, t_printdatas *d);
int					ft_printptr_min(va_list ap);
int					ft_printptr_max(va_list ap);
int					ft_printlong(va_list ap);
int					ft_printulong(va_list ap);
int					ft_printlonglong(va_list ap);
int					ft_printulonglong(va_list ap);
int					ft_printlongoctal(va_list ap);
int					ft_printlonghexa_min(va_list ap);
int					ft_printlonghexa_max(va_list ap);
int					ft_printlonglonghexa_min(va_list ap);
int					ft_printlonglonghexa_max(va_list ap);
int					ft_printlonglongoctal(va_list ap);
int					ft_printlonglonghexa(va_list ap);
int					ft_printstr(va_list ap);
int					ft_printchar(va_list ap);
int					ft_printwchar(va_list ap, t_printdatas *d);
int					ft_printwstr(va_list ap, t_printdatas *d);
int					ft_printchar(va_list ap);

#endif
