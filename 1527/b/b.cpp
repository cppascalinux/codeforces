#include<bits/stdc++.h>
#define inf 0x3F3F3F3F
using namespace std;
int f[1009][1009][2][2];
int n;
char s[1009];
void init()
{
	memset(f,0x3F,sizeof(f));
	for(int i=0;i<=1000;i++)
		for(int j=0;j<=1000;j++)
		{
			if(i==0&&j==0)
			{
				f[i][j][1][0]=0;
			}
			if(j)
			{
				f[i][j][0][0]=min(f[i][j][0][0],max(-f[i][j-1][0][0],-f[i][j-1][0][1])+1);
				f[i][j][1][0]=min(f[i][j][1][0],max(-f[i][j-1][1][0],-f[i][j-1][1][1])+1);
			}
			if(i&&j+1<=1000)
			{
				f[i][j][0][0]=min(f[i][j][0][0],max(-f[i-1][j+1][0][0],-f[i-1][j+1][0][1])+1);
				f[i][j][1][0]=min(f[i][j][1][0],max(-f[i-1][j+1][1][0],-f[i-1][j+1][1][1])+1);
			}
			f[i][j][0][0]=min(f[i][j][0][0],-f[i][j][1][0]+1);
			if(j)
			{
				f[i][j][0][1]=min(f[i][j][0][1],-f[i][j][0][0]);
				f[i][j][1][1]=min(f[i][j][1][1],-f[i][j][1][0]);
			}
			// else
			// 	f[i][j][0][1]=f[i][j][1][1]=inf;
			// printf("i:%d j:%d 00:%d 01:%d 10:%d 11:%d\n",i,j,f[i][j][0][0],f[i][j][0][1],f[i][j][1][0],f[i][j][1][1]);
		}
}
int main()
{
	init();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
			s[i]-='0';
		int smi=0,smj=0,bg=1;
		for(int i=1;i<=n/2;i++)
			if(s[i]==0&&s[n+1-i]==0)
				smi++;
			else if(s[i]==0||s[n+1-i]==0)
				smj++;
		if(n%2==1&&s[n/2+1]==0)
			bg=0;
		int ans=min(f[smi][smj][bg][0],f[smi][smj][bg][1]);
		printf("%s\n",ans<0?"ALICE":ans>0?"BOB":"DRAW");
	}
	return 0;
}