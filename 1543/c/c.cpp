#include<bits/stdc++.h>
#define db double
#define eps 1e-8
using namespace std;
db a,b,c,v;
db dp(db a,db b,db c)
{
	// printf("a:%lf b:%lf c:%lf\n",a,b,c);
	if(abs(c-1)<=eps)
		return 1;
	db ans=0;
	if(abs(a)>eps)
	{
		db dl=min(a,v);
		db na=a-dl,nb,nc;
		if(abs(b)>eps)
			nb=b+dl/2,nc=c+dl/2;
		else
			nb=0,nc=c+dl;
		ans+=a*(dp(na,nb,nc)+1);
	}
	if(abs(b)>eps)
	{
		db dl=min(b,v);
		db na,nb=b-dl,nc;
		if(abs(a)>eps)
			na=a+dl/2,nc=c+dl/2;
		else
			na=0,nc=c+dl;
		ans+=b*(dp(na,nb,nc)+1);
	}
	ans+=c;
	return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf",&a,&b,&c,&v);
		printf("%.12lf\n",dp(a,b,c));
	}
	return 0;
}