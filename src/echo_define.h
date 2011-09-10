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
#include "echo_color.h"
#include "echo_generic.h"


#define POSITION_STR  "[file %s, line %d] "
#define POSITION_ARGS  __FILE__, __LINE__

#define echo_msg(_fmt,...) echo_generic(stdout, _fmt, COLOR_DEFAULT, "message", ##__VA_ARGS__)
#define echo_info(_fmt, ...) echo_generic(stdout, _fmt, COLOR_GREEN, "info      ", ##__VA_ARGS__)
#define echo_warning(_fmt, ...) echo_generic(stdout, _fmt, COLOR_ORANGE, "warning", ##__VA_ARGS__)
#define echo_error(_fmt, ...) echo_generic(stderr, _fmt, COLOR_RED, "error ", ##__VA_ARGS__)
#define echo_debug(_fmt, ...) echo_generic(stdout, POSITION_STR _fmt, COLOR_BLUE, "debug  ", POSITION_ARGS, ##__VA_ARGS__)


#endif /* _ECHO_DEFINE_H_ */
