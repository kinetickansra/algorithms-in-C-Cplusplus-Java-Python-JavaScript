import java.util.*;

public class DFS {
//////////simple DFS//////////////////
	private static boolean[] marked;
	private static int count;

	public static void dfsUtil(Graph G, int s) {
		marked = new boolean[G.V()];
		dfs(G, s);
	}

	private static void dfs(Graph G, int v) {
		marked[v] = true;
		count++;
		for (int w : G.adj(v)) {
			if (!marked[w]) {
				dfs(G, w);
			}
		}
	}
	
	public static boolean isMarked(int w) {
		return marked[w];
	}
	
	public static int count() {
		return count;
	}
////////////////////////////////////////
	static class Graph {
		private final int V; // vertices
		private int E; // edges
		ArrayList<Integer>[] adj; // adjacency list

		public Graph(int V) {
			this.V = V;
			adj = new ArrayList[V];
			for (int v = 0; v < V; v++) {
				adj[v] = new ArrayList<Integer>();
			}
		}

		public int V() {
			return V;
		}

		public int E() {
			return E;
		}

		public void addEdge(int v, int w) {
			adj[v].add(w);
			adj[w].add(v);
			E++;
		}

		public Iterable<Integer> adj(int v) {
			return adj[v];
		}
	}

	public static void main(String[] args) {
		int v=3;  //no of vertex 
		Graph G = new Graph(v);
		G.addEdge(0, 1);
		G.addEdge(1, 2);
		G.addEdge(2, 0);
		int source=1;
		dfsUtil(G, source);
		System.out.println(isMarked(2));       //tell reachable from source or not
		System.out.println(count);			   //number of vertices reachable from source	
	}
}
