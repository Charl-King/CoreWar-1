/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:13:33 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/12 18:56:58 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw.h"
#include <stdlib.h>

/*
** No comment yet.
*/

void	ft_and(t_cw *cw, t_pc *pc)
{
	int		*arr;
	int		newidx;
	int		val[3];
	int		i;

	i = 0;
	if (!pc->cr)
		pc->cr = cw->op_tab[6].ctc;
	pc->cyccomplete++;
	if (pc->cr == pc->cyccomplete)
	{
		newidx = 1;
		if (ft_verify_eb(cw, pc))
		{
			arr = ft_getparam(cw->mem[pc->index + newidx]);
			newidx += 1;
			if (arr[0] == T_REG)
			{
				val[0] = ft_getregval(pc, cw->mem[pc->index + newidx]);
				newidx += 1;
			}
			if (arr[0] == T_IND)
			{
				val[0] = ft_getdir(cw, (pc->index + ft_getind(cw, (pc->index +
					newidx) % IDX_MOD)) % IDX_MOD);
				newidx += IND_SIZE;
			}
			else
			{
				val[0] = ft_getdir(cw, (pc->index + newidx) % IDX_MOD);
				newidx += DIR_SIZE;
			}
			if (arr[1] == T_REG)
			{
				val[1] = ft_getregval(pc, cw->mem[pc->index + newidx]);
				newidx += 1;
			}
			if (arr[1] == T_IND)
			{
				val[1] = ft_getdir(cw, (pc->index + ft_getind(cw, (pc->index +
					newidx) % IDX_MOD)) % IDX_MOD);
				newidx += IND_SIZE;
			}
			else
			{
				val[1] = ft_getdir(cw, (pc->index + newidx) % IDX_MOD);
				newidx += DIR_SIZE;
			}
			val[2] = val[1] & val[0];
			if (!val[2])
				pc->carry = 1;
			ft_strinreg(pc, cw->mem[(pc->index + newidx) % IDX_MOD], val[2]);
			newidx += 1;
		}
		pc->index = (pc->index + newidx) % MEM_SIZE;
		pc->cr = 0;
		pc->cyccomplete = 0;
	}
}
