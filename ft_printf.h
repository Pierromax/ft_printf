/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:14:06 by ple-guya          #+#    #+#             */
/*   Updated: 2023/12/12 06:48:33 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

int	ft_putchar(char c);
int	ft_putestr(char *s);
int	ft_strlen(const char *s);
int	ft_printoa_base(int n, char *base);
int	ft_printf(const char *s, ...);
int	ft_unitoa_base(unsigned int n, char *base);
int	ft_putaddr(size_t ag, char *base);

#endif
