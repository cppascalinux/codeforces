#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define li long long
using namespace std;
int main()
{
#ifdef I_LOVE_KTY
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	li ans=c*2;
	int t=min(a,b);
	ans+=t*2;
	// printf("min:%d\n",min(a,b));
	a-=t,b-=t;
	// printf("a:%d b:%d\n",a,b);
	if(a||b)
		ans++;
	cout<<ans;
	return 0;
}