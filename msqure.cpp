
/*
ID:naturec1
PROG: msquare
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
#define REP(i,n) for(int i=1;i<=(n);++i)
#define REV(i,n) for(int i=(n);i>=1;--i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)
#define X first
#define Y second

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;

struct node{
	int step;
	int s[9];
};

queue<node> q;
map<int,pii > pre;

int Trans(node a){
	int sum = 0;
	for(int i = 1; i <= 8; ++i)
		sum = sum * 10 + a.s[i];
	return sum;
}

int main(){
	freopen("msquare.in","r",stdin);
	freopen("msquare.out","w",stdout);
	int tem,ED = 0;
	REP(i,8) scanf("%d",&tem),ED = ED * 10 + tem;
	node st;
	REP(i,8) st.s[i] = i;
	int st_tag = Trans(st);
	pre[st_tag] = MP(-1,-1);
	st.step = 0;
	q.push(st);
	while(!q.empty()){
		node x = q.front(); q.pop();
		int xid = Trans(x);
		if(xid == ED){
			printf("%d\n",x.step);
			break;
		}
		node nxt;
		nxt.step = x.step + 1;
		//A operation
		REP(i,8) nxt.s[i] = x.s[9 - i];
		int id = Trans(nxt);
		if(pre[id].X == 0){
			pre[id] = MP(1,xid);
			q.push(nxt);
		}
		//B operation
		nxt.s[1] = x.s[4],nxt.s[2] = x.s[1],nxt.s[3] = x.s[2],nxt.s[4] = x.s[3];
		nxt.s[8] = x.s[5],nxt.s[7] = x.s[8],nxt.s[6] = x.s[7],nxt.s[5] = x.s[6];
		id = Trans(nxt);
		if(pre[id].X == 0){
			pre[id] = MP(2,xid);
			q.push(nxt);
		}
		//C operation
		nxt.s[1] = x.s[1],nxt.s[4] = x.s[4],nxt.s[5] = x.s[5],nxt.s[8] = x.s[8];
		nxt.s[2] = x.s[7],nxt.s[3] = x.s[2];
		nxt.s[7] = x.s[6],nxt.s[6] = x.s[3];
		id = Trans(nxt);
		if(pre[id].X == 0){
			pre[id] = MP(3,xid);
			q.push(nxt);
		}
	}
	vector<char>ans; ans.clear();
	while(ED != st_tag){
		pii id = pre[ED];
		if(id.X == 1) ans.push_back('A');
		else if(id.X == 2) ans.push_back('B');
		else ans.push_back('C');
		ED = pre[ED].Y;
	}
	int cnt = 0;
	for(int i = ans.size() - 1; i >= 0; --i){
		printf("%c",ans[i]);
		if((++cnt) % 60 == 0) puts("");
	}
	if(cnt == 0 || cnt % 60 != 0) puts("");
	return 0;
}

