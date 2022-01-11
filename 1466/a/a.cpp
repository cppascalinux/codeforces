#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		int s[60];
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i);
		set<int> p;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(s[i]-s[j]!=0)
					p.insert(abs(s[i]-s[j]));
		printf("%d\n",(int)p.size());
	}
	return 0;
}