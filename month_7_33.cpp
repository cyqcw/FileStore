#include<bits/stdc++.h>
using std::vector;
using std::cout;
int main(){
    int n,t;
    scanf("%d",&n);
    vector<int>nums(n);
    for(int i=0;i<n;i++)scanf("%d",&nums[i]);
    scanf("%d",&t);
    while(t--){
        int val;
        scanf("%d",&val);
        auto it=std::find(nums.begin(),nums.end(),val);
        if(it!=nums.end()){
            printf("%d\n",it-nums.begin());
        }else printf("-1\n");
    }
}