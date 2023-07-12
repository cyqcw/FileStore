#include<bits/stdc++.h>
using std::vector;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int>nums(n+1);
    vector<int>sum(n+1,0);
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
        sum[i+1]=sum[i]+nums[i];
    }
    
    while(m--){
        int start,end;
        scanf("%d%d",&start,&end);
        printf("%d\n",sum[end]-sum[start-1]);
    }
}