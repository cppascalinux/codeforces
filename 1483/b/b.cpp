#include<bits/stdc++.h>
using namespace std;
int n;
int s[100009],f[100009];
int nxt[100009];
int gcd(int a,int b)
{
	return !a||!b?a+b:gcd(b,a%b);
}
int fnd(int x)
{
	return x==f[x]?x:f[x]=fnd(f[x]);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i);
		for(int i=1;i<=n;i++)
			f[i]=i,nxt[i]=i%n+1;
		int cur=1,cnt=0;
		vector<int> ans;
		while(1)
		{
			int p=nxt[cur];
			if(p==cur&&s[p]==1)
			{
				ans.push_back(p);
				break;
			}
			if(gcd(s[cur],s[p])==1)
			{
				nxt[cur]=nxt[p];
				cur=fnd(nxt[p]);
				ans.push_back(p);
			}
			else
			{
				if(fnd(cur)==fnd(p))
					break;
				f[fnd(cur)]=fnd(p);
				cur=fnd(p);
			}
		}
		printf("%d ",(int)ans.size());
		for(int v:ans)
			printf("%d ",v);
		printf("\n");
	}
	return 0;
}