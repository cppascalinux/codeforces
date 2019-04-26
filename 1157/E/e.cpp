#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<cassert>
#define msi multiset<int>::iterator
using namespace std;
int n;
int v[200009];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",v+i);
	multiset<int> s;
	msi it1,it2;
	for(int i=1,a;i<=n;i++)
		scanf("%d",&a),s.insert(a);
	for(int i=1;i<=n;i++)
	{
		it1=s.lower_bound(0);
		it2=s.lower_bound(n-v[i]);
		if(it2==s.end())
		{
			printf("%d ",(v[i]+*it1)%n),s.erase(it1);
			continue;
		}
		int v1=(v[i]+*it1)%n,v2=(v[i]+*it2)%n;
		if(v1<v2)
			printf("%d ",v1),s.erase(it1);
		else
			printf("%d ",v2),s.erase(it2);
	}
	return 0;
}