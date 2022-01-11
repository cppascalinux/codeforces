#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define db double
using namespace std;
int n,k;
int s[200009];
int sm[200009];
db mn[200009];
int judge(int v)
{
	for(int i=1;i<=n;i++)
		if(s[i]>=v)
			sm[i]=1;
		else
			sm[i]=0;
	for(int i=1;i<=n;i++)
		sm[i]+=sm[i-1],mn[i]=min(mn[i-1],sm[i]-i/2.0);
	for(int i=k;i<=n;i++)
		if(sm[i]-i/2.0-mn[i-k]-0.5+0.01>=0)
			return 1;
	return 0;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i);
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r+1)/2;
		// printf("mid:%d\n",mid);
		if(judge(mid))
			l=mid;
		else
			r=mid-1;
	}
	printf("%d",l);
	return 0;
}