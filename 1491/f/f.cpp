#include<bits/stdc++.h>
using namespace std;
int n;
int qry(int l1,int r1,int l2,int r2)
{
	printf("? %d %d\n",r1-l1+1,r2-l2+1);
	for(int i=l1;i<=r1;i++)
		printf("%d ",i);
	printf("\n");
	for(int i=l2;i<=r2;i++)
		printf("%d ",i);
	printf("\n"),fflush(stdout);
	scanf("%d",&l1);
	return l1;
}
void output(vector<int> &ans)
{
	printf("! %d",(int)ans.size());
	for(int v:ans)
		printf(" %d",v);
	printf("\n"),fflush(stdout);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int p=0;
		vector<int> ans;
		for(int i=2;i<=n;i++)
		{
			int t=qry(1,i-1,i,i);
			if(t)
			{
				p=i;
				break;
			}
		}
		for(int i=p+1;i<=n;i++)
			if(!qry(p,p,i,i))
				ans.push_back(i);
		int l=1,r=p-1;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(qry(p,p,l,mid))
				r=mid;
			else
				l=mid+1;
		}
		for(int i=1;i<=p-1;i++)
			if(i!=l)
				ans.push_back(i);
		output(ans);
	}
	return 0;
}