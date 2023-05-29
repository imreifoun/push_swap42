/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:20:23 by areifoun          #+#    #+#             */
/*   Updated: 2023/05/27 16:37:17 by areifoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	check_str(const char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			ft_error("Error");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
				i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			ft_error("Error");
			exit(1);
		}
		i++;
	}
}

int	ft_atoi(const char *str)
{
	long	number;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	number = 0;
	check_str(str);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	number = ft_protect_atoi(number, sign);
	return (number);
}

void	*ft_calloc(size_t count, size_t size)
{
	int		n;
	char	*p;

	n = (count * size);
	p = (char *)malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, n);
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	char			*str;
	char			d;
	unsigned int	i;

	i = 0;
	d = (char)c;
	str = (char *)s;
	while (str[i] != '\0' && str[i] != d)
		i++;
	if (str[i] == d)
		return (str + i);
	return (NULL);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}
