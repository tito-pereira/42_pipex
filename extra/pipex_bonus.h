/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:21:40 by tibarbos          #+#    #+#             */
/*   Updated: 2023/12/26 17:28:35 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../mandatory/pipex.h"

t_all	*proc_central(t_all *all, int ac, char **av);

#endif

// proc all, mult pipes
/*
provavelmente tenho que refazer a main porque ficou toda mal
a distinção do numero de argumentos eu já faço no proc bonus
o resto tmb, incluindo o multi pipes

apenas usar o proc central em vez de proc cmds ou isso
*/