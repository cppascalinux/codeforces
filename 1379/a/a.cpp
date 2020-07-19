#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
char s[100],ns[100];
int test(char *ss,int x)
{
	char t[8]="abacaba";
	for(int i=0;i<=6;i++)
		if(t[i]!=ss[x+i])
			return 0;
	return 1;
}
int chk(char *ss)
{
	int tme=0;
	for(int i=1;i<=n-6;i++)
		tme+=test(ss,i);
	return tme;
}
int fil(int pos)
{
	memcpy(ns,s,n+2);
	char t[8]="abacaba";
	for(int i=0;i<=6;i++)
		ns[pos+i]=t[i];
	for(int i=1;i<=n;i++)
	{
		if(ns[i]!=s[i]&&s[i]!='?')
			return 0;
		if(ns[i]=='?')
			ns[i]='d';
	}
	if(chk(ns)==1)
		return 1;
	return 0;
}
int main()
{
#ifdef I_LOVE_KTY
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		int fg=0;
		for(int i=1;i<=n-6;i++)
			if(fil(i))
			{
				fg=1;
				printf("Yes\n");
				printf("%s\n",ns+1);
				break;
			}
		if(!fg)
			printf("No\n");
	}
	return 0;
}