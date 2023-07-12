#include<bits/stdc++.h>
using std::vector;
using std::string;
using std::cin;
using std::cout;
bool compare(string a,string b){
    char data_a[10]={0},data_b[10]={0};
    for(int i=6;i<14;i++){
        data_a[i-6]=a[i];
        data_b[i-6]=b[i];
    }
    int cmp=strcmp(data_a,data_b);
    if(cmp==0)return a>b;
    if(cmp<0)return false;
    return true;
}
int main(){
    int n;
    scanf("%d",&n);
    vector<string> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end(),compare);
    for(string ele:nums){
        cout<<ele<<"\n";
    }
}