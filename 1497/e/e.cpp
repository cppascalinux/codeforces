#include<bits/stdc++.h>
#define ull unsigned long long
#define fi first
#define se second
#define pli pair<ull,int>
#define inf 0x7F7F7F7F
using namespace std;
int n,k,tot;
ull s[200009];
ull hs[10000009];
int f[200009][21],ls[200009][21];
int buc[200009];
mt19937_64 rnd(20020618);
int main()
{
	for(int i=2;i<=10000000;i++)
		hs[i]=rnd();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			s[i]=0;
			int x;
			scanf("%d",&x);
			for(int j=2;j*j<=x;j++)
			{
				while(x%j==0)
				{
					s[i]^=hs[j];
					x/=j;
				}
			}
			if(x>1)
				s[i]^=hs[x];
			// printf("i:%d hs:%llu\n",i,s[i]);
		}
		unordered_map<ull,int> mp;
		for(int i=1;i<=n;i++)
		{
			if(!mp[s[i]])
				mp[s[i]]=++tot;
			s[i]=mp[s[i]];
			// printf("i:%d s:%d\n",i,s[i]);
		}
		for(int i=0;i<=n;i++)
			for(int j=0;j<=k;j++)
				f[i][j]=inf,ls[i][j]=0;
		f[0][0]=0;
		for(int j=0;j<=k;j++)
		{
			int lp=1,sm=0;
			for(int i=1;i<=n;i++)
			{
				if(buc[s[i]])
					sm++;
				buc[s[i]]++;
				while(lp<i&&sm>j)
				{
					buc[s[lp]]--;
					if(buc[s[lp]])
						sm--;
					lp++;
				}
				ls[i][j]=lp-1;
				// printf("i:%d j:%d ls:%d\n",i,j,ls[i][j]);
			}
			for(int i=lp;i<=n;i++)
				buc[s[i]]=0;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=k;j++)
				for(int l=0;l<=j;l++)
					f[i][j]=min(f[i][j],f[ls[i][l]][j-l]+1);
		}
		int ans=inf;
		for(int i=0;i<=k;i++)
			ans=min(ans,f[n][i]);
		printf("%d\n",ans);
	}
	return 0;
}