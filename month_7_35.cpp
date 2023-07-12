#include<bits/stdc++.h>
using std::vector;
//  每一个都有选或不选两种状态
void getRes(vector<int>&nums,int index,int left,int n){
    if(index>=n && left==0){
        for(int i=0;i<n;i++){
            if(nums[i])printf("%d ",i+1);
        }printf("\n");        
    }else if(index>=n)return;
    else{
        nums[index]=1;
        getRes(nums,index+1,left-1,n); 
        nums[index]=0;               
        getRes(nums,index+1,left,n);
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int>nums(n,0);
    getRes(nums,0,m,n);
}