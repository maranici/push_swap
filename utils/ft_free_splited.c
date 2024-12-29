/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_splited.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuesta <macuesta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:09:32 by macuesta          #+#    #+#             */
/*   Updated: 2024/12/09 18:09:42 by macuesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_splited(char **splited, bool do_we_free)
{
	int	i;

	i = 0;
	if (do_we_free)
	{
		while (splited[i])
			free(splited[i++]);
		free(splited);
	}
}
