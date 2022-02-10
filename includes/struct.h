/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <lbenedar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:24:06 by lbenedar          #+#    #+#             */
/*   Updated: 2021/01/16 11:22:41 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdlib.h>

typedef enum	e_type
{
	type_empty,
	type_d_i,
	type_u,
	type_o,
	type_x_upper,
	type_x_lower,
	type_c,
	type_s,
	type_p,
	type_percentage
}				t_type;

typedef	enum	e_spec
{
	spec_empty,
	spec_l,
	spec_ll,
	spec_h,
	spec_hh
}				t_spec;

typedef	struct	s_placeholder
{
	int				width;
	int				precision;
	unsigned int	minus;
	unsigned int	zero;
	unsigned int	star;
	enum e_spec		spec;
	enum e_type		type;
}				t_placeholder;

t_placeholder	*ft_new_ph(t_placeholder *new_ph);

#endif
