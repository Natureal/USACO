/*
ID:naturec1
PROG: contact
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

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;

int A,B,N;
string s,ts;
map<int,int> mp[20];

struct node{
	int len,val,cnt;
	node(int tlen = 0,int tval = 0,int tcnt = 0) :
		len(tlen),val(tval),cnt(tcnt) {}
}nd[10000];

int ncnt;

bool cmp(node a,node b){
	if(a.cnt == b.cnt){
		if(a.len == b.len)
			return a.val < b.val;
		return a.len < b.len;
	}
	return a.cnt > b.cnt;
}

void Print(int id){
	int v = nd[id].val;
	for(int i = nd[id].len; i >= 1; --i){
		if(v & (1 << (i - 1))) printf("1");
		else printf("0");
	}
}

int main(){
	freopen("contact.in","r",stdin);
	freopen("contact.out","w",stdout);
	scanf("%d%d%d",&A,&B,&N);
	while(cin >> ts) s += ts;
	int len = s.size();
	FOR(l,A,B){
		if(len < l) break;
		int cur = 0;
		for(int i = 0; i < l; ++i){
			cur *= 2;
			if(s[i] == '1') cur += 1;
		}
		mp[l][cur]++;
		for(int i = l; i < len; ++i){
			cur -= (cur & (1 << (l - 1)));
			cur *= 2;
			if(s[i] == '1') cur += 1;
			mp[l][cur]++;
		}
		for(int i = 0; i < (1 << l); ++i)
			if(mp[l][i]) nd[++ncnt] = node(l,i,mp[l][i]);
	}
	sort(nd + 1,nd + ncnt + 1,cmp);
	int same_cnt;
	for(int i = 1,pos = 0; i <= ncnt; ++i){
		if(i == 1 || nd[i].cnt != nd[i - 1].cnt){
			same_cnt = 0;
			if((++pos) > N) break;
			printf("%d\n",nd[i].cnt);
		}
		same_cnt++;
		Print(i);
		if(same_cnt % 6 == 0 || i == ncnt || (nd[i + 1].cnt != nd[i].cnt))
			puts("");
		else printf(" ");
	}
	return 0;
}

