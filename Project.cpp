#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<string.h>
void Border();
class Person
{       long int cont;
	char Name[15];
	int dd,mm,yy;
	char Qualifications[20];
	char Job[20];
	char XP;
	char Gender;
	char Password[15];
	public:
	void gdata();
	void pdata();
	void alter();
	long int getcont();
	char *getjob();
	char *getname();
	char *getpwd();
};
  void Person::gdata()
 {
	clrscr();
	Border();
	gotoxy(8,10);
	cout<<" Enter your name ";  gotoxy(50,10); cout<<":";
	gotoxy(8,11);
	cout<<" Enter your Date of Birth (DD/MM/YYYY)";  gotoxy(50,11); cout<<":";
	gotoxy(8,12);
	cout<<" Enter the job you are looking for "; gotoxy(50,12); cout<<":";
	gotoxy(8,13);
	cout<<" Enter your Qualifications" ; gotoxy(50,13); cout<<":";
	gotoxy(8,14);
	cout<<" Enter number of years of experience"; gotoxy(50,14); cout<<":";
	gotoxy(8,15);
	cout<<" Enter Gender(M/F/T) "; gotoxy(50,15); cout<<":";
	gotoxy(8,16);
	cout<<" Enter Contact Number";  gotoxy(50,16); cout<<":";
	gotoxy(8,17);
	cout<<" Create your Password "; gotoxy(50,17); cout<<":";
	gotoxy(8,18);
	cout<<" Re enter your Password "; gotoxy(50,18); cout<<":";
	gotoxy(56,10);
	gets(Name);
	gotoxy(56,11);
	cin>>dd;
	gotoxy(58,11);
	cout<<"/";
	cin>>mm;
	gotoxy(61,11);
	cout<<"/";
	cin>>yy;
	gotoxy(56,12);
	gets(Job);
	gotoxy(56,13);
	gets(Qualifications);
	gotoxy(56,14);
	cin>>XP;
	gotoxy(56,15);
	cin>>Gender;
	gotoxy(56,16);
	cin>>cont;
	gotoxy(56,17);
	for(int i=0;;i++)
	{	Password[i]=getch();
		if(Password[i]=='\r')
		{	Password[i]='\0';
			break;
		}
		else if(Password[i]=='\b')
		{	if(i>0)
			{	i=i-2;
				cout<<"\b";
			}
			else
			i--;
		}
		else
			cout<<"*";
	}

	char temp[12];
	gotoxy(56,18);
	for(i=0;;i++)
	{	temp[i]=getch();
		if(temp[i]=='\r')
		{	temp[i]='\0';
			return;
		}
		else if(temp[i]=='\b')
		{	if(i>0)
			{	i=i-2;
				cout<<"\b";
			}
			else
			i--;
		}
		else
		cout<<"*";
	}
	if(strcmpi(Password,temp)==0)
	{	for(int j=0;j<i;j++)
		cout<<"\b";
		cout<<" Password Match Success";
	}
	getch();
 }


  void Person::pdata()
  {
  cout<<"\n "<<Name<<"("<<Gender<<"), "<<Qualifications<<"  Job: "<<Job
      <<"  XP: "<<XP<<" years  DOB: "<<dd<<"/"<<mm<<"/"<<yy<<"  Num: "<<cont;
  }
  void Person::alter()
  {     clrscr();
	Border();
	gotoxy(20,10);
	cout<<" Enter name";gotoxy(45,10); cout<<":\t";
	gets(Name);
	gotoxy(20,11);
	cout<<" Enter job";gotoxy(45,11); cout<<":\t";
	gets(Job);
	gotoxy(20,12);
	cout<<" Enter Qualifications";gotoxy(45,12); cout<<":\t";
	gets(Qualifications);
  }
  long int Person::getcont()
  {	return cont;
  }
  char* Person::getjob()
  {	return Job;
  }
  char* Person::getname()
  {	return Name;
  }
  char* Person::getpwd()
  {	return Password;
  }


void Border()
 {	gotoxy(7,4);
	cout<<"***************************  H I R E C O  *************************** ";
	gotoxy(7,23);
	cout<<"********************************************************************* ";
	gotoxy(5,5);
	return;
 }

			       //Search function

void Search(char rno[])
  {
	clrscr();
	Person per;
	int flag=0;
	fstream fin("MOPA.dat",ios::in|ios::binary);
	if(fin==NULL)
	{	cout<<"\n File does not exist!";
		return;
	}
	while(fin.read((char*)&per,sizeof(Person)))
	{
		if(strcmpi(rno,per.getjob())==0)
		{       clrscr();
			Border();
			cout<<" Resume details are as follows";
			per.pdata();
			flag=1;
			getch();
			break;
		}
	}
	if(flag==0)
	{     Border();
	      gotoxy(25,15);
	      cout<<" This job is not available";
	      getch();
	}
	fin.close();
  }

				//Modify Function

  void Modify(char rno[])
  {
	clrscr();
	Person per;
	int flag=0,rec=0;
	fstream fin("MOPA.DAT",ios::in|ios::out|ios::binary);
	if(fin==NULL)
	{	cout<<"\n file does not exist";
		return;
	}
	while(fin.read((char*)&per,sizeof(Person)))
	{
		rec++;
		if(strcmpi(rno,per.getname())==0)
		{
			cout<<" Resume details are as follows:";
			per.pdata();
			cout<<" Enter the new details:";
			per.alter();
			fin.seekg((rec-1)*sizeof(Person),ios::beg);
			fin.write((char*)&per,sizeof(Person));
			flag=1;
			break;
		}
	}
	if(flag==0)
	{       clrscr();
		Border();
		gotoxy(20,20);
		cout<<" Resume does not exist";
	}
	else
	{       clrscr();
		Border();
		gotoxy(20,20);
		cout<<" Resume modified";
	}
	fin.close();
  }

				//Delete Function


  void Delete(char rno[])
  {
	Person per;
	int flag=0;
	fstream fin("MOPA.DAT",ios::in|ios::binary);
	if (fin==NULL)
	{
		clrscr();
		Border();
		cout<<" File does not exist";
		return;
	}
	fstream fout("Temp.dat",ios::out|ios::binary);
	while(fin.read((char*)&per,sizeof(Person)))
	{
		if(strcmpi(rno,per.getname())!=0)
			fout.write((char*)&per,sizeof(Person));
		else
			flag=1;
	}
	if(flag==0)
	{       clrscr();
		Border();
		gotoxy(30,16);
		cout<<" Name does not exist";
	}
	else
	{       clrscr();
		Border();
		gotoxy(30,16);
		cout<<" Resume deleted";
	}
	fin.close();
	fout.close();
	remove("MOPA.DAT");
	rename("Temp.DAT","MOPA.DAT");
  }

				 //Insert Function

  void Insert(Person pr)
  {
	clrscr();
	Person per;
	int p=0,c=1,i,rec;
	fstream fin("MOPA.DAT",ios::in|ios::binary);
	while(fin.read((char*)&per,sizeof(Person)))
	{
		p++;
	if(pr.getcont()<=per.getcont())
		break;
	}
	fin.close();
	if(pr.getcont()>per.getcont())
		p++;
	fin.open("MOPA.DAT",ios::in|ios::binary);
	fstream fout("Temp.dat",ios::out|ios::binary);
	while(c<p)
	{
		fin.read((char*)&per,sizeof(Person));
		fout.write((char*)&per,sizeof(Person));
		c++;
	}
	fout.write((char*)&pr,sizeof(Person));
	while(fin.read((char*)&per,sizeof(Person)))
	{
		fout.write((char*)&per,sizeof(Person));
	}
	fin.close();
	fout.close();
	remove("MOPA.DAT");
	rename("Temp.dat","MOPA.DAT");
  }

  void Display_Personfile()
  {
	Person per;
	fstream fin("MOPA.DAT",ios::in|ios::binary);
	if(fin==NULL)
	{	cout<<"\n file does not exist";
		return;
	}
	clrscr();
	Border();
	cout<<"\n  Details are as follows:\n";
	while(fin.read((char*)&per,sizeof(Person)))
	{	per.pdata();	}
	fin.close();
	getch();
  }


  class Design
  {     public:
	void intro();
	void menu();
	void Login();
	void about();
	void Exit();
  };

  void Design::intro()
  {	clrscr();
	char chars[]={'-','\\','|','/','-','\\','|','/'};
	int i;
	gotoxy(26,13);
	cout<<"W E L C O M E  T O  H I R E C O";
	gotoxy(42,10);
	for(i=0;i<8;++i)
	{	cout<<"\b"<<chars[i];
		delay(300);
	}
	return;
  }

  void Design::Exit()
  {
	clrscr();
	gotoxy(10,4);
	Border();
	char ch;
	gotoxy(23,11);
	cout<<"ARE YOU SURE YOU WANT TO LEAVE ?";
	gotoxy(15,16);
	cout<<"YES I WANT TO LEAVE (Y/y)";
	gotoxy(44,16);
	cout<<"NO TAKE ME BACK (N/n)";
	gotoxy(38,20);
	cin>>ch;
	if((ch=='Y')||(ch=='y'))
		exit(0);
	if((ch=='N')||(ch=='n'))
		menu();
  }



  void Design::menu()
  {
  Person pers;
  Menu:
  int choice,m;
  char job[20];
  do{
	clrscr();
	Border();
	gotoxy(14,10);
	cout<<" 1. Post your resume. Let employers find you!";
	gotoxy(14,11);
	cout<<" 2. Employers, Your next hire is here. Search Jobs";
	gotoxy(14,12);
	cout<<" 3. Login to update your resume";
	gotoxy(14,13);
	cout<<" 4. Display all resumes";
	gotoxy(14,14);
	cout<<" 5. About us";
	gotoxy(14,15);
	cout<<" 6. Exit Hireco";
	gotoxy(23,19);
	cout<<" Enter your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1 :	pers.gdata();
				Insert(pers);
				break;
		case 2 :
				clrscr();
				Border();
				gotoxy(25,10);
				cout<<" Enter Job to be searched :   ";
				gets(job);
				Search(job);
				break;
		case 3:		clrscr();
				gotoxy(30,14);
				Login();
				break;
		case 4:         clrscr();
				Border();
				Display_Personfile();
				break;
		case 5:         about();
				break;
		case 6:         Exit();
		default:	cout<<"Enter a proper choice";
				getch();
				goto Menu;
	}
  }
  while(choice>=1&&choice<=6);
  return;
  }

  void Design::Login()
  {
	Login:
	clrscr();
	gotoxy(10,4);
	Border();
	char tempuname[15];
	char temppswd[15];
	gotoxy(33,10);
	cout<<"LOGIN TO HIRECO";
	gotoxy(25,11);
	cout<<"_______________________________";
	gotoxy(25,16);
	cout<<"_______________________________";
	gotoxy(25,13);
	cout<<"Username";gotoxy(34,13);cout<<":";
	gotoxy(25,15);
	cout<<"Password";gotoxy(34,15);cout<<":";
	gotoxy(40,13);
	gets(tempuname);
	gotoxy(40,15);
	gets(temppswd);
	Person per;
	ifstream fin;
	int flag=0;
	fin.open("MOPA.DAT",ios::in|ios::binary);
	if(!fin)
	{	clrscr();
		Border();
		gotoxy(50,30);
		cout<<"Data file not open!!";
		getch();
		exit(0);
	}
	fin.seekg(0,ios::beg);
	while(fin.read((char*)&per,sizeof(Person)))
	{ 	if(strcmpi(per.getname(),tempuname)==0&&strcmpi(per.getpwd(),temppswd)==0)
		{	flag=1;
			break;
		}
	}
	fin.close();
	int ch;
	if(flag==1)
	{	clrscr();
		Border();
		gotoxy(28,10);
		cout<<"Welcome Back "<<tempuname;
		gotoxy(18,14);
		cout<<"1.Edit resume";
		gotoxy(18,15);
		cout<<"2.Delete resume";
		gotoxy(18,16);
		cout<<"3.Logout";
		gotoxy(23,18);
		cout<<"Enter choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1 :        Modify(tempuname);
					break;
			case 2 :	getch();
					Delete(tempuname);
					break;
			case 3 :        return;
			default:        cout<<"Enter a Proper Choice";
					getch();
					goto Login;
		}
	}
}


  void Design::about()
  {	clrscr();
	Border();
	gotoxy(27,11);
	cout<<"C O D E  D E V E O P E D  B Y";
	gotoxy(24,13);
	cout<<"MOHAMMED IHSAN     |     PAUL JOSHI";
	gotoxy(15,19);
	cout<<"N I R M A L A  M A T H A  C E N T R A L  S C H O O L ";
	getch();
	return;
  }

  Design D;
  void main()
  {     clrscr();
	textcolor(0);
	textbackground(7);
	D.intro();
	D.menu();
	return;
  }













