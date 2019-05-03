//判断最大流多解就是在残留网络中找正环
bool vis[MAXN], no[MAXN];
int Stack[MAXN], top;
bool dfs(int u, int pre, bool flag) {
  vis[u] = 1;
  Stack[top++] = u;
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].to;
    if (edge[i].cap <= edge[i].flow) continue;
    if (v == pre) continue;
    if (!vis[v]) {
      if (dfs(v, u, edge[i ^ 1].flow < edge[i ^ 1].cap)) return true;
    } else if (!no[v])
      return true;
  }
  if (!flag) {
    while (1) {
      int v = Stack[--top];
      no[v] = true;
      if (v == u) break;
    }
  }
  return false;

}  //执行完最大流后可进行调用

memset(vis, false, sizeof(vis));
memset(no, false, sizeof(no));
top = 0;
bool flag = dfs(end, end, 0);