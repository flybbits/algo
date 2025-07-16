#include <stdio.h>
#include <stdlib.h>
#define MAXN 5
typedef int ElemType;

typedef struct {
    ElemType data[MAXN];
    int front, rear;   
} SqQueue;

SqQueue *q;
int i, data;

void init();
void destroy();
void inqueue();
void dequeue();
void query();
void print();

int main() {
    printf("1");
    init();
    int choice = -1;
    while(choice != 0) {
        printf("+----队列操作系统----+\t\t\n");
        printf("|\t1.入队\t     |\n");
        printf("|\t2.出队\t     |\n");
        printf("|\t3.查找\t     |\n");
        printf("|\t4.展示\t     |\n");
        printf("|\t0.退出\t     |\n");
        printf("+--------------------+\t\t\n");
        printf("请输入您的选择：\n");
        scanf("%d",&choice);
        switch(choice) {
        case 1:
            inqueue();
            break;
        case 2:
            dequeue();
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
            printf("输入有误，请重新输入！");
            break;
        }
    }
    destroy();
}

void init() {
    q = (SqQueue *)malloc(sizeof(SqQueue));
    q->front = q->rear = 0;
}

void destroy() {
    free(q);
}

void inqueue() {
    if ((q->rear + 1) % MAXN == q->front) {
        printf("队满，插入失败！\n");
    } else {
        printf("请输入要入队的数：");
        scanf("%d", &data);
        q->data[q->rear] = data;
        q->rear = (q->rear + 1) % MAXN;
        printf("入队成功！\n");
    }
}

void dequeue() {
    if (q->front == q->rear) {
        printf("队空，出队失败！\n");
        q->front = q->rear = 0;
    } else {
        q->front = (q->front + 1) % MAXN;
        printf("出队成功！\n");
    }
}

void query() {
    if (q->front == q->rear) {
        printf("队空，该元素不存在！\n");
        q->front = q->rear = 0;
    }
    int count = 1, flag = 0;
    i = q->front;
    printf("请输入要查找的元素：");
    scanf("%d", &data);
    while(i != q->rear) {
        if (q->data[i] == data) {
            printf("该元素在队列的第%d个位置！\n", count);
            flag = 1;
            break;
        } else {
            i = (i + 1) % MAXN;
            count++;
        }
    }
    if (!flag) {
        printf("该数据不在队列中！\n");
    }
}

void print() {
    if (q->front == q->rear) {
        printf("队空！\n");
        q->front = q->rear = 0;
    }
    int count = 1;
    i = q->front;
    while ((i + 1) % MAXN != q->front) {
        printf("%d-th元素的值为：%d\n", count, q->data[i]);
        i = (i + 1) % MAXN;
        count++;
    }
}
