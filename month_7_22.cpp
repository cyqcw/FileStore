#include<bits/stdc++.h>
#define MAXN 100
using std::vector;
void MergeSort(vector<int>&a,int start,int end){
    if(start>=end)return;
    int mid=(start+end)/2;
    //  递归把两部分都归并好
    MergeSort(a,start,mid);
    MergeSort(a,mid+1,end);
    //  处理
    int temp[MAXN]={0},index=0;
    int i=start,j=mid+1;
    while(i<=mid && j<=end){
        if(a[i]<=a[j])temp[index++]=a[i++];
        else temp[index++]=a[j++];
    }while(i<=mid)temp[index++]=a[i++];
    while(j<=end)temp[index++]=a[j++];
    for(int i=start;i<=end;i++)a[i]=temp[i-start];
}
int main(){
    int n;
    scanf("%d",&n);
    vector<int> nums(n);
    for(int i=0;i<n;i++)scanf("%d",&nums[i]);
    MergeSort(nums,0,nums.size()-1);
    for(int ele:nums){
        printf("%d ",ele);
    }printf("\n");
}