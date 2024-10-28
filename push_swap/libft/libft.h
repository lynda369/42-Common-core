/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:37:11 by lybey             #+#    #+#             */
/*   Updated: 2024/03/25 01:18:13 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../includes/push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

/* get_next_line*/
long long int		ft_atoi(const char *str);
int					ft_isdigit(int c);

#endif