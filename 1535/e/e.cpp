#include<bits/stdc++.h>
#define ll long long
using namespace std;
int q,n;
int a[300009],c[300009];
int f[300009][20],dep[300009];
int getkf(int x,int k)
{
	for(int i=0;i<=19;i++)
		if(k>>i&1)
			x=f[x][i];
	return x;
}
int main()
{
	n=1;
	dep[1]=1;
	scanf("%d%d%d",&q,a+1,c+1);
	for(int i=2;i<=q+1;i++)
	{
		int x,y,z,w;
		scanf("%d%d%d",&x,&y,&z);
		y++;
		if(x==1)
		{
			scanf("%d",&w);
			a[i]=z,c[i]=w;
			f[i][0]=y;
			dep[i]=dep[y]+1;
			for(int j=1;j<=19;j++)
				f[i][j]=f[f[i][j-1]][j-1];
		}
		else
		{
			int cur=y;
			for(int j=19;j>=0;j--)
				if(a[f[cur][j]])
					cur=f[cur][j];
			int ans1=0;
			ll ans2=0;
			while(z)
			{
				int dt=min(a[cur],z);
				a[cur]-=dt,z-=dt;
				ans1+=dt;
				ans2+=(ll)c[cur]*dt;
				if(!a[cur])
				{
					if(cur==y)
						break;
					cur=getkf(y,dep[y]-dep[cur]-1);
				}
			}
			printf("%d %lld\n",ans1,ans2);
			fflush(stdout);
		}
	}
	return 0;
}