#include<bits/stdc++.h>
using namespace std;
int n;
char s[4][200009];
vector<int> md[200009];
int sm[4];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=3;i++)
		{
			scanf("%s",s[i]+1);
			for(int j=1;j<=2*n;j++)
				s[i][j]-='0';
		}
		for(int i=1;i<=3;i++)
			sm[i]=0;
		for(int i=1;i<=3;i++)
			for(int j=1;j<=2*n;j++)
				sm[i]+=s[i][j];
		int c0=0,c1=0,v=0,mx=0;
		for(int i=1;i<=3;i++)
			for(int j=i+1;j<=3;j++)
			{
				if(min(sm[i],sm[j])>=n)
					c0=i,c1=j,v=1,mx=min(sm[i],sm[j]);
				else if(min(2*n-sm[i],2*n-sm[j])>=n)
					c0=i,c1=j,v=0,mx=min(2*n-sm[i],2*n-sm[j]);
			}
		// printf("c0:%d c1:%d v:%d mx:%d\n",c0,c1,v,mx);
		int lp0=0,lp1=0;
		for(int i=0;i<=2*n;i++)
			md[i].clear();
		for(int i=1;i<=2*n;i++)
		{
			if(s[c0][i]==v&&lp0<mx)
				lp0++;
			else
				md[lp0].push_back(s[c0][i]);
			if(s[c1][i]==v&&lp1<mx)
				lp1++;
			else
				md[lp1].push_back(s[c1][i]);
		}
		for(int i=0;i<=mx;i++)
		{
			if(i)
				printf("%d",v);
			for(int t:md[i])
				printf("%d",t);
		}
		printf("\n");
	}
	return 0;
}