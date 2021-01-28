#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n;
int s[2009];
int ax[2009],ay[2009],av;
int p[1000009],bkp[1000009];
int solve(int c)
{
	// printf("c:%d\n",c);
	av=s[2*n]+s[c];
	int cv=av;
	int rp=2*n;
	for(int i=1;i<=n;i++)
	{
		int np=cv-s[rp];
		if(!p[np])
			return 0;
		p[np]--,p[s[rp]]--;
		if(p[np]<0||p[s[rp]]<0)
			return 0;
		ax[i]=s[rp],ay[i]=np;
		cv=s[rp];
		while(rp>0&&!p[s[rp]])
			rp--;
		// printf("i:%d rp:%d\n",i,rp);
	}
	return 1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
			scanf("%d",s+i),bkp[s[i]]++;
		sort(s+1,s+2*n+1);
		int fg=0;
		for(int i=1;i<=2*n-1;i++)
		{
			for(int j=1;j<=2*n;j++)
				p[s[j]]=bkp[s[j]];
			if(solve(i))
			{
				fg=1;
				break;
			}
		}
		if(!fg)
			puts("NO");
		else
		{
			puts("YES");
			printf("%d\n",av);
			for(int i=1;i<=n;i++)
				printf("%d %d\n",ax[i],ay[i]);
		}
		for(int i=1;i<=2*n;i++)
			p[s[i]]=bkp[s[i]]=0;
	}
	return 0;
}