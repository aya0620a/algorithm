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

void find(struct Node *Root, int num){
    if(Root == NIL){
        printf("no\n");
        return ;
    }
    if(Root->key == num){
        printf("yes\n");
        return ;
    }
    if(Root->key > num){
        Root = Root->left;
        find(Root, num);
    }
    else{
        Root = Root->right;
        find(Root, num);
    }

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

            find(root, num);
        }
        
    }
    
    return 0;
}