#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
char s[200009];
vector<int> ps[2];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		ps[0].clear(),ps[1].clear();
		ps[0].push_back(0),ps[1].push_back(0);
		for(int i=1;i<=n;i++)
			if(s[i]=='0'||s[i]=='1')
			{
				s[i]-='0';
				if(i&1)
					s[i]^=1;
				ps[s[i]].push_back(i);
			}
			else
				s[i]=-1;
		ll ans=0;
		for(int i=1;i<=n;i++)
			if(s[i]>=0)
			{
				int nv=s[i]^1;
				int lp=lower_bound(ps[nv].begin(),ps[nv].end(),i)-ps[nv].begin()-1;
				ans+=i-ps[nv][lp];
			}
			else
			{
				int p0=lower_bound(ps[0].begin(),ps[0].end(),i)-ps[0].begin()-1;
				p0=ps[0][p0];
				int p1=lower_bound(ps[1].begin(),ps[1].end(),i)-ps[1].begin()-1;
				p1=ps[1][p1];
				ans+=i-min(p0,p1);
			}
		printf("%lld\n",ans);
	}
	return 0;
}