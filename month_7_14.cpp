#include<bits/stdc++.h>
using std::vector;
int isIn(vector<char>&used,char val,int index){
    for(int i=0;i<index;i++){
        if(used[i]==val)return 1;
    }return 0;
}
void dfs(vector<char>&nums,int index,int n,char* str){
    if(index==n){
        for(int ele:nums){
            printf("%c",ele);
        }printf("\n");
    }else{
        for(int i=0;i<n;i++){
            if(!isIn(nums,str[i],index)){
                nums[index]=str[i];
                dfs(nums,index+1,n,str);
            }
        }
    }
}
int main(){
    char str[100];
    scanf("%s",str);
    int n=strlen(str);
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i;j<n;j++){
            if(str[j]<str[min])min=j;
        }
        char temp=str[min];
        str[min]=str[i];
        str[i]=temp;
    }
    vector<char>nums(n);
    dfs(nums,0,n,str);
}
