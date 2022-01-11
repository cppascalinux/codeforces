#include<bits/stdc++.h>
using namespace std;
int n;
int mat[3][100009];
int sm[3][100009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=2;i++)
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&mat[i][j]);
				sm[i][j]=mat[i][j]+sm[i][j-1];
			}
		int ans=2e9;
		for(int i=1;i<=n;i++)
			ans=min(ans,max(sm[2][i-1],sm[1][n]-sm[1][i]));
		printf("%d\n",ans);
	}
	return 0;
}