// 约瑟夫问题:
// n个人围着圆桌坐, 每人一个编号, 现指定编号为k的人从1开始报数, 报到第m的人离开圆桌出局
// 下一个人开始从1报数, 仍然第m个离开, 如此重复直至剩下一个人
// 编写程序输出每个离开圆桌的人的编号(n, k, m分别通过键盘输入)

// 思路: 使用不带头节点的循环链表解决

#include <stdio.h>
#include <alloca.h>
#include <stdlib.h>

struct clist
{
    int data;
    struct clist * next;
};


int main(void){
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    struct clist * list, * p, *q;
    list=(struct clist *)malloc(sizeof(struct clist));
    p=list;
    p->data=1;
    for (int i = 1; i < n; i++)
    {
        q=(struct clist *)malloc(sizeof(struct clist));
        q->data=i+1;
        p->next=q;
        p=p->next;
    }
    p->next=list;

    while (p)
    {
        if (p->data==k)
        {
            break;
        }
        else
        {
            p=p->next;
        }
    }
    
    while (p->next!=p)
    {
        for (int i = 1; i < m; i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        printf("%d ", p->data);
        free(p);
        p=q->next;
    }

    printf("\nLeft:%d", p->data);    
    
    getchar();
    getchar();
    return 0;
}