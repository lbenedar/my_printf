/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:17:22 by lbenedar          #+#    #+#             */
/*   Updated: 2021/01/06 21:27:03 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include <stdlib.h>
# include "struct.h"
# include <stdarg.h>
# include "ft_processor.h"
# include "../libft/libft.h"

size_t	ft_parser(const char *format, va_list argptr);
t_type	ft_type_parser(const char c, t_placeholder *ph);
void	ft_star_parser(t_placeholder *ph, va_list argptr);
size_t	ft_width_parser(const char *format, size_t index, t_placeholder *ph);
size_t	ft_parse_ph(const char *format, size_t index,
					t_placeholder *ph, va_list argptr);
size_t	ft_precision_parser(const char *format, size_t index,
							t_placeholder *ph, va_list argptr);
size_t	ft_spec_parser(const char *format, size_t index, t_placeholder *ph);

#endif
