#include<bits/stdc++.h>
using std::vector;
int isIn(vector<int>&nums,int val){
    for(int ele:nums){
        if(ele==val)return 1;
    }return 0;
}
int main(){
    int n;
    scanf("%d",&n);
    
    while(n--){
        int x;
        scanf("%d",&x);
        vector<int>nums;
        for(int i=1;i<=sqrt(x);i++){
            if(x%i==0){
                nums.push_back(i);
                if(i!=x/i)nums.push_back(x/i);
            }
        }
        sort(nums.begin(),nums.end());
        for(int ele:nums){
            printf("%d ",ele);
        }printf("\n");
    }
}