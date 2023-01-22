/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <scornhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:45:19 by scornhol          #+#    #+#             */
/*   Updated: 2022/03/19 17:22:12 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_join(char **str)
{
	int		i;
	char	*ret;
	char	*tmp;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (!str[i][0])
			error();
		if (!ret)
		{
			ret = ft_strdup(str[i++]);
		}
		else
		{
			tmp = ret;
			ret = ft_strjoin(ret, " ");
			free(tmp);
			tmp = ret;
			ret = ft_strjoin(ret, str[i++]);
			free(tmp);
		}
	}
	return (ret);
}

int	ft_count_arg(char const *s, char c)
{
	int	i;
	int	word;

	i = -1;
	word = 0;
	while (s[++i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			word++;
	}
	return (word);
}

void	leaks(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
}
