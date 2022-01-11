#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n;
int s[200009],q[200009];
pii mp[400009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i);
		s[n+1]=-1;
		int tp=0;
		for(int i=1;i<=2*n;i++)
			if(*lower_bound(s+1,s+n+1,i)!=i)
				q[++tp]=i;
		// printf("s1:%d q1:%d\n",s[1],q[1]);
		int l=0,r=n;
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			int tp=0;
			for(int i=1;i<=mid;i++)
				mp[++tp]=pii(s[i],1);
			for(int i=n;i>=n-mid+1;i--)
				mp[++tp]=pii(q[i],-1);
			sort(mp+1,mp+tp+1);
			int sm=0,fg=1;
			for(int i=1;i<=tp;i++)
				if((sm+=mp[i].se)<0)
					fg=0;
			if(fg)
				l=mid;
			else
				r=mid-1;
		}
		int rbd=l;
		for(int i=1;i<=n;i++)
			s[i]=2*n+1-s[i],q[i]=2*n+1-q[i];
		sort(s+1,s+n+1);
		sort(q+1,q+n+1);
		l=0,r=n;
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			int tp=0;
			for(int i=1;i<=mid;i++)
				mp[++tp]=pii(s[i],1);
			for(int i=n;i>=n-mid+1;i--)
				mp[++tp]=pii(q[i],-1);
			sort(mp+1,mp+tp+1);
			int sm=0,fg=1;
			for(int i=1;i<=tp;i++)
				if((sm+=mp[i].se)<0)
					fg=0;
			if(fg)
				l=mid;
			else
				r=mid-1;
		}
		int lbd=n-l;
		// printf("rbd:%d lbd:%d\n",rbd,lbd);
		printf("%d\n",rbd-lbd+1);
	}
	return 0;
}