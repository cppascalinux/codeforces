#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m;
int mx[300009];
void init()
{
	mx[2]=2;
	mx[3]=6;
	int t=100000;
	for(int i=1;i<=t;i++)
	{
		mx[i*3+1]=mx[i*3]+i*4;
		mx[i*3+2]=mx[i*3+1]+4*i+2;
		mx[i*3+3]=mx[i*3+2]+4*i+4;
		if(mx[i*3+3]>=2e9)
		{
			m=i*3+3;
			break;
		}
	}
	// printf("%d %d %d",mx[4],mx[5],mx[6]);
	// printf("m:%d\n",m);
}
int cal(int x)
{
	return lower_bound(mx+1,mx+m+1,x)-mx;
}
int main()
{
	init();
	int tt;
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d",&n);
		printf("%d\n",cal(n));
	}
	return 0;
}