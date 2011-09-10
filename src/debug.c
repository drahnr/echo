/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * debug.c
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

#include "debug.h"


void 
echo_debug(char *msg, ...)
{
#ifdef DEBUG
	char buffer[2048]; //TODO fix this to not break on long messages
  	va_list args;
  	va_start (args, msg);
  	vsprintf (buffer, msg, args);
  	va_end (args);
	
#ifndef __WINDOWS__
	printf("[ %sDEBUG%s   ] - %s\n", COLOR_BLUE, COLOR_DEFAULT, buffer);
#else
	printf("[ DEBUG   ] - %s\r\n", msg);
#endif
#endif
}
