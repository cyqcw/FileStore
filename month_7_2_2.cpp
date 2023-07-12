//  熄灯问题

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void push(int** num,int** res,int i,int j){
    //  记录按下哪个
    res[i][j]=!res[i][j];
    //  自己
    num[i][j]=!num[i][j];
    //  上下
    if(i!=0)num[i-1][j]=!num[i-1][j];
    if(i!=4)num[i+1][j]=!num[i+1][j];
    //  左右
    if(j!=0)num[i][j-1]=!num[i][j-1];
    if(j!=5)num[i][j+1]=!num[i][j+1];
}

void show(int** nums){
    for(int i=0;i<5;i++){
        for(int j=0;j<6;j++)printf("%d ",nums[i][j]);
        printf("\n");
    }
}

int isOk(int** nums,int** res,int index){
    if(index==6){   //  第一行的遍历完了
        //  直接看后面可不可以就行了
        for(int i=1;i<5;i++){
            for(int j=0;j<6;j++){
                if(nums[i-1][j])push(nums,res,i,j); //  上一个亮着就需要按掉下面的
            }
        }
        //  按完之后看最后一行
        for(int j=0;j<6;j++){
            if(nums[4][j]){
                //  将之前的所有按下的归位
                for(int i=1;i<5;i++){
                    for(int j=0;j<6;j++){
                        push(nums,res,i,j);
                    }
                }
                return 0; //  最后一行没有全部熄灭
            }
        }
        //  可以的话
        show(res);
        return 1;
    }else{
        //  不按下来
        if(isOk(nums,res,index+1))return 1;
        //  按下来
        push(nums,res,0,index); //  按下看看能不能用
        if(isOk(nums,res,index+1))return 1;
        return 0;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int** nums=(int**)malloc(5*sizeof(int*));
        int** res=(int**)malloc(5*sizeof(int*));
        for(int i=0;i<5;i++){
            nums[i]=(int*)malloc(6*sizeof(int));
            res[i]=(int*)malloc(6*sizeof(int));
            memset(nums[i],0,6*sizeof(int));
            memset(res[i],0,6*sizeof(int));
        }
        for(int i=0;i<5;i++){
            for(int j=0;j<6;j++)scanf("%d",&nums[i][j]);
        }
        // show(nums);
        //  结果
        printf("PUZZLE #%d\n",i+1);
        isOk(nums,res,0);        
    }
}