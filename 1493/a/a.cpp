#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		vector<int> ans;
		for(int i=k+1;i<=n;i++)
			ans.push_back(i);
		for(int i=(k+1)/2;i<k;i++)
			ans.push_back(i);
		printf("%d\n",(int)ans.size());
		for(int v:ans)
			printf("%d ",v);
		printf("\n");
	}
	return 0;
}