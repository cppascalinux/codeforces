#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,tp;
int *s[250009];
int st[250009],ans[250009];
void cmp(int *a,int *b)
{
	tp=0;
	for(int i=1;i<=m;i++)
		if(a[i]!=b[i])
			st[++tp]=i;
}
int chk(int *ans)
{
	for(int i=1;i<=n;i++)
	{
		cmp(ans,s[i]);
		if(tp>2)
			return 0;
	}
	return 1;
}
void fail()
{
	printf("No");
	exit(0);
}
void suc(int *ans)
{
	printf("Yes\n");
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	exit(0);
}
void out(int *ans)
{
	printf("\n");
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	printf("\n");
	fflush(stdout);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		s[i]=(int*)calloc(m+2,sizeof(int));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&s[i][j]);
	if(chk(s[1]))
		suc(s[1]);
	for(int i=2;i<=n;i++)
	{
		cmp(s[i],s[1]);
		if(tp>4)
			fail();
		if(tp<=2)
			continue;
		if(tp==4)
		{
			int ts[5];
			for(int j=1;j<=4;j++)
				ts[j]=st[j];
			for(int j=1;j<=4;j++)
				for(int k=j+1;k<=4;k++)
				{
					for(int l=1;l<=m;l++)
						ans[l]=s[1][l];
					ans[ts[j]]=s[i][ts[j]];
					ans[ts[k]]=s[i][ts[k]];
					// printf("j:%d k:%d\n",j,k);
					// for(int o=1;o<=tp;o++)
					// 	printf("i:%d st:%d\n",o,ts[o]);
					// out(ans);
					if(chk(ans))
						suc(ans);
				}
			fail();
		}
		if(tp==3)
		{
			int t1[5];
			for(int j=1;j<=3;j++)
				t1[j]=st[j];
			for(int j=1;j<=3;j++)
			{
				for(int l=1;l<=m;l++)
					ans[l]=s[1][l];
				ans[t1[j]]=s[i][t1[j]];
				int p=t1[j];
				// printf("p:%d\n",p);
				// out(ans);
				if(chk(ans))
					suc(ans);
				for(int k=1;k<=n;k++)
				{
					cmp(s[k],ans);
					if(tp>=4)
						break;
					if(tp<=2)
						continue;
					int t2[5];
					for(int l=1;l<=3;l++)
						t2[l]=st[l];
					for(int l=1;l<=3;l++)
					{
						int q=t2[l];
						if(q!=p)
						{
							int tmp=ans[q];
							ans[q]=s[k][q];
							if(chk(ans))
								suc(ans);
							ans[q]=tmp;
						}
					}
				}
			}
			fail();
		}
	}
	suc(s[1]);
	return 0;
}