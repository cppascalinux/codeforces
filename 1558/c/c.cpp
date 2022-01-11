#include<bits/stdc++.h>
using namespace std;
int n;
int p[3009];
vector<int> ans;
void rev(int v)
{
	reverse(p+1,p+v+1);
	ans.push_back(v);
}
int main()
{
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		scanf("%d",&n);
		ans.clear();
		int fil=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",p+i);
			if((i-p[i])%2)
				fil=1;
		}
		if(fil)
		{
			printf("-1\n");
			continue;
		}
		for(int c=n;c>1;c-=2)
		{
			int v=0;
			for(int i=1;i<=n;i++)
				if(p[i]==c)
					v=i;
			rev(v);
			for(int i=1;i<=n;i++)
				if(p[i]==c-1)
					v=i-1;
			rev(v);
			rev(v+2);
			rev(3);
			rev(c);
		}
		printf("%d\n",(int)ans.size());
		for(int v:ans)
			printf("%d ",v);
		printf("\n");
	}
	return 0;
}