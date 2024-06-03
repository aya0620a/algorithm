#include <stdio.h>
#define LEN 100005

typedef struct pp{
  char name[100];
  int t;
}P;

P Q[LEN+1];
int head, tail, n;

void enqueue(P x){
    Q[tail] = x;
    tail = (tail + 1) % LEN;
}

P dequeue(){
    P x = Q[head];
    head = (head + 1) % LEN;
    return x;
}

int isEmpty(){
    if (tail == head)
    {
        return 1;
    }
    else return 0;
}

int ifFull(){
    if (head == (tail + 1) % LEN)
    {
        return 1;
    }
    else return 0;    
}


int main(){
    int time = 0;
    int i, q, current_q;
    P nowTask;
    scanf("%d %d", &n, &q);

    for ( i = 1; i <= n; i++){
        scanf("%s", Q[i].name);
        scanf("%d", &Q[i].t);
    }

    head = 1;
    tail = n + 1;
    //headとtailを初期化

    while (isEmpty() != 1){
        nowTask = dequeue();
        //キューからタスクを取り出す
        current_q = q;
        //現在のタイムクオンタムを設定
        if (nowTask.t <= current_q){
            //タスク完了
            time += nowTask.t;
            printf("%s %d\n", nowTask.name, time);
        }
        else{
            //タイムクォンタムだけ処理
            time += current_q;
            nowTask.t -= current_q;
            enqueue(nowTask);
        }
    } 

    return 0;
}