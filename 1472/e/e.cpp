#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
struct node
{
	int h,w,id;
};
int n;
node s[200009],p[200009];
int ans[200009];
bool cmp1(node a,node b)
{
	return a.h<b.h;
}
bool cmp2(node a,node b)
{
	return a.w<b.w;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d",&s[i].h,&s[i].w),s[i].id=i,p[i]=s[i];//h,w
		sort(s+1,s+n+1,cmp1);
		sort(p+1,p+n+1,cmp2);
		map<int,int> mp;
		int lst=1;
		for(int i=1;i<=n;i++)
			ans[i]=-1;
		for(int i=1;i<=n;i++)
		{
			auto it=mp.lower_bound(s[i].w);
			if(it!=mp.begin())
				ans[s[i].id]=(--it)->se;
			if(s[i+1].h>s[i].h)
			{
				for(int j=lst;j<=i;j++)
					mp[s[j].w]=s[j].id;
				lst=i+1;
			}
		}
		mp.clear();
		int lp=0;
		for(int i=1;i<=n;i++)
		{
			while(lp<n&&p[lp+1].w<s[i].h)
				lp++,mp[p[lp].h]=p[lp].id;
			auto it=mp.lower_bound(s[i].w);
			if(it!=mp.begin())
				ans[s[i].id]=(--it)->se;
		}
		// printf("qwq:");
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}