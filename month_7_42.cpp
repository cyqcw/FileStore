#include<bits/stdc++.h>
using namespace std;
int t;
struct prt{
	int s, e, d;
};
prt f[200009];
int n;
long long check(int x)
{
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		if(f[i].s<=x) 
		sum+=( min(f[i].e,x) - f[i].s ) / f[i].d + 1;
	}
	return sum;
}
int main()
{
	scanf("%d",&t);
	
	while(t--)
	{
		int l=0,r=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&f[i].s,&f[i].e,&f[i].d);
			r=max(r,f[i].e);
		}
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(check(mid)%2==0) l=mid+1;
			else r=mid;
		}
		int anss=check(r)-check(r-1);
		if(anss%2==0) cout<<"There's no weakness."<<endl;
		else cout<<r<<" "<<anss<<endl;
	}
	return 0;
}
