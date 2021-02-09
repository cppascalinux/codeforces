#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int n;
int s[500009];
int f[500009];
int ls[500009],rs[500009],sm[500009],lf[500009];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i),sm[s[i]]++;
	for(int i=1;i<=n;i++)
		rs[s[i]]=i;
	for(int i=n;i>=1;i--)
		ls[s[i]]=i;
	for(int i=n;i>=1;i--)
	{
		f[i]=f[i+1];
		lf[s[i]]++;
		if(i==ls[s[i]])
			f[i]=max(f[i],f[rs[s[i]]+1]+sm[s[i]]);
		else
			f[i]=max(f[i],lf[s[i]]);
	}
	printf("%d",n-f[1]);
	return 0;
}