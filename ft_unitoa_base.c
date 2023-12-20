/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:49:50 by ple-guya          #+#    #+#             */
/*   Updated: 2023/11/23 17:07:36 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	getsize(long int n, char *base)
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

int	ft_unitoa_base(unsigned int n, char *base)
{
	char			*res;
	int				size;
	unsigned int	nb;
	int				resize;
	int				blen;

	blen = ft_strlen(base);
	nb = n;
	size = getsize(n, base);
	res = malloc((size + 1) * sizeof(char));
	if (!res)
		return (0);
	res[size] = '\0';
	if (nb == 0)
		res[0] = '0';
	while (nb != 0)
	{
		res[size - 1] = base[nb % blen];
		nb /= blen;
		size--;
	}
	resize = ft_strlen(res);
	write (1, res, resize);
	free(res);
	return (resize);
}

/* #include <stdio.h>
int	main()
{
	unsigned int	a;
	unsigned int i;

	i = -1;
	a = ft_unitoa_base(i, "0123456789abcdef");
	printf(" = unitoa value\nsize = %u\n",a);
	printf("real value = %x", i);
} */