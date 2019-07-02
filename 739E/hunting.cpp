//2019.07.02
//CF739E Gosha is hunting 首先考虑暴力dp,fijk表示前i个,用了j个p,和k个u的期望max,然后不难发现在固定j的前提下,k是凸的,在k取最大值的前提下,j也是凸的,于是
//直接wqs二分套wqs二分即可,O(nlog^2n),还有费用流和贪心做法,懒得写了
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define db double
#define eps 1e-10
#define pid pair<int,db>
#define fi first
#define se second
#define getmx(a,b) (a<b?(a=b,1):0)
using namespace std;
int n,mp,mu;
db p[2009],u[2009];
db f[2009];
int gp[2009],gu[2009];
int check2(db dp,db du)
{
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1],gp[i]=gp[i-1],gu[i]=gu[i-1];
		if(getmx(f[i],f[i-1]+p[i]+u[i]-p[i]*u[i]-dp-du))
			gp[i]=gp[i-1]+1,gu[i]=gu[i-1]+1;
		if(getmx(f[i],f[i-1]+u[i]-du))
			gp[i]=gp[i-1],gu[i]=gu[i-1]+1;
		if(getmx(f[i],f[i-1]+p[i]-dp))
			gp[i]=gp[i-1]+1,gu[i]=gu[i-1];
	}
	return gu[n]>=mu;
}
pid check1(db x)
{
	db l=-2,r=2;
	for(int i=1;i<=50;i++)
	{
		db mid=(l+r)/2;
		if(check2(x,mid))
			l=mid;
		else
			r=mid;
	}
	check2(x,l);
	return pid(gp[n]>=mp,l);
}
void solve1()
{
	db l=-2,r=2;
	for(int i=1;i<=50;i++)
	{
		db mid=(l+r)/2;
		if(check1(mid).fi)
			l=mid;
		else
			r=mid;
	}
	db t=check1(l).se;
	// printf("l:%lf t:%lf\n",l,t);
	printf("%.10lf",f[n]+mp*l+mu*t);
}
int main()
{
#ifdef I_LOVE_KTY
	freopen("hunting.in","r",stdin);
	freopen("hunting.out","w",stdout);
#endif
	scanf("%d%d%d",&n,&mp,&mu);
	for(int i=1;i<=n;i++)
		scanf("%lf",p+i);
	for(int i=1;i<=n;i++)
		scanf("%lf",u+i);
	solve1();
	return 0;
}