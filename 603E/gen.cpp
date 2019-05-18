#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<random>
using namespace std;
struct node
{
	int a,b,c;
	node(){}
	node(int x,int y,int z){a=x,b=y,c=z;}
};
node e[300009];
int main()
{
	freopen("lct.in","w",stdout);
	random_device sd;
	mt19937 rnd(sd());
	int n=60,m=300000;
	printf("%d %d\n",n,m);
	for(int i=2;i<=n;i++)
		e[i-1]=node(i,rnd()%(i-1)+1,rnd()%10+1);
	for(int i=n;i<=m;i++)
	{
		int a=rnd()%n+1,b=rnd()%n+1;
		if(a==b)
			i--;
		else
			e[i]=node(a,b,rnd()%10+1);
	}
	shuffle(e+1,e+m+1,rnd);
	for(int i=1;i<=m;i++)
		printf("%d %d %d\n",e[i].a,e[i].b,e[i].c);
	return 0;
}