#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int p[200009],q[200009];
int main()
{
	int a,b,k;
	scanf("%d%d%d",&a,&b,&k);
	b--;
	if(k==0)
	{
		printf("Yes\n");
		for(int i=1;i<=b+1;i++)
			printf("1");
		for(int i=1;i<=a;i++)
			printf("0");
		printf("\n");
		for(int i=1;i<=b+1;i++)
			printf("1");
		for(int i=1;i<=a;i++)
			printf("0");
		return 0;
	}
	if(k>=a+b)
		return printf("No"),0;
	if(a==0||b==0)
		return printf("No"),0;
	p[1]=q[1]=1;
	int n=a+b+1;
	// printf("a:%d b:%d n:%d\n",a,b,n);
	p[n]=0,q[n]=1;
	p[n-k]=1,q[n-k]=0;
	a--,b--;
	for(int i=2;i<=n;i++)
		if(i!=n-k&&i!=n)
		{
			if(a)
				p[i]=q[i]=0,a--;
			else
				p[i]=q[i]=1,b--;
		}
	printf("Yes\n");
	for(int i=1;i<=n;i++)
		printf("%d",p[i]);
	printf("\n");
	for(int i=1;i<=n;i++)
		printf("%d",q[i]);
	return 0;
}