#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
int n;
struct pt
{
	ll x,y;
	bool operator<(const pt &p)const{return x<p.x||(x==p.x&&y<p.y);}
	pt operator+(const pt &p)const{return pt{x+p.x,y+p.y};}
	pt operator-(const pt &p)const{return pt{x-p.x,y-p.y};}
	ll operator*(const pt &p)const{return x*p.x+y*p.y;}
	ll operator^(const pt &p)const{return x*p.y-y*p.x;}
};
pt p[5009];
int ans[5009];
ll dot(pt a,pt b,pt c)
{
	return (b-a)*(c-a);
}
ll cross(pt a,pt b,pt c)
{
	return (b-a)^(c-a);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&p[i].x,&p[i].y),ans[i]=i;
	for(int i=3;i<=n;i++)
	{
		int pos=i;
		while(pos>=3&&dot(p[ans[pos-1]],p[ans[pos-2]],p[ans[pos]])<=0)
			swap(ans[pos],ans[pos-1]),pos--;
	}
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}