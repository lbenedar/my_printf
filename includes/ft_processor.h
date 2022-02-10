/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <lbenedar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:49:21 by lbenedar          #+#    #+#             */
/*   Updated: 2021/01/16 11:23:07 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROCESSOR_H
# define FT_PROCESSOR_H

# include <stdlib.h>
# include "struct.h"
# include <stdarg.h>
# include "../libft/libft.h"

size_t		ft_proc_percent(t_placeholder *ph);
size_t		ft_proc_char(t_placeholder *ph, char c);
size_t		ft_proc_str(t_placeholder *ph, char *str);
size_t		ft_proc_int(t_placeholder *ph, long long val);
size_t		ft_processor(t_placeholder *ph, va_list argptr);
char		*ft_proc_zero_flag(t_placeholder *ph, char *str);
long long	ft_proc_spec_s(t_placeholder *ph, long long val);
size_t		ft_proc_pointer(t_placeholder *ph, unsigned long ptr);
size_t		ft_proc_oct(t_placeholder *ph, unsigned long long oct);
char		*ft_use_zero_flag(size_t sublen, char *str, size_t len);
size_t		ft_proc_output(t_placeholder *ph, char *str, char space);
size_t		ft_out_spaces(t_placeholder *ph, char space, int strlen);
size_t		ft_proc_unsign(t_placeholder *ph, unsigned long long val);
long long	ft_proc_spec_us(t_placeholder *ph, unsigned long long val);
size_t		ft_proc_hex(t_placeholder *ph, int capitals,
						unsigned long long hex);

#endif
