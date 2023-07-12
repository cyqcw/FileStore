#include<cstdio>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<numeric>
using std::vector;
using std::cin;
#define MAXN 100
void push(char* src,vector<int>&res,int i){
    src[i]=!(src[i]-'0')+'0';
    if(i!=0){
        src[i-1]=!(src[i-1]-'0')+'0';
    }
    if(i!=res.size()-1){
        src[i+1]=!(src[i+1]-'0')+'0';
    }
    res[i]=!res[i];
}
int isOk(char* src,const char* tar,vector<int>& res,int index,int n){
    if(index==n){
        if(strcmp(src,tar)==0){
            int sum=accumulate(res.begin(),res.end(),0);
            return sum;
        }return 0;
    }else{
        //  不按行不行
        int count=isOk(src,tar,res,index+1,n);
        if(count)return count;
        //  按了行不行
        push(src,res,index);
        count=isOk(src,tar,res,index+1,n);
        if(count)return count;
        else {
            push(src,res,index);
            return 0;
        }
    }
}
int main(){
    char src[MAXN]={0};
    char tar[MAXN]={0};
    scanf("%s%s",src,tar);
    int n=strlen(src);
    vector<int> res(n,0);
    int result=isOk(src,tar,res,0,n);
    if(result){
        printf("%d\n",result);
    }else{
        printf("impossible\n");
    }
}