#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define mod 1000000007
using namespace std;
int n;
int f[1000009],sz[1000009];
int p[1000009];
int fnd(int x)
{
	return x==f[x]?x:f[x]=fnd(f[x]);
}
int cal(int *sm)
{
	// for(int i=1;i<=4;i++)
	// 	printf("i:%d sm:%d\n",i,sm[i]);
	int rep=0;
	while(sm[1]&&sm[2])
		rep++,sm[1]--,sm[2]--;
	while(sm[2]&&sm[4])
		rep+=2,sm[2]--,sm[4]--;
	while(sm[1]>=2&&sm[4]>=1)
		rep+=3,sm[1]-=2,sm[4]--;
	while(sm[1]>=1&&sm[4]>=2)
		rep+=4,sm[1]--,sm[4]-=2;
	while(sm[1]>=3)
		rep+=2,sm[1]-=3;
	while(sm[2]>=3)
		rep+=3,sm[2]-=3;
	while(sm[4]>=3)
		rep+=5,sm[4]-=3;
	return rep;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int os=1;os<=t;os++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			f[i]=i,sz[i]=0;
		for(int i=1;i<=n;i++)
			scanf("%d",p+i),f[fnd(p[i])]=fnd(i);
		// if(t==42&&os==26)
		// 	for(int i=1;i<=n;i++)
		// 		printf("%d ",p[i]);
		for(int i=1;i<=n;i++)
			sz[fnd(i)]++;
		// for(int i=1;i<=n;i++)
		// 	if(sz[i])
		// 		printf("i:%d sz:%d\n",i,sz[i]);
		int t=n%3,ans=1,rep=0;
		if(t==0)
		{
			for(int i=1;i<=n/3;i++)
				ans=(ll)ans*3%mod;
		}
		else if(t==1)
		{
			ans=4;
			for(int i=1;i<=n/3-1;i++)
				ans=(ll)ans*3%mod;
		}
		else
		{
			ans=2;
			for(int i=1;i<=n/3;i++)
				ans=(ll)ans*3%mod;
		}
		int sm[5]={0,0,0,0,0};
		for(int i=1;i<=n;i++)
			if(sz[i])
			{
				int v=sz[i];
				if(v<=2)
					sm[v]++;
				else if(v%3==0)
				{
					rep+=v/3-1;
					sm[3]+=v/3;
				}
				else if(v%3==1)
				{
					rep+=v/3-1;
					sm[3]+=v/3-1;
					sm[4]++;
				}
				else
				{
					rep+=v/3;
					sm[3]+=v/3;
					sm[2]++;
				}
			}
		// for(int i=1;i<=4;i++)
		// 	printf("i:%d sm:%d\n",i,sm[i]);
		// printf("rep:%d\n",rep);
		if(n%3==0)
		{
			rep+=cal(sm);
		}
		else if(n%3==1)
		{
			int bsm[5],mn=mod;
			memcpy(bsm,sm,5*4);
			if(sm[2]>=2)
			{
				sm[2]-=2;
				mn=min(mn,cal(sm));
				memcpy(sm,bsm,5*4);
			}
			if(sm[4]>=1)
			{
				sm[4]--;
				mn=min(mn,cal(sm));
				memcpy(sm,bsm,5*4);
			}
			if(sm[1]>=4)
			{
				sm[1]-=4;
				mn=min(mn,cal(sm)+2);
				memcpy(sm,bsm,5*4);
			}
			if(sm[1]>=2&&sm[2]>=1)
			{
				sm[1]-=2,sm[2]--;
				mn=min(mn,cal(sm)+1);
				memcpy(sm,bsm,5*4);
			}
			if(sm[1]>=1&&sm[3]>=1)
			{
				sm[1]--;
				mn=min(mn,cal(sm)+1);
				memcpy(sm,bsm,5*4);
			}
			rep+=mn;
		}
		else
		{
			int bsm[5],mn=mod;
			memcpy(bsm,sm,5*4);
			if(sm[2]>=1)
			{
				sm[2]--;
				mn=min(mn,cal(sm));
				memcpy(sm,bsm,5*4);
			}
			if(sm[1]>=2)
			{
				sm[1]-=2;
				mn=min(mn,cal(sm)+1);
				memcpy(sm,bsm,5*4);
			}
			if(sm[1]>=1&&sm[4]>=1)
			{
				sm[1]--,sm[4]--;
				mn=min(mn,cal(sm)+2);
				memcpy(sm,bsm,5*4);
			}
			if(sm[4]>=2)
			{
				sm[4]-=2;
				mn=min(mn,cal(sm)+3);
				memcpy(sm,bsm,5*4);
			}
			rep+=mn;
		}
		// if(t!=42)
		printf("%d %d\n",ans,rep);
	}
	return 0;
}