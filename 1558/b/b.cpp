#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int f[4000009],sm[4000009];
int main()
{
	scanf("%d%d",&n,&m);
	f[1]=1;
	for(int i=1;i<=n;i++)
	{
		(sm[i]+=sm[i-1])%=m;
		f[i]=sm[i];
		if(i==1)
			f[i]=1;
		// printf("i:%d f:%d\n",i,f[i]);
		(sm[i+1]+=f[i])%=m;
		for(int j=2;i*j<=n;j++)
		{
			(sm[i*j]+=f[i])%=m;
			if((i+1)*j<=n)
				(sm[(i+1)*j]+=m-f[i])%=m;
		}
	}
	printf("%d",f[n]);
	return 0;
}