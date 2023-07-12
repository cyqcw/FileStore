#include<bits/stdc++.h>
using std::vector;
void bfs(vector<vector<int>>&nums,vector<vector<int>>&ans,int i,int j){
    int n=nums.size();
    int m=nums[0].size();
    if(i<0 || i>=n)return;
    if(j<0 || j>=m)return;
    //  左右
    if(j!=0){
        if(nums[i][j-1]==-1 || nums[i][j-1]>nums[i][j]+1){
            nums[i][j-1]=nums[i][j]+1;  //  更新
            // bfs(nums,i,j-1);
            vector<int>temp={i,j-1};
            ans.push_back(temp);
        }
    }
    if(j!=m-1){
        if(nums[i][j+1]==-1 || nums[i][j+1]>nums[i][j]+1){
            nums[i][j+1]=nums[i][j]+1;  //  更新
            // bfs(nums,i,j+1);
            vector<int>temp={i,j+1};
            ans.push_back(temp);
        }
    }
    //  上下
    if(i!=0){
        if(nums[i-1][j]==-1 || nums[i-1][j]>nums[i][j]+1){
            nums[i-1][j]=nums[i][j]+1;  //  更新
            // bfs(nums,i-1,j);
            vector<int>temp={i-1,j};
            ans.push_back(temp);
        }
    }
    if(i!=n-1){
        if(nums[i+1][j]==-1 || nums[i+1][j]>nums[i][j]+1){
            nums[i+1][j]=nums[i][j]+1;  //  更新
            // bfs(nums,i+1,j);
            vector<int>temp={i+1,j};
            ans.push_back(temp);
        }
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%*c");
    vector<vector<int>>nums(n);
    vector<vector<int>>ans; //  记录所有的0
    //  使得在的地方初始值为0,不在的地方初始值为-1
    for(int i=0;i<n;i++){
        vector<int>line(m);
        for(int j=0;j<m;j++){
            char temp;
            scanf("%c",&temp);
            line[j]=temp-'0'-1;
            if(line[j]==0){
                vector<int>temp={i,j};
                ans.push_back(temp);
            }
        }scanf("%*c");
        nums[i]=line;
    }

    //  bfs
    int start=0,end=ans.size();
    while(start<end){
        int temp=end;
        while(start<temp){
            bfs(nums,ans,ans[start][0],ans[start][1]);
            start++;
        }end=ans.size();
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",nums[i][j]);
        }printf("\n");
    }
}