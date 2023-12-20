/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:49:50 by ple-guya          #+#    #+#             */
/*   Updated: 2023/12/12 07:10:18 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	getsize(size_t n, char *base)
{
	int	size;
	int	blen;

	blen = ft_strlen(base);
	size = 0;
	if (n == 0)
		size++;
	while (n > 0)
	{
		size++;
		n /= blen;
	}
	return (size);
}

static size_t	ft_unitoa_addr(size_t n, char *base)
{
	char		*res;
	int			size;
	int			resize;
	int			blen;

	blen = ft_strlen(base);
	size = getsize(n, base);
	res = malloc((size + 1) * sizeof(char));
	if (!res)
		return (0);
	res[size] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n != 0)
	{
		res[--size] = base[n % blen];
		n /= blen;
	}
	resize = ft_strlen(res);
	write (1, res, resize);
	free(res);
	return (resize);
}

int	putaddr(size_t ag, char *base)
{
	int	resize;

	resize = 0;
	if (ag)
	{
		write(1, "0x", 2);
		resize += 2;
	}
	else
		return (write(1, "(nil)", 5));
	resize += ft_unitoa_addr(ag, base);
	return (resize);
}
