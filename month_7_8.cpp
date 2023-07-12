#include<cstdio>
#include<vector>
#include<algorithm>
using std::vector;
bool compare(vector<int>& ans1,vector<int>& ans2){
    if(ans1[0]!=ans2[0])return ans1[0]<ans2[0];
    if(ans1[1]!=ans2[1])return ans1[1]<ans2[1];
    return ans1[2]<ans2[2];
}
int main(){
    int target,n;
    scanf("%d%d",&target,&n);
    vector<int> nums;
    vector<vector<int>> res;
    //  读入顺便去重
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        if(nums.empty())nums.push_back(temp);
        else if(nums[nums.size()-1]!=temp)nums.push_back(temp);
    }
    sort(nums.begin(),nums.end());
    n=nums.size();
    //  加入到三元组
    for(int i=1;i<n-1;i++){
        int temp=target-nums[i];
        int start=0,end=n-1;
        while(start<i && i<end){
            if(nums[start]+nums[end]>temp)end--;
            else if(nums[start]+nums[end]<temp)start++;
            else{
                vector<int> ans={nums[start],nums[i],nums[end]};
                res.push_back(ans);
                start++;
                end--;
            }
        }
    }
    sort(res.begin(),res.end(),compare);
    for(int i=0;i<res.size();i++){
        printf("%d %d %d\n",res[i][0],res[i][1],res[i][2]);        
    }
}