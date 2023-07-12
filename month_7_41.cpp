#include<bits/stdc++.h>
using std::map;
map<int,int>nums;
const int MOD=1e9+7;
typedef long long ll;
void getApp(ll x){
    for(ll i=2;i<=x/i;i++){
        while(x%i==0){
            nums[i]++;
            x/=i;
        }
    }
    if(x>1)nums[x]++;
}
ll quick_pow(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=(res*a)%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        ll temp;
        scanf("%lld",&temp);
        getApp(temp);
    }
    ll ans=1;
    for(auto mp:nums){
        ll sum=0;
        for(int i=0;i<=mp.second;i++){
            sum=(sum+quick_pow(mp.first,i))%MOD;
        }
        ans=ans*sum%MOD;
    }
    printf("%lld\n",ans);
}