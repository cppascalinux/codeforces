#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int ask(int l,int r)
{
	if(l==r)
		return -1;
	printf("? %d %d\n",l,r);
	fflush(stdout);
	scanf("%d",&l);
	return l;
}
void output(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
}
int main()
{
	int t;
	scanf("%d",&n);
	int p=ask(1,n);
	int sm=0;
	int tp=1;
	while(tp*2<=n)
		tp*=2;
	int rev=0;
	// if(p>1)
		if(ask(1,p)==p)
			rev=1;
	for(int i=tp;i>=1;i/=2)
	{
		if(sm+i>n)
			continue;
		int np;
		if(!rev)
			np=ask(1,sm+i);
		else
			np=ask(n-(sm+i)+1,n);
		if(np!=p)
			sm+=i;
	}
	// printf("sm:%d\n",sm);
	output(rev?n-sm:sm+1);
	return 0;
}