#include<bits/stdc++.h>
using std::vector;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int>nums(n);
    for(int i=0;i<n;i++)scanf("%d",&nums[i]);
    sort(nums.begin(),nums.end());
    printf("%d\n",nums[k-1]);
}