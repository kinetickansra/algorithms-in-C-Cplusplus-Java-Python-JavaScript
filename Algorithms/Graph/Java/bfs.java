import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;

public class BFS {

	public static void main(String[] args) {
		Graph G = new Graph(8);
		G.addEdge(0, 1);
		G.addEdge(2, 3);
		G.addEdge(0, 4);
		G.addEdge(5, 6);
		G.addEdge(2, 5);
		G.addEdge(2, 6);
		G.addEdge(1, 5);
		G.addEdge(6, 7);
		G.addEdge(3, 6);
		G.addEdge(3, 7);
		BFS b = new BFS();
		b.bfs(G, 1);
	}
	
	public void bfs(Graph G,int s) {
		int[] color = new int[G.V()]; //0-White,1-Gray,2-Black
		int[] d = new int[G.V()]; //distance from source
		int[] p = new int[G.V()]; // parent
		Arrays.fill(d, -1);
		Arrays.fill(p, -1);
		ArrayDeque<Integer> q = new ArrayDeque<>();
		
		color[s]=1;
		d[s]=0;
		p[s]=-1; //parent of source in BFS tree is NIL
		q.add(s);
		while(!q.isEmpty()) {
			int u = q.poll();
			for(int v:G.adj[u]) {
				if(color[v]==0) { //if color is white
					color[v]=1;   //make it Grey
					d[v]=d[u]+1;  // update distance from source
					p[v]=u;       // update parent
					q.add(v);
				}
			}
			color[u]=2; //change color to black when all adjacent of u are discovered
		}
		System.out.println(Arrays.toString(color));
		System.out.println(Arrays.toString(d));
		System.out.println(Arrays.toString(p));
	}
	
	static class Graph {
		private final int V;
		private int E;
		private ArrayList<Integer>[] adj;

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
}
