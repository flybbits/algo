#include <stdio.h>
#include <stdlib.h>

typedef int Type;
typedef struct Node
{
    Type data;
    struct Node *next;
} node;
node *head, *ptr;

void init();
void insert_link();
void delete_link();
void print_link(node *);
void query_link(node *, int);

int main()
{
    init();
    int choice = 8, num;
    while (choice != 0)
    {
        printf("+----链表操作系统----+\t\t\n");
        printf("|\t1.插入\t     |\n");
        printf("|\t2.删除\t     |\n");
        printf("|\t3.查找\t     |\n");
        printf("|\t4.展示\t     |\n");
        printf("|\t0.退出\t     |\n");
        printf("+--------------------+\t\t\n");
        printf("请出入您的选择：\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_link();
            break;
        case 2:
            delete_link();
            break;
        case 3:
            printf("请出入您要查找的数：\n");
            scanf("%d", &num);
            query_link(head, num);
            break;
        case 4:
            print_link(head);
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("输入有误，请重新输入！\n");
            break;
        }
    }
    return 0;
}

void init()
{
    ptr = (node *)malloc(sizeof(node *));
    ptr->data = 1;
    ptr->next = NULL;
    head = ptr;

    ptr = (node *)malloc(sizeof(node *));
    ptr->data = 2;
    head->next = ptr;
    ptr->next = NULL;

    ptr = (node *)malloc(sizeof(node *));
    ptr->data = 3;
    head->next->next = ptr;
    ptr->next = NULL;

    ptr = (node *)malloc(sizeof(node *));
    ptr->data = 4;
    head->next->next->next = ptr;
    ptr->next = NULL;
}

void print_link(node *ptr)
{
    int count = 1;
    if (ptr == NULL)
    {
        printf("链表为空！");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d-th节点的值：%d\n", count, ptr->data);
            ptr = ptr->next;
            count++;
        }
    }
}

void insert_link()
{
    int data = 0, choice;
    printf("请输入插入位置(1:开头,2:中间,3:结尾)：\n");
    scanf("%d", &choice);
    printf("请输入要插入的数据：");
    scanf("%d", &data);
    ptr = (node *)malloc(sizeof(node *));
    switch (choice)
    {
    case 1:
        if (ptr)
        {
            ptr->data = data;
            ptr->next = head;
            head = ptr;
            printf("结点已插入！\n");
        }
        else
        {
            printf("申请内存失败！");
        }
        break;
    case 2:
        if (ptr)
        {
            int loc, i;
            node *temp = head;
            ptr->data = data;
            printf("请输入要插入的位置（插入该位置之后）：");
            scanf("%d", &loc);
            for (i = 0; i < loc - 1; ++i)
            {
                if (temp)
                {
                    temp = temp->next;
                }
                else
                {
                    printf("该位置不存在!\n");
                    return;
                }
            }
            ptr->next = temp->next;
            temp->next = ptr;
            printf("结点已插入！\n");
        }
        else
        {
            printf("申请内存失败！");
        }
        break;
    case 3:
        if (ptr)
        {
            ptr->data = data;
            ptr->next = NULL;
            if (head != NULL)
            {
                node *temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = ptr;
            }
            else
            {
                head = ptr;
            }
            printf("结点已插入！\n");
        }
        else
        {
            printf("申请内存失败！");
        }
        break;
    default:
        printf("输出有误，请再次输入!");
        insert_link();
        break;
    }
}

void delete_link()
{
    int loc, i;
    node *prev;
    printf("请输入您要删除结点的位置（1:第一个，-1：最后一个，其他：中间位置）：\n");
    scanf("%d", &loc);
    switch (loc)
    {
    case 1:
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("第一个结点删除成功！\n");
        break;
    case -1:
        if (head->next == NULL)
        {
            ptr = head;
            head = NULL;
            free(ptr);
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
            {
                prev = ptr;
                ptr = ptr->next;
            }
            prev->next = NULL;
            free(ptr);
        }
        printf("最后一个节点删除成功！\n");
        break;
    default:
        ptr = head;
        for (i = 1; i != loc; ++i)
        {
            prev = ptr;
            ptr = ptr->next;
            if (ptr == NULL)
            {
                printf("该位置不存在！\n");
                return;
            }
        }
        prev->next = ptr->next;
        free(ptr);
        printf("第%d个结点删除成功！\n", loc);
        break;
    }
}

void query_link(node *ptr, int data)
{
    int count = 1, flag = 0;
    if (ptr == NULL)
    {
        printf("链表为空！");
    }
    else
    {
        while (ptr != NULL)
        {
            if (ptr->data == data)
            {
                flag = 1;
                printf("该数字处在链表中的第%d个位置...\n", count);
                break;
            }
            ptr = ptr->next;
            count++;
        }
        if (!flag)
        {
            printf("该数字不存在于链表中！\n");
        }
    }
}
