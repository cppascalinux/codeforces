#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int s[100009];
int ns[100009],tp;
int pos[100009],lst[100009];
int f[100009];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",s+i);
		if(s[i]!=s[i-1])
			ns[++tp]=s[i];
	}
	for(int i=1;i<=tp;i++)
	{
		f[i]=f[i-1];
		lst[i]=pos[ns[i]];
		pos[ns[i]]=i;
		if(lst[i])
			f[i]=max(f[i],f[lst[i]+1]+1);
	}
	printf("%d",tp-f[tp]);
	return 0;
}