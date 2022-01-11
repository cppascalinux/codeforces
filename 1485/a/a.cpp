#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int solve(int a,int b)
{
	int ans=0;
	while(a)
		a/=b,ans++;
	return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		int sm=0,ans=0x7F7F7F7F;
		scanf("%d%d",&a,&b);
		if(b==1)
			sm++,b++;
		for(int i=0;i<=10;i++)
			ans=min(ans,solve(a,b+i)+i+sm);
		printf("%d\n",ans);
	}
	return 0;
}