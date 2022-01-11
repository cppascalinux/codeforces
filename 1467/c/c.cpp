#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define inf 0x7F7F7F7F7F7F7F7FLL
using namespace std;
int n1,n2,n3,tp;
ll st[300009];
ll s1[300009],s2[300009],s3[300009];
int main()
{
	scanf("%d%d%d",&n1,&n2,&n3);
	ll sm1=0,sm2=0,sm3=0;
	for(int i=1;i<=n1;i++)
		scanf("%lld",s1+i),sm1+=s1[i];
	for(int i=1;i<=n2;i++)
		scanf("%lld",s2+i),sm2+=s2[i];
	for(int i=1;i<=n3;i++)
		scanf("%lld",s3+i),sm3+=s3[i];
	ll ans=inf;
	if(n1==1)
		ans=min(ans,s1[1]);
	if(n2==1)
		ans=min(ans,s2[1]);
	if(n3==1)
		ans=min(ans,s3[1]);
	if(n1==2)
		ans=min(ans,s1[1]+s1[2]);
	if(n2==2)
		ans=min(ans,s2[1]+s2[2]);
	if(n3==2)
		ans=min(ans,s3[1]+s3[2]);
	sort(s1+1,s1+n1+1);
	sort(s2+1,s2+n2+1);
	sort(s3+1,s3+n3+1);
	st[++tp]=s1[1];
	st[++tp]=s2[1];
	st[++tp]=s3[1];
	sort(st+1,st+tp+1);
	ans=min(ans,st[1]+st[2]);
	ans=min(ans,sm1);
	ans=min(ans,sm2);
	ans=min(ans,sm3);
	printf("%lld",sm1+sm2+sm3-2*ans);
	return 0;
}