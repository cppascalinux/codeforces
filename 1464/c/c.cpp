#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int n;
ll k;
char s[100009];
int st[100009];
void suc()
{
	printf("YES");
	exit(0);
}
void fail()
{
	printf("NO");
	exit(0);
}
int main()
{
	scanf("%d%lld",&n,&k);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		s[i]-='a';
	if(n==1)
	{
		if(k==1<<s[1])
			suc();
		else
			fail();
	}
	k-=1<<s[n];
	k+=1<<s[n-1];
	for(int i=1;i<=n-2;i++)
		k+=1<<s[i];
	for(int i=1;i<=n-2;i++)
		st[i]=1<<(s[i]+1);
	sort(st+1,st+n-1,greater<int>());
	for(int i=1;i<=n-2;i++)
		if(k>=st[i])
			k-=st[i];
	if(k)
		fail();
	else
		suc();
	return 0;
}