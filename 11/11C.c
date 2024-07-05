#include <stdio.h>

int status[100]; // 頂点の訪問状態、0:未訪問、1:訪問した、2:訪問完了
int d[100]; //最短距離

// 幅優先探索
void bfs( int n, int A[][n]){
    int Q[n];
    int head = 0;
    int tail = 0;

    //距離が未設定の場合は-1(未到達)
    for(int i = 0; i < n; i++){
        d[i] = -1;
    }

    d[0] = 0;
    Q[tail] = 0;
    tail++;

    //キューが空になるまで繰り返す
    while(head != tail){
        int u = Q[head];
        head++;

        for(int v = 0; v < n; v++){
            //頂点uに隣接する頂点vが未訪問の場合、頂点vを訪問
            if(A[u][v] == 1 && d[v] == -1){
                d[v] = d[u] + 1;
                Q[tail] = v;
                tail++;
            }
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d %d\n", i+1, d[i]);
    }
}


int main(void){
    int n; // 頂点数
    int u, k; // 頂点uの出次数k

    scanf("%d", &n);    

    int A[n][n]; // 隣接行列

    // 隣接行列の初期化
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            A[i][j] = 0;
        }
    }

    // 隣接行列の作成
    for(int i = 0; i < n; i++){
        scanf("%d %d", &u, &k);

        for(int j = 0; j < k; j++){
            int v;
            scanf("%d", &v);
            A[u-1][v-1] = 1;
        }
    }

    // 深さ優先探索
    bfs(n, A);

    return 0;
}