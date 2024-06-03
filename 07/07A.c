#include <stdio.h>
#include <stdlib.h>

#define MAX 100000
#define NIL -1

// 木構造のノードを表す構造体
struct Node
{
    int parent, left, right;
};

// 木構造のノードを格納する配列
struct Node T[MAX];
// 木構造のノードの深さを格納する配列
int n, D[MAX];

void print(int u)
{
    int i, c;
    printf("node %d: ", u);
    printf("parent = %d, ", T[u].parent);
    printf("depth = %d, ", D[u]);

    if (T[u].parent == NIL)
        printf("root, ");
    else if (T[u].left == NIL)
        printf("leaf, ");
    else
        printf("internal node, ");

    printf("[");

    for (i = 0, c = T[u].left; c != NIL; i++, c = T[c].right)
    {
        if (i)
            printf(", ");
        printf("%d", c);
    }
    printf("]\n");
}

//再帰的に深さを求める
int rec(int u, int p)
{
    //木の深さが求まっている場合は終了
    D[u] = p;
    if (T[u].right != NIL)
        //右の兄弟に対して再帰的に深さを求める
        rec(T[u].right, p);
    if (T[u].left != NIL)
        //最も左の子に対して再帰的に深さを求める
        rec(T[u].left, p + 1);
}

int main()
{
    int i, j, k, id, c, l, r;

    scanf("%d", &n);

    //初期化
    for (i = 0; i < n; i++)
        T[i].parent = T[i].left = T[i].right = NIL;

    //入力を受け取り、各ノードに子ノードを設定
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &id, &k);
        for (j = 0; j < k; j++)
        {
            scanf("%d", &c);
            if (j == 0)
                T[id].left = c;
            else
                T[l].right = c;
            l = c;
            T[c].parent = id;
        }
    }

    //根を探す
    for (i = 0; i < n; i++)
    {
        if (T[i].parent == NIL)
            r = i;
    }

    //深さを求める
    rec(r, 0);

    for (i = 0; i < n; i++)
        print(i);

    return 0;
}



