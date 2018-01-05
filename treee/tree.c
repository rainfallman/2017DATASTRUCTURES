#include <stdio.h>
#include <stdlib.h>
typedef struct n{
    int value;
    struct n *leftnode;
    struct n *rightnode;
} node;
node* createnode(int in);
int main(int argc, char *argv[])
{
    int inputval;
    char c[10];
    node *head=(node *)malloc(sizeof(node));
    head->value=0;
    head->leftnode=NULL;
    head->rightnode=NULL;
    node *point=head;
    scanf("%d%[,]",&inputval,c);
    head->value=inputval;
    while(scanf("%d%[,]",&inputval,c)==2)
    {
        point=head;
        while(point->value>0)
        {
            if(inputval>point->value)
            {
                if(point->rightnode==NULL)
                {
                    point->rightnode=createnode(inputval);
                    break;
                }
                point=point->rightnode;
            }
            if(inputval<point->value)
            {
                if(point->leftnode==NULL)
                {
                    point->leftnode=createnode(inputval);
                    break;
                }
                point=point->leftnode;
            }
        }
    }
    printf("Create Binary search tree\n");
    int flag;
    int level=1,i;
    node** a=(node**)malloc(level*sizeof(node*));
    a[0]=head;
    do
    {
        flag=0;
        level*=2;
        node** b=(node**)malloc(level*sizeof(node*));
        for(i=0;i<level/2;i++)
        {
            if(a[i]==NULL) printf(" * ");
            else printf("%d ",a[i]->value);
            if(a[i]==NULL)
            {
                b[2*i]=NULL;
                b[2*i+1]=NULL;
            }
            else 
            {
                b[2*i]=a[i]->leftnode;
                b[2*i+1]=a[i]->rightnode;
            }
            if(b[i*2]!=NULL||b[i*2+1]!=NULL)
                flag=1;
        }
        free(a);
        a=b;
        printf("\n");

    }
    while(flag);
    int deletenumber,dyes=0,dir=0;
    char deleteor;
    scanf("%c",&deleteor);
    node* depoint;
    while(1)
    {
        printf("delete element?\n");
        scanf("%c",&deleteor);
        if(deleteor=='n'||deleteor=='N')
            break;
        printf("Choice element\n");
        scanf("%d",&deletenumber);
        point=head;
        while(point!=NULL)
        {
            if(deletenumber>point->value)
            {
                depoint=point;
                dir=1;
                point=point->rightnode;
            }
            else if(deletenumber<point->value)
            {
                depoint=point;
                dir=2;
                point=point->leftnode;
            }
            else if(deletenumber==point->value)
            {
                dyes=1;
                break;
            }
        }
        if(dyes==0)
            printf("%d is not in the tree\n",deletenumber);
        if(dyes==1)
        {
            if(point->rightnode!=NULL)
            {
                depoint=point;
                node* detmp=point->rightnode;
                while(detmp->leftnode!=NULL)
                {
                    depoint=detmp;
                    detmp=detmp->leftnode;
                }
                point->value=detmp->value;
                if(depoint == point)
                    depoint->rightnode = detmp->rightnode;
                else
                    depoint->leftnode = detmp->rightnode;
                free(detmp);
            }
            else
            {
                if(dir==1)
                {
                    depoint->rightnode=point->leftnode;
                    free(point);
                }
                if(dir==2)
                {
                    depoint->leftnode=point->leftnode;
                    free(point);
                }
            }

        }

    int flag;
    int level=1,i;
    node** a=(node**)malloc(level*sizeof(node*));
    a[0]=head;
    do
    {
        flag=0;
        level*=2;
        node** b=(node**)malloc(level*sizeof(node*));
        for(i=0;i<level/2;i++)
        {
            if(a[i]==NULL) printf(" * ");
            else printf("%d ",a[i]->value);
            if(a[i]==NULL)
            {
                b[2*i]=NULL;
                b[2*i+1]=NULL;
            }
            else
            {
                b[2*i]=a[i]->leftnode;
                b[2*i+1]=a[i]->rightnode;
            }
            if(b[i*2]!=NULL||b[i*2+1]!=NULL)
                flag=1;
        }
        free(a);
        a=b;
        printf("\n");

    }
    while(flag);
    scanf("%c",&deleteor);
    }
    return 0;
}
node* createnode(int in)
{
    node* tmp=(node *)malloc(sizeof(node));
    tmp->value=in;
    tmp->leftnode=NULL;
    tmp->rightnode=NULL;
}
