#include<iostream>
#include<unordered_map>
#include<windows.h>
#include<iomanip>
#include<fstream>
using namespace std;

class trienode {
public:
	string name;
	unordered_map<char, trienode*> map;
	string last_date;
	string next_date;
	string roomno;
	bool eow;
	trienode()
	{
		this->eow = false;
	}
};

class trie {
	trienode* root = new trienode();
	int count = 0;
	int cl = 0;
public:
	void insertnode(trienode* root, string name, string last_date, string next_date, string roomno);
	void insertdetails(string name, string last_date, string next_date, string roomno)
	{
		insertnode(root, name, last_date, next_date, roomno);
	}

	void deletenode(trienode* root, string name);
	void deletedetails(string name)
	{
		deletenode(root, name);
	}

	void displaynode(trienode* root, string name);
	void display(string name)
	{
		displaynode(root, name);
	}

	void displayallnode(trienode* root, int& cl);
	void displayall()
	{
		displayallnode(root, this->cl);
	}
	int getcount()
	{
		return this->count;
	}

};

void mainlogo();
void logo();
void logo2();
bool verifycred(string name, string pass);
void forgotpassword();
void verify();
void changepassword();
void logo3();
void changeusername();
void changeboth();
void aboutauthor();

int main()
{
	mainlogo();
	verify();
	trie root;
	char ch;
	do {
		system("cls");
		logo2();
		cout << " 1.Add a Client" << endl;
		cout << " 2.Delete a Client" << endl;
		cout << " 3.Search a Client" << endl;
		cout << " 4.Display All Clients" << endl;
		cout << " 5.Display count of Clients " << endl;
		cout << " 6.Change Username " << endl;
		cout << " 7.Change Password " << endl;
		cout << " 8.Change Username and Password " << endl;
		cout << " 9.About Author " << endl;
		cout << " 10.Exit" << endl;
		cout << "\n Enter your choice: ";
		int choice;
		cin >> choice;

		if (choice == 1)
		{
			system("cls");
			logo2();
			string name, ldate, ndate, room;
			cout << " Enter Name: ";
			cin >> name;
			cout << " Enter last date: ";
			cin >> ldate;
			cout << " Enter next date: ";
			cin >> ndate;
			cout << " Room number: ";
			cin >> room;
			root.insertdetails(name, ldate, ndate, room);

		}
		else if (choice == 2)
		{
			system("cls");
			logo2();
			string name;
			cout << " Enter Name: ";
			cin >> name;
			root.deletedetails(name);
		}
		else if (choice == 3)
		{
			system("cls");
			logo2();
			string name;
			cout << "Enter Name: " << endl;
			cin >> name;
			root.display(name);

		}
		else if (choice == 4)
		{
			system("cls");
			logo2();
			root.displayall();
		}
		else if (choice == 5)
		{
			system("cls");
			logo2();
			cout << " TOTAL CLIENTS: " << root.getcount();
		}
		else if (choice == 6)
		{
			system("cls");
			logo2();
			changepassword();
		}
		else if (choice == 7)
		{
			system("cls");
			logo2();
			changeusername();
		}
		else if (choice == 8)
		{
			system("cls");
			logo2();
			changeboth();
		}
		else if (choice == 9)
		{
			system("cls");
			aboutauthor();

		}
		else if (choice == 10)
		{
			system("cls");
			logo3();
			cout << "                           THANK YOU. HAVE A NICE DAY!            " << endl;
			return 0;
		}
		else
		{
			cout << " ********* WRONG CHOICE! ***********";
		}


		cout << "\n BACK TO MAIN MENU (Y/N): ";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');

	if (ch != 'y' || ch != 'Y')
	{
		system("cls");
		logo3();
		cout << "                           THANK YOU. HAVE A NICE DAY!            " << endl;

		Sleep(1000);
	}

	return 0;
}

void trie::insertnode(trienode* root, string name, string last_date, string next_date, string roomno)
{

	if (root == NULL)
		root = new trienode();

	trienode* temp = root;

	for (int i = 0;i < name.size();i++)
	{
		char ch = name[i];
		if (temp->map.find(ch) == temp->map.end())
			temp->map[ch] = new trienode();

		temp = temp->map[ch];
	}
	if (temp->eow == 1)
	{
		cout << " ******** CLIENT ALREADY EXISTS *********";
	}
	else
	{
		cout << "\n ************* SUCCESSFULLY ADDED IN DIARY *********";
		temp->eow = true;
		temp->name = name;
		temp->last_date = last_date;
		temp->next_date = next_date;
		temp->roomno = roomno;
		this->count++;
	}
}
void trie::deletenode(trienode* root, string name)
{

	if (this->count == 0)
	{
		cout << "\n ********* THERE ARE NO ENTRIES **********";
		return;
	}

	trienode* temp = root;
	for (int i = 0;i < name.size();i++)
	{
		char ch = name[i];
		if (temp->map.find(ch) == temp->map.end())
		{
			cout << "\n ************ NO SUCH CLIENT EXISTS IN DIARY ************** ";
			return;
		}

		temp = temp->map[ch];
	}

	if (temp->eow == true)
	{
		temp->eow = false;
		temp->name = "";
		temp->last_date = "";
		temp->next_date = "";
		temp->roomno = "";
		this - count--;
		cout << "\n ************** SUCCESSFULLY DELETED ***********";
	}
}
void trie::displaynode(trienode* root, string name)
{
	if (root == NULL)
	{
		cout << "\n Diary is empty";
		return;
	}

	trienode* temp = root;
	for (int i = 0;i < name.size();i++)
	{
		char ch = name[i];
		if (temp->map.find(ch) == temp->map.end())
		{
			cout << "\n ************ NO SUCH CLIENT EXISTS IN DIARY ************** ";
			return;
		}

		temp = temp->map[ch];
	}

	if (temp->eow == true)
	{
		cout << temp->name;
		cout << temp->last_date;
		cout << temp->next_date;
		cout << temp->roomno;
	}
	else
		cout << "\n ************ NO SUCH CLIENT EXISTS IN DIARY ************** ";
}
void trie::displayallnode(trienode* root, int& cl)
{
	if (this->count == 0)
	{
		cout << "\n ********* THERE ARE NO ENTRIES **********";
		return;
	}
	for (auto i = root->map.begin();i != root->map.end();i++)
	{

		if (i->second->eow == true)
		{
			cl++;
			cout << " " << cl << ". CLIENT ->" << i->second->name << endl;
		}

		if (i->second != NULL)
			displayallnode(i->second, cl);
	}
}
void mainlogo()
{
	cout << " ***********************************************************************\n";
	cout << " *                                                                     *\n";
	cout << " *                   *********************************                 *\n";
	cout << " *                     Developed by SURYANSHU DINKAR                   *\n";
	cout << " *                   *********************************                 *\n";
	cout << " *                                                                     *\n";
	cout << " ***********************************************************************\n\n";

	Sleep(1000);
}
void logo2()
{
	cout << " ***********************************************************************\n";
	cout << " *                                                                     *\n";
	cout << " *                                                                     *\n";
	cout << " *                        Lawyer's Diary                               *\n";
	cout << " *                                                                     *\n";
	cout << " *                                                                     *\n";
	cout << " ***********************************************************************\n\n";
}
void verify()
{
	string uname, pass;
	bool check = false;

	do {
		system("cls");
		logo();
		cout << " Enter Username: ";
		cin >> uname;
		cout << " Enter Password: ";
		cin >> pass;
		if (verifycred(uname, pass))
		{
			cout << "\n ************* ACCESS GRANTED ***********\n";
			Sleep(500);
			check = true;
		}
		else
		{
			system("cls");
			logo();
			cout << " Entered Username:";
			cout << uname << endl;
			cout << "\n Entered Password:";
			cout << "*****\n";
			cout << "\n ********* Incorrect credentials *********\n";
			cout << "\n Forgot Password(y/n):";
			char ch;
			cin >> ch;
			if (ch == 'Y' || ch == 'y')
			{
				forgotpassword();
			}
			else
			{

			}

		}
	} while (!check);
}
void logo()
{
	cout << " ***********************************************************************\n";
	cout << " *                                                                     *\n";
	cout << " *                                                                     *\n";
	cout << " *                     WELCOME TO LAWYERS'S DIARY                      *\n";
	cout << " *                                                                     *\n";
	cout << " *                                                                     *\n";
	cout << " ***********************************************************************\n\n";
}
void logo3()
{
	cout << " ***********************************************************************\n";
	cout << " *                                                                     *\n";
	cout << " *                                                                     *\n";
	cout << " *                          LAWYERS'S DIARY                            *\n";
	cout << " *                                                                     *\n";
	cout << " *                                     |DEVELOPED BY SURYANSHU DINKAR| *\n";
	cout << " ***********************************************************************\n\n";
}
bool verifycred(string name, string pass)
{
	fstream file;
	file.open("hii.txt");
	string vername, verpass;
	file >> vername >> verpass;
	file.close();
	if (vername == name && verpass == pass)
		return true;
	else
		return false;
}
void forgotpassword()
{
	system("cls");
	logo();
	fstream file;
	file.open("hii.txt");
	string vername, verpass;
	file >> vername >> verpass;
	file.close();
	cout << "\n Username is: " << vername;
	cout << "\n Password is: " << verpass;
	Sleep(2000);
}
void changepassword()
{
	cout << " Enter current password: ";
	string old;
	cin >> old;
	fstream file;
	file.open("hii.txt");
	string vername, verpass;
	file >> vername >> verpass;
	file.close();
	if (verpass == old)
	{
		cout << " Enter new password: ";
		string npass;
		cin >> npass;
		fstream file;
		file.open("hii.txt", ios::trunc | ios::out | ios::in);
		file << vername << endl << npass;
		file.close();

		cout << " PASSWORD SUCCESSFULLY CHANGED";
	}
	else
	{
		cout << " ********** INCORRECT PASSWORD! *******";
	}
}
void changeusername()
{
	cout << "Enter current password: ";
	string old;
	cin >> old;
	fstream file;
	file.open("hii.txt");
	string vername, verpass;
	file >> vername >> verpass;
	file.close();
	if (verpass == old)
	{
		string nuser, npass;
		cout << " Enter new username:";
		cin >> nuser;
		fstream file;
		file.open("hii.txt", ios::trunc | ios::out | ios::in);
		file << npass << endl << verpass;
		file.close();

		cout << " PASSWORD SUCCESSFULLY CHANGED";
	}
	else
	{
		cout << " ********** INCORRECT PASSWORD! *******";
	}
}
void changeboth() {

	cout << "Enter current password: ";
	string old;
	cin >> old;
	fstream file;
	file.open("hii.txt");
	string vername, verpass;
	file >> vername >> verpass;
	file.close();
	if (verpass == old)
	{
		string nuser, npass;
		cout << " Enter new username:";
		cin >> nuser;
		cout << " Enter new password:";
		cin >> npass;
		fstream file;
		file.open("hii.txt", ios::trunc | ios::out | ios::in);
		file << npass << endl << npass;
		file.close();

		cout << " PASSWORD SUCCESSFULLY CHANGED";
	}
	else
	{
		cout << " ********** INCORRECT PASSWORD! *******";
	}

}
void aboutauthor()
{
	cout << " ***********************************************************************\n";
	cout << " *                                                                     *\n";
	cout << " *                   *********************************                 *\n";
	cout << " *                   | Developed by SURYANSHU DINKAR |                 *\n";
	cout << " *                   *********************************                 *\n";
	cout << " *                                                                     *\n";
	cout << " ***********************************************************************\n\n";

	Sleep(1000);
}
