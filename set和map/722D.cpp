#include<stdio.h>
#include<string.h>
#include<set>

using namespace std;

set<int> S;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        S.clear();
        for(int i=0;i<n;i++)
        {
            int p;
            scanf("%d",&p);
            S.insert(p);
        }
        while(1)
        {
            set<int>::iterator it;
            it=S.end();
            it--;
            S.erase(it);
            int sk=*it;
            while(1)
            {
                sk/=2;
                if(S.find(sk)==S.end())
                    break;
            }
            if(sk==0)
            {
                S.insert(*it);
                break;
            }
            else
            {
                S.insert(sk);
            }
        }

        set<int>::iterator it;
        for(it=S.begin();it!=S.end();it++)
        {
            if(it!=S.begin())
                printf(" ");
            printf("%d",*it);
        }
        printf("\n");
    }
    return 0;
}
