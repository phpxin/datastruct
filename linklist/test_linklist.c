#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linklist.h"

int main(int argc, char* argv[])
{
    
    LLink link;

    init_llink(&link);

    append_data_llink(&link, 1);
    append_data_llink(&link, 10);
    append_data_llink(&link, 100);
    append_data_llink(&link, 1000);
    append_data_llink(&link, 10000);

    foreach_llink(&link);

    return 0;
}
