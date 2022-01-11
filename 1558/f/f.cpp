#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int n,ans;
int a[19];
int inv[2000009];
int f[17009];
int tag[19];
int qpow(int a,int b)
{
	int ans=1;
	for(;b;b>>=1,a=(ll)a*a%mod)
		if(b&1)
			ans=(ll)ans*a%mod;
	return ans;
}
void init()
{
	for(int i=1;i<=2000000;i++)
		inv[i]=qpow(i,mod-2);
}
int main()
{
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int s=1;s<(1<<n);s++)
	{
		int sm=0;
		for(int t=(s-1)&s;t;t=(t-1)&s)
		{
			// printf("s:%d t:%d\n",s,t);
			int p=s^t,pb=1;
			for(int i=1;i<=n;i++)
				if(t>>(i-1)&1)
					for(int j=1;j<=n;j++)
						if(p>>(j-1)&1)
							pb=(ll)pb*a[i]%mod*inv[a[i]+a[j]]%mod;
			sm=(sm+(ll)f[t]*pb)%mod;
		}
		f[s]=(mod+1-sm)%mod;
		// printf("s:%d f:%d\n",s,f[s]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int s=1;s<(1<<n);s++)
			if(s>>(i-1)&1)
			{
				int pb=1;
				for(int j=1;j<=n;j++)
					if(s>>(j-1)&1)
						for(int k=1;k<=n;k++)
							if(!(s>>(k-1)&1))
								pb=(ll)pb*a[j]%mod*inv[a[k]+a[j]]%mod;
				ans=(ans+(ll)f[s]*pb)%mod;
			}
	printf("%d",ans);
	return 0;
}