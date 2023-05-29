/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:20:23 by areifoun          #+#    #+#             */
/*   Updated: 2023/05/27 16:53:07 by areifoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_abs(int x, int negv)
{
	if (negv)
		return (-x);
	else
		return (x);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		len;
	char	str[12];
	int		negv;

	negv = (n < 0);
	ft_bzero(str, 12);
	len = 0;
	if (n == 0)
		str[len] = '0';
	while (n != 0)
	{
		str[len++] = '0' + ft_abs(n % 10, negv);
		n /= 10;
	}
	if (negv)
		str[len] = '-';
	else if (len > 0)
		len--;
	while (len >= 0)
		write(fd, &str[len--], 1);
}

int	ft_protect_atoi(long number, int sign)
{
	if (number > INT_MAX)
		exit(ft_error("Error"));
	else if (number < INT_MIN)
		exit(ft_error("Error"));
	else
		return (((int)number) * sign);
}
