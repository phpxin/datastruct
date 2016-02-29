#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* 自定义数据类型 */
#define UDF_ELETYPE 1
typedef char* EleType ;

#include "linklist.h"

int equals_callback_llink(EleType e1, EleType e2);
void iterator_callback_llink(EleType e1);

int main(int argc, char* argv[])
{

    LLink link;

    init_llink(&link);

    append_data_llink(&link, "hellosss");
    append_data_llink(&link, "world");

    del_data_llink(&link, "world", equals_callback_llink);

    foreach_llink(&link, iterator_callback_llink);


    return 0;
}

void iterator_callback_llink(EleType e1)
{
    printf("%s \n", e1);

}

int equals_callback_llink(EleType e1, EleType e2)
{
    size_t n1 = strlen(e1);
    size_t n2 = strlen(e2);
    if(n1!=n2)
    {
        return 0;
    }

    if(strncmp(e1,e2,n1) == 0)
    {
        return 1;
    }

    return 0;
}
