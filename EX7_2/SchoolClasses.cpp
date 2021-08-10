#include"SchoolClasses.h"

void SchoolClasses::LoadData(string filename) {
	ifstream fin(filename);
	if (!fin) {
		cout << "Failed to open file!\n";
		system("pause");
		return;
	}
	int n; fin >> n;
	BST::infor t;
	fin.get();
	for (int i = 0; i < n; i++) {
		getline(fin, t.id);
		getline(fin, t.name);
		fin >> t.dob.d;	fin.get();
		fin >> t.dob.m;	fin.get();
		fin >> t.dob.y;	fin.get();
		fin >> t.status; fin.get();
		tree.insertNode(t);
	}
	fin.close();
}

void SchoolClasses::AddStudents() {
	int n;
	cout << "\t\t   *** ADD STUDENTS ***\n\n";
	cout << "* Enter the numbers of students n = ";
	cin >> n;
	cout << "* Enter the information of the students:\n\n";
	for (int i = 1; i <= n; i++) {
		BST::infor t;
		cout << "- Student " << i << " :\n";
		cout << "ID: ";		cin >> t.id;
		cout << "Name: ";	cin >> t.name;
		cout << "Day of birth (dd mm yyyy): "; 
		cin >> t.dob.d;	cin >> t.dob.m;	cin >> t.dob.y;
		cout << "Status (0: undergrad/ 1: graduated): ";	cin >> t.status;
		tree.insertNode(t);
	}
	cout << "Add successfully!\n";
	printFrameList();
	tree.printTree(cout);
}

void SchoolClasses::FindStudnet_andUpdate() {
	string id;
	cout << "Enter ID: ";	cin >> id;
	BST::Node* p = tree.SearchID(id);	cout << endl;
	if (!p) {
		cout << "Don't found!\n";
		return;
	}
	tree.printInforNode(p);
	cout << "\nPress 1 to update information of student, other key to back to Menu...";
	int ans;	cin >> ans;
	if (ans == 1) {
		cout << "Information update (if the item does not update, enter \"n\")\n";
		cout << "ID: ";		cin >> id;
		if (id != "n" && id != "N")	p->data.id = id;
		cout << "Name: ";	cin >> id;
		if (id != "n" && id != "N")	p->data.name = id;
		cout << "Status (0: undergrad/ 1: graduated): ";	cin >> id;
		if (id != "n" && id != "N")	p->data.status = atoi(id.c_str());
		cout << "Day of birth:\n";
		cout << "  Day: ";	cin >> id;
		if (id != "n" && id != "N")	p->data.dob.d = atoi(id.c_str());
		cout << "  Month: ";	cin >> id;
		if (id != "n" && id != "N")	p->data.dob.m = atoi(id.c_str());
		cout << "  Year: ";	cin >> id;
		if (id != "n" && id != "N")	p->data.dob.y = atoi(id.c_str());
		cout << "Updated successfull!\n";
		tree.printInforNode(p);
	}
	else cout << "Don't update!\n";
}

void SchoolClasses::printFrameList() {
	cout << "------------------------------------------------------\n"
		<< "   ID\t\tName\t\tDoB\t\tStatus\n"
		<< "------------------------------------------------------\n";
}

void SchoolClasses::copytoLinkList(BST::Node* root) {
	if (root == nullptr)	return;

	sortList.insert(root->data.id, root->data.name, root->data.dob.d, root->data.dob.m, root->data.dob.y, root->data.status);

	if (root->left)		copytoLinkList(root->left);
	if (root->right)	copytoLinkList(root->right);
}

void SchoolClasses::ListNameLexi() {
	copytoLinkList(tree.getRoot());
	sortList.QuickSort();
	cout << "***  ALL STUDENTS IN LEXICOGRAPHIC ORDER OF THEIR NAMES ***\n\n";
	printFrameList();
	sortList.printList();
	sortList.~LinkList();
}

void SchoolClasses::deleteGradList(BST::Node*root) {
	if (!root)
		return;
	if (root->left)		deleteGradList(root->left);
	if (root->right)	deleteGradList(root->right);
	tree.deleteNode(root->data.id);
}

void SchoolClasses::GraduatedList() {
	BST list;
	tree.ListGraduated(list);

	cout << "\tList all graduated students:\n\n";
	printFrameList();

	list.printTree(cout);
	cout << "\nPress 1 to delete all graduates"
		<< "\nPress 2 to save list all graduated students to file"
		<< "\nPress 3 to save to file and delete all graduates"
		<< "\nOther key to back to Menu...";
	int ans; cin >> ans;
	if (ans == 2 || ans == 3) {
		string file;
		cout << "Enter file's name: ";	
		cin.ignore();	 getline(cin, file);
		ofstream fout(file);
		if (!fout)	cout << "Failed to open file!\n";
		else {
			fout << list.n << endl;
			list.printFile(fout);
			cout << "Save successfully!\n";
		}
		fout.close();
	}
	if (ans == 1 || ans == 3) {
		deleteGradList(list.getRoot());
		cout << "Delete successfully!\n";
	}
}

void SchoolClasses::deleteStudentID() {
	cout << "Enter ID: ";
	cin.ignore();
	string id;	getline(cin, id);

	tree.deleteNode(id);
	cout << "Delete successfully!\n";
}

void SchoolClasses::printList() {
	printFrameList();
	tree.printTree(cout);
}

bool SchoolClasses::isEmpty() {
	return tree.getRoot() == nullptr;
}

void SchoolClasses::printList_toFile(string filename) {
	ofstream fout(filename);
	if (!fout) {
		cout << "Failed to open file!\n";
		return;
	}
	fout << tree.n << endl;
	tree.printFile(fout);
	cout << "Save successfully!\n";
}