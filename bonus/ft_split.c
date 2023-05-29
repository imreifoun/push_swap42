/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:20:23 by areifoun          #+#    #+#             */
/*   Updated: 2023/05/23 11:12:15 by areifoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	ft_free_split(char **str, int n)
{
	while (n--)
	{
		free(str[n]);
	}
	free(str);
}

int	ft_counter(char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
			word++;
		while (str[i] != c && str[i])
		i++;
	}
	return (word);
}

void	ft_print(char *split, const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
	{
		split[i] = str[i];
		i++;
	}
	split[i] = '\0';
}

int	ft_writ(char **split, char *str, char c)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == c || str[i] == '\0') == 1)
			i++;
		else
		{
			j = 0;
			while ((str[i + j] != c && str[i + j] != '\0') == 1)
				j++;
			split[word] = (char *)malloc(sizeof(char) * j + 1);
			if (split == NULL)
				ft_free_split(split, word);
			ft_print(split[word], str + i, c);
			word++;
			i += j;
		}
	}
	return (0);
}

char	**ft_split(const char *str, char c)
{
	char	**split;
	int		word;

	if (str == NULL)
		return (0);
	word = ft_counter((char *)str, c);
	split = (char **)malloc(sizeof(char *) * (word + 1));
	if (split == NULL)
		return (NULL);
	split[word] = 0;
	ft_writ(split, (char *)str, c);
	return (split);
}
