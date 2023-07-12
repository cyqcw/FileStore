#include<bits/stdc++.h>
using std::vector;
// int COUNT=0;
// vector<int> nums;
int canChoose(vector<int>& res,int index,int choose){
    for(int i=0;i<index;i++){
        if(res[i]==choose || abs(i-index)==abs(res[i]-choose))return 0;
    }return 1;
}
void getRes(vector<int>&fin,vector<int>& res,int index,int n){
    if(index==n){
        // COUNT++;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(res[i]==j)printf("Q");
        //         else printf(".");
        //     }printf("\n");
        // }printf("\n");
        // for(int ele:nums){
        //     if(COUNT==ele){
        int sum=0;
        for(int i=0;i<n;i++){
            // printf("%d",res[i]+1);
            sum=sum*10+res[i]+1;
        }//printf("%d\n",sum);
        fin.push_back(sum);
        //     }
        // }
    }else{
        //  index代表填充的第几行
        for(int i=0;i<n;i++){
            if(canChoose(res,index,i)){
                res[index]=i;
                getRes(fin,res,index+1,n);
            }
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    vector<int> fin;
    vector<int> res(8);
    getRes(fin,res,0,8);
    while(n--){
        int temp;
        scanf("%d",&temp);
        printf("%d\n",fin[temp-1]);
    }

    // }
    // printf("%d\n",COUNT);
}