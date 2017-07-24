#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;
struct XX
{
    char a[13];
    char b[13];
};
struct YY
{
    long long a,b;
};
int n;
int num;
XX input[300000];
YY theinput[300000];
long long flagcolor[600000];
long long color[600000];
int colornumber[600000];


int bcarray[600000];

int father(int x)
{
    if(bcarray[x]==x)
    {
        return x;
    }
    else
    {
        int kk=father(bcarray[x]);
        bcarray[x]=kk;
        return kk;
    }
}

int bcmerge(int x,int y)
{
    int flag1=father(x);
    int flag2=father(y);
    bcarray[flag1]=bcarray[flag2];
    return 0;
}

int ff(int l,int r,long long x)
{
    int mid=(l+r)/2;
    if(color[mid]==x)
    {
        return mid;
    }
    else if(color[mid]<x)
    {
        return ff(mid+1,r,x);
    }
    else
    {
        return ff(l,mid,x);
    }
}

int findgrade(long long x)
{
    return ff(0,num-1,x);
}

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s%s",input[i].a,input[i].b);
        }

        for(int i=0;i<n;i++)
        {
            int len;
            long long coefficient=1;
            len=strlen(input[i].a);
            flagcolor[i*2]=0;
            for(int j=0;j<len;j++)
            {
                flagcolor[i*2]+=(input[i].a[j]-'a')*coefficient;
                coefficient*=30;
            }
            theinput[i].a=flagcolor[i*2];


            coefficient=1;
            len=strlen(input[i].b);
            flagcolor[i*2+1]=0;
            for(int j=0;j<len;j++)
            {
                flagcolor[i*2+1]+=(input[i].b[j]-'a')*coefficient;
                coefficient*=30;
            }

            theinput[i].b=flagcolor[i*2+1];
        }

        sort(flagcolor,flagcolor+n*2);
        num=0;
        int oddnumber=0;
        int thiscolornum=1;
        for(int i=1;i<n*2;i++)
        {
            if(flagcolor[i]!=flagcolor[i-1])
            {
                color[num]=flagcolor[i-1];
                colornumber[num]=thiscolornum;
                if(thiscolornum%2==1)
                    oddnumber++;
                num++;
            }
            else
            {
                thiscolornum++;
            }
        }
        color[num]=flagcolor[n*2-1];
        colornumber[num]=thiscolornum;
        if(thiscolornum%2==1)
            oddnumber++;
        num++;


        for(int i=0;i<=num;i++)
        {
            bcarray[i]=i;
        }
        for(int i=0;i<n;i++)
        {
            bcmerge(findgrade(theinput[i].a),findgrade(theinput[i].b));
        }

        int cuo=0;
        if(oddnumber>2||oddnumber==1)
            cuo=1;

        int ancestor;
        ancestor=father(0);
        for(int i=0;i<num;i++)
        {
            if(ancestor!=father(i))
            {
                cuo=1;
                break;
            }
        }

        if(cuo==1)
        {
            printf("Impossible\n");
        }
        else
        {
            printf("Possible\n");
        }
    }
    return 0;
}





