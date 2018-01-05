#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int dirx[8]={0,1,0,-1,-1,1,1,-1};
int diry[8]={1,0,-1,0,1,1,-1,-1};

class place {
    public:
        int x;
        int y;
};


int main()
{
    int y,x,nextx,nexty,goal=0,gonextcorrect=0;
    vector<place> v;
    place putin;
    cin >>x>>y ;
    /*char micemap[x][y];*/
    char **micemap;
    micemap=new char*[x];
    for (int i= 0; i < x; ++i) {
        micemap[i]=new char[y];
    }
    // input map info
    for (int i = 0;i<x; ++i) {
        for (int j = 0; j < y; ++j) {
            cin >> micemap[i][j];
            if(micemap[i][j]=='s')
            {
                putin.x=i;
                putin.y=j;
            }
        }
    }
    //out put map
    /*for (int i = 0; i<x; ++i) {
      for (int j = 0; j < y; ++j) {
      cout<<micemap[i][j];
      }
      cout<<endl;
      }*/
    v.push_back(putin);
    while(goal==0)
    {
        gonextcorrect=0;
        for (int i = 0; i <8; ++i) {
            nextx=v.back().x+dirx[i];
            nexty=v.back().y+diry[i];
            if(nextx>=0&&nextx<x&&nexty>=0&&nexty<y)
            {
                if(micemap[nextx][nexty]=='d')
                {
                    /*cout<<"goal"<<endl;*/
                    goal=1;
                    break;
                }
            }
        }
        for (int i = 0; i <8; ++i) {
            nextx=v.back().x+dirx[i];
            nexty=v.back().y+diry[i];
            if(nextx>=0&&nextx<x&&nexty>=0&&nexty<y)
            {
                if(micemap[nextx][nexty]=='0')
                {
                    if(micemap[v.back().x][v.back().y]=='*')
                    {
                        micemap[v.back().x][v.back().y]='2';
                        v.pop_back();
                    }
                    putin.x=nextx;
                    putin.y=nexty;
                    micemap[v.back().x][v.back().y]='*';
                    v.push_back(putin);
                    gonextcorrect=1;
                    break;
                }
            }
        }
        if(gonextcorrect==0&&goal==0)
        {
            if(v.size()==1)
            {
                goal=2;
                break;
            }
            micemap[v.back().x][v.back().y]='2';
            v.pop_back();

        }

    }
    /*for (int i=0;i<v.size();i++)
        cout << v[i].x << v[i].y<<endl;*/
    //out put map and set s back
    if(goal==1)
    {
        micemap[v.front().x][v.front().y]='s';
        micemap[v.back().x][v.back().y]='*';
        for (int i = 0; i<x; ++i) {
            for (int j = 0; j < y; ++j) {
                if(micemap[i][j]=='2')
                    cout<<"0";
                else cout<<micemap[i][j];
            }
            cout<<endl;
        }
        cout<< v.size()<<" steps"<<endl;
    }
    if(goal==2)
        cout<<"No route"<<endl;
    delete [] micemap;
    return 0;
}
