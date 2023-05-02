#include <iostream>
#include<fstream>
#include<string>
#include<string.h>
using namespace std;

void display_all()
{
	fstream pet_schedule;

	pet_schedule.open("petscheduale.txt", ios::in);

	char name[25];
	char type[25];
	char d_ob[15];
	char treatment[35];
	char d_ot[15];
	char d_out[15];
	char a[25];
	cout << "\n name \t\t type \t\t date of birth \t\t treatments \t\t date of treatment \t\t date of upcoming treatment \t\t\n";

	while (!pet_schedule.eof())
	{
		pet_schedule.getline(name, 25, '|');
		pet_schedule.getline(type, 25, '|');

		pet_schedule.getline(d_ob, 15, '|');
		pet_schedule.getline(treatment, 35, '|');

		pet_schedule.getline(d_ot, 15, '|');
		pet_schedule.getline(d_out, 15);
		cout << name << " \t\t " << type << " \t\t " << d_ob << " \t\t " << treatment << " \t\t " << d_ot << " \t\t " << d_out << " \t\t\n ";
		break;
	}

}

void search()
{
	fstream pet_schedule;

	pet_schedule.open("petscheduale.txt", ios::in);

	char name[25];
	char type[25];
	char d_ob[15];
	char treatment[35];
	char d_ot[15];
	char d_out[15];
	char a[25];
	int x = 0;

	cout << "\n\t enter the upcoming of the pet you want to search for \n";
	cin.ignore();
	cin.getline(a, 25);

	cout << "\n name \t\t type \t\t date of birth \t\t treatments \t\t date of treatment \t\t date of upcoming treatment \t\t\n";

	while (!pet_schedule.eof())
	{
		pet_schedule.getline(name, 25, '|');
		pet_schedule.getline(type, 25, '|');

		pet_schedule.getline(d_ob, 15, '|');
		pet_schedule.getline(treatment, 35, '|');

		pet_schedule.getline(d_ot, 15, '|');
		pet_schedule.getline(d_out, 15);
		if (strcmp(name, a)==0)
		{
			cout << name << " \t\t " << type << " \t\t " << d_ob << " \t\t " << treatment << " \t\t " << d_ot << " \t\t " << d_out << " \t\t\n ";
			x = 1;
			break;
		}
	}
	if (x == 0)
	{
		cout << "\n **** not found **** \n";
	}
	pet_schedule.close();
}



void delete_info()
{
	fstream pet_schedule;
	fstream temp;

	pet_schedule.open("petscheduale.txt", ios::in);
	temp.open("temp.txt", ios::out);

	char name[25];
	char type[25];
	char d_ob[15];
	char treatment[35];
	char d_ot[15];
	char d_out[15];
	char n[25];

	cin.ignore();
	cout << "\n enter the name of the pet that you want to delete its information \n ";
	cin.getline(n, 25);


	while (!pet_schedule.eof())
	{
		pet_schedule.getline(name, 25, '|');
		pet_schedule.getline(type, 25, '|');

		pet_schedule.getline(d_ob, 15, '|');
		pet_schedule.getline(treatment, 35, '|');

		pet_schedule.getline(d_ot, 15, '|');
		pet_schedule.getline(d_out, 15);

		if (strcmp(name,n)== 0)
		{
			continue;
		}
		else
		{
			temp << name << '|' << type << '|' << d_ob << '|' << treatment << '|' << d_ot << '|' << d_out << '\n';
		}

	}

	pet_schedule.close();
	temp.close();

	pet_schedule.open("petscheduale.txt", ios::out);
	temp.open("temp.txt", ios::in);

	while (!temp.eof())
	{
		temp.getline(name, 25, '|');
		temp.getline(type, 25, '|');
		temp.getline(d_ob, 15, '|');
		temp.getline(treatment, 35, '|');
		temp.getline(d_ot, 15, '|');
		temp.getline(d_out, 15);

		pet_schedule << name << '|' << type << '|' << d_ob << '|' << treatment << '|' << d_ot << '|' << d_out <<'\n';

	}
	pet_schedule.close();
	temp.close();
	remove("temp.txt");
	cout << "\n your data has been updated \n";
}

bool login()
{
	string usernamesaved = "emanhamdi";
	string passwordsaved = "1234";
	string username;
	string password;
	int logintrials = 0;
	while (logintrials < 3)
	{
		cout << "to use this program you have to login\nenter your username\n";
		cin >> username;
		cout << "enter your password\n";
		cin >> password;

		if (username == usernamesaved && password == passwordsaved)
		{
			break;
		}
		else
		{
			cout << "try again\n";
			logintrials++;
		}
	}
	if (logintrials == 3)
	{
		return false;
	}
	else
	{
		return true;
	}

}
void insert_pet()
{
	char name[25];
	char type[25];
	char d_ob[15];
	char treatment[35];
	char d_ot[15];
	char d_out[15];

	fstream petscheduale;
	petscheduale.open("petscheduale.txt", ios::app);

	cin.ignore();
	cout << "please enter the name of your pet \n";
	cin.getline(name, 25);
	cout << "please enter the type of your pet \n";
	cin.getline(type, 25);
	cout << "please enter the date of birth of your pet \n";
	cin.getline(d_ob, 15);
	petscheduale << name << '|' << type << '|' << d_ob << '|';

	cout << " please enter every treatment the pet has taken \n ";
	bool another_treat;
	while (another_treat = true)
	{


		cout << "  to add treatment press 1 \n  to save your treatments press 2 \n";
		char no;
		cin >> no;
		if (no == '1')
		{
			another_treat = true;
			cin.ignore();
			cout << "  enter the treatment \n";
			cin.getline(treatment, 35);
			cout << "  enter the date of the treatment \n ";
			cin.getline(d_ot, 15);


		}
		else if(no == '2')
		{
			cout << "\n treatments have been saved \n \n ************************** \n";
			break;
		}
		
		petscheduale << treatment << '|' << d_ot << '|';

	}
	cout << "please enter the date of upcoming treatment of your pet \n";
	cin.ignore();
	cin.getline( d_out,15);

	petscheduale << d_out << "\n";

	cout << "\n DONE ! \n";
}


/*void add_a_new_pet()
{
	string name;
	string type;
	string date_of_birth;
	char treat_date[3][2];
	char upcoming_treat_date[30];
	fstream petscheduale;
	petscheduale.open("petscheduale.txt", ios::app);
	cin.ignore();
	cout << "enter the new pet name\n";
	getline(cin, name);
	cout << "enter the new pet type\n";
	getline(cin, type);
	cout << "enter the new pet date of birth\n";
	getline(cin, date_of_birth);
	cout << "enter every treatment it takes and the date of each treatment\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> treat_date[i][j];
		}

	}
	cout << "enter upcoming treatment date\n";
	cin.getline(upcoming_treat_date, 30);

	petscheduale << name << '|' << type << '|' << date_of_birth << '|' << treat_date << '|' << upcoming_treat_date << "\n";
	petscheduale.close();

}*/
/*void search()
{
	fstream petscheduale;
	petscheduale.open("newpet.txt", ios::in);
	string name;
	string type;
	string date_of_birth;
	char upcoming_treat_date[30];
	char search[30];
	cout << "enter what you want to search with\n";
	cin.ignore();
	cin.getline(search, 30);
	cout << "\tname\ttype\tdate of birth\tupcoming treatment date\n";
	int f = 0;
	while (!petscheduale.eof())
	{
		getline(petscheduale, name, '|');
		getline(petscheduale, type, '|');
		getline(petscheduale, date_of_birth, '|');
		petscheduale.getline(upcoming_treat_date, 30);
		if (strcmp(upcoming_treat_date, search) == 0)
		{
			cout << "\t" << name << "\t" << type << "\t" << date_of_birth << "\t" << upcoming_treat_date << "\n";
			f = 1;
			break;
		}
	}
	if (f == 0)
	{
		cout << "wrong input\n";
	}

	cout << f;
}*/

void update_info()
{
	fstream petscheduale;
	fstream temp;

	petscheduale.open("petscheduale.txt", ios::in);
	temp.open("temp.txt", ios::out);

	char name[25];      
	char type[25];     
	char d_ob[15];   
	char treatment[35]; 
	char d_ot[15];    
	char d_out[15];
	char n[25];

	cin.ignore();
	cout << "\n enter the name of the pet that you want to change its information \n ";
	cin.getline(n, 25);


	while (!petscheduale.eof())
	{
		petscheduale.getline(name, 25, '|');
		petscheduale.getline(type, 25, '|');

		petscheduale.getline(d_ob, 15, '|');
		petscheduale.getline(treatment, 35, '|');

		petscheduale.getline(d_ot, 15, '|');
		petscheduale.getline(d_out, 15);

		if (strcmp(name, n) == 0)
		{
			cin.ignore();
			cout << "please enter the new name of your pet \n";
			cin.getline(name, 25);
			cout << "please enter the new type of your pet \n";
			cin.getline(type, 25);
			cout << "please enter the new date of birth of your pet \n";
			cin.getline(d_ob, 15);
			cout << "please enter the new treatments of your pet \n";
			cin.getline(treatment, 35);
			cout << "please enter the date of the new treatment \n";
			cin.getline(d_ot, 15);
			cout << "please enter the date of the upcoming treatment \n";
			cin.getline(d_out, 15);

            temp << name << '|' << type << '|' << d_ob << '|' << treatment << '|' << d_ot << '|' << d_out ;
		}
		else
		{
			temp << name << '|' << type << '|' << d_ob << '|' << treatment << '|' << d_ot << '|' << d_out ;

		}
			
	}
	
	petscheduale.close();
	temp.close();

	petscheduale.open("petscheduale.txt", ios::out);
	temp.open("temp.txt", ios::in);

	while (!temp.eof())
	{
		temp.getline(name, 25, '|');
		temp.getline(type, 25, '|');
		temp.getline(d_ob, 15, '|');
		temp.getline(treatment, 35, '|');
		temp.getline(d_ot, 15, '|');
		temp.getline(d_out, 15);

		petscheduale << name << '|' << type << '|' << d_ob << '|' << treatment << '|' << d_ot << '|' << d_out ;

	}
	petscheduale.close();
	temp.close();
	remove("temp.txt");
	cout << "\n your data has been updated \n";
}



int main()
{
	bool status = login();
	if (!status)
	{
		cout << "\n invaild login\n";
		return 0;
	}
	else
	{
		cout << "\n you are logged in \n\n";
	}

	bool flag=true;
	while (flag)
	{
		cout << " insert a new pet : 1 \n search : 2 \n display all : 3 \n update : 4 \n delete : 5 \n";
		int c;
		cin >> c;
		switch (c)
		{
		case 1:
			insert_pet();
			break;
		case 2:
			search();
			break;
		case 3:
			display_all();
			break;
		case 4:
			update_info();
			break;
		case 5:
			delete_info();
			break;
		default:
			cout << "****** please enter a valid choice ****** \n";
			break;
		}

			cout << "\n\t\t if you want to continue the program press 1 \t\t\n\n\t\t if you want to close the program press 2 \n";
			char f;
			cin >> f;
			if (f == '1')
			{
				flag = true;
			}
			else if (f == '2')
			{
				flag = false;
			}
			else
			{
				cout << "\n ****** please enter a valid choice ****** \n ";
			}
		
	}
}