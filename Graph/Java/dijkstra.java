package dijkstra;

import java.io.BufferedReader;

import java.io.IOException;

import java.io.InputStream;

import java.io.InputStreamReader;

import java.util.StringTokenizer;



/** Class for buffered reading int and double values */

class Reader {

    static BufferedReader reader;

    static StringTokenizer tokenizer;



    /** call this method to initialize reader for InputStream */

    static void init(InputStream input) {

        reader = new BufferedReader(

                     new InputStreamReader(input) );

        tokenizer = new StringTokenizer("");

    }



    /** get next word */

    static String next() throws IOException {

        while ( ! tokenizer.hasMoreTokens() ) {

            //TODO add check for eof if necessary

            tokenizer = new StringTokenizer(

                   reader.readLine() );

        }

        return tokenizer.nextToken();

    }



    static int nextInt() throws IOException {

        return Integer.parseInt( next() );

    }

    static long nextLong() throws IOException {

        return Long.parseLong( next() );

    }

    static double nextDouble() throws IOException {

        return Double.parseDouble( next() );

    }

}


class dijkstra {



	long[][] array;

	long dist[]=new long[11000];

	int parent[]=new int[11000];

	dijkstra (int v) {

		 array=new long[v+1][v+1];
	}

	void addedge(int src, int dest, long weight) {
		array[src][dest]=weight;
		array[dest][src]=weight;
	}
	

	int findmin(long [] dist,int size, boolean[] visited) {

		int low=0;

		long min=Integer.MAX_VALUE;

		for (int i=1;i<size;i++) {

			if (dist[i]<min&&visited[i]==false) {

				min=dist[i];

				low=i;

			}

		}

		return low;

	}

	

	int[] DJK(int s){

		

		for (int i=1;i<array.length;i++) {

			dist[i]=Integer.MAX_VALUE;

		}

		dist[s]=0;

		parent[s]=0;

		boolean[] visited=new boolean[array.length];

		for (int i=1;i<array.length;i++) {

			int min=findmin(dist,array.length,visited);
			visited[min]=true;

			for (int x=1;x<array[min].length;x++) {

				if (array[min][x]!=0 && !visited[x] ) {

					if(array[min][x]<dist[x]) {

						dist[x]=array[min][x];
						parent[x]=min;

					}

				}

			}

		}

		return parent;

	}

	

	public static void main(String[] args) throws IOException {

		// TODO Auto-generated method stub
		Reader.init(System.in);
		int test=Reader.nextInt();
		for (int t=1;t<=test;t++) {
			
			int v=Reader.nextInt();
			dijkstra obj=new dijkstra(v);
			int e=Reader.nextInt();
			long sum=0;
			for (int x=0;x<e;x++) {
				int a=Reader.nextInt();
				int b=Reader.nextInt();
				long c=Reader.nextLong();
				sum+=c;
				obj.addedge(a,b,c);
			}
			int[] ans=obj.DJK(1);
			for(int o=2;o<=v;o++) {
				sum-=obj.array[o][ans[o]];
			}
			System.out.println(sum);
		}
			
	}

}

