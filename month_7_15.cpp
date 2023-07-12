#include<bits/stdc++.h>
using std::vector;
double count(){
    char exp[100];
    scanf("%s",exp);
    switch(exp[0]){
        case '+':return count()+count();
        case '-':return count()-count();
        case '*':return count()*count();
        case '/':return count()/count();
        default:return atof(exp);
    }
}
int main(){
    printf("%f\n",count());
}