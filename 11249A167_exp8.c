#include <stdio.h>

#define MAX 1000
#define INF 1000000000

int n = 6;
int capacity[MAX][MAX], flow[MAX][MAX], pred[MAX], color[MAX];
int q[MAX], head, tail;

int min(int a, int b) { return a < b ? a : b; }

void enqueue(int x) { q[tail++] = x; color[x] = 1; }
int dequeue() { int x = q[head++]; color[x] = 2; return x; }

int bfs(int s, int t) {
for (int i = 0; i < n; i++) color[i] = 0;

head = tail = 0;
enqueue(s);
pred[s] = -1;

while (head != tail) {
int u = dequeue();
for (int v = 0; v < n; v++)
if (!color[v] && capacity[u][v] - flow[u][v] > 0) {
enqueue(v);
pred[v] = u;
}
}
return color[t] == 2;
}

int fordFulkerson(int s, int t) {
int max_flow = 0;

for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++)
flow[i][j] = 0;

while (bfs(s, t)) {
int inc = INF;

for (int u = t; pred[u] != -1; u = pred[u])
inc = min(inc, capacity[pred[u]][u] - flow[pred[u]][u]);

for (int u = t; pred[u] != -1; u = pred[u]) {
flow[pred[u]][u] += inc;
flow[u][pred[u]] -= inc;
}

max_flow += inc;
}
return max_flow;
}

int main() {
// initialize capacity
for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++)
capacity[i][j] = 0;

capacity[0][1] = 8;
capacity[0][4] = 3;
capacity[1][2] = 9;
capacity[2][4] = 7;
capacity[2][5] = 2;
capacity[3][5] = 5;
capacity[4][2] = 7;
capacity[4][3] = 4;

printf("Max Flow: %d", fordFulkerson(0, 5));
}
