#include <stdio.h>

int status[100]; // 頂点の訪問状態、0:未訪問、1:訪問した、2:訪問完了
int time = 0; // 訪問時刻
int d[100]; // 発見時刻
int f[100]; // 完了時刻

// 深さ優先探索
void dfs_visit(int n, int A[][n], int u){
    status[u] = 1; // 頂点uを訪問したに設定
    d[u] = ++time; // 訪問時刻を更新

    for(int v = 0; v < n; v++){
        // 頂点uに隣接する頂点vが未訪問の場合、頂点vを訪問
        if(A[u][v] == 1 && status[v] == 0){
            dfs_visit(n, A, v);
        }
    }

    status[u] = 2; // 頂点uを訪問完了に設定
    f[u] = ++time; // 完了時刻を更新
}

// 発見時刻と完了時刻を出力
void printArray(int n){
    for(int i = 0; i < n; i++){
        printf("%d %d %d\n", i+1, d[i], f[i]);
    }
}

void dfs(int n, int A[][n]){
    //初期化
    for(int i = 0; i < n; i++){
        status[i] = 0; // 全頂点を未訪問に設定
    }

    for(int u = 0; u < n; u++){
        if(status[u] == 0){
            dfs_visit(n, A, u);
        }
    }

    printArray(n); // 解を出力
}


int main(void){
    int n; // 頂点数
    int u, k; // 頂点uの出次数k

    scanf("%d", &n);

    int A[n][n]; // 隣接行列

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            A[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++){
        scanf("%d %d", &u, &k);

        for(int j = 0; j < k; j++){
            int v;
            scanf("%d", &v);
            A[u-1][v-1] = 1;
        }
    }

    dfs(n, A);

    return 0;
}
