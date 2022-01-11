#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,sm[2]={0};
		scanf("%d",&n);
		for(int i=1;i<=n*2;i++)
		{
			int a;
			scanf("%d",&a);
			sm[a%2]++;
		}
		printf("%s\n",sm[0]==sm[1]?"YES":"NO");
	}
	return 0;
}