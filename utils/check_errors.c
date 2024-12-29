/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:24:30 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/12 09:55:52 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_there_a_number(char	*s)
{
	int		i;
	bool	num_present;

	i = 0;
	num_present = false;
	while (s[i])
	{
		if (ft_isdigit(s[i]))
			num_present = true;
		i++;
	}
	return (num_present);
}

int	check_duplicates(char **splited)
{
	int		i;
	int		j;
	bool	num_present;

	i = 0;
	num_present = false;
	while (splited[i])
	{
		j = i + 1;
		if (!splited[i][0])
			return (1);
		while (splited[j])
		{
			if (ft_atoli(splited[i]) == ft_atoli(splited[j]))
				return (1);
			j++;
		}
		if (is_there_a_number(splited[i]))
			num_present = true;
		i++;
	}
	if (!num_present)
		return (1);
	return (0);
}

int	check_errors(char **splited)
{
	int	i;
	int	j;

	i = 0;
	while (splited[i])
	{
		j = 0;
		while (splited[i][j])
		{
			if (!splited[i][j] || (!ft_isdigit(splited[i][j])
				&& splited[i][j] != '+' && splited[i][j] != '-'))
				return (1);
			if ((splited[i][j] == '-' || splited[i][j] == '+')
				&& !ft_isdigit(splited[i][j + 1]))
				return (1);
			j++;
		}
		if (ft_atoli(splited[i]) < INT_MIN || ft_atoli(splited[i]) > INT_MAX
			|| check_duplicates(splited))
			return (1);
		i++;
	}
	return (0);
}
