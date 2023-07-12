#include<bits/stdc++.h>
#define MAXN 100
using std::vector;

int getResCount(int m,int n){
    if(m<n)return getResCount(m,m);
    if(m==0)return 1;
    if(n==0)return 0;
    return getResCount(m,n-1)+getResCount(m-n,n);
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",getResCount(a,b));
    }
}