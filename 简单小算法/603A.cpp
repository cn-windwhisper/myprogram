#include<stdio.h>
#include<string.h>

char input[100100];
int n;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%s",input);
        if(n==1)
        {
            printf("1\n");
            continue;
        }
        int threecont=0;
        int ans=1;
        char flag=input[0];
        for(int i=1;i<n;i++)
        {
            if(input[i]!=flag)
            {
                ans++;
                flag=input[i];
            }
        }
        int divis=0;
        for(int i=0;i<n-1;i++)
        {
            if(input[i]==input[i+1])
            {
                divis++;
            }
        }
        if(divis>=2)
        {
            ans+=2;
        }
        else
        {
            ans+=divis;
        }
        printf("%d\n",ans);
    }

    return 0;
}
