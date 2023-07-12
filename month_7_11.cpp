#include<cstdio>
void hanoi(int n,char start,char end,char mid){
    if(n==1){
        printf("%c->%c\n",start,end);
    }
    else{        
        //  再把上面的n-1个从A->B
        hanoi(n-1,start,mid,end);
        //  先把最下面一个从A->C
        printf("%c->%c\n",start,end);
        // 再把上面n-1个从B到C
        hanoi(n-1,mid,end,start);        
    }
}
int main(){
    int n;
    scanf("%d",&n);
    hanoi(n,'A','C','B');
}