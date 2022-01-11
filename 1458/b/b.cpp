#include<bits/stdc++.h>
#define db double
using namespace std;
int n;
int sa[109],sb[109],sm[109];
int f[2][109][10009];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",sa+i,sb+i),sm[i]=sm[i-1]+sa[i];
	memset(f,0x80,sizeof(f));
	f[0][0][0]=0;
	for(int i=1;i<=n;i++)
	{
		int cur=i&1;
		memset(f[cur],0x80,sizeof(f[cur]));
		for(int j=0;j<=i;j++)
			for(int k=0;k<=sm[i];k++)
			{
				if(j>=1&&k>=sa[i])
					f[cur][j][k]=max(f[cur][j][k],f[cur^1][j-1][k-sa[i]]+2*sb[i]);
				f[cur][j][k]=max(f[cur][j][k],f[cur^1][j][k]+sb[i]);
			}
	}
	for(int i=1;i<=n;i++)
	{
		int ans=0x80808080;
		for(int j=1;j<=sm[n];j++)
			ans=max(ans,min(f[n&1][i][j],2*j));
		printf("%.12lf ",(db)ans/2);
	}
	return 0;
}