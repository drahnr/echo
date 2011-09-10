#include "echo_generic.h"


void 
echo_generic(FILE *fp, char *msg, const char *color, char *prefix, ...)
{
	char buffer[2048]; //TODO fix this to not break on long messages
  	va_list args;
  	va_start (args, prefix);
  	vsprintf (buffer, msg, args);
  	va_end (args);

#ifndef __WINDOWS__
	fprintf(fp, "[%s %s %s] - %s\n", color, prefix, COLOR_DEFAULT, buffer);
#else
	fprintf(fp, "[ %s ] - %s\r\n", prefix, msg);
#endif
}
