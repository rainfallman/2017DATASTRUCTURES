#include <stdio.h>
#include <stdlib.h>
typedef struct no{
    int num;
    struct no *link;
} lin;

lin *createlink(lin *prev,lin *now,int innum);

int main(int argc, char *argv[])
{
    int i=1;
    lin *start=(lin *)malloc(sizeof(lin));
    start->link=NULL;
    start->num=1;
    lin *p;
    p=start;
    for(i=2;i<=20;i++)
    {
        lin *mid=(lin *)malloc(sizeof(lin));
        p->link=(lin *)((unsigned long)mid^(unsigned long)p->link);
        mid->link=p;
        p=mid;
        p->num=i;
    }
    lin *endnode=p;
    p=start;
    lin *printfp=NULL;
    lin *ploca=p;
    for(i=1;i<=20;i++)
    {
        if(i==20)
            printf("%d",p->num);
        else
            printf("%d, ",p->num);
        p=(lin *)((unsigned long)p->link^(unsigned long)printfp);
        printfp=ploca;
        ploca=p;
    }
    printf("\n");

    p=endnode;
    lin *endp=NULL;
    lin *endploca=p;
    for(i=1;i<=20;i++)
    {
        if(i==20)
            printf("%d",p->num);
        else
            printf("%d, ",p->num);
        p=(lin *)((unsigned long)p->link^(unsigned long)endp);
        endp=endploca;
        endploca=p;
    }
    printf("\n");
    return 0;
}
/*lin *createlink(lin *prev,lin *now,int innum )
{
    lin *tmp=(lin *)malloc(sizeof(lin));
    now->link=(unsigned int)prev^(unsigned int)tmp;
    now->num=innum;
    return tmp;
}*/
