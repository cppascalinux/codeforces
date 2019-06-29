#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
char sa[1000009],sb[1000009];
int sm[1000009];
int main()
{
#ifdef I_LOVE_KTY
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
#endif
	scanf("%s%s",sa+1,sb+1);
	n=strlen(sa+1),m=strlen(sb+1);
	for(int i=1;i<=n;i++)
		sa[i]-='0';
	int ssb=0;
	for(int i=1;i<=m;i++)
	{
		sb[i]-='0';
		ssb^=sb[i];
	}
	int ans0=0,ans1=0;
	for(int i=1;i<=n;i++)
	{
		sm[i]=sm[i-1]^sa[i];
		if(i>=m)
		{
			if(sm[i]^sm[i-m])
				ans1++;
			else
				ans0++;
		}
	}
	if(ssb)
		printf("%d",ans1);
	else
		printf("%d",ans0);
	return 0;
}