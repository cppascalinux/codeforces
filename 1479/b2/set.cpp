#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int n;
int s[100009];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i);
	set<int> p;
	int ans=0;
	for(int i=1;i<=n;i++)
		if(s[i]!=s[i-1])
		{
			if(p.count(s[i]))
				p.clear();
			else
				ans++;
			p.insert(s[i-1]);
		}
	printf("%d",ans);
	return 0;
}