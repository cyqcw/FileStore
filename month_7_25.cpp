#include <stdio.h>
#include <stdbool.h>
#include <string.h>
char left[3][7];
char right[3][7];
char result[3][7];
bool isfake(char c,bool light){  //假币是c，且假币轻
    char *pleft,*pright;
    for (int i=0;i<3;i++){
        if (light) { pleft=left[i]; pright=right[i]; }
        else { pleft=right[i]; pright=left[i]; }
        switch (result[i][0]){  //通过逻辑关系判断左右两边中c出现可能
            case 'u':
                if (strchr(pright,c)==NULL) return false;
                break;
            case 'e':if (strchr(pleft,c)||strchr(pright,c)) return false;
                break;
            case 'd':
                if (strchr(pleft,c)==NULL) return false;
                break;
        }
    }return true;
}


int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        for (int i=0;i<3;i++) scanf("%s%s%s",left[i],right[i],result[i]);
        //
        for (char c='A';c<='L';c++){
            if (isfake(c,true)) printf("%c is the counterfeit coin and it is light. \n",c);
            else if (isfake(c,false)) printf("%c is the counterfeit coin and it is heavy. \n",c);
        }        
    }
    return 0;
}