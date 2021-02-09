#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
#define ll long long
using namespace std;
int n,tp;
int s[100009],nxt[100009],pos[100009];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i);
	for(int i=1;i<=n;i++)
		pos[i]=n+1;
	for(int i=n;i>=1;i--)
		nxt[i]=pos[s[i]],pos[s[i]]=i;
	int p1=0,p2=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		if(s[p1]==s[i])
			nxt[p1]=nxt[i];
		else if(s[p2]==s[i])
			nxt[p2]=nxt[i];
		else
		{
			ans++;
			if(nxt[p1]<nxt[p2]||p2==0)
				swap(p1,p2);
			p1=i;
		}
		// printf("i:%d p1:%d p2:%d nxt1:%d nxt2:%d\n",i,p1,p2,nxt[p1],nxt[p2]);
	}
	printf("%d",ans);
	return 0;
}