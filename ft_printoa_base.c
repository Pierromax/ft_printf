/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:49:50 by ple-guya          #+#    #+#             */
/*   Updated: 2023/11/23 17:05:01 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	getsize(long int n, char *base)
{
	int	size;
	int	blen;

	blen = ft_strlen(base);
	size = 0;
	if (n <= 0)
	{
		size++;
		n = -n;
	}
	while (n > 0)
	{
		size++;
		n /= blen;
	}
	return (size);
}

static char	*get_tab(long int nb, char *base, int size, char *res)
{	
	int			blen;

	blen = ft_strlen(base);
	if (nb < 0)
	{
		nb = -nb;
		res[0] = '-';
	}
	if (nb == 0)
		res[0] = '0';
	while (nb > 0)
	{
		res[size - 1] = base[nb % blen];
		nb /= blen;
		size--;
	}
	return (res);
}

int	ft_printoa_base(int n, char *base)
{
	char		*res;
	int			size;
	long int	nb;
	int			resize;

	nb = n;
	size = getsize(n, base);
	res = malloc((size + 1) * sizeof(char));
	if (!res)
		return (0);
	res[size] = '\0';
	res = get_tab(nb, base, size, res);
	resize = ft_strlen(res);
	write (1, res, resize);
	free(res);
	return (resize);
}


