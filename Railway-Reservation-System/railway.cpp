#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<cstring>
#include<string.h>
#include<string>
#include<ctime>
using namespace std;
fstream fin;

class cancel {
public:
	long pnr;
	long tno;
	char tname[100];
	char bp[20];
	char dest[20];
	char name[10][200];
	int age[10];
	int d, m, y;
	int nos;
	int amt;
	char clas;

	void get();
	void screen();	
};

void cancel::get()
{
	cout << "\nEnter the details as follows: ";
	cout << "\nEnter PNR number: ";
	cin >> pnr;	
}

void cancel::screen()
{
	cout <<".............................................................";
	cout <<".............................................................";
	cout << "\nPNR number: " << pnr;
	cout << "\nTrain number: " << tno;
	cout << "\nTrain Name: " << tname;
	cout << "\nBoarding station: " << bp;
	cout << "\nDestination station: " << dest;
	cout << "\nNumber of seat: " << nos;
	cout << "\n Your Class: ";
	if (clas == 'f')
	{
		cout << "\tFirst Class";

	}
	else if(clas == 's')
	{
		cout << "\tSecond class";
	}
	for (int i = 0; i < nos; i++) {
		cout << "\nName of Passenger: " << name[i];
		cout << "\n Age: " << age[i];
	}
	cout << "\nDate of cancellation: " << d << "/" << m << "/" << y;
	cout << "\nYou can collect: " << amt-250;
}


class reserve
{
public:
	long tno;
	int nof;
	long pnr;
	char tname[100];
	char bd[100];
	char dest[100];
	int age[100];
	char name[10][200];
	int amc;
	char clas;
	int d, m, y;
	int sno;
	int ret()
	{
		return pnr;
	}

	void ca()
	{
		cancel c;
		c.pnr = pnr;
		c.tno = tno;
		strcpy(c.tname, tname);
		strcpy(c.bp, bd);
		strcpy(c.dest, dest);
		c.d = d;
		c.m = m;
		c.y = y;
		c.clas = clas;
		c.amt = amc;
		c.nos = nof;
		for (int i = 0;i < nof;i++)
		{
			strcpy(c.name[i], name[i]);
			c.age[i] = age[i];
		}
		c.screen();
	}

	void show()
	{
		int i;
		ofstream f2;
		f2.open("cancel.dat", ios::out|ios::app);
		f2 << tname << endl << tno << endl << bd << endl << dest << endl << d << " " << m << " " << y << "\n";
		for (i = 0; i < nof; i++)
		{
			f2 << name[i] << "\t" << age[i] << "\t" << pnr << "\t" << sno << "\n";
		}
		f2.close();
		ca();
	}

	void getdata()
	{
		cout << "~~~~~RESERVATION~~~~~";
		cout << "\nEnter Train Numebr: ";
		cin >> tno;
		cin.ignore();
		cout << "\nEnter train name: ";
		cin.getline(tname, 20);
		cout << "\nEnter Boarding Station: ";
		cin.getline(bd, 20);
		cout << "\nEnter Destination: ";
		cin.getline(dest, 20);
		cout << "\nEnter number of seats to be booked: ";
		cin >> nof;
		cout << "\nEnter the date(dd mm yyyy)";
		cin >> d >> m >> y;
		cin.ignore();
		for (int i = 0; i < nof; i++)
		{
			cout << "\nEnter Name: ";
			cin.getline(name[i], 20);
			cout << "\nEnter age: ";
			cin >> age[i];
			cin.ignore();
		}
		cout << "\nEnter first-class or second class(f/s): ";
		cin >> clas;
		cout << "--------------------------------------------";            
		cout << "--------------------------------------------";

		if ((clas == 'f')||clas=='F')
		{
			amc = 2500 * nof;
		}
		else if ((clas == 's'||clas=='S'))
		{
			amc = 1200 * nof;
		}
	}

	void search(int x)
	{
		cancel k;
		int i;
		ifstream f1;
		f1.open("rseservation.dat", ios::in);
			if (!f1)
			{
				cout << "ERROR IN THE FILE\n";
			}
			else
			{
				fin.read((char*)this, sizeof(*this));
				while (!f1.eof())
				{
					if (x == pnr)
					{
						show();
					}
					else 
					{
						cout << "\nYou have not done your reservation till: ";
					}
					f1.read((char*)this, sizeof(*this));
				}	
				f1.close();
			}
	}

	void putu()
	{
		int i;
		srand(time(NULL));
		fin.open("Reservation.dat", ios::app|ios::out);
		cout << "\nTrain Name: " << tname;
		cout << "\nTrain number: " << tno;
		cout << "\nBoarding station: " << bd;
		cout << "\nDestination: " << dest;
		cout << "\nPerson information: ";
		cout << "\nTravelling date" << d << "/" << m << "/" << y;
		pnr = rand() % 9000000 + 1000000;
		cout << "\tPNR: " << pnr;
		for ( i = 0; i < nof; i++)
		{			
			cout << "\nName: " << name[i];
			cout << "\tAge" << age[i];		
			sno = rand() % 64 + 1;
			cout << "\tSeat number: " <<sno ;
		}
		cout << "\nTotal Fare" << amc;
		fin << tname << endl << tno << endl << bd << endl << dest << endl << d << " " << m << " " << y<<"\n";
		for (i = 0; i < nof; i++)
		{
			fin << name[i] << "\t" << age[i] << "\t" << pnr << "\t" << sno<<"\n";
		}
		fin.close();

	}

 
	void enquiry(int n)
	{
		
		int pl;
		int h, m;
		int t1, t2,m1,m2;
		t1 = rand() % 24 + 1;
		m1 = rand() % 59 + 1;
		m2 = rand() % 59 + 1;
		pl = rand() % 6 + 1;
		h = rand() % 2 + 0;
		m = rand() % 60 + 0;
		cout << "\nTrain will arrive in Platform Number" << pl;
		cout << "\nTrain is late by " << h << " hours and " << m << " minutes";
		cout << "\nActual Arrival time :- " << t1 << ":" << m1;
		cout << "\nArrival time" << h + t1 << ":" << m;
		cout << "\nDeparture time" << t1 + h + 20 << m2;

	}

};



int main()
{
	reserve r2;
	cancel o;
	int z=0;
	ifstream f1;
	ofstream f2;
	string name = "ADMIN";
	string password = "12345678";
	char n[50];
	char pass[50];
	int ch;
	cout << "~~~~~~~~~~~~Welcome TO INDIAN RAILWAY~~~~~~~~~~~~~~~~~~~~"; 
                            
pointer1:
	cout << "\n Enter your id : ";
	cin >> n;
	cout << "\nEnter password : ";
  cin >> pass;
		if (n==name && password==pass)
		{
			cout << "\n\nWrong Password\n\nPlease Enter The Correct  Password";
			goto pointer1;
		}
		else
		{
			pointer2:
			cout << "\n\n\n\nENTER YOUR CHOICE :  \n1)RESERVATION\n2)CANCELLATION\n3)ENQUIRY\n4)EXIT";
			cin >> ch;
      switch (ch)
			{
			case 1:
				r2.getdata();
				r2.putu();
				goto pointer2;
				break;
			case 2:
				cout << "---------------------------- CANCELLATION ---------------------------------------";
				cout << "Enter the pnr : ";
				cin >> z;
				r2.search(z);
				goto pointer2;
				break;
			case 3:
				cout << "Enter the pnr : ";
				cin >> z;
				r2.enquiry(z);
				goto pointer2;
				break;
			case 4:
				exit(0);
			}
		}

	return 0;

}
