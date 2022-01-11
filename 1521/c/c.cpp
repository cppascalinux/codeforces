#include<bits/stdc++.h>
using namespace std;
int n;
int p[200009];
int ask(int t,int x,int y)//t=1:max,t=2:min
{
	int v=t==1?n-1:1;
	printf("? %d %d %d %d\n",t,x,y,v);
	fflush(stdout);
	scanf("%d",&v);
	return v;
}
void output()
{
	printf("! ");
	for(int i=1;i<=n;i++)
		printf("%d ",p[i]);
	printf("\n");
	fflush(stdout);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			p[i]=0;
		map<int,int> vis;
		int s=1;
		int v1=ask(1,1,2);
		int v2=ask(1,2,1);
		if(v1!=v2)
		{
			if(v1==n)
				p[2]=n,s=2;
			else
				p[1]=n,s=1;
			for(int i=1;i<=n;i++)
				if(!p[i])
					p[i]=ask(2,i,s);
			output();
			continue;
		}
		vis[v1]++;
		v1=ask(2,1,2);
		v2=ask(2,2,1);
		if(v1!=v2)
		{
			if(v1==1)
				p[1]=1,s=1;
			else
				p[2]=1,s=2;
			for(int i=1;i<=n;i++)
				if(!p[i])
					p[i]=ask(1,s,i);
			output();
			continue;
		}
		vis[v1]++;
		v1=ask(1,1,3);
		v2=ask(1,3,1);
		if(v1!=v2)
		{
			if(v1==n)
				p[3]=n,s=3;
			else
				p[1]=n,s=1;
			for(int i=1;i<=n;i++)
				if(!p[i])
					p[i]=ask(2,i,s);
			output();
			continue;
		}
		vis[v1]++;
		v1=ask(2,1,3);
		v2=ask(2,3,1);
		if(v1!=v2)
		{
			if(v1==1)
				p[1]=1,s=1;
			else
				p[3]=1,s=3;
			for(int i=1;i<=n;i++)
				if(!p[i])
					p[i]=ask(1,s,i);
			output();
			continue;
		}
		vis[v1]++;
		for(auto t:vis)
			if(t.second==2)
				p[1]=t.first;
		int typ=p[1]<=n/2?1:2;
		for(int i=2;i<=n;i++)
		{
			int v=0;
			if(typ==1)
			{
				v=ask(1,1,i);
				if(v==p[1])
					v=ask(2,i,1);
				p[i]=v;
			}
			else
			{
				v=ask(2,i,1);
				if(v==p[1])
					v=ask(1,1,i);
				p[i]=v;
			}
		}
		output();
	}
	return 0;
}