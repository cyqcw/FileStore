#include<bits/stdc++.h>
using std::vector;
double f(double x){
    return x*x*x;
}
double res(double start,double end,double target){
    if(fabs(f(start)-target)<1e-10)return start;
    double mid=(start+end)/2;
    if(f(start)<target && f(mid)>target){
        return res(start,mid,target);
    }else{
        return res(mid,end,target);
    }
}
int main(){
    double target;
    scanf("%lf",&target);
    printf("%.6f\n",res(-100,100,target));
}