/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:07:57 by pvong             #+#    #+#             */
/*   Updated: 2022/10/11 14:53:43 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
	return (0);
}
/*
#include <stdio.h>

int	main(int argc, char** argv)
{
	if (argc < 3)
		printf("Is %s alpha ? 1 = Yes 0 = No\n Isalpha: %d\n", \
				argv[1], ft_isalpha(argv[1][0]));
	return (0);
}
*/
