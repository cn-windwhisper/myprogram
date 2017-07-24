#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

char input[100010];
int n,k;
int ans;
int flag1,flag2;
int key;
int findans(char yy)
{
    flag1=0;
    key=0;
    int conclusion=0;
    for(int i=0; i<n; i++)
    {
        if(input[i]!=yy)
        {
            key++;
            if(key>k)
            {
                conclusion=max(conclusion,i-flag1);
                while(input[flag1]==yy)
                {
                    flag1++;
                }
                flag1++;
                key--;
            }
        }
    }
    conclusion=max(conclusion,n-flag1);
    return conclusion;
}

int main()
{
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        scanf("%s",input);
        ans=findans('a');
        ans=max(ans,findans('b'));
        printf("%d\n",ans);
    }
    return 0;
}


