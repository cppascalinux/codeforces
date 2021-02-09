#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define inf 0x7F7F7F7F
using namespace std;
int n;
int s[100009];
int qry(int p)
{
	printf("? %d\n",p);
	fflush(stdout);
	scanf("%d",&p);
	return p;
}
void output(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
	exit(0);
}
int main()
{
	scanf("%d",&n);
	if(n<=100)
	{
		for(int i=1;i<=n;i++)
			s[i]=qry(i);
		s[0]=s[n+1]=inf;
		for(int i=1;i<=n;i++)
			if(s[i]<s[i-1]&&s[i]<s[i+1])
				output(i);
	}
	s[1]=qry(1);
	s[2]=qry(2);
	if(s[1]<s[2])
		output(1);
	s[n-1]=qry(n-1);
	s[n]=qry(n);
	if(s[n]<s[n-1])
		output(n);
	int l=2,r=n-1;
	while(r-l>10)
	{
		int mid=(l+r)/2;
		int c1=qry(mid),c2=qry(mid+1);
		s[mid]=c1,s[mid+1]=c2;
		if(c1<c2)
			r=mid;
		else
			l=mid+1;
	}
	for(int i=l;i<=r;i++)
		if(!s[i])
			s[i]=qry(i);
	for(int i=l;i<=r;i++)
		if(s[i]<s[i-1]&&s[i]<s[i+1])
			output(i);
	return 0;
}