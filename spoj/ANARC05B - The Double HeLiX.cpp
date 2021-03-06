#include<bits/stdc++.h>
using namespace std;
long long a[10004],b[10004];
long long solve(long long n1,long long n2)
{
    long long k=0,sum1=0,sum2=0,ans=0,i=0,j=0;
    while(i<n1 and j<n2){
        if(a[i]<b[j]){
            sum1+=a[i];
            i++;
        }
        else if(a[i]>b[j]){
            sum2+=b[j];
            j++;
        }
        else
        {
            ans=ans+a[i]+max(sum1,sum2);
            sum1=sum2=0;
            i++;
            j++;
        }
    }
    while(i<n1){
        sum1+=a[i];
        i++;
    }
    while(j<n2){
        sum2+=b[j];
        j++;
    }
    ans+=max(sum1,sum2);
    return ans;
    

}
int main() {

    long long n1,n2;
    while(true){
        scanf("%lld",&n1);
       if(n1==0)
            break;
       for(long long i=0;i<n1;++i)
            scanf(" %lld",&a[i]);
        scanf(" %lld",&n2);
        for(long long i=0;i<n2;++i)
            scanf(" %lld",&b[i]);
        long long ans=solve(n1,n2);

        printf("%lld\n",ans);
    }
    return 0;
}
