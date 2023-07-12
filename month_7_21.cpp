#include<bits/stdc++.h>
using std::vector;
int main(){
    int n,k;
    scanf("%d",&n);
    vector<int>nums(n);
    for(int i=0;i<n;i++)scanf("%d",&nums[i]);
    scanf("%d",&k);
    sort(nums.begin(),nums.end());
    int index=nums.size()-1;
    while(k--){
        printf("%d\n",nums[index--]);
    }
}