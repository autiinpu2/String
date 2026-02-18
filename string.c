/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 02:30:17 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/18 02:30:18 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include "libft.h"

static void	_create(t_string *self, const char *val)
{
	if (!val)
		return ;
	self->len = ft_strlen(val);
	self->str = malloc(self->len + 1);
	if (self->str)
		memcpy(self->str, val, self->len + 1);
}

static void	_print(const t_string *self)
{
	if (self->str)
		printf("%s\n", self->str);
}

static void	_destroy(t_string *self)
{
	if (self->str)
		free(self->str);
	self->str = NULL;
	self->len = 0;
}

static char	*_reverse(const t_string *self)
{
	char	*rev;
	size_t	i;
	size_t	j;

	if (!self->str)
		return (NULL);
	rev = malloc(self->len + 1);
	if (!rev)
		return (NULL);
	i = 0;
	j = self->len;
	rev[j--] = '\0';
	while (i < self->len)
		rev[j--] = self->str[i++];
	return (rev);
}

static int	_to_int(const t_string *self)
{
	long	res;
	int		sign;
	char	*s;

	if (!self->str)
		return (0);
	res = 0;
	sign = 1;
	s = self->str;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		res = (res << 3) + (res << 1) + (*s++ - '0');
	return ((int)(res * sign));
}

static void	_do_join(t_string *self, int count, const char **pts, size_t ex)
{
	char	*new_str;
	char	*ptr;
	int		i;
	size_t	len;

	new_str = malloc(self->len + ex + 1);
	if (!new_str)
		return ;
	if (self->str)
	{
		memcpy(new_str, self->str, self->len);
		free(self->str);
	}
	ptr = new_str + self->len;
	i = -1;
	while (++i < count)
	{
		len = ft_strlen(pts[i]);
		memcpy(ptr, pts[i], len);
		ptr += len;
	}
	*ptr = '\0';
	self->str = new_str;
	self->len += ex;
}

static void	_strjoin(t_string *self, int count, ...)
{
	va_list		args;
	const char	*pts[count];
	size_t		extra_len;
	int			i;

	if (!self || count <= 0)
		return ;
	extra_len = 0;
	i = 0;
	va_start(args, count);
	while (i < count)
	{
		pts[i] = va_arg(args, const char *);
		if (pts[i])
			extra_len += ft_strlen(pts[i]);
		i++;
	}
	va_end(args);
	if (extra_len > 0)
		_do_join(self, count, pts, extra_len);
}

static const t_vtable	g_vtable = {
	_create,
	_print,
	_destroy,
	_reverse,
	_to_int,
	_strjoin
};

void	string_init(t_string *target)
{
	target->str = NULL;
	target->len = 0;
	target->vptr = &g_vtable;
}
