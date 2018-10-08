/*
*	Author: Pritish Thakkar
*/
#include<bits/stdc++.h>

using namespace std;

const int N = 1000000;

// Adjacency list:
// Key is node "u" and vector of pairs ("weight", "adjacent node v") is the value.
map<int, vector<pair<int, int> > > adj;
int visited[N];

// Depth first search
void dfs(int u){
	cout << u << endl;
	visited[u] = 1;
	for(int i = 0 ; i < adj[u].size() ; i++){
		int v = adj[u][i].first;
		// If not visited
		if(visited[v] == 0){
			dfs(v);
		}
	}
}


int main(){
	memset(visited, 0, sizeof(visited));
	int n; // number of nodes from 0 to n-1.
	int m; // numer of edges
	cin >> n >> m;
	for(int i = 0 ; i < m ; i++){
		int u, v, wt;
		// scanning the edge and weight of that edge
		cin >> u >> v >> wt;
		adj[u].push_back(make_pair(v, wt));
		adj[v].push_back(make_pair(u, wt));
	}

	// Print the nodes in dfs order considering 0 as starting node.
	dfs(0); 
	return 0;
}

