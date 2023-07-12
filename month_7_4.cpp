#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    // int count=0;
    // for(int i=2;i<=n;i++){
    //     for(int j=2;j<=i;j++){
    //         for(int k=2;k<=j;k++){
    //             for(int d=2;d<=k;d++){
    //                 if(i*i*i==j*j*j+k*k*k+d*d*d){
    //                     printf("Cube = %d, Triple = (%d,%d,%d)\n",i,d,k,j);
    //                     count++;
    //                 }
    //             }
    //         }
    //     }
    // }

    for(int a=2;a<=n;a++){
        for(int b=2;b<a;b++){
            for(int c=b;c<a;c++){
                for(int d=c;d<a;d++){
                    if(a*a*a==b*b*b+c*c*c+d*d*d){
                        printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
                        // count--;
                    }
                }
            }
        }
    }
    // printf("count=%d\n",count);
}