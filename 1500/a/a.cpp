#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
using namespace std;
int n;
const int m=2500000;
int s[200009],mp[200009];
vector<int> b0[2500009];
pii b1[5000009];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",s+i);
		b0[s[i]].push_back(i);
	}
	int sm=0;
	for(int i=1;i<=m;i++)
	{
		if(b0[i].size()>1)
			sm++;
		if(b0[i].size()>=4)
		{
			printf("YES\n");
			for(int j=0;j<=3;j++)
				printf("%d ",b0[i][j]);
			return 0;
		}
	}
	if(sm>=2)
	{
		int ans[5],tp=0;
		for(int i=1;i<=m;i++)
			if(b0[i].size()>1)
			{
				for(int j=0;j<=1;j++)
					ans[++tp]=b0[i][j];
				if(tp>=4)
					break;
			}
		swap(ans[2],ans[3]);
		printf("YES\n");
		for(int i=1;i<=4;i++)
			printf("%d ",ans[i]);
		return 0;
	}
	int tp=0;
	for(int i=1;i<=n;i++)
		mp[i]=i;
	for(int i=1;i<=n;i++)
		if(b0[s[i]].size()>1)
		{
			swap(s[++tp],s[i]);
			swap(mp[tp],mp[i]);
		}
	// for(int i=1;i<=n;i++)
	// 	printf("i:%d s:%d mp:%d\n",i,s[i],mp[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
			if(b1[s[i]+s[j]].fi&&i>=4)
			{
				pii t=b1[s[i]+s[j]];
				printf("YES\n");
				printf("%d %d %d %d",t.fi,t.se,mp[i],mp[j]);
				return 0;
			}
		for(int j=1;j<i;j++)
			b1[s[i]+s[j]]=pii(mp[i],mp[j]);
	}
	printf("NO");
	return 0;
}