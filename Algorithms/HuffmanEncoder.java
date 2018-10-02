import java.util.ArrayList;
import java.util.HashMap;
import java.util.PriorityQueue;

public class HuffmanEncoder {
	private HashMap<Character, String> encoder = new HashMap<>();
	private HashMap<String, Character> decoder = new HashMap<>();

	private class Node implements Comparable<Node> {
		char data;
		int freq;
		Node left;
		Node right;

		@Override
		public int compareTo(Node o) {
			return this.freq - o.freq;
		}
	}

	public HuffmanEncoder(String feeder) {
		// Step 1 -> Feeder to fmap
		HashMap<Character, Integer> fmap = new HashMap<>();

		for (int i = 0; i < feeder.length(); i++) {
			char ch = feeder.charAt(i);
			fmap.put(ch, fmap.containsKey(ch) ? fmap.get(ch) + 1 : 1);
		}

		// Step 2 -> fmap to Priority Queue
		ArrayList<Character> keys = new ArrayList<>(fmap.keySet());
		PriorityQueue<Node> pq = new PriorityQueue<>();
		for (Character key : keys) {
			Node node = new Node();
			node.freq = fmap.get(key);
			node.data = key;
			pq.add(node);
		}

		// Step 3 -> while PQ.size > 1, remove 2 from PQ, merge them and add in
		// PQ
		while (pq.size() > 1) {
			Node one = pq.remove();
			Node two = pq.remove();
			Node merged = new Node();
			merged.freq = one.freq + two.freq;
			merged.left = one;
			merged.right = two;
			pq.add(merged);
		}

		Node lastNodeInPQ = pq.remove();
		traverse(lastNodeInPQ, "");
		System.out.println(encoder);
	}

	private void traverse(Node node, String psf) {
		if (node.left == null && node.right == null) {
			encoder.put(node.data, psf);
			decoder.put(psf, node.data);
			return;
		}
		traverse(node.left, psf + "0");
		traverse(node.right, psf + "1");
	}

	public String encode(String str) {
		String coded = "";
		for (int i = 0; i < str.length(); i++) {
			coded += encoder.get(str.charAt(i));
		}

		return coded;
	}

	public String decode(String str) {
		String ch = "";
		String decoded = "";
		
		for (int i = 0; i < str.length(); i++) {
			ch += str.substring(i, i + 1);
			if (decoder.containsKey(ch)) {
				decoded += decoder.get(ch);
				ch = "";
			}
		}

		return decoded;
	}

}
