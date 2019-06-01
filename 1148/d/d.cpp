#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n;
pii s[300009];
pii s1[300009],s2[300009];
bool cmp1(pii a,pii b)
{
	return a.fi>b.fi;
}
bool cmp2(pii a,pii b)
{
	return a.fi<b.fi;
}
void solve()
{
	int tp1=0,tp2=0;
	for(int i=1;i<=n;i++)
		if(s[i].fi<s[i].se)
			s1[++tp1]=pii(s[i].fi,i);
		else
			s2[++tp2]=pii(s[i].fi,i);
	if(tp1>tp2)
	{
		sort(s1+1,s1+tp1+1,cmp1);
		printf("%d\n",tp1);
		for(int i=1;i<=tp1;i++)
			printf("%d ",s1[i].se);
	}
	else
	{
		sort(s2+1,s2+tp2+1,cmp2);
		printf("%d\n",tp2);
		for(int i=1;i<=tp2;i++)
			printf("%d ",s2[i].se);
	}
}
int main()
{
#ifdef I_LOVE_KTY
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&s[i].fi,&s[i].se);
	solve();
	return 0;
}