#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef struct {
    char data[256];
    int top;
} Stack;

void init(Stack *s) {
    s->top = 0;
}

void push(Stack *s, char val) {
    s->data[s->top++] = val;
}

char pop(Stack *s) {
    char val = s->data[--s->top];
    return val;
}

bool judge(Stack *s, char str[]) {
    int i, n = strlen(str);
    char temp[256];
    for(i = 0; i < n; ++i) {
        push(s, str[i]);
    }
    for(i = 0; i < n; ++i) {
        temp[i] = pop(s);
    }
    temp[i] = '\0';
    if(strcmp(str, temp) == 0) {
        return true;
    }
    return false;
}

int main() {
    char str[256];
    Stack *S;
    S = (Stack *)malloc(sizeof(Stack));
    init(S);
    scanf("%s", str);
    if(judge(S, str)) {
        printf("YES");
    } else {
        printf("NO");
    }
    free(S);
    return 0;
}