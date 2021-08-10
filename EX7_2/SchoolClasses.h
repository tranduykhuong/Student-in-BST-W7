#include"BST.h"
#include"LinkList.h"
#include<string>
#include<fstream>

class SchoolClasses {
	BST tree;
	LinkList sortList;

	void deleteGradList(BST::Node*);
	void copytoLinkList(BST::Node*);
public:
	void LoadData(string);
	void AddStudents();
	void ListNameLexi();
	void FindStudnet_andUpdate();
	void GraduatedList();
	void deleteStudentID();
	void printFrameList();
	void printList();
	void printList_toFile(string);
	bool isEmpty();
};