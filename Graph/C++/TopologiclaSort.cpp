/*
*
* Author : Pritish Thakkar
* Topic : Topological sort on a directed acyclic graph
* Link : http://sleepincode.blogspot.com/2017/07/topological-sort-on-directed-acyclic.html
*/

#include<bits/stdc++.h>

using namespace std;

const int N = 100000;                 // Maximum number of nodes, change according to constraints.
map<int, vector<int> > adjList;      
bool visited[N];
vector<int> tSort;


void dfs(int u){
  visited[u] = true;
  for(int i = 0 ; i < adjList[u].size() ; i ++){
    int v = adjList[u][i];          // neighbour of u
    if(visited[v] != true){         // checking if neighbour is already visited or not
      dfs(v);
    }
  }
  tSort.push_back(u);              // push in tSort[] only when it has no unvisited node left.
}

int main(){
  memset(visited, 0, sizeof(visited));
  int n , edges;                    // n = number of nodes, edges = Number of edges
  scanf("%d%d",&n,&edges);
  for(int i = 0 ; i < edges ; i ++){
    int u, v;
    scanf("%d%d",&u,&v);            // u -> v
    adjList[u].push_back(v);
  }
  for(int i = 1 ; i <= n ; i++){
    if(!visited[i]){
      dfs(i);
    }
  }
  reverse(tSort.begin(), tSort.end());   // Reversing tSort[]
  printf("Topological Sorting of DAG G is :\n");
  for(int i = 0 ; i < tSort.size() ; i ++){
    printf("%d ",tSort[i]);
  }
  printf("\n");
}