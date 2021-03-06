/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inittable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 13:09:25 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/12 10:10:22 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"
#include <stdlib.h>

void	ft_inittablecont(t_cw *cw)
{
	cw->op_tab[12] = (t_op){"fork", 1, {T_DIR, 0, 0, 0}, 12, 800, "fork", 0, 1};
	cw->op_tab[13] = (t_op){"lld", 2, {T_DIR | T_IND, T_REG, 0, 0}, 13, 10,
		"long load", 1, 0};
	cw->op_tab[14] = (t_op){"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG,
		T_REG, 0}, 14, 50, "long load index", 1, 1};
	cw->op_tab[15] = (t_op){"lfork", 1, {T_DIR, 0, 0, 0}, 15, 1000,
		"long fork", 0, 1};
	cw->op_tab[16] = (t_op){"aff", 1, {T_REG, 0, 0, 0}, 16, 2, "aff", 1, 0};
}

void	ft_inittable(t_cw *cw)
{
	cw->op_tab[0] = (t_op){0, 0, {0, 0, 0, 0}, 0, 0, 0, 0, 0};
	cw->op_tab[1] = (t_op){"live", 1, {T_DIR, 0, 0, 0}, 1, 10, "alive", 0, 0};
	cw->op_tab[2] = (t_op){"ld", 2, {T_DIR | T_IND, T_REG, 0, 0}, 2, 5, "load",
		1, 0};
	cw->op_tab[3] = (t_op){"st", 2, {T_REG, T_IND | T_REG, 0, 0}, 3, 5, "store",
		1, 0};
	cw->op_tab[4] = (t_op){"add", 3, {T_REG, T_REG, T_REG, 0}, 4, 10,
		"addition", 1, 0};
	cw->op_tab[5] = (t_op){"sub", 3, {T_REG, T_REG, T_REG, 0}, 5, 10,
		"soustraction", 1, 0};
	cw->op_tab[6] = (t_op){"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND |
		T_DIR, T_REG, 0}, 6, 6, "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0};
	cw->op_tab[7] = (t_op){"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND |
		T_DIR, T_REG, 0}, 7, 6, "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0};
	cw->op_tab[8] = (t_op){"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND |
		T_DIR, T_REG, 0}, 8, 6, "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0};
	cw->op_tab[9] = (t_op){"zjmp", 1, {T_DIR, 0, 0, 0}, 9, 20,
		"jump if zero", 0, 1};
	cw->op_tab[10] = (t_op){"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG,
		T_REG, 0}, 10, 25, "load index", 1, 1};
	cw->op_tab[11] = (t_op){"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR |
		T_REG, 0}, 11, 25, "store index", 1, 1};
	ft_inittablecont(cw);
}
