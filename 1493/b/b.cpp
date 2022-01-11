#include<bits/stdc++.h>
using namespace std;
int h,m,ch,cm;
int v[10]={0,1,5,-1,-1,2,-1,-1,8,-1};
int judge(int a,int b)
{
	int s[4]={a/10,a%10,b/10,b%10};
	for(int i=0;i<4;i++)
		if(v[s[i]]==-1)
			return 0;
		else
			s[i]=v[s[i]];
	reverse(s,s+4);
	int na=s[0]*10+s[1],nb=s[2]*10+s[3];
	if(!(na>=0&&na<h&&nb>=0&&nb<m))
		return 0;
	return 1;
}
void add(int &a,int &b)
{
	b++;
	if(b==m)
	{
		b=0,a++;
		if(a==h)
			a=0;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&h,&m);
		scanf("%d:%d",&ch,&cm);
		while(!judge(ch,cm))
			add(ch,cm);
		printf("%d%d:%d%d\n",ch/10,ch%10,cm/10,cm%10);
	}
	return 0;
}