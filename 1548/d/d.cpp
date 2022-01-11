#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int mat[6009][6009];
int x[6009],y[6009];
int dis[6009];
int gcd(int a,int b)
{
	return !a||!b?a+b:gcd(b,a%b);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",x+i,y+i);
	int sm0[2][2]={0};
	for(int i=1;i<=n;i++)
		sm0[x[i]/2%2][y[i]/2%2]++;
	ll ans=0;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			ans+=(ll)sm0[i][j]*(sm0[i][j]-1)*(sm0[i][j]-2)/6;
	for(int i=1;i<=n;i++)
	{
		int tx=x[i]/2%2,ty=y[i]/2%2;
		sm0[tx][ty]--;
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				if(j!=tx||k!=ty)
					ans+=(ll)(sm0[j][k]-1)*sm0[j][k]/2;
		sm0[tx][ty]++;
	}
	printf("%lld",ans);
	return 0;
}