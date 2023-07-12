#include<bits/stdc++.h>
using std::vector;
int canChoose(char* str,int len){
    int n=strlen(str);
    for(int i=0;i<n-len+1;i++){
        for(int j=i+1;j<n-len+1;j++){
            bool same=true;
            if(str[i]==str[j]){
                for(int k=1;k<len;k++){
                    if(str[i+k]!=str[j+k]){
                        same=false;
                        break;
                    }
                }if(same)return 0;
            }
        }
    }return 1;
}
int binary(char* str){
    int n=strlen(str);
    int start=1,end=n;
    while(start<end){
        int mid=(start+end)/2;
        if(canChoose(str,mid)){
            end=mid;
        }else start=mid+1;
    }return start;
}
int main(){
    int n;
    scanf("%d",&n);
    char str[n]={0};
    scanf("%s",str);
    // for(int i=1;i<=n;i++){
    //     if(canChoose(str,i))printf("%d is ok\n",i);
    // }
    int ans=binary(str);
    printf("%d\n",ans);
}