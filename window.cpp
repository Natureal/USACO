/*
ID:naturec1
PROG: window
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define MEM(a,b) memset(a,b,sizeof(a))
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;
const int MAXN = 10010;

string str;
int pmin,pmax;
int tot,id[200];
int pro[MAXN];

struct Rec{
	int a1,b1,a2,b2;
	int pro;
	char id;
}R[MAXN];

int Dfs(int p,int a1,int b1,int a2,int b2){
	if(a1 >= a2 || b1 >= b2) return 0;
	if(p >= pmax) return (a2 - a1) * (b2 - b1);
	int res = 0,nxt = pro[p];
	if(pro[nxt] == -1) Dfs(p + 1,a1,b1,a2,b2);
	res += Dfs(p + 1,a1,b1,min(a2,R[nxt].a1),b2); //左半片
	res += Dfs(p + 1,max(a1,R[nxt].a2),b1,a2,b2); //右半片
	res += Dfs(p + 1,max(a1,R[nxt].a1),max(b1,R[nxt].b2),min(a2,R[nxt].a2),b2);
	res += Dfs(p + 1,max(a1,R[nxt].a1),b1,min(a2,R[nxt].a2),min(b2,R[nxt].b1));
	return res;
}

int Solve(int cur){
	int st = R[cur].pro + 1;
	return Dfs(st,R[cur].a1,R[cur].b1,R[cur].a2,R[cur].b2);
}

int main(){
	freopen("window.in","r",stdin);
	freopen("window.out","w",stdout);
	pmin = 499;
	pmax = 500;
	while(cin >> str){
		int len = str.length();
		if(str[0] == 'w'){
			R[tot].id = str[2]; //矩形的flag
			R[tot].pro = pmax++; //矩形的优先级
			id[(int)str[2]] = tot; //
			pro[R[tot].pro] = tot;
			int v[4] = {0},cur = 0;
			for(int i = 4; i < len - 1; ++i){
				if(str[i] == ',') ++cur;
				else v[cur] = v[cur] * 10 + str[i] - '0';
			}
			R[tot].a1 = min(v[0],v[2]),R[tot].b1 = min(v[1],v[3]);
			R[tot].a2 = max(v[0],v[2]),R[tot].b2 = max(v[1],v[3]);
			tot++;
		}
		else if(str[0] == 't'){
			int cur_id = id[(int)str[2]];
			pro[R[cur_id].pro] = -1;
			R[cur_id].pro = pmax++;
			pro[R[cur_id].pro] = cur_id;
		}
		else if(str[0] == 'b'){
			int cur_id = id[(int)str[2]];
			pro[R[cur_id].pro] = -1;
			R[cur_id].pro = pmin--;
			pro[R[cur_id].pro] = cur_id;
		}
		else if(str[0] == 'd'){
			int cur_id = id[(int)str[2]];
			pro[R[cur_id].pro] = -1;
		}
		else{
			int cur_id = id[(int)str[2]];
			int ans = Solve(cur_id);
			int total = (R[cur_id].a2 - R[cur_id].a1) * 
				(R[cur_id].b2 - R[cur_id].b1);
			printf("%.3f\n",(double)ans * 100 / total);
		}
	}
	return 0;
}

