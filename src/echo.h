/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * echo_define.h
 * Copyright (C) Bernhard Schuster 2011 <schuster.bernhard@googlemail.com>
 * 
 * echo is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * echo is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef _ECHO_DEFINE_H_
#define _ECHO_DEFINE_H_

#include <stdarg.h> /* tripple dot args */
#include <stdio.h> /* printf */
#include <string.h> /* string */

#define ECHO_COLOR_GREEN "\033[32m"
#define ECHO_COLOR_RED "\033[31m"
#define ECHO_COLOR_ORANGE "\033[33m"
#define ECHO_COLOR_BLUE "\033[34m"
#define ECHO_COLOR_DEFAULT "\033[0m"

#ifndef __WINDOWS__
#define ECHO_GENERIC_PREFIX_STR "[%s %s %s]"
#else
#define ECHO_GENERIC_PREFIX_STR "[ %s ]"
#endif

#define ECHO_DEBUG_POSITION_STR  "[file %s, line %d] "
#define ECHO_DEBUG_POSITION_ARGS  __FILE__, __LINE__

#ifndef __WINDOWS__
#define echo_generic(io, msg, prefix, color, ...) fprintf (io, ECHO_GENERIC_PREFIX_STR msg , color, prefix, ECHO_COLOR_DEFAULT, ##__VA_ARGS__)
#else
#define echo_generic(io, msg, prefix, color, ...) fprintf (io, ECHO_GENERIC_PREFIX_STR msg , prefix, ##__VA_ARGS__)
#endif

#define echo_msg(msg, ...) echo_generic(stdout, msg, "message", ECHO_COLOR_DEFAULT, ##__VA_ARGS__)
#define echo_info(msg, ...) echo_generic(stdout, msg, "info    ", ECHO_COLOR_GREEN, ##__VA_ARGS__)
#define echo_warning(msg, ...) echo_generic(stdout, msg, "warning", ECHO_COLOR_ORANGE, ##__VA_ARGS__)
#define echo_error(msg, ...) echo_generic(stderr, msg, "error ", ECHO_COLOR_RED, ##__VA_ARGS__)
#define echo_debug(msg, ...) echo_generic(stdout, ECHO_DEBUG_POSITION_STR msg, "debug  ", ECHO_COLOR_BLUE, ECHO_DEBUG_POSITION_ARGS, ##__VA_ARGS__)

#endif /* _ECHO_DEFINE_H_ */
