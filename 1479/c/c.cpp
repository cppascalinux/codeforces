#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int l0,r0,n,tp;
struct edge
{
	int u,v,len;
};
edge e[1000009];
void adde(int a,int b,int c)
{
	e[++tp]=edge{a,b,c};
}
int main()
{
	scanf("%d%d",&l0,&r0);
	printf("YES\n");
	if(l0==r0)
		return printf("2 1\n1 2 %d",l0),0;
	// if(l0+1==r0)
	// 	return printf("3 3\n1 2 1\n2 3 %d\n1 3 %d\n",l0,l0),0;
	int len=r0-l0,mx=0,ost=l0-1;
	for(int i=0;i<=20;i++)
		if(len>>i&1)
			mx=i;
	n=mx+3;
	for(int i=2;i<=n-2;i++)
		for(int j=1;j<i;j++)
			adde(j,i,1<<(i-2));
	for(int i=1;i<n-1;i++)
		adde(i,n-1,1);
	adde(1,n,1+ost);
	int sm=1;//already solved
	for(int i=20;i>=0;i--)
		if(len>>i&1)
		{
			int l=sm+1-(i==mx?1:1<<i);
			adde(i+2,n,l+ost);
			sm+=1<<i;
		}
	printf("%d %d\n",n,tp);
	for(int i=1;i<=tp;i++)
		printf("%d %d %d\n",e[i].u,e[i].v,e[i].len);
	return 0;
}