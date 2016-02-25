#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linklist.h"

int main(int argc, char* argv[])
{
    LLink link;

    init_llink(&link);

    //char *str = "hello world";
    //void *str_c = malloc(200);
    //memcpy(str_c, str, strlen(str));

    LNode *node = (LNode *)calloc(sizeof(LNode), 1);
    node->data = 1;

    append_data_llink(&link, node);

    //foreach_llink(&link);

    return 0;
}
