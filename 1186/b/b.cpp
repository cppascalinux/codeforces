#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define li long long
using namespace std;
int n,m;
int main()
{
#ifdef I_LOVE_KTY
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	n++,m++;
	cout<<(li)n*m/6;
	// if(n>m)
	// 	swap(n,m);
	// // if(n==1)
	// // {
	// // 	li v0=m/3,v1=m%3;
	// // 	if(v1==2)
	// // 		v0++;
	// // 	printf("%lld",v0);
	// // 	return 0;
	// // }
	// // if(n==2)
	// // {
	// // 	li v0=(m+1)/2;
	// // 	printf("%lld",v0);
	// // 	return 0;
	// // }
	// li v0=(n-1)/3;
	// li ans0=v0*((m+1)/2);
	// li ans1=0;
	// li lft=n-3*v0;
	// if(lft==3)
	// {
	// 	li s1=m/3,s2=m%3;
	// 	s1+=s2==2;
	// 	ans1=2*s1;
	// }
	// else if(lft==2)
	// 	ans1=(m+1)/2;
	// else
	// {
	// 	li s1=m/3,s2=m%3;
	// 	s1+=s2==2;
	// 	ans1=s1;
	// }
	// printf("%lld",ans0+ans1);
	return 0;
}