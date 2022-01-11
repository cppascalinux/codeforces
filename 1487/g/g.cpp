#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define mod 998244353
using namespace std;
int n,ans;
int c[30];
int f[209][109][2],cf[409];
int g[209][109][109][3],cg[409][409];
void cal1()
{
	int m=(n+1)/2;
	f[0][0][0]=1;
	for(int i=1;i<=m;i++)
		for(int j=0;j<=(i+1)/2;j++)
		{
			if(i>1)
				f[i][j][0]=((ll)f[i-1][j][1]*25+(ll)f[i-1][j][0]*24)%mod;
			else
				f[i][j][0]=f[i-1][j][0]*25;
			if(j)
				f[i][j][1]=f[i-1][j-1][0];
		}
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++)
		{
			int t1=(f[m][j][0]+f[m][j][1])%mod;
			int t2=(f[n-m][i-j][0]+f[n-m][i-j][1])%mod;
			cf[i]=(cf[i]+(ll)t1*t2)%mod;
			// printf("i:%d cf:%d\n",i,cf[i]);
		}
	// for(int i=0;i<=n;i++)
	// 	printf("i:%d cf:%d\n",i,cf[i]);
	for(int i=1;i<=26;i++)
		for(int j=c[i]+1;j<=n;j++)
			(ans+=mod-cf[j])%=mod;
}
void cal2()
{
	int m=(n+1)/2;
	g[0][0][0][0]=1;
	for(int i=1;i<=m;i++)
		for(int j=0;j<=(i+1)/2;j++)
			for(int k=0;k<=(i+1)/2&&j+k<=i;k++)
			{
				if(i>1)
					g[i][j][k][0]=((ll)g[i-1][j][k][0]*23+(ll)g[i-1][j][k][1]*24+(ll)g[i-1][j][k][2]*24)%mod;
				else
					g[i][j][k][0]=g[i-1][j][k][0]*24;
				if(j)
					g[i][j][k][1]=(g[i-1][j-1][k][0]+g[i-1][j-1][k][2])%mod;
				if(k)
					g[i][j][k][2]=(g[i-1][j][k-1][0]+g[i-1][j][k-1][1])%mod;
			}
	for(int i=0;i<=(m+1)/2;i++)
		for(int j=0;j<=(m+1)/2;j++)
			for(int k=0;k<=(n-m+1)/2;k++)
				for(int l=0;l<=(n-m+1)/2;l++)
				{
					int t1=((g[m][i][k][0]+g[m][i][k][1])%mod+g[m][i][k][2])%mod;
					// printf("i:%d k:%d g:%d\n",i,k,t1);
					int t2=((g[n-m][j][l][0]+g[n-m][j][l][1])%mod+g[n-m][j][l][2])%mod;
					cg[i+j][k+l]=(cg[i+j][k+l]+(ll)t1*t2)%mod;
				}
	// for(int i=1;i<=n;i++)
	// 	for(int j=1;j<=n;j++)
	// 		printf("i:%d j:%d cg:%d\n",i,j,cg[i][j]);
	for(int i=1;i<=26;i++)
		for(int j=i+1;j<=26;j++)
			for(int k=c[i]+1;k<=n;k++)
				for(int l=c[j]+1;l<=n;l++)
					(ans+=cg[k][l])%=mod;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=26;i++)
		scanf("%d",c+i);
	ans=26*26;
	for(int i=1;i<=n-2;i++)
		ans=(ll)ans*25%mod;
	cal1();
	cal2();
	printf("%d",ans);
	return 0;
}