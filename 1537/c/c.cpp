#include<bits/stdc++.h>
using namespace std;
int n;
int h[200009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",h+i);
		sort(h+1,h+n+1);
		if(n==2)
		{
			for(int i=1;i<=n;i++)
				printf("%d ",h[i]);
			printf("\n");
			continue;
		}
		int mn=2e9;
		for(int i=1;i<=n-1;i++)
			mn=min(mn,h[i+1]-h[i]);
		multiset<int> ms;
		for(int i=1;i<=n;i++)
			ms.insert(h[i]);
		int ans=0,pos=1,typ=0;
		for(int i=1;i<=n-1;i++)
			if(h[i+1]-h[i]==mn)
			{
				int sm=n-3;
				ms.erase(ms.find(h[i]));
				ms.erase(ms.find(h[i+1]));
				if(h[i]<=*ms.begin())
					sm++;
				if(*ms.rbegin()<=h[i+1])
					sm++;
				if(sm>ans)
				{
					ans=sm;
					pos=i;
					typ=0;
				}
				sm=n-2;
				if(*ms.rbegin()<=*ms.begin())
					sm++;
				if(sm>ans)
				{
					ans=sm;
					pos=i;
					typ=1;
				}
				ms.insert(h[i]);
				ms.insert(h[i+1]);
			}
		if(typ==0)
		{
			printf("%d ",h[pos]);
			for(int i=1;i<=n;i++)
				if(i<pos||i>pos+1)
					printf("%d ",h[i]);
			printf("%d ",h[pos+1]);
		}
		else
		{
			printf("%d ",h[pos]);
			for(int i=pos+2;i<=n;i++)
				printf("%d ",h[i]);
			for(int i=1;i<=pos-1;i++)
				printf("%d ",h[i]);
			printf("%d ",h[pos+1]);
		}
		printf("\n");
	}
	return 0;
}