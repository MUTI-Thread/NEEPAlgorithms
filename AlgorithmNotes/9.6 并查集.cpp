/**
* 并查集：一种维护集合的数据结构
**/

//定义
//“并”“查”“集”即Union(合并)、Find(查找)、Set(集合)
//支持合并（合并两个集合）和查找（判断两个元素是否在一个集合）
//用一个数组father[N]，其中father[i]表示元素i的父亲结点
//对同一个集合来说只存在一个根结点，且将其作为所属集合的标识
int father[N];

//基本操作
//初始化
for (int i = 1; i <= N; i++) {
    father[i] = i; //令father[i]为-1也可，此处以father[i]=i为例
}
//查找
//findFather函数返回元素x所在集合的根结点
//递推实现
int findFather(int x) {
    //如果不是根结点，继续循环
    while (x != father[x]) {
        x = father[x]; //获得自己的父亲结点
    }
    return x;
}
//递归实现
int findFather(int x) {
    if (x == father[x])
        return x; //如果找到根结点，则返回根结点编号x
    else
        return findFather(father[x]); //否则，递归判断x的父亲结点是否是根结点
}
//合并
void Union(int a, int b) {
    int faA = findFather(a); //查找a的根结点，记为faA
    int faB = findFather(b); //查找b的根结点，记为faB
    if (faA != faB)
        father[faA] = faB; //如果不属于同一个集合，合并它们
}

//路径压缩（优化查询操作）
int findFather(int x) {
    //由于x在下面的while中会变成根结点，因此先把原先的x保存一下
    int a = x;
    while (x != father[x]) {
        x = father[x]; //寻找根结点
    }
    //到这里，x存放的是根结点。下面把路径上的所有结点的father都改成根结点
    while (a != father[a]) {
        int z = a; //因为a要被father[a]覆盖，所以先保存a的值，以修改father[a]
        a = father[a]; //a回溯父亲结点
        father[z] = x; //将原先的结点a的父亲改为根结点
    }
    return x; //返回根结点
}
//递归版
int findFather(int v) {
    if (v == father[v])
        return v; //找到根结点
    else {
        int F = findFather(father[v]); //递归寻找father[v]的根结点F
        father[v] = F; //将根结点F赋给father[v]
        return F; //返回根结点F
    }
}
