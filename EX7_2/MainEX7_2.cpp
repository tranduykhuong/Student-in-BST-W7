#include"SchoolClasses.h"
#include"programFrame.h"

int main()
{
	int ans;
	string file;
	while (1) {
		SchoolClasses cla;
		MenuFile();
		inputSelect(ans, 1, 3);
		if (ans == 3)	return 0;
		inputFilename(ans, file);
		cla.LoadData(file);
		if (cla.isEmpty())	continue;

		while (1) {
			MenuProcess();
			inputSelect(ans, 0, 8);
			if (ans == 8)	return 0;
			else if (ans == 7)	break;

			title();
			switch (ans) {
			case 0:
				cla.printList();			 break;
			case 1:
				cla.AddStudents();			 break;
			case 2:
				cla.FindStudnet_andUpdate(); break;
			case 3:
				cla.ListNameLexi();			 break;
			case 4:
				cla.deleteStudentID();		 break;
			case 5:
				cla.GraduatedList();		 break;
			case 6:
				inputFilename(2, file);
				cla.printList_toFile(file);
				break;
			}
			cout << endl;
			system("pause");
		}
	}
}