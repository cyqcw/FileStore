#include<bits/stdc++.h>
using std::vector;
int isIn(vector<int>&nums,int index,int val){
    for(int i=0;i<index;i++){
        if(nums[i]==val)return 1;
    }return 0;
}
void getRes(vector<int>&nums,int index,int n){
    if(index>=n){
        for(int i=0;i<n;i++){
            printf("%d ",nums[i]);
        }printf("\n");
    }
    else{
        for(int i=1;i<=n;i++){
            if(!isIn(nums,index,i)){
                nums[index]=i;
                getRes(nums,index+1,n);
            }
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    vector<int>nums(n,0);
    getRes(nums,0,n);
}