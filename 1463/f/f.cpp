#include<bits/stdc++.h>
#define ninf 0x80808080
using namespace std;
int n,x,y;
int rep[50];
int f[2][4194304];
int main()
{
	scanf("%d%d%d",&n,&x,&y);
	if(x<y)
		swap(x,y);
	for(int i=1;i<=x+y;i++)
	{
		rep[i]=n/(x+y);
		if(i<=n%(x+y))
			rep[i]++;
	}
	memset(f,0x80,sizeof(f));
	f[0][0]=0;
	int mk=(1<<x)-1;
	for(int i=0;i<x+y;i++)
	{
		int cur=i&1;
		memset(f[cur^1],0x80,sizeof(f[0]));
		for(int s=0;s<1<<x;s++)
		{
			int ns=(s<<1)&mk;
			f[cur^1][ns]=max(f[cur^1][ns],f[cur][s]);
			if(!(s&(1<<(x-1)))&&!(s&(1<<(y-1))))
				f[cur^1][ns+1]=max(f[cur^1][ns+1],f[cur][s]+rep[i+1]);
		}
	}
	int ans=0;
	for(int s=0;s<1<<x;s++)
		ans=max(ans,f[(x+y)&1][s]);
	printf("%d",ans);
	return 0;
}