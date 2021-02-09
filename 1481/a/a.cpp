#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int px,py;
char s[100009];
int sm[5];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&px,&py);
		scanf("%s",s+1);
		int n=strlen(s+1);
		memset(sm,0,sizeof(sm));
		for(int i=1;i<=n;i++)
			if(s[i]=='R')
				sm[1]++;
			else if(s[i]=='L')
				sm[2]++;
			else if(s[i]=='U')
				sm[3]++;
			else if(s[i]=='D')
				sm[4]++;
		int dx=-px+(sm[1]-sm[2]),dy=-py+(sm[3]-sm[4]);
		int flg=1;
		if(dx>0&&sm[1]<dx)
			flg=0;
		if(dx<0&&sm[2]<-dx)
			flg=0;
		if(dy>0&&sm[3]<dy)
			flg=0;
		if(dy<0&&sm[4]<-dy)
			flg=0;
		printf("%s\n",flg?"YES":"NO");
	}
	return 0;
}