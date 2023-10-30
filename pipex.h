/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarbos <tibarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:31:19 by tibarbos          #+#    #+#             */
/*   Updated: 2023/10/30 16:10:11 by tibarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h> //write, read, fork, exec
# include <stdlib.h> //malloc, free
# include <sys/wait.h> //wait, waitpid, getpid, getppid
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h> //open
# include <limits.h>
# include "./libft/mylib.h" //usar no read

# define LIMITER    "LIM"
# define ENV_VAR    __environ
# define PATH       __environ[32]

//atencao ao mylib/libft porque ha funcoes auxiliares c o mesmo nome
//se so chamar ft_printf ou getnext na boa, as outras cuidado

#endif