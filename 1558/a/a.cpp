#include<bits/stdc++.h>
using namespace std;
int main()
{
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a<b)
			swap(a,b);
		int n=a+b;
		if(n%2==0)
		{
			int v=n/2;
			int mn=a-v;
			int mx=n-mn;
			printf("%d\n",(mx-mn)/2+1);
			for(int i=mn;i<=mx;i+=2)
				printf("%d ",i);
			printf("\n");
		}
		else
		{
			vector<int> ans;
			int v=n/2;
			int mn=n-(min(a,v+1)+min(b,v));
			int mx=min(a,v)+min(b,v+1);
			for(int i=mn;i<=mx;i+=2)
				ans.push_back(i);
			mn=n-(min(a,v)+min(b,v+1));
			mx=min(a,v+1)+min(b,v);
			for(int i=mn;i<=mx;i+=2)
				ans.push_back(i);
			sort(ans.begin(),ans.end());
			printf("%d\n",(int)ans.size());
			for(int t:ans)
				printf("%d ",t);
			printf("\n");
		}
	}
	return 0;
}