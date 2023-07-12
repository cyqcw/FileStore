#include<bits/stdc++.h>
using std::vector;
double f(double x){
    return x*x*x-5*x*x+10*x-80;
}
double res(double start,double end){
    if(fabs(f(start))<=1e-10)return start;
    double mid=(start+end)/2;
    if(f(start)*f(mid)<0){
        return res(start,mid);
    }else{
        return res(mid,end);
    }
}
int main(){
    printf("%.9f\n",res(5,6));
}