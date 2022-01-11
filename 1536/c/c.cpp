#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n;
vector<int> fc[500009];
char s[500009];
int sm[2][500009],ps[2][500009];
int f[500009];
int gcd(int a,int b)
{
	if(!a||!b)
		return a+b;
	return gcd(b,a%b);
}
void init()
{
	int m=500000;
	for(int i=1;i<=m;i++)
		for(int j=i;j<=m;j+=i)
			fc[j].push_back(i);
}
int main()
{
	// init();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
			s[i]=(s[i]=='K');
		map<pii,int>mp;
		for(int i=1;i<=n;i++)
		{
			sm[0][i]=sm[0][i-1];
			sm[1][i]=sm[1][i-1];
			sm[s[i]][i]++;
			ps[s[i]][sm[s[i]][i]]=i;
		}
		for(int i=1;i<=n;i++)
		{
			f[i]=0;
			int g=gcd(sm[0][i],sm[1][i]);
			int s0=sm[0][i]/g,s1=sm[1][i]/g;
			f[i]=mp[pii(s0,s1)]+1;
			mp[pii(s0,s1)]=f[i];
		}
		for(int i=1;i<=n;i++)
			printf("%d ",f[i]);
		printf("\n");
	}
	return 0;
}