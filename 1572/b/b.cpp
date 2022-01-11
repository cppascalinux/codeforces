#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,tp;
int s[200009];
int ed[200009];
int main()
{
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		scanf("%d",&n);
		tp=0;
		int sm=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",s+i);
			sm^=s[i];
		}
		if(sm==1)
		{
			printf("NO\n");
			continue;
		}
		s[n+1]=-1;
		for(int i=1;i<=n;i++)
			if(s[i]!=s[i+1])
				ed[++tp]=i;
		if(tp==1)
		{
			if(s[1]==0)
				printf("YES\n0\n");
			else
				printf("NO\n");
			continue;
		}
		vector<int> ans;
		int cure,lft,err=0;
		if(s[1]==0)
			cure=2,lft=ed[1];
		else
			cure=1,lft=0;
		while(cure<=tp)
		{
			int len=ed[cure]-lft;
			// printf("cure:%d ed:%d lft:%d\n",cure,ed[cure],lft);
			if(len%2==0)
			{
				if(lft>0)
				{
					for(int i=lft;i<=ed[cure]-2;i+=2)
						ans.push_back(i);
				}
				else if(cure<tp)
				{
					for(int i=ed[cure]-1;i>=lft+1;i-=2)
						ans.push_back(i);
				}
				else
				{
					err=1;
					break;
				}
				cure+=2;
				lft=ed[cure-1];
			}
			else
			{
				int l2=(ed[cure+1]-ed[cure])%2;
				if(l2==0)
				{
					// printf("21\n");
					for(int i=ed[cure];i<=ed[cure+1]-2;i+=2)
						ans.push_back(i);
					cure+=2;
				}
				else if(l2==1)
				{
					// printf("22\n");
					for(int i=ed[cure];i<=ed[cure+1]-3;i+=2)
						ans.push_back(i);
					ans.push_back(ed[cure+1]-1);
					for(int i=ed[cure+1]-3;i>=lft+1;i-=2)
						ans.push_back(i);
					lft=ed[cure+1]+1;
					cure+=2;
				}
			}
		}
		if(err)
			printf("NO\n");
		else
		{
			printf("YES\n%d\n",(int)ans.size());
			for(int v:ans)
				printf("%d ",v);
			printf("\n");
		}
	}
	return 0;
}