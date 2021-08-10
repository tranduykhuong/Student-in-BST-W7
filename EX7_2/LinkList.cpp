#include"LinkList.h"

LinkList::LinkList() {
	head = nullptr;
	size = 0;
}

LinkList::~LinkList() {
	while (head) {
		NodeL* tmp = head;
		head = head->next;
		delete tmp;
	}
}

LinkList::NodeL* LinkList::createNodeL(infor data) {
	NodeL* node = new NodeL;
	node->data = data;
	node->next = nullptr;
	return node;
}

void LinkList::insert(string id, string name, int d, int m, int y, int k) {
	infor data;
	data.id = id;
	data.name = name;
	data.dob.d = d; data.dob.m = m; data.dob.y = y;
	data.status = k;
	if (head == nullptr)
		head = createNodeL(data);
	else {
		NodeL* node = createNodeL(data);
		node->next = head;
		head = node;
	}
	size++;
}
void LinkList::printList() {
	NodeL* p = head;
	while (p) {
		cout << p->data.id << "\t" << p->data.name << "\t\t" << p->data.dob.d << "/" << p->data.dob.m << "/" << p->data.dob.y << "\t  " << p->data.status << endl;
		p = p->next;
	}
}

LinkList::NodeL* LinkList::getTail(NodeL* cur) {
	while (cur != nullptr && cur->next != nullptr)
		cur = cur->next;
	return cur;
}
LinkList::NodeL* LinkList::partition(NodeL* head, NodeL* end, NodeL** nH, NodeL** nE) {
	NodeL* prev = nullptr, * cur = head, * tail = end, * pivot = end;
	while (cur != pivot) {
		if (cur->data.name < pivot->data.name) {
			if (*nH == nullptr)
				*nH = cur;
			prev = cur;
			cur = cur->next;
		}
		else {
			if (prev)
				prev->next = cur->next;
			NodeL* tmp = cur->next;
			cur->next = nullptr;
			tail->next = cur;
			tail = cur;
			cur = tmp;
		}
	}
	if (*nH == nullptr)
		*nH = pivot;
	*nE = tail;
	return pivot;
}
LinkList::NodeL* LinkList::QuickSortRecur(NodeL* head, NodeL* end) {
	if (!head || head == end)
		return head;
	NodeL* nH = nullptr, * nE = nullptr;
	NodeL* pivot = partition(head, end, &nH, &nE);
	if (nH != pivot) {
		NodeL* tmp = nH;
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = nullptr;
		nH = QuickSortRecur(nH, tmp);
		tmp = getTail(nH);
		tmp->next = pivot;
	}
	pivot->next = QuickSortRecur(pivot->next, nE);
	return nH;
}
void LinkList::QuickSort() {
	NodeL* end = getTail(head);
	head = QuickSortRecur(head, end);
}
