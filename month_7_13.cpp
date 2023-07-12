#include<bits/stdc++.h>
using std::vector;
int isIn(vector<int>&used,int val,int index){
    for(int i=0;i<index;i++){
        if(used[i]==val)return 1;
    }return 0;
}
void dfs(vector<int>&nums,int index,int n){
    if(index==n){
        for(int ele:nums){
            printf("%d ",ele);
        }printf("\n");
    }else{
        for(int i=1;i<=n;i++){
            if(!isIn(nums,i,index)){
                nums[index]=i;
                dfs(nums,index+1,n);
            }
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    vector<int>nums(n);
    dfs(nums,0,n);
}
