/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 02:26:43 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/18 02:28:11 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

typedef struct s_string	t_string;

typedef struct s_vtable
{
	void	(*create)(t_string *self, const char *val);
	void	(*print)(const t_string *self);
	void	(*destroy)(t_string *self);
	char	*(*reverse)(const t_string *self);
	int		(*to_int)(const t_string *self);
	void	(*join)(t_string *self, int count, ...);
}	t_vtable;

struct s_string
{
	char			*str;
	size_t			len;
	const t_vtable	*vptr;
};

void	string_init(t_string *target);

#endif