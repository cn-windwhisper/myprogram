#include<stdio.h>
#include<string.h>


int givebnum(int a,int b)
{
    if(2*a>3*b)
    {
        if(a%3==0||a%3==1)
        {
            return (2*a-3*b)/6;
        }
        else
        {
            if(b%2==1)
            {
                return (2*a-3*b)/6;
            }
            else
            {
                return (2*a-3*b)/6+1;
            }
        }
    }
    else
    {
        if(b%2==0)
        {
            if(a%3==1)
            {
                return ((3*b-2*a)/6)*2+1;
            }
            else
            {
                return ((3*b-2*a)/6)*2;
            }
        }
        else
        {
            if(a%3==1)
            {
                return ((3*b-2*a)/6)*2;
            }
            else
            {
                return ((3*b-2*a)/6)*2+1;
            }
        }
    }
}

int main()
{
    int a,b;
    int ans;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
         int k;
         int bnum;
         if(2*a>3*b)
         {
             k=b/2;
             bnum=givebnum(a,b);
             if(bnum>=k)
             {
                 ans=2*a;
             }
             else
             {
                 int flag=k-bnum;
                 int p=flag/4;
                 int psp=2*a+p*6;
                 int q=flag%4;
                 if(psp%6==0)
                 {
                     if(q==0)
                     {
                         ans=psp;
                     }
                     else if(q==1)
                     {
                         ans=psp+2;
                     }
                     else if(q==2)
                     {
                         ans=psp+3;
                     }
                     else
                     {
                         ans=psp+4;
                     }
                 }
                 else if(psp%6==2)
                 {
                     if(q==0)
                     {
                         ans=psp;
                     }
                     else if(q==1)
                     {
                         ans=psp+1;
                     }
                     else if(q==2)
                     {
                         ans=psp+2;
                     }
                     else
                     {
                         ans=psp+4;
                     }
                 }
                 else
                 {
                     if(q==0)
                     {
                         ans=psp;
                     }
                     else if(q==1)
                     {
                         ans=psp+2;
                     }
                     else if(q==2)
                     {
                         ans=psp+4;
                     }
                     else
                     {
                         ans=psp+5;
                     }
                 }

             }

         }
         else
         {
             k=a/3;

             bnum=givebnum(a,b);

           //  printf("bnum==%d,k==%d\n",bnum,k);
             if(bnum>=k)
             {

                 ans=3*b;
             }
             else
             {
                 int flag=k-bnum;
                 int p=flag/4;
                 int psp=3*b+p*6;
                 int q=flag%4;
                 if(psp%6==0)
                 {
                     if(q==0)
                     {
                         ans=psp;
                     }
                     else if(q==1)
                     {
                         ans=psp+2;
                     }
                     else if(q==2)
                     {
                         ans=psp+3;
                     }
                     else
                     {
                         ans=psp+4;
                     }
                 }
                 else
                 {
                     if(q==0)
                     {
                         ans=psp;
                     }
                     else if(q==1)
                     {
                         ans=psp+1;
                     }
                     else if(q==2)
                     {
                         ans=psp+3;
                     }
                     else
                     {
                         ans=psp+5;
                     }
                 }
             }
         }

         printf("%d\n",ans);

    }
    return 0;
}



