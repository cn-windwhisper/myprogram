#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int num;
int input[100010];
int segtree[400010];
int segmaxpoint[400010];
long long dpans[100010];
int themaxpoint;
int themaxnumber;
int buildtree(int l,int r,int n)
{
    if(l==r)
    {
        segmaxpoint[n]=l;
        segtree[n]=input[l];
        return 0;
    }
    int mid=(l+r)/2;
    buildtree(l,mid,n*2);
    buildtree(mid+1,r,n*2+1);
    if(segtree[n*2]>segtree[n*2+1])
    {
        segmaxpoint[n]=segmaxpoint[n*2];
        segtree[n]=segtree[n*2];
    }
    else
    {
        segmaxpoint[n]=segmaxpoint[n*2+1];
        segtree[n]=segtree[n*2+1];
    }
    return 0;
}

int findtree(int tarl,int tarr,int l,int r,int n)
{
    if(l==tarl&&r==tarr)
    {
        if(themaxnumber<=segtree[n])
        {
            themaxnumber=segtree[n];
            themaxpoint=segmaxpoint[n];
        }
        return segtree[n];
    }
    int mid=(l+r)/2;
    if(mid<tarl)
        return findtree(tarl,tarr,mid+1,r,n*2+1);
    else if(mid>=tarr)
        return findtree(tarl,tarr,l,mid,n*2);
    else
        return max(findtree(tarl,mid,l,mid,n*2),findtree(mid+1,tarr,mid+1,r,n*2+1));
}

int main()
{
    while(scanf("%d",&num)!=EOF)
    {
        for(int i=1;i<num;i++)
        {
            scanf("%d",&input[i]);
        }
        input[num]=0;
       // printf("======1===\n");
        buildtree(1,num,1);
       // printf("======2===\n");
        dpans[num]=0;
        long long finalans=0;
        for(int i=num-1;i>=1;i--)
        {
            themaxnumber=0;
        //    printf("====%d====%d===\n",i+1,input[i]);
            int themaxlong=findtree(i+1,input[i],1,num,1);
            dpans[i]=(num-i+dpans[themaxpoint])-(input[i]-themaxpoint);
            finalans+=dpans[i];
        }
        printf("%lld\n",finalans);
    }
    return 0;
}
