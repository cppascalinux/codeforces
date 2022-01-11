#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int s[10],v[10];
		for(int i=1;i<=4;i++)
			scanf("%d",s+i),v[i]=s[i];
		sort(v+1,v+5);
		s[1]=max(s[1],s[2]);
		s[2]=max(s[3],s[4]);
		sort(s+1,s+3);
		if(s[1]==v[3]&&s[2]==v[4])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}