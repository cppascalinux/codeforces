#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define inf 0x7F7F7F7F
using namespace std;
int n;
char s[59];
int f[2][109][309][309];
int mnk[309];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		s[i]-='0';
	reverse(s+1,s+n+1);
	memset(f,0x7F,sizeof(f));
	memset(f[0][n],0,sizeof(f[0][n]));
	for(int i=0;i<=n;i++)
	{
		memset(f[(i+1)&1],0x7F,sizeof(f[(i+1)&1]));
		for(int j=0;j<=2*n;j++)
		{
			int nj=j-n;
			memset(mnk,0x7F,sizeof(mnk));
			for(int k=6*n;k>=0;k--)
			{
				int mnl=inf;
				for(int l=6*n;l>=0;l--)
				{
					mnl=min(mnl,f[i&1][j][k][l]);
					mnk[l]=min(mnk[l],f[i&1][j][k][l]);
					if((nj+k-l+1000000)%10==s[i+1])
					{
						int tj=((nj+k-l)<0?(nj+k-l+1)/10-1:(nj+k-l)/10)+n;
						int &p=f[(i+1)&1][tj][k][l];
						p=min(p,mnl+k+l);
						p=min(p,mnk[l]+k+l);
						// printf("i:%d nj:%d j:%d k:%d l:%d f:%d\n",i+1,nj,tj-n,k,l,f[(i+1)&1][tj][k][l]);
					}
				}
			}
		}
	}
	int ans=inf;
	for(int i=0;i<=5*n;i++)
		for(int j=0;j<=5*n;j++)
			ans=min(ans,f[(n+1)&1][n][i][j]);
	printf("%d",ans);
	return 0;
}