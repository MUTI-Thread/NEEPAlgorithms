#include <stdio.h>
using namespace std;
#define N 1000

int Tree[N];

//查找某个结点所在树的根结点
int findRoot(int x) {
    if (Tree[x] == -1) {
        return x;
    } else {
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

int main() {
    int n, m;
    while (scanf("%d", &n) != EOF && n != 0) {
        scanf("%d", &m);
        for (int i = 1; i <= n; i++)
            Tree[i] = -1; //初始时，所有结点都是孤立的集合，即其所在集合只有一个结点，其本身就是所在树根结点
        //读入边信息
        while (m-- != 0) {
            int a, b;
            scanf("%d%d", &a, &b);
            //查找边的两个顶点所在集合信息
            a = findRoot(a);
            b = findRoot(b);
            if (a != b)
                Tree[a] = b; //若两个顶点不在同一个集合则合并这两个集合
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (Tree[i] == -1)
                ans++; //统计所有结点中根结点的个数
        }
        printf("%d\n", ans - 1); //答案即为在ans个集合间再修建ans-1条道路即可使所有结点连通
    }
    return 0;
}
