/*
*	Author: Pritish Thakkar
*/
#include<bits/stdc++.h>

using namespace std;

const int N = 1000000;

// Adjacency list:
// Key is node "u" and vector of pairs ("weight", "adjacent node v") is the value.
map<int, vector<pair<int, int> > > adj;

// breadth first search
void bfs(int start){
	queue<int> q;
	q.push(start);
	
	// dist vector: for storing the distance of other
	// nodes from source node.
	map<int, int> dist;
	dist[start] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 0 ; i < adj[u].size() ; i++){
			int v = adj[u][i].first;
			if(!dist.count(v)){
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}

	for(auto distance: dist){
		cout << "Distance of node " << distance.first << " from " << start << " is : " << distance.second << endl;
	}
}


int main(){
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

	// Print the nodes in bfs order considering 0 as source node.
	bfs(0); 
	return 0;
}

