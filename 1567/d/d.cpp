#include<bits/stdc++.h>
using namespace std;
int n,s,m;
int v[29];
int mul[20];
int main()
{
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		scanf("%d%d",&s,&n);
		m=0;
		for(int x=s;x;x/=10)
			v[++m]=x%10;
		multiset<int> st;
		mul[0]=1;
		for(int i=1;i<=9;i++)
			mul[i]=mul[i-1]*10;
		int tot=0;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=v[i];j++)
				st.insert(mul[i-1]);
			tot+=v[i];
			// printf("i:%d v:%d\n",i,v[i]);
		}
		vector<int> ans;
		if(st.size()>=n)
		{
			for(int i=1;i<=n-1;i++)
			{
				ans.push_back(*st.begin());
				s-=*st.begin();
				st.erase(st.begin());
			}
			ans.push_back(s);
			for(int v:ans)
				printf("%d ",v);
			printf("\n");
		}
		else
		{
			while(tot<n)
			{
				for(int i=2;i<=m;i++)
					if(v[i])
					{
						v[i]--;
						v[i-1]+=10;
						tot+=9;
						break;
					}
			}
			for(int i=1;i<=n-1;i++)
			{
				for(int j=1;j<=m;j++)
					if(v[j])
					{
						v[j]--;
						ans.push_back(mul[j-1]);
						s-=mul[j-1];
						break;
					}
			}
			ans.push_back(s);
			for(int v:ans)
				printf("%d ",v);
			printf("\n");
		}
	}
	return 0;
}