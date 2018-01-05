#include <stdio.h>

struct l {
    int s;
    int e;
    int w;
} line[15]={{0,1,5},{0,2,4},{0,3,2},{1,4,3},{2,1,1},{2,5,8},{2,4,2},{3,2,1},{3,5,7},{4,6,7},{4,8,15},{4,7,10},{5,7,3},{6,8,6},{7,8,5}};
struct d{
    int dis;
    int pre;
} trace[9]={0,-1};
int path(int start,int end);

int main(int argc, char *argv[])
{
    int start,end,road,pa[9]={-1},count=1;
    scanf("%d %d",&start,&end);
    path(start,end);
    if(trace[end].dis==0)
        printf("No solution\n");
    else
    {
        printf("Distance : %d\n",trace[end].dis);
        pa[0]=end;
        printf("The route for the shortest path : %d",start);
        road=trace[end].pre;
        while(road!=start)
        {
            /*if(road==start)
            {
                pa[count]=road;
                road=trace[road].pre;
                count++;
                break;
            }*/
            pa[count]=road;
            road=trace[road].pre;
            count++;
        }
        for(count--;count>=0;count--)
        {
            printf("->%d",pa[count]);
        }
        printf("\n");
    }
    return 0;
}

int path(int start,int end)
{
    int i;
    for(i=0;i<15;i++)
    {
        if(line[i].s==start&&line[i].e!=end)
        {
            trace[line[i].e].dis=line[i].w+trace[line[i].s].dis;
            trace[line[i].e].pre=start;
            path(line[i].e,end);
        }
        if(line[i].s==start&&line[i].e==end)
        {
            if(trace[end].dis==0)
            {
                trace[line[i].e].dis=line[i].w+trace[line[i].s].dis;
                trace[line[i].e].pre=start;
            }
            else
            {
                if(trace[end].dis>line[i].w+trace[line[i].s].dis)
                {
                    trace[line[i].e].dis=line[i].w+trace[line[i].s].dis;
                    trace[line[i].e].pre=start;
                }
            }
        }
    }
}
