#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
//  全部

int isOk(int** nums){
    for(int i=1;i<5;i++){
        for(int j=0;j<6;j++){
            if(nums[i-1][j])push(nums,i,j);
        }
    }
    for(int j=0;j<6;j++){
        if(nums[4][j])return 0;
    }return 1;
}

void show(int** res){
    for(int i=0;i<5;i++){
        for(int j=0;j<6;j++){
            printf("%d ",res[i][j]);
        }printf("\n");
    }
}
int dfs(int** res,int** nums,int index){
    if(index==6){
        if(isOk(nums)){
            show(res);
            return 1;
        }
    }else{
        for(int i=0;i<2;i++){
            if(i){push(nums,0,index);
            // else push(nums,0,index);
            if(dfs(res,nums,index+1))return 1;
            else if(i)push(nums,0,index);
        }
    }

}

int main(){
    int** nums=(int**)malloc(5*sizeof(int*));
    int** res=(int**)malloc(5*sizeof(int*));
    for(int i=0;i<5;i++){
        nums[i]=(int*)malloc(6*sizeof(int));
        res[i]=(int*)malloc(6*sizeof(int));
        memset(res[i],0,6*sizeof(int));
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<6;j++)cin>>nums[i][j];
    }
    dfs(res,nums,0);
}