/**
* queue：翻译为队列，在STL中实现了一个先进先出的容器
**/
#include <cstdio>
#include <queue>
using namespace std;


//queue的定义
queue<typename> name;


//queue容器内元素的访问
{
    queue<int> q;
    for (itn i = 1; i <= 5; i++)
        q.push(i); //push(i)用以将i压入队列，因此依次入队1 2 3 4 5
    printf("%d %d\n", q.front(), q.back()); // 1 5
}


//queue常用函数实例解析
//push()  O(1)
//front() back()  O(1)
//pop()  O(1)
{
    queue<int> q;
    for (itn i = 1; i <= 5; i++)
        q.push(i); //依次入队1 2 3 4 5
    for (int i = 1; i <= 3; i++)
        q.pop(); //出队首元素三次（即依次出队1 2 3）
    printf("%d\n", q.front()); // 4
}
//empty()
{
    queue<int> q;
    //一开始队列内没有元素，所以是空
    if (q.empty() == true)
        printf("Empty\n");
    else
        printf("Not Empty\n");
    q.push(1);
    //在入队“1”后，队列非空
    if (q.empty() == true)
        printf("Empty\n");
    else
        printf("Not Empty\n");
}
//size()
{
    queue<int> q;
    for (int i = 1; i <= 5; i++)
        q.push(i);
    printf("%d\n", q.size()); // 5
}


//queue的常见用途
//当需要实现广度优先搜索时，可以使用queue代替手动实现一个队列
//注意：使用front()和pop()函数前，必须用empty()判断队列是否为空
//延伸：STL中还有两种容器跟队列有关，分别是双端队列(deque)和优先队列(priority_queue)
//      前者是首尾皆可插入和删除的队列，后者是使用堆实现的默认将当前队列最大元素置于队首的容器
