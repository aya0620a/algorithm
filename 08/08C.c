#include <stdio.h>
#include <stdlib.h>

#define COMMAX 500000

struct Node 
{
    int key;
    struct Node *parent, *left, *right; 
};

struct Node *root, *NIL;




void insert(int num, struct Node *Tree){
    //初期化
    Tree->left = NIL;
    Tree->right = NIL;

    struct Node *Root = root;
    struct Node *y = NIL;

    while(Root != NIL){
        y = Root;

        if(Tree->key < Root->key){
            Root = Root->left;
        }
        else{
            Root = Root->right;
        }
    }

    Tree->parent = y;
    
    if(y == NIL){
        root = Tree;
    }
    else{
        if(Tree->key < y->key){
            y->left = Tree;
        }
        else{
            y->right = Tree;
        }
    }
}

void inorder(struct Node *Root){
    if(Root == NIL){
        return;
    }
    inorder(Root->left);
    printf(" %d", Root->key);
    inorder(Root->right);
}

void preorder(struct Node *Root){
    if(Root == NIL){
        return;
    }
    printf(" %d", Root->key);
    preorder(Root->left);
    preorder(Root->right);
}

struct Node *find(struct Node *Root, int num){
    while(Root != NIL && num != Root->key){
        if(num < Root->key){
            Root = Root->left;
        }
        else{
            Root = Root->right;
        }
    }

    return Root;
}

//最小値を探す
struct Node *getMinimum(struct Node *Tree){
    while(Tree->left != NIL){
        Tree = Tree->left;
    }

    return Tree;
}

//次頂点を探す
struct Node *getSuccessor(struct Node *Tree){
    struct Node *y;

    if(Tree->right != NIL){
        //右部分木の中で最小の値を探す
        return getMinimum(Tree->right);
    }

    y = Tree->parent;
    //親ノードがNILでなく、Treeが親ノードの右の子である間、親ノードをたどる
    while(y != NIL && Tree == y->right){
        Tree = y;
        y = y->parent;
    }

    return y;
}

void delete(struct Node *deleteNode){
    struct Node *y;
    struct Node *x;

    //削除するノードが一つも子を持たない場合
    if(deleteNode->left == NIL || deleteNode->right == NIL){
        //そのノードをyとする
        y = deleteNode;
    }
    else{
        //削除するノードが子を2つ持つ場合
        y = getSuccessor(deleteNode);
    }

    //yの子をxとする
    if(y->left != NIL){
        x = y->left;
    }
    else{
        x = y->right;
    }

    if(x != NIL){
        x->parent = y->parent;
    }

    //削除するノードが親ノードの左の子である場合
    if(y->parent == NIL){
        root = x;
    }
    else{
        if(y == y->parent->left){
            y->parent->left = x;
        }
        else{
            y->parent->right = x;
        }
    }

    //削除するノードが子を持たない場合
    if(y != deleteNode){
        deleteNode->key = y->key;
    }

    free(y);    //メモリ解放
}

int main (void){
    int comNum;
    int num;
    char com[10];

    struct Node *Tree;

    scanf("%d", &comNum);

    for (int i = 0; i < comNum; i++)
    {
        scanf("%s", &com);

        

        if (com[0] == 'i')
        {
            scanf("%d", &num);

            Tree = (struct Node *)malloc(sizeof(struct Node));
            Tree->key = num;

            insert(num, Tree);
        }
        else if (com[0] == 'p'){
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
        }
        else if(com[0] == 'f'){
            scanf("%d", &num);

            struct Node *Tree = root;

            if(find(root, num) == NIL){
                printf("no\n");
            }
            else{
                printf("yes\n");
            }
        }
        else if(com[0] == 'd'){
            scanf("%d", &num);

            struct Node *Tree = root;

            if(Tree != NIL){
                delete(find(root, num));
            }
        }
        
    }
    
    return 0;
}