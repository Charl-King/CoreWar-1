/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 13:18:18 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/05 13:36:03 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#incude "libft.h"
#include "cw.h"

unsigned char	*dec_to_hex(unsigned char n)
{
	int	x;
	unsigned char	tmp;

	tmp = (unsigned char*)malloc(3);
	x = n / 16;
	if (x < 10)
		tmp[0] = x + '0';
	else
		tmp[0] = x - 10 + 'a';
	n = n % 16;
	if (n < 10)
		tmp[1] = n + '0'
	else
		tmp[1] = n - 10 + 'a';
	tmp[2] = '\0';
	return (tmp);

}