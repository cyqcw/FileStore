#include<bits/stdc++.h>
using std::vector;
int main(){
    int n;
    scanf("%d",&n);
    vector<int>nums(n);
    for(int i=0;i<n;i++)scanf("%d",&nums[i]);
    sort(nums.begin(),nums.end());
    for(int ele:nums){
        printf("%d ",ele);
    }
}