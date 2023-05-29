/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:08:46 by areifoun          #+#    #+#             */
/*   Updated: 2023/05/27 16:23:36 by areifoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_valid_nbr(char **argv)
{
	int	i;
	int	j;
	int	num_spc;
	int	len;

	i = 1;
	while (argv[i])
	{
		j = 0;
		num_spc = 0;
		len = ft_strlen(argv[i]);
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
				num_spc++;
			j++;
		}
		if (len == num_spc || argv[i][0] == 0)
			exit(ft_error("Error"));
		i++;
	}
}

int	ft_is_duplicated(char **argv, int nbr)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (argv[i])
	{
		if (nbr == ft_atoi(argv[i]))
			count++;
		i++;
	}
	if (count == 1)
		return (0);
	return (1);
}

int	ft_arg_checker(char **av)
{
	int		i;
	int		nbr;

	i = 0;
	while (av[i])
	{
		nbr = ft_atoi(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (1);
		else if (ft_is_duplicated(av, nbr) == 1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = 0;
	}
	if (!s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i] != 0)
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	free(s1);
	return (str);
}

char	**join_args(char **argv)
{
	int		i;
	char	**args;
	char	*join;
	char	*str;

	i = 1;
	str = NULL;
	while (argv[i])
	{
		join = ft_strjoin(argv[i], " ");
		str = ft_strjoin1(str, join);
		free(join);
		i++;
	}
	ft_valid_nbr(argv);
	args = ft_split(str, ' ');
	free(str);
	return (args);
}
