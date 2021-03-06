#include <bits/stdc++.h>
#define mod 100000000
using namespace std;
vector<pair<long long,long long> > v;
vector<long long> endArr;
map<long long,long long> dp;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(true)
    {
        dp.clear();
        v.clear();
        endArr.clear();
        cin>>n;
        if(n==-1)
            return 0;

        long long s,e;
        for(int i=0;i<n;++i)
        {
            cin>>s>>e;
            v.push_back(make_pair(e,s));
        }

        sort(v.begin(),v.end());
        for(int i=0;i<v.size();++i)
            endArr.push_back(v[i].first);

        int endt,startTime;
        vector<long long>::iterator startt;

        for(int i=0;i<n;++i)
        {
            if(i==0)
            {
                endt=endArr[i];
                dp[endt]=1;
                continue;
            }

            endt=endArr[i];

            if(v[i].second<endArr[0])
            {
                startTime=0;
            }
            else
            {
                startt=upper_bound(endArr.begin(),endArr.end(),v[i].second)-1;
                startTime=*startt;
                //cout<<startTime<<endl;
                startTime=dp[startTime];
            }

            //cout<<i<<" "<<startTime<<" "<<endt<<endl;
            if(dp.find(endt)==dp.end())
            {
                    dp[endt]=(dp[endArr[i-1]]%mod+1+startTime%mod)%mod;
            }
            else
            {
                    if(endt==endArr[i-1])
                        dp[endt]=(dp[endt]%mod+1+startTime%mod)%mod;
                    else
                        dp[endt]=(dp[endt]%mod+dp[endArr[i-1]]%mod+1+startTime%mod)%mod;

            }
            if(dp[endt]>=mod)
                    dp[endt]=dp[endt]%mod;

            //cout<<dp[endt]<<endl;
        }

        stringstream mystream;
        mystream << dp[endArr[n-1]];
        string ans = mystream.str();
        if(ans.size()<8)
        {
            while(ans.size()<8)
                ans.insert(0,"0");
        }
        cout<<ans<<endl;

    }

    return 0;
}
