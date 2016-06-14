#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 1000000000;
const int MXN = 100000+3;
const int MXM = 100000+3;
const int MXS = 20000000;

int tmp[MXM+MXN];
int id[MXM+MXN], rk[MXM+MXN];
int cnt, s;

	struct Node{
		Node *ch[2];
		int r,sz;//r是随机优先级，sz是子树的结点个数
		bool operator<(const Node &nd) const{
			return r<nd.r;
		}
		int cmp(int x){
			if(x==v) return -1;
			return x>v;
		}

		//维护的结点信息
		int v;

		void init(int _v){
			v = _v;
			sz = 1;
			ch[0] = ch[1] = NULL;
			r = rand();
		}
	} nd[MXS];
	int ndcnt;
	void init(){
		ndcnt = 0;
	}

	Node *newNode(int v){
		nd[ndcnt].init(v);
		return &nd[ndcnt++];
	}

	void push_Up(Node *rt){
		if(rt==NULL) return;
		rt->sz = 1;
		if(rt->ch[0]!=NULL) rt->sz+=rt->ch[0]->sz;
		if(rt->ch[1]!=NULL) rt->sz+=rt->ch[1]->sz;
	}

	void rotate(Node *&o,int d){
		Node *k = o->ch[d^1];
		o->ch[d^1] = k->ch[d];
		k->ch[d] = o;
		push_Up(o);
		push_Up(k);
		o = k;
	}

	//插入值为val的结点
	void insertVal(Node *&o,int val){
		if(o==NULL) o = newNode(val);
		else{
			int d = (val<o->v?0:1);
			insertVal(o->ch[d],val);
			if((*(o->ch[d]))<(*o)) rotate(o,d^1);
		}
		push_Up(o);
	}

	//删除值为val的结点，只删除一个
	void removeVal(Node *&o,int val){
		if(o==NULL) return;
		int d = o->cmp(val);
		if(d==-1){
            //把结点转到子树中再删除
			if(o->ch[0]!=NULL&&o->ch[1]!=NULL){
				int d2 = (o->ch[0]>o->ch[1]?1:0);
				rotate(o,d2);removeVal(o->ch[d2],val);
			}else{
				if(o->ch[0]==NULL) o = o->ch[1];
				else o = o->ch[0];
			}
		}else removeVal(o->ch[d],val);
		if(o!=NULL) push_Up(o);
	}

	//返回比结点值比val小的结点个数
	int getRank(Node *o,int val){
		if(o==NULL) return 0;
		int d = o->cmp(val);
		if(d==1){
			int lsz = (o->ch[0]==NULL?0:o->ch[0]->sz);
			return lsz+1+getRank(o->ch[1],val);
		}else return getRank(o->ch[0],val);
	}

Node* bit[MXM+MXN];
int op[MXM][4];
int a[MXM];
int n, m;

int sum(int p, int l, int r) {
    int ret = 0;
    while (p > 0) {
        ret += getRank(bit[p], r+1) - getRank(bit[p], l);
        p -= p & (-p);
    }
    return ret;
}

void add(int p, int v) {
    while (p <= s) {
        insertVal(bit[p], v);
        p += p & (-p);
    }
}

void sub(int p, int v) {
    while (p <= s) {
        removeVal(bit[p], v);
        p += p & (-p);
    }
}

int cmp(const int &p, const int &q) {
    return tmp[p] < tmp[q];
}

void discrete()
{
    for (int i = 0; i < cnt; ++i) {
        id[i] = i;
    }
    sort(id, id+cnt, cmp);
    int cur = 1, last = tmp[id[0]];
    rk[cur] = last;
    tmp[id[0]] = cur;
    for (int i = 1; i < cnt; ++i) {
        if (tmp[id[i]] > last) {
            ++cur;
            last = tmp[id[i]];
            rk[cur] = last;
        }
        tmp[id[i]] = cur;
    }
    s = tmp[id[cnt-1]];
}

void deal()
{
    memset(bit, 0, sizeof(bit));
    init();
    for (int i = 0; i < MXN+MXM; ++i) {
        insertVal(bit[i], MXN+MXM);
    }
    cnt = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &tmp[cnt]);
        a[i] = cnt++;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            op[i][0] = 1;
            scanf("%d%d", &op[i][1],&tmp[cnt]);
            op[i][2] = cnt++;
        }
        else {
            op[i][0] = 2;
            scanf("%d%d%d", &op[i][1], &op[i][2], &op[i][3]);
        }
    }
    discrete();
    for (int i = 0; i < n; ++i) {
        a[i] = tmp[a[i]];
        add(a[i], i+1);
    }
    for (int i = 0; i < m; ++i) {
        if (op[i][0] == 1) {
            op[i][2] = tmp[op[i][2]];
            sub(a[op[i][1]-1], op[i][1]);
            a[op[i][1]] = op[i][2];
            add(op[i][2], op[i][1]);
        }
        else {
            int l = 0, r = s;
            while (r- l > 1) {
                int mid = (l + r) >> 1;
//                printf("%d %d %d | %d %d\n", l, r, op[i][3], mid, sum(mid, op[i][1], op[i][2]));
                if (sum(mid, op[i][1], op[i][2]) >= op[i][3]) {
                    r = mid;
                }
                else {
                    l = mid;
                }
            }
            printf("%d\n", rk[r]);
        }
    }
}

int main()
{
//    freopen("a.in", "r", stdin);
    while (scanf("%d", &n) != EOF) {
        deal();
    }
    return 0;
}