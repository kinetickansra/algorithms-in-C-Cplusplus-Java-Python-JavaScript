#include <string>
#include <vector>
#include <iostream>

namespace segmentTrees
{



	class SegmentTree
	{
	private:
		class Node
		{
		private:
			SegmentTree *outerInstance;

		public:
			virtual ~Node()
			{
				delete left;
				delete right;
				delete outerInstance;
			}

			Node(SegmentTree *outerInstance);

			int rsi = 0;
			int rei = 0;
			int data = 0;
			Node *left;
			Node *right;
		};
	public:
		Node *root;
		virtual ~SegmentTree()
		{
			delete root;
		}

		SegmentTree(std::vector<int> &arr);
	private:
		Node *construct(std::vector<int> &arr, int lo, int hi);

	public:
		virtual void display();
	private:
		void display(Node *node);

	public:
		virtual void update(int idx, int delta);
	private:
		void update(Node *node, int idx, int delta);

	public:
		virtual int query(int qsi, int qei);
	private:
		int query(Node *node, int qsi, int qei);
	};
}

namespace segmentTrees
{

	SegmentTree::Node::Node(SegmentTree *outerInstance) : outerInstance(outerInstance)
	{
	}

	SegmentTree::SegmentTree(std::vector<int> &arr)
	{
		this->root = construct(arr, 0, arr.size() - 1);
	}

	SegmentTree::Node *SegmentTree::construct(std::vector<int> &arr, int lo, int hi)
	{

		if (lo == hi)
		{
			Node *bn = new Node(this);
			bn->data = arr[lo];
			bn->rsi = lo;
			bn->rei = hi;
			return bn;
		}


		Node *node = new Node(this);
		int mid = (lo + hi) / 2;
		node->rsi = lo;
		node->rei = hi;
		node->left = construct(arr, lo, mid);
		node->right = construct(arr,mid + 1,hi);
		node->data = node->left->data + node->right->data;
		return node;


	}

	void SegmentTree::display()
	{
		display(root);
	}

	void SegmentTree::display(Node *node)
	{
		if (node == nullptr)
		{
			return;
		}
		std::wstring str = L"";
		if (node->left == nullptr)
		{
			str += L". <= ";
		}
		else
		{
			str += std::to_wstring(node->left->data) + L" <= ";
		}
		str += std::to_wstring(node->data) + L" => ";
		if (node->right == nullptr)
		{
			str += L".";
		}
		else
		{
			str += node->right->data;
		}
		std::wcout << str << std::endl;
		display(node->left);
		display(node->right);

	}

	void SegmentTree::update(int idx, int delta)
	{
	 update(root, idx, delta);

	}

	void SegmentTree::update(Node *node, int idx, int delta)
	{
		if (idx <= node->rei && idx >= node->rsi)
		{
			if (node->rei == idx && node->rsi == idx)
			{
				node->data += delta;
				return;

			}
			update(node->left, idx, delta);
			update(node->right, idx, delta);
			node->data = node->left->data + node->right->data;

		}



	}

	int SegmentTree::query(int qsi, int qei)
	{
		return query(root, qsi, qei);
	}

	int SegmentTree::query(Node *node, int qsi, int qei)
	{
		if (qsi <= node->rsi && qei >= node->rei)
		{
			return node->data;
		}
		else if (qsi > node->rei || qei < node->rsi)
		{
			return 0;
		}
		int n1 = query(node->left, qsi, qei);
		int n2 = query(node->right, qsi, qei);
		return (n1 + n2);

	}
}
