#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
struct node
{
	int v,id;
	bool operator<(const node &p)const{return v<p.v;}
};
int n;
node s[200009];
ll sm[200009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&s[i].v),s[i].id=i;
		sort(s+1,s+n+1);
		for(int i=1;i<=n;i++)
			sm[i]=sm[i-1]+s[i].v;
		vector<int> ans;
		for(int i=n-1;i>=1;i--)
			if(s[i+1].v!=s[i].v)
				if(sm[i]<s[i+1].v)
				{
					for(int j=i+1;j<=n;j++)
						ans.push_back(s[j].id);
					break;
				}
		if(ans.empty())
			for(int i=1;i<=n;i++)
				ans.push_back(i);
		sort(ans.begin(),ans.end());
		// printf("ans:");
		printf("%d\n",(int)ans.size());
		for(int v:ans)
			printf("%d ",v);
		printf("\n");
	}
	return 0;
}