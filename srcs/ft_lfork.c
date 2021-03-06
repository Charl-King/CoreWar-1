/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:27:06 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/13 16:37:06 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"
#include "op.h"

void	ft_lfork(t_cw *cw, t_pc *pc)
{
	int		newidx;
	t_list	*newpclist;
	t_pc	*newpc;
	int		i;

	if (!pc->cr)
		pc->cr = cw->op_tab[15].ctc;
	pc->cyccomplete++;
	if (pc->cr == pc->cyccomplete)
	{
		newpc = (t_pc*)malloc(sizeof(pc));
		newpc->index = (pc->index + (ft_getdir(cw, pc->index + 1))) % MEM_SIZE;
		newpc->idnbr = pc->idnbr;
		newpc->cr = pc->cr;
		newpc->carry = pc->carry;
		newpc->registers = (unsigned char**)malloc(sizeof(char*) * REG_NUMBER);
		i = 0;
		while (i < REG_NUMBER)
		{
			newpc->registers[i] = (unsigned char*)malloc(sizeof(char)
				* REG_SIZE);
			ft_memcpy(newpc->registers[i], pc->registers[i], REG_SIZE);
			i++;
		}
		newpclist = (t_list*)malloc(sizeof(t_list));
		newpclist->content = newpc;
		newpclist->content_size = sizeof(t_pc);
		ft_lstadd(&(cw->pclist), newpclist);
		if (newpc->index == 0)
			pc->carry = 1;
		newidx = DIR_SIZE;
		pc->index = (pc->index + newidx) % MEM_SIZE;
		pc->cr = 0;
		pc->cyccomplete = 0;
	}
}
