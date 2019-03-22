/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:28:20 by jblue-da          #+#    #+#             */
/*   Updated: 2019/03/21 23:29:38 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H_
#define FT_PRINTF_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <fcntl.h>
#include "fs_vector/fs_vector.h"
#include "parsing/printf_parsing.h"
#include "preparation/prepare.h"
#include "handling/handling.h"

/* Main function */
int				ft_printf(char *format, ...);

#endif
