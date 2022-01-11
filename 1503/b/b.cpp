#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n;
void out(int c,int x,int y)
{
	printf("%d %d %d\n",c,x,y);
	fflush(stdout);
}
int main()
{
	scanf("%d",&n);
	vector<pii> v1,v2;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if((i+j)&1)
				v1.push_back(pii(i,j));
			else
				v2.push_back(pii(i,j));
	for(int i=1;i<=n*n;i++)
	{
		int a;
		scanf("%d",&a);
		if(a==1)
		{
			if(v2.size())
			{
				out(2,v2.back().fi,v2.back().se);
				v2.pop_back();
			}
			else
			{
				out(3,v1.back().fi,v1.back().se);
				v1.pop_back();
			}
		}
		else
		{
			if(v1.size())
			{
				out(1,v1.back().fi,v1.back().se);
				v1.pop_back();
			}
			else
			{
				int c=6-1-a;
				out(c,v2.back().fi,v2.back().se);
				v2.pop_back();
			}
		}
	}
	return 0;
}