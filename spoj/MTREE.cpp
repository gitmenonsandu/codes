#include <bits/stdc++.h>
#define mod 1000000007
#define twoInv 500000004
using namespace std;
long long n;
vector<pair<long long,long long> >adj[100005];
bool visited[100005];
long long treeWt[100005];
long long pathWt[100005];
long long par[100005];
void dfs(long long r)
{
    if(visited[r])
        return ;

    pair<long long,long long> u;
    long long sigma=0,pu=0,sigmaSq=0,ans=0;
    for(long long i=0;i<adj[r].size();++i)
    {
        u=adj[r][i];
        if(par[r]!=u.first)
        {
            par[u.first]=r;
            dfs(u.first);
            pu=(u.second+u.second*pathWt[u.first])%mod;
            sigma+=pu;
            sigma%=mod;

            sigmaSq+=(pu*pu)%mod;
            sigmaSq%=mod;

            ans+=treeWt[u.first];
            ans%=mod;
        }
    }
    ans+=sigma;
    ans%=mod;
    ans+=(((sigma*sigma-sigmaSq)%mod)*twoInv)%mod;
    ans%=mod;
    pathWt[r]=sigma;
    visited[r]=true;
    treeWt[r]=ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    long long a,b,w;
    for(long long i=0;i<=n;++i)
    {
        if(i<n-1){
            cin>>a>>b>>w;
            adj[a].push_back(make_pair(b,w));
            adj[b].push_back(make_pair(a,w));
        }
        par[i]=-1;
        treeWt[i]=0;
        pathWt[i]=0;
        visited[i]=false;
    }

    dfs(1);
    cout<<treeWt[1];

	return 0;
}
