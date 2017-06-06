#include<stdio.h>
#include<string.h>
#include<queue>

using namespace std;

struct XX
{
    int x,y,z;
};

char maps[4][1010][1010];
int m,n;
int bx,by;
int ex,ey;
char standard[20]={'+','-','|','^','>','<','v','L','R','U','D','*'};///======
char standardnext[20]={'+','|','-','>','v','^','<','U','D','R','L','*'};///=====
int standarddoor[20][4]={{1,1,1,1},{0,0,1,1},{1,1,0,0},{1,0,0,0},{0,0,0,1},{0,0,1,0},{0,1,0,0},{1,1,0,1},{1,1,1,0},{0,1,1,1},{1,0,1,1},{0,0,0,0}};
int change[4][2]={{-1,0},{1,0},{0,-1},{0,1}};///====
int ans[1010][1010][4];
int backchar[1000];
char thnext(char x)
{
    return standardnext[backchar[x]];
}


int backmv[4]={1,0,3,2};
int okk(int x1,int y1,int x2,int y2,int zt,int mv)
{
    int p1,p2;
    p1=backchar[maps[zt][x1][y1]];
    p2=backchar[maps[zt][x2][y2]];
    if(standarddoor[p1][mv]==1&&standarddoor[p2][backmv[mv]]==1)
        return 1;
    return 0;
}

int main()
{
    for(int i=0;i<12;i++)
    {
        backchar[standard[i]]=i;
    }
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        for(int i=0;i<m;i++)
        {
            scanf("%s",maps[0][i]);
        }

        for(int i=1;i<4;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int k=0;k<n;k++)
                {
                    maps[i][j][k]=thnext(maps[i-1][j][k]);
                }
            }
        }
        scanf("%d%d",&bx,&by);
        scanf("%d%d",&ex,&ey);
        bx--;
        by--;
        ex--;
        ey--;
        memset(ans,0,sizeof(ans));
        /*for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                for(int k=0;k<4;k++)
                {
                    ans[i][j][k]=0;
                }
            }
        }*/
        queue<XX> Q;
        while(!Q.empty())
            Q.pop();
        XX  yy;
        yy.x=bx;
        yy.y=by;
        yy.z=0;
        ans[bx][by][0]=1;
        Q.push(yy);
   //     printf("lllllllll===%c\n",maps[0][0][1]);

        while(!Q.empty())
        {

            yy=Q.front();
            Q.pop();
            int nx,ny;
            for(int i=0;i<4;i++)
            {
                nx=yy.x+change[i][0];
                ny=yy.y+change[i][1];
                if(nx<0||ny<0||nx>=m||ny>=n)
                    continue;
                if(okk(yy.x,yy.y,nx,ny,yy.z,i))
                {
                    if(ans[nx][ny][yy.z]==0||ans[nx][ny][yy.z]>(ans[yy.x][yy.y][yy.z]+1))
                    {
                        XX zz;
                        zz.x=nx;
                        zz.y=ny;
                        zz.z=yy.z;
                        ans[zz.x][zz.y][zz.z]=ans[yy.x][yy.y][yy.z]+1;
                        Q.push(zz);
                    }
                }
            }
            for(int i=1;i<=3;i++)
            {
                if(ans[yy.x][yy.y][(yy.z+i)%4]==0||ans[yy.x][yy.y][(yy.z+i)%4]>(ans[yy.x][yy.y][yy.z]+i))
                {
                    XX zz;
                    zz.x=yy.x;
                    zz.y=yy.y;
                    zz.z=(yy.z+i)%4;
                    ans[yy.x][yy.y][(yy.z+i)%4]=ans[yy.x][yy.y][yy.z]+i;
                    Q.push(zz);
                }
            }
        }
        int anss=9999999;
        for(int i=0;i<4;i++)
        {
            if(ans[ex][ey][i]!=0&&ans[ex][ey][i]<anss)
                anss=ans[ex][ey][i];
        }
        if(anss>=9999999)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n",anss-1);
        }
    }
    return 0;
}







