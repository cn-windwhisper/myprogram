#include<stdio.h>
#include<string.h>

long long num;

int main()
{
    while(scanf("%lld",&num)!=EOF)
    {
        long long k=2;
        long long ans;
       // printf("==============\n");
        for(long long i=1;i<=num;i++)
        {
            ans=(i+1)*(i+1)*i-k;
            printf("%lld\n",ans);
            k=i;
        }

    }
    return 0;
}
