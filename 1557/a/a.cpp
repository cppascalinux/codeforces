#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[100009];
double sm[100009];
int main()
{
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i);
		sort(s+1,s+n+1);
		for(int i=1;i<=n;i++)
			sm[i]=sm[i-1]+s[i];
		double ans=-2e9;
		for(int i=1;i<=n-1;i++)
		{
			double cur=sm[i]/i+(sm[n]-sm[i])/(n-i);
			ans=max(ans,cur);
		}
		printf("%.12lf\n",ans);
	}
	return 0;
}