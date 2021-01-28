#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define INFL 0x7F7F7F7F7F7F7F7FLL
using namespace std;
int n;
int s[200009],d[200009];
ll sm[2][200009];
int pr[2][200009];
ll sf[2][200009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i);
		s[n+1]=s[0]=0;
		for(int i=1;i<=n+1;i++)
			d[i]=s[i]-s[i-1];
		for(int i=1;i<=n+1;i++)
			sm[i&1][i]=d[i]+sm[i&1][i-2];
		int n0=n+(n&1),n1=2*n+1-n0;
		int fg=0;
		for(int i=0;i<=n+5;i++)
			pr[0][i]=pr[1][i]=1,sf[0][i]=sf[1][i]=INFL;
		for(int i=1;i<=n+1;i++)
			if(sm[i&1][i]>=0)
				pr[i&1][i]=(i>=3?pr[i&1][i-2]:1);
			else
				pr[i&1][i]=0;
		for(int i=n+1;i>=1;i--)
			sf[i&1][i]=min(sm[i&1][i],(i<=n-1?sf[i&1][i+2]:INFL));
		// for(int i=1;i<=n+1;i++)
		// 	printf("i:%d pr:%d sf:%d\n",i,pr[i&1][i],sf[i&1][i]);
		if(sf[0][2]>=0&&sf[1][1]>=0&&sm[(n+1)&1][n+1]==0)
			fg=1;
		for(int i=2;i<=n;i++)
			if(sm[i&1][i&1?n1:n0]==2*d[i])
			{
				int c0=0,c1=0;
				if(pr[i&1][i-2]&&sf[i&1][i]>=2*d[i])
					c0=1;
				if((i==2||pr[(i&1)^1][i-3])&&sm[(i&1)^1][i-1]>=-d[i]&&sf[(i&1)^1][i+1]>=-2*d[i])
					c1=1;
				// printf("qwq i:%d c0:%d c1:%d\n",i,c0,c1);
				fg|=c0&c1;
			}
		printf("%s\n",fg?"YES":"NO");
	}
	return 0;
}