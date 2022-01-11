#include<bits/stdc++.h>
using namespace std;
int n,m;
int p[300009],q[300009];
int sm[300009];
int f[300009];
int fnd(int x)
{
	return x==f[x]?x:f[x]=fnd(f[x]);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;i++)
			sm[i]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",p+i);
			sm[(i-p[i]+n)%n]++;
		}
		vector<int> ans;
		for(int i=0;i<=n-1;i++)
			if(sm[i]>=n/3-1)
			{
				for(int j=1;j<=n;j++)
					q[j]=(p[j]+i-1)%n+1,f[j]=j;
				for(int j=1;j<=n;j++)
				{
					int fa=fnd(j),fb=fnd(q[j]);
					f[fa]=fb;
				}
				int tm=n;
				for(int j=1;j<=n;j++)
					if(fnd(j)==j)
						tm--;
				if(tm<=m)
					ans.push_back(i);
			}
		printf("%d ",(int)ans.size());
		for(int v:ans)
			printf("%d ",v);
		printf("\n");
	}
	return 0;
}