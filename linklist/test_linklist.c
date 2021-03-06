#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* 自定义数据类型 */
#define UDF_ELETYPE 1
typedef int EleType ;

#include "linklist.h"

int equals_callback_llink(EleType e1, EleType e2);
void iterator_callback_llink(EleType e1);

int sum = 0;

int main(int argc, char* argv[])
{

    LLink link;

    init_llink(&link);

    append_data_llink(&link, 1);
    append_data_llink(&link, 10);
    append_data_llink(&link, 100);
    append_data_llink(&link, 1000);
    append_data_llink(&link, 10000);
    append_data_llink(&link, 1000);
    append_data_llink(&link, 10000);

    del_data_llink(&link, 1000, equals_callback_llink);

    sum = 0;
    foreach_llink(&link, iterator_callback_llink);
    printf("sum is %d \n", sum);

    return 0;
}

void iterator_callback_llink(EleType e1)
{
    printf("%d \n", (int)e1);
    sum += (int)e1;
}

int equals_callback_llink(EleType e1, EleType e2)
{
    if(e1 == e2)
    {
        return 1;
    }
    return 0;
}
