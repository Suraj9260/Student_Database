#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
class stu{  int roll,nroll;
	     char name[25];
	     int c,eng,math;
	     public:
	     void get()
	     {
	     cout<<"ENTER ROLL:";
	     cin>>roll;
	     cout<<"ENTER NAME:";
	     gets(name);
	     cout<<"ENTER SCORE IN COMPUTER SCIENCE:";
	     cin>>c;
	     cout<<"ENTER SCORE IN ENGLISH:";
	     cin>>eng;
	     cout<<"ENTER SCORE IN MATHS:";
	     cin>>math;
	     }
//===========================================================================
	     void put()
	     {
	     cout<<"|---------------------------------------------|"<<endl;
	     cout<<"| STUDENT ROLL NO.:"<<roll<<endl;
	     cout<<"| STUDENT NAME:"<<name<<endl;
	     cout<<"| STUDENT SCORE IN C.s:"<<c<<endl;
	     cout<<"| STUDENT SCORE IN ENGLISH:"<<eng<<endl;
	     cout<<"| STUDENT SCORE IN MATHS:"<<math<<endl;
	     cout<<"|---------------------------------------------|"<<endl;
	     }
//===========================================================================
	     int getroll()
	     {
	     return roll;
	     }
//===========================================================================
	     int getch()
	     {
	     return c;
	     }
//===========================================================================
	     int geteng()
	     {
	     return eng;
	     }
//===========================================================================
	     int getmath()
	     {
	     return math;
	     }
//===========================================================================
	     void modify()
	     {
	     cout<<"ENTER NEW NAME:";
	     cin>>name;
	     cout<<"ENTER NEW MARKS:"<<endl;
	     cout<<"SCORE IN C.s:";
	     cin>>c;
	     cout<<"SCORE IN ENGLISH:";
	     cin>>eng;
	     cout<<"SCORE IN MATHS:";
	     cin>>math;
	     }
}s1;
//============================END OF CLASS================================
//==========================FOR DELAY=====================================
void ser()
{
   long i;
   int j;
   for(i=0;i<95000;i++)
   {
      j=i;
      if(j/2==0)
      {
	 cout<<"searching........";
	 clrscr();
      }
      else if(j/3==0)
      {
	 cout<<"searching.....";
	 clrscr();
      }
      else
      {
	 cout<<"searching..";
	 clrscr();
      }
   }
}
//***************************INSERT FUNCTION*******************************
void insert()
{    clrscr();

    char ch;int y,Y;
    cout<<"ENTER DATA"<<endl;
    do
    {
    clrscr();
    ofstream fout;
    fout.open("furkan.dat",ios::out|ios::binary|ios::app);
    {
       s1.get();
       fout.write((char*)&s1,sizeof(s1));
       fout.close();
    }
    cout<<"DO YOU WANT TO ENTER MORE RECORD:";
    cin>>ch;
    }while(ch=='y'||ch=='Y');

}
//***********************SEARCH FUNCTION************************
void search()
{   clrscr();
    int roll=0,flag=0;
    cout<<"               SEARCH RESULT"<<endl;
    ifstream fin("furkan.dat",ios::in);
    cout<<"ENTER ROLL TO BE SEARCHED:";
    cin>>roll;
    ser();
    while(fin)
    {
       fin.read((char*)&s1,sizeof(s1));
       if(s1.getroll()==roll)
       {
	 s1.put();
	 flag=1;
	 break;
       }
    }
    fin.close();
       if(flag==0)
       {
	  cout<<"ROLL NO. NOT FOUND......"<<endl;
       }

}
//**********************DELETE FUNCTION***********************
void removal()
{    clrscr();
     cout<<           "DELETE STUDENT RESULT"<<endl;
     int x;
    int roll=0,flag=0;
    ifstream fi;
    ofstream fo;
    fi.open("furkan.dat",ios::in);
    fo.open("new.dat",ios::out);
    cout<<"ENTER ROLL TO BE DELETED:";
    cin>>roll;
    while(fi)
    {
       fi.read((char*)&s1,sizeof(s1));
       if(s1.getroll()==roll)
       {
	 s1.put();
	 cout<<"hjjll";
	 flag=1;
	 continue;
       }
       fo.write((char*)&s1,sizeof(s1));
    }
       if(flag==0)
       {
	  cout<<"ROLL NO. NOT FOUND......"<<endl;
       }
       fi.close();
       fo.close();
       remove("furkan.dat");
       rename("new.dat","furkan.dat");
}
//***************MODIFY************************
void mod()
{
     clrscr();
     int asd,flag=0;
     cout<<"              MODIFY STUDENT DATA"<<endl;
     cout<<"ENTER ROLL OF STUDENT:";
     cin>>asd;
     fstream fin;
     fin.open("furkan.dat",ios::in|ios::out|ios::binary);
     ser();
     while(fin)
     {
	  fin.read((char*)&s1,sizeof(s1));
	  if(asd==s1.getroll())
	  {
	    s1.put();
	    s1.modify();
	    fin.seekp(fin.tellp()-sizeof(s1),ios::beg);
	    fin.write((char*)&s1,sizeof(s1));
	    flag=9;
	    break;
	   }
      }
      if(flag==0)
      {
	 cout<<"RECORD NOT EXIST..."<<endl;
      }
     fin.close();
}
//*********************display*********************
void display()
{
    clrscr();
    ifstream fin;
    fin.open("furkan.dat",ios::in|ios::binary);
       while(fin)
       {

	 fin.read((char*)&s1,sizeof(s1));
	 if(fin.eof())
	     break;
	     s1.put();
       }
    fin.close();
    getch();
}
//**************************clear****************
void clear()
{
remove("furkan.dat");
cout<<"FILE IS CLEAR......."<<endl;
}
//********************generator******************************
void generator()
{
    clrscr();
    int c,math,eng,roll;
    float avg;
    int flag=0;
    ifstream fin("furkan.dat",ios::in);
    cout<<"ENTER ROLL OF STUDENT:";
    cin>>roll;
    ser();
    while(fin)
    {
       fin.read((char*)&s1,sizeof(s1));
       if(s1.getroll()==roll)
       {

	 s1.put();
	 c=s1.getch();
	 math=s1.getmath();
	 eng=s1.geteng();
	 avg=(c+eng+math)/3;
	 cout<<"| STUDENT AVERAGE:"<<avg<<endl;
	 if(eng>33)
	 {
	   cout<<"| STUDENT PASS IN ENGLISH"<<endl;
	 }
	 else
	 {
	   cout<<"| STUDENT FAIL IN ENGLISH"<<endl;
	 }
	 if(c>33)
	 {
	    cout<<"| STUDENT PASS IN C.sc"<<endl;
	 }
	 else
	 {
	    cout<<"| STUDENT FAIL IN C.sc"<<endl;
	 }
	 if(math>33)
	 {
	    cout<<"| STUDENT PASS IN MATH"<<endl;
	 }
	 else
	 {
	    cout<<"| STUDENT FAIL IN MATH"<<endl;
	 }
	 if(avg>33)
	 {
	    cout<<"| STUDENT PASSED CLASS.....congo"<<endl;
	 }
	 else
	 {
	    cout<<"| Sorry.....Student have to reapear"<<endl;
	 }
	 cout<<"|---------------------------------------------|"<<endl;
	 flag=1;
	 break;
       }
    }
       fin.close();
       if(flag==0)
       {
	  cout<<"ROLL NO. NOT FOUND......"<<endl;
       }
}
//==========================================================================
void main()
{
    clrscr();

    int ch;
    char cha;
    do{
    clrscr();
    textcolor(YELLOW);
    textbackground(RED);
    clrscr();
    cout<<"                           STUDENT RESULT MANAGEMENT "<<endl;
    cout<<"|------------------------------------------------------------------------------|";
    cout<<endl;
    cout<<"| 1-ENTER DATA                                                                 |";
    cout<<endl;
    cout<<"| 2-SEARCH RESULT                                                              |";
    cout<<endl;
    cout<<"| 3-DELETION                                                                   |";
    cout<<endl;
    cout<<"| 4-MODIFY DATA                                                                |";
    cout<<endl;
    cout<<"| 5-DISPLAY ALL STUDENT RESULT                                                 |";
    cout<<endl;
    cout<<"| 6-GENERATE RESULT                                                            |";
    cout<<endl;
    cout<<"| 7-CLEAR WHOLE FILE                                                           |";
    cout<<endl;
    cout<<"| 8-EXIT FROM PROGRAM                                                          |";
    cout<<endl;
    cout<<"| CHOOSE FROM ABOVE:                                                           |";
    cout<<endl;
    cout<<"|------------------------------------------------------------------------------|";
    cin>>ch;
       switch(ch)
       {
	   case 1: textbackground(LIGHTCYAN);
		   textcolor(BLACK);
		   clrscr();
		   insert();
	   break;
	   case 2: textbackground(WHITE);
		   textcolor(BLUE);
		   clrscr();
		   search();
	   break;
	   case 3:textbackground(RED);
		   textcolor(YELLOW);
		   clrscr();
		   removal();
	   break;
	   case 4: textbackground(GREEN);
		   textcolor(BLACK);
		   clrscr();
		   mod();
	   break;
	   case 5: textbackground(YELLOW);
		   textcolor(BLACK);
		   clrscr();
		   display();
	   break;
	   case 6: generator();
	   break;
	   case 7: clear();
	   break;
	   case 8: exit(0);
	   default:cout<<"INVALID COMMAND.....";
	   exit(0);
       }
       cout<<"DO YOU WANT TO CONTINUE:";
	   cin>>cha;
	   if(cha=='n'||cha=='N')
		 {
		     exit(0);
		 }
     }
    while(cha=='y'||cha=='Y');

getch();
}
