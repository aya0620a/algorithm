#include <stdio.h>

#define MAX 1000
#define NIL -1

//節点数に変化のない二分木
struct Node
{
    int parent, left, right;
};

//木構造のノードを格納する配列
struct Node T[MAX];
//木構造のノードの深さを格納する配列と高さを格納する配列

//先行順巡回
void preParse(int u){
    if(u == NIL){
        return;
    }
    printf(" %d", u);
    preParse(T[u].left);
    preParse(T[u].right);
}

//中間順巡回
void inParse(int u){
    if(u == NIL){
        return;
    }
    inParse(T[u].left);
    printf(" %d", u);
    inParse(T[u].right);
}

//後行順巡回
void postParse(int u){
    if(u == NIL){
        return;
    }
    postParse(T[u].left);
    postParse(T[u].right);

    printf(" %d", u);
}

//それぞれの巡回の結果を出力
void print_Patrol(int u){
    printf("Preorder\n");
    preParse(u);
    printf("\n");
    printf("Inorder\n");
    inParse(u);
    printf("\n");
    printf("Postorder\n");
    postParse(u);
    printf("\n");
}

int main (void){
    int n;
    scanf("%d", &n);
    int id, left, right;
    int root;

    //初期化
    for(int i = 0; i < n; i++){
        T[i].parent = T[i].left = T[i].right = NIL;
    }

    //節点の親、左の子、右の子を入力
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &id, &left, &right);
        T[id].left = left;
        T[id].right = right;

        if(left != NIL){
            T[left].parent = id;
        }
        if(right != NIL){
            T[right].parent = id;
        }
    }

    //根を探す
    for(int i = 0; i < n; i++){
        if(T[i].parent == NIL){
            root = i;
        }
    }

    //それぞれの巡回の結果を出力
    print_Patrol(root);

    return 0;
}