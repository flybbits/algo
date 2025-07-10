#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef int Type;

Type stack[N];
int top = 0;

void push();
void pop();
void query();
void print();

int main()
{
    int choice = -1;
    while (choice != 0)
    {
        printf("+----堆栈操作系统----+\t\t\n");
        printf("|\t1.入栈\t     |\n");
        printf("|\t2.出栈\t     |\n");
        printf("|\t3.查找\t     |\n");
        printf("|\t4.展示\t     |\n");
        printf("|\t0.退出\t     |\n");
        printf("+--------------------+\t\t\n");
        printf("请输入您的选择：\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            query();
            break;
        case 4:
            print();
            break;
        case 0:
            exit(0);
        default:
            printf("输入有误，请重新输入！\n");
            break;
        }
    }
    return 0;
}

void push()
{
    if (top == N)
    {
        printf("栈满，入栈失败！");
    }
    else
    {
        Type data;
        printf("请输入你要插入的数据：");
        scanf("%d", &data);
        stack[top++] = data;
        printf("数据已入栈！\n");
    }
}

void pop()
{
    if (top == 0)
    {
        printf("栈空，出栈失败！");
    }
    else
    {
        top--;
        printf("顶端元素已出栈！\n");
    }
}

void query()
{
    int data, temp = top, count = 0, flag = 0;
    if (top == -1)
    {
        printf("栈为空！\n");
    }
    else
    {
        printf("请输入待查询数据：");
        scanf("%d", &data);
        while (temp > 0)
        {
            if (stack[--temp] == data) 
            {
                printf("该数据距栈顶的位置为：%d\n", count);
                flag=1;
            }
            count++;
        }
        if (!flag)
        {
            printf("该数据不在堆栈中！\n");
        }
    }
}

void print()
{
    int count = 1, temp = top;
    if (temp == 0) 
    {
        printf("栈空！\n");
    }
    else
    {
        while (temp > 0)
        {
            printf("%d-th个元素：%d\n", count++, stack[--temp]);
        }
    }
}
