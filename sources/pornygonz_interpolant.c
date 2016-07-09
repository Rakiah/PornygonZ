/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz_interpolant.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 16:24:46 by Rakiah            #+#    #+#             */
/*   Updated: 2016/07/06 16:24:55 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pornygonz_internal.h"

t_interpolant	*ipl_new(t_vector4f *pos[3], float v1, float v2, float v3)
{
	t_interpolant	*ipl;

	ipl = malloc(sizeof(t_interpolant));
	ipl->values[0] = v1;
	ipl->values[1] = v2;
	ipl->values[2] = v3;
	ipl_calculate_steps(ipl, pos[0], pos[1], pos[2]);
	return (ipl);
}

void		ipl_calculate_steps(t_interpolant *ipl,
								t_vector4f *min,
								t_vector4f *mid,
								t_vector4f *max)
{
	float inverse_dx;

	inverse_dx = 1.0f / (((mid->x - max->x) * (min->y - max->y)) -
						((min->x - max->x) * (mid->y - max->y)));
	ipl->x_step = (((ipl->values[1] - ipl->values[2]) * (min->y - max->y)) -
					((ipl->values[0] - ipl->values[2]) * (mid->y - max->y))) *
					inverse_dx;
	ipl->y_step = (((ipl->values[1] - ipl->values[2]) * (min->x - max->x)) -
					((ipl->values[0] - ipl->values[2]) * (mid->x - max->x))) *
					(-inverse_dx);
}
