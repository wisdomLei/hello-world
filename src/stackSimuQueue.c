//定义布尔值
#define true 1
#define false 0

#include <stdio.h>

// 定义栈结构体
struct STACK
{
    int data[100];
    int top;
};

// 将元素e插入栈s1的指定位置local
// 参数
// s1：栈
// local：插入位置
// e:需要插入的元素
int inqueue(struct STACK *s1, int local, int e)
{
    if (local == 0)
    {
        (*s1).data[++(*s1).top] = e;
        return 0;
    }

    if (local < 0 || (*s1).top < local)
    {
        return false;
    }
    else
    {
        struct STACK s2;
        s2.top = -1;
        for (int i = 0; i < local; i++)
        {
            s2.data[++s2.top] = (*s1).data[(*s1).top];
            (*s1).top--;
        }
        (*s1).data[++(*s1).top] = e;
        while (s2.top != -1)
        {
            (*s1).data[++(*s1).top] = s2.data[s2.top];
            s2.top--;
        }
    }
    return 0;
}

// 删除指定位置local的元素
// 参数
// s1：栈
// local：删除位置
int outqueue(struct STACK *s1, int local)
{
    if (local == 0)
    {
        (*s1).top--;
        return 0;
    }

    if (local < 0 || (*s1).top < local)
    {
        return false;
    }
    else
    {
        struct STACK s2;
        s2.top = -1;
        for (int i = 0; i < local; i++)
        {
            s2.data[++s2.top] = (*s1).data[(*s1).top];
            (*s1).top--;
        }
        (*s1).top--;
        while (s2.top != -1)
        {
            (*s1).data[++(*s1).top] = s2.data[s2.top];
            s2.top--;
        }
    }
    return 0;
}

// 判断传入栈s1是否为空
// 参数
// s1：栈
// 返回：true |false
int queue_empty(struct STACK *s1)
{
    if ((*s1).top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(void)
{
    struct STACK s1;
    s1.top = -1;
    if(queue_empty(&s1))
        printf("empty\n");
    inqueue(&s1, 0, 123);
    if(!queue_empty(&s1))
        printf("not empty\n");
    inqueue(&s1, 0, 234);
    inqueue(&s1, 1, 345);
    return 0;
}
