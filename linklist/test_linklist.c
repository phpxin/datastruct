#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linklist.h"

int main(int argc, char* argv[])
{
    LLink *link = (LLink *)calloc(1, sizeof(LLink));

    init_llink(link);

    //char *str = "hello world";
    //void *str_c = malloc(200);
    //memcpy(str_c, str, strlen(str));

    //LNode *node = (LNode *)calloc(sizeof(LNode), 1);
    //node->data = 1;
    EleType e = 1;

    append_data_llink(link, e);

    //foreach_llink(&link);

    return 0;
}
