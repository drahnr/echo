/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 *  The MIT License (MIT)
 *
 * Copyright (c) 2011,2013    Bernhard Schuster
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
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
