//¶þ·ÖÍ¼È¾É«
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1010;
const int inf=0x3f3f3f3f;
struct edge {int to,next;}e[maxn<<1];
int c[maxn],head[maxn],a[maxn],f[maxn],s1[maxn],s2[maxn];
int t1,t2,n,cnt;
void link(int u,int v) {
    e[++cnt].to=v;e[cnt].next=head[u];head[u]=cnt;
    e[++cnt].to=u;e[cnt].next=head[v];head[v]=cnt;
}
bool color(int x,int cl) {
    c[x]=cl;
    for (int i=head[x];i;i=e[i].next) {
        if (!c[e[i].to]) {if (!color(e[i].to,3-cl)) return 0;}
        else if (c[e[i].to]==cl) return 0;
    }
    return 1;
}
int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    f[n+1]=inf;
    for (int i=n;i;i--) f[i]=min(f[i+1],a[i]);
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            if (a[i]<a[j] && f[j+1]<a[i]) link(i,j);
    for (int i=1;i<=n;i++)
        if (!c[i] && !color(i,1)) {puts("0");return 0;}
    int now=1;
    for (int i=1;i<=n;i++) {
        if (c[i]==1) printf("a "),s1[++t1]=a[i];
        else printf("c "),s2[++t2]=a[i];
        while (s1[t1]==now || s2[t2]==now) {
            if (s1[t1]==now) printf("b "),t1--;
            else printf("d "),t2--;
            now++;
        }
    }
    return 0;
}
