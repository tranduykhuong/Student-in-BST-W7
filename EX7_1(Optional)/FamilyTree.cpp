#include"FamilyTree.h"

FamilyTree::FamilyTree()
{
	root = nullptr;
}

FamilyTree::Node* FamilyTree::createNode(string name)
{
	Node* newnode = new Node;
	newnode->name = name;
	newnode->n = 0;
	return newnode;
}

void FamilyTree::PreOrder(Node* p, ostream& out)
{
	if (p == nullptr)
		return;
	out << p->name << " ";
	for (int i = 0; i < p->n; i++)
		PreOrder(p->c[i], out);
}
void FamilyTree::PreOrder(ostream& out) {
	PreOrder(root, out);
}

void FamilyTree::InOrder(Node* p, ostream& out)
{
	if (p == nullptr)
		return;
	InOrder(p->c[0], out);
	out << p->name << " ";
	for (int i = 1; i <= p->n; i++)
		InOrder(p->c[i], out);
}
void FamilyTree::InOrder(ostream& out) {
	InOrder(root, out);
}

void FamilyTree::PostOrder(Node* p, ostream& out)
{
	if (p == nullptr)
		return;
	for (int i = 0; i < p->n; i++)
		PostOrder(p->c[i], out);
	out << p->name << " ";
}
void FamilyTree::PostOrder(ostream& out) {
	PostOrder(root, out);
}

void FamilyTree::SearchName(Node* p, string name, Node** res)
{
	if (p == nullptr || p->name == name) {
		*res = p;
		return;
	}
	for (int i = 0; i < p->n; i++)
		if (p->c[i])	
			SearchName(p->c[i], name, res);
}

void FamilyTree::insertFamily(string parent, string a[], int n)
{
	if (root == nullptr) {
		root = createNode(parent);
		for (int i=0; i<n; i++)
			root->c[i] = createNode(a[i]);
		root->n = n;
		return;
	}
	Node* p;
	SearchName(root, parent, &p);
	if (p) {
		for (int i = 0; i < n; i++)
			p->c[p->n + i] = createNode(a[i]);
		p->n += n;
		return;
	}
}

void FamilyTree::ReadFile(string filename)
{
	ifstream fin(filename);
	if (!fin)	return;
	int n;	fin >> n;
	for (int i = 0; i < n; i++) {
		string a[MAX], tmp, pr; int k = 0;
		fin.seekg(3, ios::cur);
		fin >> pr;
		fin.seekg(2, ios::cur);
		fin >> tmp;
		while (tmp[tmp.length() - 1] != ')') {
			a[k++] = tmp;
			fin >> tmp;
		}
		tmp = tmp.substr(0, tmp.length() - 2);
		a[k++] = tmp;
		insertFamily(pr, a, k);
	}
	fin.close();
}

void inputSelect(int& ans, int beg, int end)
{
	cout << "\tYour choice: ";
	cin >> ans;
	if (ans<beg || ans>end) {
		cout << "Enter error! Please enter again!\n";
		return inputSelect(ans, beg, end);
	}
}

void Menu()
{
	system("cls");
	cout << "\tA FAMILY TREE\n"
		<< "\t-----/*\\-----\n";
	cout << "The program has read the \"input.txt\" file of the topic\n\n";
	cout << "\tThe options:\n"
		<< "\t1. PreOrder (NLR)\n"
		<< "\t2. InOrder (LNR)\n"
		<< "\t3. PostOrder (LRN)\n"
		<< "\t4. All cases above\n"
		<< "\t5. Quit\n";
}

void SelectPrint(string& fn)
{
	system("cls");
	cout << "\tA FAMILY TREE\n"
		<< "\t-----/*\\-----\n";
	cout << "Enter your file's name to print to file: ";
	cin.ignore();
	getline(cin, fn);
}