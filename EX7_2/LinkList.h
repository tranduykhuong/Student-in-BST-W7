#include<iostream>
using namespace std;

class LinkList {
	struct infor {
		string id, name;
		int status;
		struct bir {
			int d, m, y;
		}dob;
	};
	struct NodeL {
		infor data;
		NodeL* next;
	};

	NodeL* head;
	int size;

	NodeL* createNodeL(infor);
	NodeL* getTail(NodeL*);
	NodeL* partition(NodeL* head, NodeL* end, NodeL** nH, NodeL** nE);
	NodeL* QuickSortRecur(NodeL* head, NodeL* end);

public:
	LinkList();
	void insert(string, string, int, int, int, int);
	void printList();

	void QuickSort();
	~LinkList();
};