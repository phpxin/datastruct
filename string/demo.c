#include "apue.h"
#include "HString.h"


int main()
{
    char *ss = "Hello world";

    HString str = {NULL, 0} ;

    StrAssign(&str, ss);

    HString substr = {NULL, 0};

    SubString(&substr, &str, 2, 6);

    printf("%s sub is %s\n", str.ch, substr.ch);

    int cmp = StrCompare(&str, &substr);
    if(cmp==0)
        printf("str = sub \n");
    else if(cmp>0)
        printf("str is bigger\n");
    else if(cmp<0)
        printf("sub is bigger\n");

    StrCopy(&substr, &str);
    printf("%s sub is %s\n", str.ch, substr.ch);

    if(StrEmpty(&substr))
        printf("sub 1 is empty\n");

    int len = StrLength(&substr);
    printf("sub len is %d\n", len);

    StrAssign(&str, "hello");
    StrAssign(&substr, " Apple");
    HString strcat = {NULL, 0} ;
    Concat(&strcat, &str, &substr);
    printf("concat is %s\n", strcat);
    ClearString(&strcat);

    ClearString(&str);
    ClearString(&substr);

    if(StrEmpty(&substr))
        printf("sub 2 is empty\n");

    return 1;
}
