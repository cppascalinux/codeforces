#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int n;
int s[200009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i);
		sort(s+1,s+n+1,greater<int>());
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			if(i%2==1&&s[i]%2==0)
				ans+=s[i];
			else if(i%2==0&&s[i]%2==1)
				ans-=s[i];
		}
		if(ans>0)
			printf("Alice\n");
		else if(ans==0)
			printf("Tie\n");
		else
			printf("Bob\n");
	}
	return 0;
}