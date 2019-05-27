#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int s[300009];
int f[300009];
int judge(int x)
{
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		int up=s[i]+x;
		if(up<=m-1)
		{
			if(up<f[i-1])
				return 0;
			f[i]=max(f[i-1],s[i]);
		}
		else
		{
			up-=m;
			if(f[i-1]<=up)
				f[i]=f[i-1];
			else
				f[i]=max(f[i-1],s[i]);
		}
	}
	return 1;
}
void bin()
{
	int l=0,r=m;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(judge(mid))
			r=mid;
		else
			l=mid+1;
	}
	printf("%d",l);
}
int main()
{
#ifdef I_LOVE_KTY
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i);
	bin();
	return 0;
}