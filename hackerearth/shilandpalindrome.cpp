#include<bits/stdc++.h>
using namespace std;
int bit[100005][26];
int n;
void update(int idx,int val,int pos)
{
    while(idx<=n)
    {
        bit[idx][pos]+=val;
        idx+=(idx&-idx);
    }
}
int query(int idx,int pos)
{
    int sum=0;
    while(idx>0)
    {
        sum+=bit[idx][pos];
        idx-=(idx&-idx);
    }
    return sum;
}
int main()
{
    int q;
    scanf("%d %d",&n,&q);
    string s;
    cin>>s;
    for(int i=0;i<n;++i)
        update(i+1,1,s[i]-97);
    int ch,l,r;
    char c;
    while(q--)
    {
        scanf("%d",&ch);
        if(ch==1)
        {
            scanf("%d %c",&l,&c);
            update(l,-1,s[l-1]-97);
            update(l,1,c-97);
            s[l-1]=c;
        }
        else
        {
            scanf("%d %d",&l,&r);
            int cnt=0,od=0;
            for(int i=0;i<26;++i)
            {
                cnt=query(r,i)-query(l-1,i);
                if(cnt&1)
                    od++;

            }
            if((l-r+1)&1)
                od--;
            if(od)
                printf("no\n");
            else
                printf("yes\n");
        }
    }

    return 0;

}
