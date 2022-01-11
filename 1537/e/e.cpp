#include<bits/stdc++.h>
using namespace std;
int n,k;
char s[500009];
int main()
{
	scanf("%d%d",&n,&k);
	n=min(n,k);
	scanf("%s",s+1);
	// n=k=500000;
	// for(int i=1;i<=n-1;i++)
	// 	s[i]='z';
	// s[n]='a';
	int rt=n+1;
	for(int i=1;i<=n;i++)
		if(s[i]>s[1])
		{
			rt=i;
			break;
		}
	s[n+1]='z'+1;
	int cur=1;
	// printf("rt:%d\n",rt);
	for(int i=2;i<=rt&&i<=k+1;i++)
	{
		if(s[i]>=s[1])
		{
			// printf("i:%d cur:%d\n",i,cur);
			int fg=0;
			for(int j=cur+1;j<=i-1;j++)
				if(s[(j-1)%cur+1]!=s[j])
				{
					// printf("p1:%d p2:%d\n",(j-1)%cur+1,j);
					if(s[j]<s[(j-1)%cur+1])
					{
						printf("i:%d j:%d cur:%d\n",i,j,cur);
						fg=1;
						cur=i-1;
					}
					else
						fg=2;
					break;
				}
			if(fg==0)
				printf("asdasda:%d\n",i),cur=i-1;
			else if(fg==2)
				break;
		}
	}
	for(int i=1;i<=k;i++)
		printf("%c",s[(i-1)%cur+1]);
	return 0;
}