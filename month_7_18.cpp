#include<bits/stdc++.h>
using std::vector;
int Res[90]={1,1,2};
void getRes(){
    for(int i=3;i<50;i++){
        Res[i]=Res[i-1]+Res[i-2];
    }
}
int main(){
    getRes();
    int n;
    scanf("%d",&n);
    printf("%d\n",Res[n]);
}