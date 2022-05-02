#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,k;
int b[1050009];
int pa1[1050009],pa2[1050009];
int ans[1050009];
int cb(int a,int b)
{
	for(int i=0;i<=21;i++)
		if(!((a>>i)&1)&&((b>>i)&1))
			return 0;
	return 1;
}
int main()
{
	// printf("%d %d",cb(5,1),cb(5,2));
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",b+i);
	for(int i=max(0,n-30);i<=n;i++)
	{
		if(k-1<=0)
			pa1[i]=(i==0);
		else
			pa1[i]=cb(i-1,k-2);
		if(k-2<=0)
			pa2[i]=(i==0);
		else
			pa2[i]=cb(i-1,k-3);
	}
	for(int l=1;l<=min(22,n);l++)
	{
		for(int i=1;i<=n-l+1;i++)
		{
			ll sm=b[i];
			int fl=0;
			for(int j=i+1;j<=i+l-1;j++)
			{
				if(b[j]>20)
				{
					fl=1;
					break;
				}
				sm*=1<<b[j];
				if(sm>=(1<<20))
				{
					fl=1;
					break;
				}
			}
			if(fl)
				continue;
			if(l==n)
			{
				if(k==0)
					ans[sm]^=1;
				continue;
			}
			if(i==1||i==(n-l+1))
			{
				if(n-l-1+1>=k&&pa1[n-l-1])
					ans[sm]^=1;
			}
			else if(n-l-2+2>=k&&pa2[n-l-2])
				ans[sm]^=1;
		}
	}
	int tp=0;
	for(int i=(1<<20)-1;i>=0;i--)
		if(ans[i])
		{
			tp=1;
			for(int j=i;j>=0;j--)
				printf("%d",ans[j]);
			break;
		}
	if(!tp)
		printf("0");
	return 0;
}