/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornygonz_interpolant.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 16:24:47 by Rakiah            #+#    #+#             */
/*   Updated: 2016/07/15 12:15:04 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PORNYGONZ_INTERPOLANT_H
# define PORNYGONZ_INTERPOLANT_H

t_interpolant	*ipl_new(t_vector4f *v[3], float v1, float v2, float v3);
void			ipl_calculate_steps(t_interpolant *ipl,
									t_vector4f *min,
									t_vector4f *mid,
									t_vector4f *max);

#endif
