/**
* prim算法：算法思想与Dijkstra算法几乎完全相同
**/

//伪代码
//G为图，一般设成全局变量；数组d为顶点与集合S的最短距离
Prim(G, d[]) {
    初始化;
    for (循环n次) {
        u = 使d[u]最小的还未被访问的顶点的标号;
        记u已被访问;
        for (从u出发能到达的所有顶点v) {
            if (v未被访问 && 以u为中介点使得v与集合S的最短距离d[v]更优) {
                将G[u][v]赋值给v与集合S的最短距离d[v];
            }
        }
    }
}

const int MAXV = 1000; //最大顶点数
const int INF = 1000000000; //设INF为一个很大的数

//邻接矩阵版
int n, G[MAXV][MAXV]; //n为顶点数，MAXV为最大顶点数
int d[MAXV]; //起点到达各点的最短路径长度
bool vis[MAXV] = { false }; //标记数组，vis[i]==true表示已访问，初值均为false
//默认0号为初始点，函数返回最小生成树的边权之和
int prim() {
    fill(d, d + MAXV, INF); //fill函数将整个d数组赋值为INF（慎用memset）
    d[0] = 0; //只有0号顶点到集合S的距离为0，其余全为INF
    int ans = 0; //存放最小生成树的边权之和
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF; //u使d[u]最小，MIN存放该最小的d[u]
        //找到未访问的顶点中d[]最小的
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        //找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
        if (u == -1)
            return -1;
        vis[u] = true; //标记u已被访问
        ans += d[u]; //将与集合S距离最小的边加入最小生成树
        for (int v = 0; v < n; v++) {
            //v未访问 && u能到达v && 以u为中介点可以使v离集合S更近
            if (vis[v] == false && G[u][v] != INF && G[u][v] < d[v])
                d[v] = G[u][v]; //将G[u][v]赋值给d[v]
        }
    }
    return ans; //返回最小生成树的边权之和
}

//邻接表版
struct Node {
    int v, dis; //v为边的目标顶点，dis为边权
};
vector<Node> Adj[MAXV]; //图G，Adj[u]存放从顶点u出发可以到达的所有顶点
int n; //n为顶点数，图G使用邻接表实现，MAXV为最大顶点数
int d[MAXV]; //顶点与集合S的最短距离
bool vis[MAXV] = { false }; //标记数组，vis[i]==true表示已访问，初值均为false
//默认0号为初始点，函数返回最小生成树的边权之和
int prim() {
    fill(d, d + MAXV, INF); //fill函数将整个d数组赋值为INF（慎用memset）
    d[0] = 0; //只有0号顶点到集合S的距离为0，其余全为INF
    int ans = 0; //存放最小生成树的边权之和
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF; //u使d[u]最小，MIN存放该最小的d[u]
        //找到未访问的顶点中d[]最小的
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        //找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
        if (u == -1)
            return -1;
        vis[u] = true; //标记u已被访问
        ans += d[u]; //将与集合S距离最小的边加入最小生成树
        //只有下面这个for与邻接矩阵的写法不同
        for (int j = 0; j < Adj[u].size(); j++) {
            int v = Adj[u][v].v; //通过邻接表直接获得u能到达的顶点v
            //如果v未访问 && 以u为中介点可以使v离集合S更近
            if (vis[v] == false && d[u] + Adj[u][j].dis < d[v])
                d[v] = G[u][v]; //将G[u][v]赋值给d[v]
        }
    }
    return ans; //返回最小生成树的边权之和
}
