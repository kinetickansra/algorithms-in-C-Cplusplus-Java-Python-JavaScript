#ifndef SL_LIST
#define SL_LIST

class SLLNode {
public:
	SLLNode(): info() { next = 0; }
	SLLNode(int a, SLLNode *ptr = 0) { info = a; next = ptr; }
	int info;
	SLLNode *next;
};

class SLList {
public:
	SLList() { head = tail = 0; }
	~SLList();
	bool is_empty() { return head == 0; }
	void add_to_head(int);
	void add_to_tail(int);
	int delete_from_head();
	int delete_from_tail();
	void delete_node(int);
	bool is_in_list(int);
	void print_list();
private:
	SLLNode *head, *tail;
};

#endif 
