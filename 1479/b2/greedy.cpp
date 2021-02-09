#include<iostream>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int s[100009];
vector<int> vs[100009];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i),vs[s[i]].push_back(i);
	for(int i=0;i<=n;i++)
		vs[i].push_back(n+1);
	int p1=0,p2=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]==s[p1]&&s[i]==s[p2])
			p1=i;
		else if(s[i]==s[p1])
			p1=i;
		else if(s[i]==s[p2])
			p2=i;
		else
		{
			ans++;
			int nxt1=*lower_bound(vs[s[p1]].begin(),vs[s[p1]].end(),i);
			int nxt2=*lower_bound(vs[s[p2]].begin(),vs[s[p2]].end(),i);
			if(nxt1>nxt2)
				p1=i;
			else
				p2=i;
		}
	}
	printf("%d",ans);
	return 0;
}