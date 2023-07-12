#include<bits/stdc++.h>

long long fastPower(long long base, long long power,long long yu) {
    long long result= 1;
    while (power > 0) {
        if (power & 1) {//此处等价于if(power%2==1)
            result = result * base % yu;
        }
        power >>= 1;//此处等价于power=power/2
        base = (base * base) % yu;
    }
    return result; 
}
int main(){
    int n,a,b,c;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d",&a,&b,&c);
        printf("%d\n",fastPower(a,b,c));
    }
}
