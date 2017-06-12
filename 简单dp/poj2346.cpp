#include<stdio.h>
#include<string.h>

int dp[12][12][50];

int main()
{
    for(int i=0;i<=10;i++)
        for(int j=0;j<=10;j++)
            for(int k=0;k<=50;k++)
                dp[i][j][k]=0;
    for(int i=1;i<=5;i++)
    {
        for(int j=0;j<=9;j++)
        {
            if(i==1)
            {
                dp[i][j][j]=1;
                continue;
            }
            for(int k=j;k<=i*9;k++)
            {
                for(int m=0;m<=9;m++)
                {
                    dp[i][j][k]+=dp[i-1][m][k-j];
                }
            }
        }
    }
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int ans=0;
        for(int i=0;i<=(n/2)*9;i++)
        {
            int flag=0;
            for(int j=0;j<=9;j++)
            {
                flag+=dp[n/2][j][i];
            }
            ans+=flag*flag;
        }
        printf("%d\n",ans);
    }


    return 0;
}
