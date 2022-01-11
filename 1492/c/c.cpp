#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,m;
char s[200009],t[200009];
int f[200009],g[200009];
vector<int> p[30];
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s%s",s+1,t+1);
	for(int i=1;i<=n;i++)
		s[i]-='a'-1;
	for(int i=1;i<=m;i++)
		t[i]-='a'-1;
	for(int i=1;i<=n;i++)
		p[s[i]].push_back(i);
	for(int i=1;i<=m;i++)
		f[i]=*upper_bound(p[t[i]].begin(),p[t[i]].end(),f[i-1]);
	g[m+1]=n+1;
	for(int i=m;i>=1;i--)
		g[i]=*(lower_bound(p[t[i]].begin(),p[t[i]].end(),g[i+1])-1);
	int ans=0;
	for(int i=1;i<=m-1;i++)
		ans=max(ans,g[i+1]-f[i]);
	printf("%d",ans);
	return 0;
}