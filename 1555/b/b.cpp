#include<bits/stdc++.h>
using namespace std;
int n,m,x1,y11,x2,y2,w,h;
double cal(int x,int y)
{
	return sqrt((double)x*x+(double)y*y);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		scanf("%d%d%d%d",&x1,&y11,&x2,&y2);
		scanf("%d%d",&w,&h);
		int w0=x2-x1,h0=y2-y11;
		if(w0+w>n&&h0+h>m)
		{
			printf("-1\n");
			continue;
		}
		int ans=1e9;
		if(w0+w<=n)
		{
			ans=min(ans,max(w-x1,0));
			ans=min(ans,max(0,w-(n-x2)));
		}
		if(h0+h<=m)
		{
			ans=min(ans,max(0,h-y11));
			ans=min(ans,max(0,h-(m-y2)));
		}
		printf("%d\n",ans);
	}
	return 0;
}