#include<stdio.h>
#include<string.h>
#include<algorithm>
///注意开始给的数据可能是无须的注意排序问题
///注意初始值的准确设定
using namespace std;

struct XX
{
    double matrix[2][2];
};
int n;
double p;
int mine[12];
double ans[2];
XX intermediary;
XX standard;

XX productXX(XX a,XX b)
{
    XX theans;
    theans.matrix[0][0]=a.matrix[0][0]*b.matrix[0][0]+a.matrix[0][1]*b.matrix[1][0];
    theans.matrix[0][1]=a.matrix[0][0]*b.matrix[0][1]+a.matrix[0][1]*b.matrix[1][1];
    theans.matrix[1][0]=a.matrix[1][0]*b.matrix[0][0]+a.matrix[1][1]*b.matrix[1][0];
    theans.matrix[1][1]=a.matrix[1][0]*b.matrix[0][1]+a.matrix[1][1]*b.matrix[1][1];
    return theans;
}

XX multiplication(XX a,int n)
{
    XX theans;
    ///========
     theans.matrix[0][0]=1;
     theans.matrix[0][1]=0;
     theans.matrix[1][0]=0;
     theans.matrix[1][1]=1;
    ///========
    while(n)
    {
        if(n%2==1)
        {
            theans=productXX(theans,a);
        }
        n/=2;
        a=productXX(a,a);
    }
    return theans;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%lf",&p);
        for(int i=0;i<n;i++)
            scanf("%d",&mine[i]);

        sort(mine,mine+n);
        if(mine[0]==1)
        {
            printf("0.0000000\n");
            continue;
        }

        ans[0]=1;
        ans[1]=p;
        int i=0;
        if(mine[i]==2)
        {
            i++;
            ans[1]=0;
        }
        ///multiplication
        standard.matrix;
        standard.matrix[0][0]=0;
        standard.matrix[0][1]=1-p;
        standard.matrix[1][0]=1;
        standard.matrix[1][1]=p;

        int flag=2;
        //printf("====%.7lf %.7lf==\n",ans[0],ans[1]);
        for(i;i<n;i++)
        {
            intermediary=multiplication(standard,mine[i]-flag);
            flag=mine[i];
            ans[0]=ans[0]*intermediary.matrix[0][0]+ans[1]*intermediary.matrix[1][0];
            ans[1]=0;
          //  printf("====%.7lf %.7lf==\n",ans[0],ans[1]);
        }
        double output;
        output=ans[0]*(1-p);
        printf("%.7f\n",output);
    }
    return 0;
}
