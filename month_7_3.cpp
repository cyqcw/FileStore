#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int m;
        scanf("%d",&m);
        vector<int> nums(m);
        for(int i=0;i<m;i++)scanf("%d",&nums[i]);
        sort(nums.begin(),nums.end());
        for(int i=0;i<m-1;i++)printf("%d ",nums[i]);
        printf("%d\n",nums[m-1]);
    }
}