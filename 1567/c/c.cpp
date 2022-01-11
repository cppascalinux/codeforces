#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll f[20][2][2];
int s[20];
int main()
{
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		scanf("%d",&n);
		m=0;
		for(int x=n;x;x/=10)
			s[++m]=x%10;
		memset(f,0,sizeof(f));
		f[0][0][0]=1;
		// printf("m:%d\n",m);
		for(int i=1;i<=m;i++)
		{
			int v=s[i];

			f[i][0][0]=f[i-1][0][0]*(v+1)+f[i-1][1][0]*v;
			f[i][1][0]=f[i-1][0][1]*(v+1)+f[i-1][1][1]*v;
			f[i][0][1]=f[i-1][0][0]*(9-v)+f[i-1][1][0]*(10-v);
			f[i][1][1]=f[i-1][0][1]*(9-v)+f[i-1][1][1]*(10-v);
			// printf("i:%d 00:%d 10:%d 01:%d 11:%d\n",i,f[i][0][0],f[i][1][0],f[i][0][1],f[i][1][1]);
		}
		printf("%lld\n",f[m][0][0]-2);
	}
	return 0;
}