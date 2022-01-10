/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:59:03 by kpetrosy          #+#    #+#             */
/*   Updated: 2021/04/06 16:59:06 by kpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			init_info(t_info *info)
{
	info->align = 0;
	info->zero = 0;
	info->width = 0;
	info->dot = 0;
	info->prec = 0;
	info->spec = 0;
	info->data_len = 0;
	info->space_len = 0;
	info->zero_len = 0;
}

int				ft_printf(const char *str, ...)
{
	va_list		ap;
	t_info		info;

	init_info(&info);
	info.printed_len = 0;
	va_start(ap, str);
	parse_hub(ap, (char *)str, &info);
	va_end(ap);
	return (info.printed_len);
}
