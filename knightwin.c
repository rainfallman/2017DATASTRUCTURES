#include <stdio.h>
#include <stdlib.h>
int knight(int nowstep,int total,int x,int y);
int mapoftour[9][9];
int leftrightgo[8]={1,2,2,1,-1,-2,-2,-1};
int updowngo[8]={-2,-1,1,2,-2,-1,1,2};
int main()
{
    int i,j,k;
    for(i=1;i<5;i++)
        printf("%d :\n No solution\n",i);
    for(i=5;i<=8;i++)
    {
        knight(1,i,1,1);
        printf("%d:\n",i );
        for(j=1;j<=i;j++)
        {
            for(k=1;k<=i;k++)
                printf("%3d",mapoftour[j][k]);
            printf("\n");
        }
        printf("\n");
        for(j=1;j<=8;j++)
        {
            for(k=1;k<8;k++)
                mapoftour[j][k]=0;
        }

    }
    /*knight(1,7,1,1);
    for(i=1;i<8;i++)
    {
        for(j=1;j<8;j++)
            printf("%3d",mapoftour[i][j] );
        printf("\n");
    }*/
    return 0;
}
int knight(int nowstep,int total,int x,int y)
{
    int count=0;
    if(nowstep<=total*total+1)
    {
        if(nowstep==total*total+1)
            return 1;
        if(mapoftour[x][y]==0&&x<=total&&y<=total&&x>=1&&y>=1)
        {
            mapoftour[x][y]=nowstep;
            for(count=0;count<8;count++)
            {
                if(knight(nowstep+1,total,x+leftrightgo[count],y+updowngo[count])==1)
                    return 1;
            }
            mapoftour[x][y]=0;
        }
        else
            return 0;

        }
}
