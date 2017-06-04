#include<stdio.h>
#include<string.h>

int number[300010],readed[300010],inputa[300010],inputb[300010],san[300010];
int n,p;
int ans;
int flag;
int main()
{
    while(scanf("%d%d",&n,&p)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            number[i]=0;
            readed[i]=0;
            san[i]=0;
        }
        for(int i=0;i<p;i++)
        {
            scanf("%d%d",&inputa[i],&inputb[i]);
        }
        ans=0;
        flag=0;
        for(int i=0;i<p;i++)
        {
            if(inputa[i]==1)
            {
                ans++;
                number[inputb[i]]++;
                printf("%d\n",ans);
            }
            else if(inputa[i]==2)
            {
                ans-=(number[inputb[i]]-readed[inputb[i]]);
                readed[inputb[i]]=number[inputb[i]];
                printf("%d\n",ans);
            }
            else
            {

            }
        }

    }


    return 0;
}




