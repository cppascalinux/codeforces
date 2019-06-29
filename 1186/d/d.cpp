#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define db double
#define li long long
using namespace std;
int n;
li s[100009];
int isn[100009];
int fl[100009];
int main()
{
#ifdef I_LOVE_KTY
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		db a=0;
		scanf("%lf",&a);
		s[i]=a*100000+(a>0?0.5:-0.5);
		if(s[i]%100000==0)
			isn[i]=1;
		if(s[i]>0||isn[i])
			fl[i]=s[i]/100000;
		else
			fl[i]=s[i]/100000-1;
		// printf("i:%d a:%.5lf s:%lld isn:%d fl:%d\n",i,a,s[i],isn[i],fl[i]);
	}
	li sm=0;
	for(int i=1;i<=n;i++)
		sm+=fl[i];
	sm=-sm;
	for(int i=1;i<=n&&sm;i++)
		if(!isn[i])
			fl[i]++,sm--;
	for(int i=1;i<=n;i++)
		printf("%d\n",fl[i]);
	return 0;
}