#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[100009],t[100009];
int f[100009][2];
vector<int> p[30][2];
int main()
{
	int tt;
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%s%s",s+1,t+1);
		n=strlen(s+1);
		m=strlen(t+1);
		for(int i=1;i<=26;i++)
			for(int j=0;j<2;j++)
				p[i][j].clear();
		for(int i=1;i<=n;i++)
		{
			s[i]-='a'-1;
			p[s[i]][i&1].push_back(i);
		}
		for(int i=1;i<=m;i++)
			t[i]-='a'-1;
		if(p[t[1]][0].empty()&&p[t[1]][1].empty())
		{
			printf("NO\n");
			continue;
		}
		f[1][0]=p[t[1]][0].empty()?n+1:p[t[1]][0][0];
		f[1][1]=p[t[1]][1].empty()?n+1:p[t[1]][1][0];
		for(int i=2;i<=m;i++)
		{
			auto it=upper_bound(p[t[i]][0].begin(),p[t[i]][0].end(),f[i-1][1]);
			if(it==p[t[i]][0].end())
				f[i][0]=n+1;
			else
				f[i][0]=*it;
			it=upper_bound(p[t[i]][1].begin(),p[t[i]][1].end(),f[i-1][0]);
			if(it==p[t[i]][1].end())
				f[i][1]=n+1;
			else
				f[i][1]=*it;
		}
		if(f[m][n%2]<=n)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}