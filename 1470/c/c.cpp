#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,k;
int ask(int p)
{
	printf("? %d\n",p);
	fflush(stdout);
	scanf("%d",&p);
	return p;
}
void out(int p)
{
	printf("! %d",p);
	exit(0);
}
int main()
{
	scanf("%d%d",&n,&k);
	int l=0,r=0,len=sqrt(n);
	if(n<=100)
		len=1;
	for(int i=1;!l||!r;i=(i+len-1)%n+1)
	{
		int t=ask(i);
		if(t<k)
			l=i;
		else if(t>k)
			r=i;
	}
	if(r<l)
		r+=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		int t=ask((mid-1)%n+1);
		if(t==k)
			out((mid-1)%n+1);
		if(t>k)
			r=mid-1;
		else
			l=mid+1;
	}
	return 0;
}