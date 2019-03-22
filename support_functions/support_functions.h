/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_functions.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 21:58:28 by sindenis          #+#    #+#             */
/*   Updated: 2019/03/21 22:48:04 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPPORT_FUNCTIONS_H_
#define SUPPORT_FUNCTIONS_H_

#include <stdlib.h>

void	ft_strdel(char **as);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void    ft_strpush(char **str1, char str2);
int		ft_isalpha(int c);
int     ft_isdigit(int c);
char	*ft_strchr(const char *s, int c);

#endif