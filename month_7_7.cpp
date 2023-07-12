#include<stdio.h>
#include<vector>
using std::vector;
int main(){
    int target,n;
    scanf("%d%d",&target,&n);
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    int start=0,end=n-1;
    while(start<end){
        if(nums[start]+nums[end]>target)end--;
        else if(nums[start]+nums[end]<target)start++;
        else{
            printf("%d %d\n",start,end);
            break;
        }
    }
}