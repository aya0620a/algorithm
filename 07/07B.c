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
int n, D[MAX], H[MAX];

//深さを求める関数
void setDepth(int u, int d){
    
    //節点uの深さが求まっている場合は終了
    if(u == NIL){
        return;
    }
    D[u] = d;
    //節点uの左の子に対して再帰的に深さを求める
    setDepth(T[u].left, d + 1);
    //節点uの右の子に対して再帰的に深さを求める
    setDepth(T[u].right, d + 1);
}


//節点uの高さを求める関数
int setHeight(int u){
    //節点uの高さが求まっている場合はその値を返す
    int h1 = 0, h2 = 0;
    //ある節点の左の子が存在する場合、その子の高さに1を足す
    if(T[u].left != NIL){
        h1 = setHeight(T[u].left) + 1;
    }
    //ある節点の右の子が存在する場合、その子の高さに1を足す
    if(T[u].right != NIL){
        h2 = setHeight(T[u].right) + 1;
    }
    if(h1 > h2){
        return H[u] = h1;
    }else{
        return H[u] = h2;
    }
}

// 節点の兄弟を返す関数
int getSibling(int u){
    //節点uの親が存在しない場合、兄弟は存在しない
    if(T[u].parent == NIL){
        return NIL;
    }
    //節点uの親の左の子が節点uである場合、兄弟は親の右の子
    if(T[T[u].parent].left != u && T[T[u].parent].left != NIL){
        return T[T[u].parent].left;
    }
    //節点uの親の右の子が節点uである場合、兄弟は親の左の子
    if(T[T[u].parent].right != u && T[T[u].parent].right != NIL){
        return T[T[u].parent].right;
    }
    return NIL;

}

//子の数を返す関数
int getDegree(int u){

    //初期化
    int deg = 0;
    if(T[u].left != NIL){
        deg++;
    }
    if(T[u].right != NIL){
        deg++;
    }
    return deg;
}

int main (void){
    int n;
    //idは節点の番号、leftは左の子の番号、rightは右の子の番号
    int id, left, right;
    int root;
    scanf("%d", &n);

    //初期化
    for(int i = 0; i < n; i++){
        T[i].parent = T[i].left = T[i].right = NIL;
    }

    //idは節点の番号、leftは左の子の番号、rightは右の子の番号
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

    //根を求める
    for(int i = 0; i < n; i++){
        if(T[i].parent == NIL){
            root = i;
        }
    }

    //深さを求める
    setDepth(root, 0);
    //高さを求める
    setHeight(root);

    int deg;
    
    //出力
    for(int i = 0; i < n; i++){

        //節点iの親、兄弟、子の数、深さ、高さを出力
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", i, T[i].parent, getSibling(i), getDegree(i), D[i], H[i]);

        //節点iの種類を出力
        if(T[i].parent == NIL){
            printf("root\n");
        }else if((T[i].left == NIL) && (T[i].right == NIL)){
            printf("leaf\n");
        }else{
            printf("internal node\n");
        }
    }

    return 0;
}