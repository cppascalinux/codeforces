#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[1009];
int main()
{
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		scanf("%d%d",&n,&m);
		m=min(n,m);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
			s[i]-='0';
		s[0]=s[n+1]=0;
		for(int i=1;i<=m;i++)
		{
			vector<int> tmp;
			for(int j=1;j<=n;j++)
				if(!s[j])
				{
					int sm=s[j-1]+s[j+1];
					if(sm==1)
						tmp.push_back(j);
				}
			for(int v:tmp)
				s[v]=1;
		}
		for(int i=1;i<=n;i++)
			printf("%d",s[i]);
		printf("\n");
	}
	return 0;
}