#include<bits/stdc++.h>
#define ll long long
#define inf 0x7F7F7F7F
using namespace std;
int n;
int t[5009],x[5009];
int f[5009][5009][2];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",t+i,x+i);
	memset(f,0x7F,sizeof(f));
	f[0][0][1]=0;
	for(int i=0;i<=n;i++)
	{
		int pf=inf;
		for(int j=0;j<=i-1;j++)
			pf=min(pf,min(f[i][j][0],f[i][j][1]));
		for(int j=i+1;j<=n;j++)//next pos to put the clone
		{
			if((ll)pf+abs(x[j]-x[i])<=t[j])
				f[i][j][1]=min((ll)f[i][j][1],(ll)pf+abs(x[j]-x[i]));
			int lsp=i>0?x[i-1]:x[i];
			if((ll)f[i][i][0]+abs(x[j]-lsp)<=t[j])
				f[i][j][1]=min(f[i][j][1],max(t[i],f[i][i][0]+abs(x[j]-lsp)));
			if((ll)f[i][i][1]+abs(x[j]-x[i])<=t[j])
				f[i][j][1]=min(f[i][j][1],max(t[i],f[i][i][1]+abs(x[j]-x[i])));
		}
		if(i<n)
		{
			for(int j=0;j<=n;j++)
				if(j!=i+1)
				{
					int lsp=j==i&&i>0?x[i-1]:x[i];
					if((ll)f[i][j][0]+abs(x[i+1]-lsp)<=t[i+1])
						f[i+1][j][0]=t[i+1];
					if((ll)f[i][j][1]+abs(x[i+1]-x[j])<=t[i+1])
						f[i+1][j][0]=t[i+1];
				}
			f[i+1][i+1][0]=f[i][i+1][0];
			f[i+1][i+1][1]=f[i][i+1][1];
		}
	}
	// for(int i=0;i<=n;i++)
	// 	for(int j=0;j<=n;j++)
	// 		printf("i:%d j:%d f0:%d f1:%d\n",i,j,f[i][j][0],f[i][j][1]);
	int fg=0;
	for(int i=0;i<=n;i++)
		if(f[n][i][0]<inf||f[n][i][1]<inf)
			fg=1;
	printf("%s",fg?"YES":"NO");
	return 0;
}