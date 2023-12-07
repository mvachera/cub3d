/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isseparator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmastora <jmastora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 00:40:44 by jmastora          #+#    #+#             */
/*   Updated: 2023/09/29 19:46:45 by jmastora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isseparator(char c)
{
	if (c == '|' || c == '&' || c == '>' || c == '<')
		return (1);
	return (0);
}