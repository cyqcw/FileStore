//  2的幂次方表示
#include<bits/stdc++.h>
using std::vector;
using std::string;
void getBin(int n){
    if(n==1 || n==2 || n==4){
        if(n==1)printf("2(0)");
        else if(n==2)printf("2");
        else printf("2(2)");
    }
    else{
        int temp;
        //  n不为1,2,4,i不为0,1,2
        for(int i=0;;i++){
            if(pow(2,i)<=n && pow(2,i+1)>n){
                if(i==1){
                    printf("2");
                }else{
                    printf("2(");
                    getBin(i);
                    printf(")");                    
                }
                temp=n-pow(2,i);
                // printf("\ni=%d,temp=%d\n",i,temp); 
                break;
            }
        }
        if(temp){
            printf("+");
            getBin(temp);            
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    getBin(n);
}