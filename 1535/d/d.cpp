#include<bits/stdc++.h>
using namespace std;
int n,k,q;
char s[500009];
int f[500009];
void dfs(int a)
{
	if(a*2>n)
	{
		f[a]=s[a]>=0?1:2;
		return;
	}
	dfs(a*2);
	dfs(a*2+1);
	if(s[a]==-1)
		f[a]=f[a*2]+f[a*2+1];
	else if(s[a]==1)
		f[a]=f[a*2];
	else
		f[a]=f[a*2+1];
}
int main()
{
	scanf("%d",&k);
	n=(1<<k)-1;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='0'||s[i]=='1')
			s[i]-='0';
		else
			s[i]=-1;
	reverse(s+1,s+n+1);
	dfs(1);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int a;
		char t[5];
		scanf("%d%s",&a,t+1);
		a=n+1-a;
		t[1]=t[1]=='?'?-1:t[1]-'0';
		s[a]=t[1];
		// printf("a:%d\n",a);
		for(;a;a>>=1)
		{
			if(a*2>n)
				f[a]=s[a]>=0?1:2;
			else if(s[a]==-1)
				f[a]=f[a*2]+f[a*2+1];
			else if(s[a]==1)
				f[a]=f[a*2];
			else
				f[a]=f[a*2+1];
			
		}
		printf("%d\n",f[1]);
	}
	return 0;
}