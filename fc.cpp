/*
ID:naturec1
PROG: fc
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
const double eps = 1e-8;

int N,cnt;

struct Point{
	double x,y;
}p[MAXN];

double cross(Point st,Point a,Point b){
	double X1 = a.x - st.x;
	double Y1 = a.y - st.y;
	double X2 = b.x - st.x;
	double Y2 = b.y - st.y;
	return X1 * Y2 - X2 * Y1;
}

bool cmpx(Point a,Point b){
	if(fabs(a.x - b.x) < eps)
		return a.y < b.y;
	return a.x < b.x;
}

bool cmp(Point a,Point b){ //极角排序
	double k = cross(p[0],a,b);
	if(fabs(k) < eps)
		return cmpx(a,b);
	return k < 0;
}

double Dis(Point a,Point b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void Graham(){
	cnt = 2;
	for(int i = 2; i < N; ++i){
		while(cnt >= 2){
			double cur = cross(p[cnt - 2],p[cnt - 1],p[i]);
			if(fabs(cur) < eps || cur > 0)
				cnt--;
			else break;
		}
		p[cnt++] = p[i];
	}
}

int main(){
	freopen("fc.in","r",stdin);
	freopen("fc.out","w",stdout);
	int st = -1;
	scanf("%d",&N);
	REP(i,N){
		scanf("%lf%lf",&p[i].x,&p[i].y);
		if(st == -1 || cmpx(p[i],p[st])){
			st = i;
		}
	}
	swap(p[0],p[st]);
	sort(p + 1,p + N,cmp);
	Graham();
	double ans = Dis(p[0],p[cnt - 1]);
	REP(i,cnt - 1) ans += Dis(p[i],p[i + 1]);
	printf("%.2f\n",ans);
	return 0;
}


