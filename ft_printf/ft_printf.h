/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:24:55 by dfeve             #+#    #+#             */
/*   Updated: 2024/11/24 02:00:22 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

int	ft_putstr_fd(char *s, int fd);
int	ft_putchar_fd(char c, int fd);
int	ft_printf(const char *str, ...);
int	ft_putnbr_fd(int n, int fd);
int	ft_itohex(unsigned int i, int maj);
int	ft_uputnbr_fd(unsigned int n, int fd);
int	ft_pitohex(unsigned long long i, int maj);

#endif