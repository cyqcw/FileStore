#include<bits/stdc++.h>
using std::vector;
//  每一个都有选或不选两种状态
void getRes(vector<int>&nums,int index,int n){
    if(index>=n){
        for(int i=0;i<n;i++){
            if(nums[i])printf("%d ",i+1);
        }printf("\n");        
    }
    else{
        getRes(nums,index+1,n);
        nums[index]=1;
        getRes(nums,index+1,n);
        nums[index]=0;        
    }
}
int main(){
    int n;
    scanf("%d",&n);
    vector<int>nums(n,0);
    getRes(nums,0,n);
}