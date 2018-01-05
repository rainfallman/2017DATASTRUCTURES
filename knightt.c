#include <stdio.h>
#include <stdlib.h>
int knight(int nowstep,int total,int x,int y);
int mapoftour[12][12];
int leftrightgo[8]={2,2,1,-1,-2,-2,-1,1};
int updowngo[8]={1,-1,-2,-2,-1,1,2,2};
int canmove(int x,int y,int limi);
int main()
{

    int i,j;
    for(i=1;i<5;i++)
        printf("%d :\n No solution\n",i);
    knight(1,10,1,1);
    for(i=1;i<=10;i++)
    {
        for(j=1;j<=10;j++)
            printf("%4d",mapoftour[i][j]);
        printf("\n");
    }
    return 0;

}
int knight(int nowstep,int total,int x,int y)
{
    int count=0;
    mapoftour[x][y]=nowstep;
    if(nowstep==total*total)
    {
        return  1;
    }
    else
    {
        for(count=0;count<8;count++)
        {
            if(canmove(x+updowngo[count],y+leftrightgo[count],total)==1)
            {
                if(knight(nowstep+1,total,x+updowngo[count],y+leftrightgo[count])==1)
                    return 1;
            }
        }
        mapoftour[x][y]=0;
    }
}
int canmove(int x,int y,int limi)
{
    if(x<=limi&&x>=1&&y<=limi&&y>=1&&mapoftour[x][y]==0)
        return  1;
    else
        return  0;
}
