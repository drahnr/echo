#include "echo_define.h"
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
    echo_msg ("msg without args\n");
    echo_warning ("warning with args %s\n", "wiu wiu");
    echo_error ("error with args %s\n", "wiu wiu");
    echo_debug ("debug no args\n");
    echo_debug ("debug with args %s\n", argv[0]);
    return EXIT_SUCCESS;
}
