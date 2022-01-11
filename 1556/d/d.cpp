#include<bits/stdc++.h>
using namespace std;
int n,k;
int ad[10009],r[10009],xr[10009];
int vl[10009];
int ask(int a,int b,int typ)
{
	if(typ==0)
		printf("or %d %d\n",a,b);
	else
		printf("and %d %d\n",a,b);
	fflush(stdout);
	scanf("%d",&a);
	return a;
}
void print(int a)
{
	printf("finish %d\n",a);
	fflush(stdout);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=2;i<=n;i++)
	{
		r[i]=ask(1,i,0);
		ad[i]=ask(1,i,1);
		xr[i]=r[i]^ad[i];
	}
	int pr=ask(2,3,0);
	int pa=ask(2,3,1);
	for(int i=0;i<=30;i++)
	{
		int v2=xr[2]>>i&1,v3=xr[3]>>i&1;
		if(v2==0&&v3==0)
		{
			vl[1]|=pr&(1<<i);
		}
		else if(v2==1&&v3==1)
			vl[1]|=(pr&(1<<i))^(1<<i);
		else
		{
			if(v2==0)
				vl[1]|=ad[2]&(1<<i);
			else
				vl[1]|=ad[3]&(1<<i);
		}
	}
	for(int i=2;i<=n;i++)
		vl[i]=vl[1]^xr[i];
	// for(int i=1;i<=n;i++)
	// 	printf("%d ",vl[i]);
	// printf("\n");
	sort(vl+1,vl+n+1);
	print(vl[k]);
	return 0;
}