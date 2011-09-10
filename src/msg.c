#include "error.h"


void 
echo_msg(char *msg, ...)
{
	char buffer[2048]; //TODO fix this to not break on long messages
  	va_list args;
  	va_start (args, msg);
  	vsprintf (buffer, msg, args);
  	va_end (args);
	
#ifndef __WINDOWS__
	printf("[ %sERROR%s   ] - %s\n", COLOR_RED, COLOR_DEFAULT, buffer);
#else
	printf("[ ERROR   ] - %s\r\n", msg);
#endif
}
