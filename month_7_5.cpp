#include<cstdio>
using namespace std;
int main(){
    int p,e,i,d,count=0;
    while(scanf("%d%d%d%d",&p,&e,&i,&d) && p!=-1){
        p=p%23;
        e=e%28;
        i=i%33;
        for(int k=0;k*33+i<=d+21252;k++){
            int temp=i+k*33;
            if(temp>d && temp%23==p && temp%28==e){
                printf("Case %d: the next triple peak occurs in %d days.\n",++count,temp-d);
                break;
            }
        }
    }
}