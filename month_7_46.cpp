#include<bits/stdc++.h>
#define PI 3.1415926535897932384626
#define MIN 1e-6
using std::vector;
int canUse(vector<int>&nums,int k,double val){
    int count=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        count+=(int)(nums[i]/val);
    }
    if(count>=k)return 1;
    return 0;
}
double binary(vector<int>&nums,int k){
    double start=nums[0]*1.0/k;
    double end=nums[nums.size()-1];
    while(end-start>MIN){
        double mid=(end+start)/2;
        // printf("start=%f,end=%f,mid=%f\n",start,end,mid);
        if(canUse(nums,k,mid))start=mid+MIN;
        else end=mid;
    }return start;
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    k++;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
        nums[i]*=nums[i];
    }
    sort(nums.begin(),nums.end());
    double res=binary(nums,k);
    printf("%.3f\n",res*PI);
}