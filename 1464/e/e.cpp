#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long
#define mod 998244353
using namespace std;
int n,m;
int deg[100009];
int f[100009];
int sm[513],mat[513][513];
vector<int> g[100009],sg[100009];
int qpow(int a,int b)
{
	int ans=1;
	for(;b;b>>=1,a=(ll)a*a%mod)
		if(b&1)
			ans=(ll)ans*a%mod;
	return ans;
}
void dp()
{
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(!deg[i])
			q.push(i);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		sort(sg[x].begin(),sg[x].end());
		sg[x].push_back(n+1);
		int lst=-1;
		for(int t:sg[x])
		{
			if(t>lst+1)
			{
				f[x]=lst+1;
				break;
			}
			lst=t;
		}
		for(int v:g[x])
		{
			sg[v].push_back(f[x]);
			if(!--deg[v])
				q.push(v);
		}
	}
}
void getmat()
{
	for(int i=1;i<=n;i++)
		sm[f[i]]++;
	int inv=qpow(n+1,mod-2);
	// printf("inv:%d\n",inv);
	int m=512;
	for(int i=0;i<m;i++)
	{
		mat[i][i]=mod-1;
		for(int j=0;j<m;j++)
			mat[i][j]=(mat[i][j]+(ll)inv*sm[i^j])%mod;
		if(i!=0)
			mat[i][m]=(mod-inv)%mod;
	}
}
void gauss()
{
	int n=512;
	for(int i=0;i<n;i++)
	{
		int p=i;
		if(!mat[i][i])
			for(int j=i+1;j<n;j++)
				if(mat[j][i])
					p=j;
		for(int k=0;k<=n;k++)
			swap(mat[i][k],mat[p][k]);
		int inv=qpow(mat[i][i],mod-2);
		for(int k=i;k<=n;k++)
			mat[i][k]=(ll)mat[i][k]*inv%mod;
		for(int j=i+1;j<n;j++)
			for(int k=n;k>=i;k--)
				mat[j][k]=(mat[j][k]-(ll)mat[j][i]*mat[i][k]%mod+mod)%mod;
	}
	for(int i=n-1;i>=0;i--)
		for(int j=i-1;j>=0;j--)
			mat[j][n]=(mat[j][n]-(ll)mat[j][i]*mat[i][n]%mod+mod)%mod;
	// for(int i=0;i<n;i++)
	// 	for(int j=0;j<=n;j++)
	// 		printf("%d%c",mat[i][j],j==n?'\n':' ');
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		g[b].push_back(a);
		deg[a]++;
	}
	dp();
	// for(int i=1;i<=n;i++)
	// 	printf("i:%d sg:%d\n",i,f[i]);
	getmat();
	gauss();
	printf("%d",mat[0][512]);
	return 0;
}