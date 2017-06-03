#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int num;
struct XX
{
    int number;
    int a,b;
    int choose;
};
XX input[1010];
char p1[22],p2[22];

int cmp1(XX x,XX y)
{
    return x.b<y.b;
}
int cmp2(XX x,XX y)
{
    return x.number<y.number;
}
int main()
{
    while(scanf("%d",&num)!=EOF)
    {
        for(int i=0;i<num;i++)
        {
            scanf("%s%s",p1,p2);
            input[i].number=i;
            input[i].a=p1[0]*10000+p1[1]*100+p1[2];
            input[i].b=p1[0]*10000+p1[1]*100+p2[0];
            input[i].choose=2;
        }
        sort(input,input+num,cmp1);
        int cuo=0;
        int repeat=1;
        int last=input[0].b;
        int can1,can2;
        for(int i=1;i<num;i++)
        {
            if(input[i].b==input[i-1].b)
                repeat++;
            else
                repeat=1;

            if(repeat==2)
            {
                if(input[i].b==input[i+1].b)
                {
                    cuo=1;
                    break;
                }
                else
                {
                    can1=1;
                    can2=1;
                    for(int j=0;j<num;j++)
                    {
                        if(j==i)
                            continue;
                        if(input[i-1].a==input[j].a||input[i-1].a==input[j].b)
                            can1=0;
                        if(input[i].a==input[j].a||input[i].a==input[j].b)
                            can2=0;
                    }
                    if(can1==0&&can2==0)
                    {
                        cuo=1;
                        break;
                    }
                    if(can1==1)
                    {
                        input[i-1].choose=1;
                    }
                    else
                    {
                        input[i].choose=1;
                    }
                }
            }

        }
        if(cuo==1)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
            sort(input,input+num,cmp2);
            for(int i=0;i<num;i++)
            {
                if(input[i].choose==1)
                    printf("%c%c%c\n",input[i].a/10000,(input[i].a%10000)/100,input[i].a%100);
                else
                    printf("%c%c%c\n",input[i].b/10000,(input[i].b%10000)/100,input[i].b%100);
            }
        }

    }

    return 0;
}

