#include<bits/stdc++.h>
using namespace std;
int n,m;
int st[100009];
int main()
{
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		scanf("%d%d",&n,&m);
		int tp=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				int mx=max(abs(i-1),(n-i))+max(abs(j-1),abs(m-j));
				st[++tp]=mx;
			}
		}
		sort(st+1,st+tp+1);
		for(int i=1;i<=tp;i++)
			printf("%d ",st[i]);
		printf("\n");
	}
	return 0;
}