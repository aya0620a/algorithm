#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int key;
    struct Node *right, *left, *parent;
};

struct Node *root, *NIL;



void insert(int T, struct Node *z){
    struct Node *y = NIL;
    struct Node *x = root;

    //zの左と右の子をNILにする
    z->left = NIL;
    z->right = NIL;

    while(x != NIL){
        y = x;

        if(z->key < x->key){
            x = x->left;
        }else{
            x = x->right;
        }
    }

    z->parent = y;

    if(y == NIL){
        root = z;
    }else if(z->key < y->key){
        y->left = z;
    }else{
        y->right = z;
    }
}


void inorder(struct Node *u){
    if(u == NIL) return;
    inorder(u->left);
    printf(" %d", u->key);
    inorder(u->right);
}

void preorder(struct Node *u){
    if(u == NIL) return;
    printf(" %d", u->key);
    preorder(u->left);
    preorder(u->right);
}

int main(void){
    //命令の数、
    int m;
    //挿入する値
    int num;
    //命令
    char com[20];

    struct Node *z;

    //命令の数の入力
    scanf("%d", &m);

    for(int i = 0; i < m; i++){
        //命令の入力
        scanf("%s", com);

        //命令のイニシャルがiの場合、Insert
        if(com[0] == 'i'){
            scanf("%d", &num);
            z = (struct Node *)malloc(sizeof(struct Node));
            z->key = num;
            insert(num, z);

        //命令のイニシャルがpの場合、Print
        }else if(com[0] == 'p'){
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
        }
    }

    return 0;
}