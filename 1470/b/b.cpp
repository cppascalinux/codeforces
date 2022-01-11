#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#define ll long long
#define ull unsigned long long
using namespace std;
mt19937_64 rnd(20020618LL*20030619LL);
int n,q;
ull pm[1000009];
int s[300009];
ull h[300009];
vector<int> vs[300009];
void getpm()
{
	int m=1000000,tp=0;
	for(int i=1;i<=m;i++)
		pm[i]=rnd();
}
int main()
{
	int t;
	getpm();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",s+i);
			int x=s[i];
			h[i]=0;
			for(int j=2;j*j<=x;j++)
				if(x%j==0)
				{
					while(x%j==0)
					{
						x/=j;
						h[i]^=pm[j];
					}
				}
			if(x>1)
				h[i]^=pm[x];
		}
		for(int i=0;i<=n;i++)
			vs[i].clear();
		map<ull,int> mp;
		for(int i=1;i<=n;i++)
		{
			auto it=mp.find(h[i]);
			if(it==mp.end())
			{
				vs[i].push_back(i);
				mp[h[i]]=i;
			}
			else
				vs[it->second].push_back(i);
		}
		int ans0=0;
		for(int i=1;i<=n;i++)
			ans0=max(ans0,(int)vs[i].size());
		int ans1=0;
		for(int i=1;i<=n;i++)
			if(vs[i].size())
				if(vs[i].size()%2==0||h[vs[i][0]]==0)
				{
					for(int v:vs[i])
						vs[0].push_back(v);
					vs[i].clear();
				}	
		for(int i=0;i<=n;i++)
			ans1=max(ans1,(int)vs[i].size());
		scanf("%d",&q);
		for(int i=1;i<=q;i++)
		{
			ll a;
			scanf("%lld",&a);
			if(a==0)
				printf("%d\n",ans0);
			else
				printf("%d\n",ans1);
		}
	}
	return 0;
}