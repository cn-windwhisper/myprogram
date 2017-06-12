#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int n;
int dp[30][30];
int staarray[30];
int stuarray[30];

int main()
{

    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int p;
        scanf("%d",&p);
        staarray[p]=i;
    }
    int p;
    while(scanf("%d",&p)!=EOF)
    {
        stuarray[p]=1;
        for(int i=2;i<=n;i++)
        {
            scanf("%d",&p);
            stuarray[p]=i;
        }
        dp[0][0]=0;
        dp[0][1]=0;
        dp[1][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(staarray[i]==stuarray[j])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        printf("%d\n",dp[n][n]);
    }

    return 0;
}






