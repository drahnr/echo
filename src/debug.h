/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * debug.h
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


#ifndef _ECHO_DEBUG_H_
#define _ECHO_DEBUG_H_

#include <stdarg.h> /* tripple dot args */
#include <stdio.h> /* printf */
#include <string.h> /* string */
#include "color.h"

void echo_debug(char* msg, ...);

#endif /* _ECHO_DEBUG_H_ */
