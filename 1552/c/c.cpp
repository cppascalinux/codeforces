#include<bits/stdc++.h>
#
using namespace std;
int n,k;
int x[109],y[109];
int vis[209];
int chk(int x1,int y1,int x2,int y2)
{
	if(x1>y1)
		swap(x1,y1);
	return (x2>=x1&&x2<=y1)^(y2>=x1&&y2<=y1);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=2*n;i++)
			vis[i]=0;
		for(int i=1;i<=k;i++)
		{
			scanf("%d%d",x+i,y+i);
			vis[x[i]]=vis[y[i]]=1;
		}
		vector<int> v;
		for(int i=1;i<=2*n;i++)
			if(!vis[i])
				v.push_back(i);
		int tp=k;
		for(int i=0;i<n-k;i++)
		{
			x[++tp]=v[i];
			y[tp]=v[i+n-k];
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<i;j++)
				ans+=chk(x[i],y[i],x[j],y[j]);
		printf("%d\n",ans);
	}
	return 0;
}