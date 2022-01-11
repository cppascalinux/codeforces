#include<bits/stdc++.h>
using namespace std;
// vector<int> s[1000009];
// int f[1000009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		if(n&1)
			printf("Bob\n");
		else
		{
			int fg=0;
			for(long long i=2;i<=n;i*=4)
				if(i==n)
					fg=1;
			if(fg)
				printf("Bob\n");
			else
				printf("Alice\n");
		}
	}
	return 0;
}