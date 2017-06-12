#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

struct XX
{
    int a,b,c;
};

struct YY
{
    int a,number;
    long long theans;
};

XX edge[60000];
YY ques[20000];
int n,m,q;
int bcarray[10010];
int pointnumber[10010];

int cmp1(XX x,XX y)
{
    return x.c<y.c;
}
int cmp2(YY x,YY y)
{
    return x.a<y.a;
}
int cmp3(YY x,YY y)
{
    return x.number<y.number;
}

int father(int x)
{
    if(bcarray[x]==x)
        return x;
    else
    {
        int pp=father(bcarray[x]);
        bcarray[x]=pp;
        return pp;
    }
}


int main()
{
    while(scanf("%d%d%d",&n,&m,&q)!=EOF)
    {
         for(int i=0;i<m;i++)
            scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].c);
         for(int i=0;i<q;i++)
         {
            scanf("%d",&ques[i].a);
            ques[i].number=i;
         }
         for(int i=0;i<=n;i++)
         {
             bcarray[i]=i;
             pointnumber[i]=1;
         }

         sort(edge,edge+m,cmp1);
         sort(ques,ques+q,cmp2);

         long long ans=0;
         int flag=0;
         for(int i=0;i<m;i++)
         {
             while(ques[flag].a<edge[i].c)
             {
                 if(flag>=q)
                    break;
                 ques[flag].theans=ans;
                 flag++;
                 if(flag>=q)
                    break;
             }
             int f1=father(edge[i].a);
             int f2=father(edge[i].b);
             if(f1!=f2)
             {
                 bcarray[f1]=bcarray[f2];
                 ans+=pointnumber[f1]*pointnumber[f2];
                 pointnumber[f2]=pointnumber[f1]+pointnumber[f2];
             }
         }

         for(int i=flag;i<q;i++)
         {
              ques[i].theans=ans;
         }


         sort(ques,ques+q,cmp3);

         //printf("=================\n");
         for(int i=0;i<q;i++)
         {
             printf("%lld\n",ques[i].theans);
         }
    }
    return 0;
}






