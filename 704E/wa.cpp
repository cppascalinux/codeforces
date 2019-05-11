#include<set>
#include<vector>
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define INSERT 0
#define DELETE 1
#define LEFT 0
#define RIGHT 1
typedef double ldb;
#define int long long
const ldb eps=1e-12;
inline bool Equal(const ldb& a,const ldb& b){return a+eps>=b&&b+eps>=a;}
inline bool Below(const ldb& a,const ldb& b){return b+eps>=a;}
inline int Abs(const int& a){return a>0?a:-a;}
void Read(int& x){
	char ch; while(ch=getchar(),ch<'0'||ch>'9');
	x=ch-'0'; while(ch=getchar(),ch>='0'&&ch<='9') x=x*10+ch-'0';
}
int n,m;
struct EDGE{
	int to,next;
}edge[200010];
int head[100010],tot=0;
inline void AddEdge(int a,int b){
	edge[++tot].to=b;
	edge[tot].next=head[a];
	head[a]=tot;
}
#define ty (edge[x].to)
int size[100010],prt[100010],son[100010],deep[100010];
int dfn[100010],ufn[100010],ti=0,top[100010],Id[100010];
void Dfs1(int rt){
	size[rt]=1;
	for(int x=head[rt];x;x=edge[x].next){
		if(size[ty]) continue;
		deep[ty]=deep[rt]+1;
		prt[ty]=rt;
		Dfs1(ty);
		size[rt]+=size[ty];
		if(size[ty]>size[son[rt]]) son[rt]=ty;
	}
}
void Dfs2(int rt,int tp,int k){
	dfn[rt]=++ti; ufn[ti]=rt;
	top[rt]=tp; Id[rt]=k;
	if(son[rt]) Dfs2(son[rt],tp,k+1);
	for(int x=head[rt];x;x=edge[x].next)
		if(prt[ty]==rt&&son[rt]!=ty) Dfs2(ty,ty,1);
}
int Lca(int a,int b){
	while(top[a]!=top[b]){
		if(deep[top[a]]>deep[top[b]]) a=prt[top[a]];
		else b=prt[top[b]];
	}
	if(deep[a]<deep[b]) return a;
	return b;
}
int Dis(int a,int b){
	int c=Lca(a,b);
	return deep[a]+deep[b]-2*deep[c];
}
struct Node{
	ldb tim;
	int fr,to,spd;
	bool Dir;
	Node(ldb a=0,int b=0,int c=0,int d=0){
		tim=a,fr=b,to=c,spd=d;
		if(fr<=to) Dir=RIGHT;
		else Dir=LEFT;
	}
	bool operator < (const Node& a)const{
		if(fr!=a.fr) return fr<a.fr;
		if(Dir!=a.Dir) return Dir<a.Dir;
		if(Dir==LEFT){
			if(!Equal(tim,a.tim)) return tim<a.tim;
			else return spd>a.spd;
		}
		else{
			if(!Equal(tim,a.tim)) return tim>a.tim;
			else return spd<a.spd;
		}
	}
};
vector<Node> sta[100010];
multiset<Node> S;
typedef multiset<Node>::iterator IT;
ldb Query(Node a,Node b){
	int u1=a.fr,v1=a.to,u2=b.fr,v2=b.to;
	if(u1>v1) swap(u1,v1);
	if(u2>v2) swap(u2,v2);
	u1=max(u1,u2),v1=min(v1,v2);
	ldb t1,t2,x;
	if(u1<=v1){
		if(a.Dir==b.Dir){
			if(a.Dir==RIGHT&&b.Dir==RIGHT)
				t1=a.tim+(ldb)(u1-a.fr)/a.spd,t2=b.tim+(ldb)(u1-b.fr)/b.spd;
			else t1=a.tim+(ldb)(a.fr-v1)/a.spd,t2=b.tim+(ldb)(b.fr-v1)/b.spd;
			if(a.spd==b.spd){
				if(!Equal(t1,t2)) return 1e100;
				else return t1;
			}
			else{
				x=(t1-t2)*b.spd*a.spd/(a.spd-b.spd);
				if(Below(0,x)&&Below(x,v1-u1)) return t1+x/a.spd;
				else return 1e100;
			}
		}
		else{
			if(a.Dir==LEFT&&b.Dir==RIGHT)
				t1=a.tim+(ldb)(a.fr-v1)/a.spd,t2=b.tim+(ldb)(u1-b.fr)/b.spd;
			else t1=a.tim+(ldb)(u1-a.fr)/a.spd,t2=b.tim+(ldb)(b.fr-v1)/b.spd;
			x=a.spd*(v1-u1-b.spd*t1+b.spd*t2)/(a.spd+b.spd);
			if(Below(0,x)&&Below(x,v1-u1)) return t1+x/a.spd;
			else return 1e100;
		}
	}
	else return 1e100;
}
struct Things{
	ldb tim;
	bool Ty; int id;
	Things(ldb a=0,bool b=false,int d=0){tim=a,Ty=b,id=d;}
	bool operator < (const Things& a)const{return Equal(tim,a.tim)?(Ty!=a.Ty?Ty<a.Ty:id<a.id):tim<a.tim;}
}B[200010];
int cnt=0;
ldb Work(vector<Node> &p){
	vector<Node>::iterator it;
	cnt=0;
	int i,x;
	for(it=p.begin(),i=0;it!=p.end();++it,++i){
		B[++cnt]=Things(it->tim,INSERT,i);
		B[++cnt]=Things(it->tim+(ldb)Abs(it->to-it->fr)/it->spd,DELETE,i);
	}
	sort(B+1,B+1+cnt);
	Node q; ldb ans=1e100;
	for(int i=1;i<=cnt;++i){
		if(B[i].Ty==INSERT){
			q=p[B[i].id];
			IT iter=S.lower_bound(q);
			if(iter!=S.end()) ans=min(ans,Query(*iter,q));
			if(iter!=S.begin()) --iter,ans=min(ans,Query(*iter,q));
			S.insert(q);
		}
		else{
			q=p[B[i].id];
			//S.erase(q);
			S.erase(S.find(q));
			IT iter=S.lower_bound(q);
			if(iter!=S.end()&&iter!=S.begin()){
				IT iter2=iter; iter2--;
				ans=min(ans,Query(*iter,*iter2));
			}
		}
	}
	return ans;
}
signed main(){
	Read(n);Read(m);
	int a,b;
	for(int i=1;i<n;++i){
		Read(a);Read(b);
		AddEdge(a,b);
		AddEdge(b,a);
	}
	Dfs1(1);
	Dfs2(1,1,1);
	ldb t1,t2;
	int t,c,u,v;
	for(int i=1;i<=m;++i){
		Read(t);Read(c);Read(u);Read(v);
		a=u,b=v;
		t2=t+(ldb)Dis(a,b)/c;
		while(top[a]!=top[b]){
			if(deep[top[a]]>deep[top[b]]){
				sta[top[a]].push_back(Node(t+(ldb)(deep[u]-deep[a])/c,Id[a],0,c));
				a=prt[top[a]];
			}
			else{
				sta[top[b]].push_back(Node(t2-(ldb)(deep[v]-deep[prt[top[b]]])/c,0,Id[b],c));
				b=prt[top[b]];
			}
		}
		sta[top[a]].push_back(Node(t+(ldb)(deep[u]-deep[a])/c,Id[a],Id[b],c));
	}
	ldb ans=(ldb)1e100;
	for(int i=1;i<=n;++i){
		if(sta[i].empty()) continue;
		ans=min(ans,Work(sta[i]));
	}
	if(Equal(ans,1e100)) puts("-1");
	else printf("%.10f\n",(double)ans);
//	while(1);
	return 0;
}

 	   	 	  		 	 		 		   	 	 	  	