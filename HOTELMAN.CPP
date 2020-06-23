#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<dos.h>
#include<bits/stdc++.h>
using namespace std;
class hotel
{
private:float room_no;
	char name[30];
	char address[50];
	char phone[50];
	char id_type[50];
	char id_proof[70];
public:void input();
       void inputt();
       void show();
       void showw();
       int check(float);
       void bill(float);
       void food_menu(float);
       int room_status(float);
};
 int hotel::room_status(float r)
{
 if(room_no==r)
  return(1);
 else
  return(0);
}
int hotel::check(float r)
{
hotel h;
int flag=0;
ifstream fin("Record.dat",ios::in);
while(!fin.eof())
{
fin.read((char*)&h,sizeof(hotel));
if(room_no==r)
{
flag=1;
break;
}
}
fin.close();
return(flag);
}
void search(int r)//to display a customer's all records
{
 ifstream f("record.dat",ios::binary);
 if(!f)
  cout<<"\n file not found";
 else
 {
  hotel h;
  int g=0;
  while(f.read((char*)&h,sizeof(h)))
   if(h.room_status(r))
   {
    h.showw();
    g=1;
    break;
   }
   if(g==0)
    cout<<"\n record not found";
 }
 f.close();
}
void hotel::inputt()//input used for modification
{
cout<<"\n    Enter Customer Detalis:-";
cout<<"\n ------------------------------";
cout<<"\n\n Room no: ";
cin>>room_no;
cout<<" Name: ";
fflush(stdin);
gets(name);
cout<<" Id proof: ";
fflush(stdin);
gets(id_proof);
cout<<" Address: ";
fflush(stdin);
gets(address);
cout<<" Phone No: ";
fflush(stdin);
gets(phone);
cout<<"\n Room is booked!!!";
cout<<"\n Press any key to continue...!!";
getch();

}
void hotel::input()//to input customer's details
{
int flag;
float r;
cout<<"\n    Enter Customer Detalis:-";
cout<<"\n ------------------------------";
cout<<"\n\n Room no: ";
cin>>r;
flag=check(r);
if(flag==1)
cout<<"\n Sorry..!!!Room is already booked";
else
{
room_no=r;
cout<<" Name: ";
fflush(stdin);
gets(name);
cout<<" Id type (adhaar card, voter id, passport no., etc.) :";
fflush(stdin);
gets(id_type);
cout<<" Id proof: ";
fflush(stdin);
gets(id_proof);
cout<<" Address: ";
fflush(stdin);
gets(address);
cout<<" Phone No: ";
fflush(stdin);
gets(phone);
cout<<"\n Room is booked!!!";
}
cout<<"\n Press any key to continue...!!";
getch();
}
void hotel::show()
{
 cout<<"\n\n "<<room_no<<"\t\t"<<name<<"\t\t"<<id_proof<<"\t\t"<<address<<"\t"<<phone;
}
void hotel::showw()//to show personal records of a customer
{
 cout<<"\n    customer's record:-";
 cout<<"\n -------------------------";
 cout<<"\n room no..............."<<room_no;
 cout<<"\n id specification......"<<id_type;
 cout<<"\n id proof.............."<<id_proof;
 cout<<"\n name.................."<<name;
 cout<<"\n address..............."<<address;
 cout<<"\n phone no.............."<<phone;
}
void create()//to book rooms
{
 ofstream f("record.dat",ios::binary|ios::app);
 ofstream g("hotel.dat",ios::binary|ios::app);
 if(!f)
  cout<<"\n file creation error";
 else
 {
  hotel h;
  char c;
  do
  {
   h.input();
   {
   f.write((char*)&h,sizeof(h));
   g.write((char*)&h,sizeof(h));
   }
   cout<<"\n do you want any more y/n";
   fflush(stdin);
   c=getchar();
  }while(c=='y'||c=='Y');
 }
 f.close();
}
void display()//display all customer's record
{
//clrscr();
 ifstream f("record.dat",ios::binary);
 if(!f)
  cout<<"\n nobody is currently staying in the hotel....!!!";
 else
 {
  hotel h;
  cout<<"\n\t\t\t    List Of Rooms Allotted";
  cout<<"\n\t\t\t ----------------------------";
  cout<<"\n\n room no\t name\t\tid proof\taddress\t\tphone\n";
  while(f.read((char*)&h,sizeof(h)))
   h.show();
 }
 f.close();
}
void history()
{
//clrscr();
 ifstream f("hotel.dat",ios::binary);
 if(!f)
  cout<<"\n nobody is currently staying in the hotel....!!!";
 else
 {
  hotel h;
  cout<<"\n\t    List Of All The Customer's That Stayed Here";
  cout<<"\n\t -------------------------------------------------";
  cout<<"\n\n room no\t name\t\tid proof\taddress\t\tphone\n";
  while(f.read((char*)&h,sizeof(h)))
   h.show();
 }
 f.close();
}

void modify(float r)//modify a customer's record
{
 ifstream f("record.dat",ios::binary);
 ofstream f1("temp.dat",ios::binary);
 if(!f||!f1)
  cout<<"\n file not found";
 else
 {
  hotel h;
  int g=0;
  while(f.read((char*)&h,sizeof(h)))
  {
   if(h.room_status(r))
   {
    h.inputt();
    g=1;
   }
   f1.write((char*)&h,sizeof(h));
  }
   f.close();
   f1.close();
   if(g==0)
    cout<<"\n record not found can't modify";
   else
   {
    remove("record.dat");
    rename("temp.dat","record.dat");
   }
  }
}
void del(float r)//delete a record
{
 ifstream f("record.dat",ios::binary);
 ofstream f1("temp.dat",ios::binary);
 if(!f||!f1)
  cout<<"\n file not found";
 else
 {
  hotel h;
  int g=0;
  while(f.read((char*)&h,sizeof(h)))
  {
   if(h.room_status(r))
	g=1;
   else
	f1.write((char*)&h,sizeof(h));
  }
   f.close();
   f1.close();
   if(g==0)
    {cout<<"\n record not found can't delete";
    }
   else
   {
    remove("record.dat");
    rename("temp.dat","record.dat");
   }
  }
}
void hotel::food_menu(float r)
{
float payment=0.0;
ifstream f("record.dat",ios::binary);
 if(!f)
  cout<<"\n file not found";
 else
 {
  hotel h;
  int g=0;
  while(f.read((char*)&h,sizeof(h)))
   if(h.room_status(r))
   {
    int opt=0,x=0;
    do
    {
    cout<<"\n enter your choice";
    cout<<"\n 1.breakfast";
    cout<<"\n 2.lunch";
    cout<<"\n 3.dinner";
    cout<<"\n 4.dessert";
    cout<<"\n 5.exit";
    cin>>opt;
    getch();
      switch(opt)
       {
	 case 1:do
		{
		cout<<"\n ******************************";
		cout<<"\n         BREAKFAST MENU        ";
		cout<<"\n ******************************";
		cout<<"\n\n Item\t\tPrice\n";
		cout<<"\n 1.Toast...............60 Rs/slice";
		cout<<"\n 2.Scrambled Egg.......55 Rs/plate";
		cout<<"\n 3.Baked Beans.........45 Rs/plate";
		cout<<"\n 4.Egg Roll............40 Rs/roll";
		cout<<"\n 5.veg pasta...........70 Rs/plate";
		cout<<"\n 6.nonveg pasta........80 Rs/plate";
		cout<<"\n 7.veg burger..........100 Rs/piece";
		cout<<"\n 8.nonveg burger.......120 Rs/piece";
		cout<<"\n 9.exit";
		cout<<"\n.\n.\n.enter you choice.....";
		cin>>x;
		 switch(x)
		  {
		   case 1:payment+=60;
			  break;
		   case 2:payment+=55;
			  break;
		   case 3:payment+=45;
			  break;
		   case 4:payment+=40;
			  break;
		   case 5:payment+=70;
			  break;
		   case 6:payment+=80;
			  break;
		   case 7:payment+=100;
			  break;
		   case 8:payment+=120;
			  break;
		   case 9:cout<<"\n bye bye...........!";
			  break;
		   default:cout<<"\n invalid option";
		  }
		getch();
		}while(x!=9);
		break;
	 case 2:do
		{
		cout<<"\n ********************************";
		cout<<"\n             LUNCH MENU          ";
		cout<<"\n ********************************";
		cout<<"\n\n Item\t\tPrice\n";
		cout<<"\n----Snacks----";
		cout<<"\n 1.French Fries........20 Rs/pack";
		cout<<"\n 2.Chilli Potato.......55 Rs/plate";
		cout<<"\n 3.Garlic Bread........25 Rs/slice";
		cout<<"\n----Soups----";
		cout<<"\n 4.Sapa Cusine Soup................50 Rs/cup";
		cout<<"\n 5.Chicken & Mushroom Soup.........70 Rs/cup";
		cout<<"\n 6.Pumpkin Soup....................80 Rs/cup";
		cout<<"\n----Pizza----";
		cout<<"\n 7.sapa cusine.........170 Rs";
		cout<<"\n(tomato,mozzrella,chicken,mushroom,chilli)";
		cout<<"\n 8.Marinara............150 Rs";
		cout<<"\n(tomato,mozzrella,oregano)";
		cout<<"\n 9.Tropicale...........160 Rs";
		cout<<"\n(tomato,mozzrella,ham,pineappla)";
		cout<<"\n 10.exit";
		cout<<"\n.\n.\n.enter you choice.....";
		cin>>x;
		 switch(x)
		  {
		   case 1:payment+=20;
			  break;
		   case 2:payment+=55;
			  break;
		   case 3:payment+=25;
			  break;
		   case 4:payment+=50;
			  break;
		   case 5:payment+=70;
			  break;
		   case 6:payment+=80;
			  break;
		   case 7:payment+=170;
			  break;
		   case 8:payment+=150;
			  break;
		   case 9:payment+=160;
			  break;
		   case 10:cout<<"\n byebye";
		   default:cout<<"\n invalid option";
		  }
		  getch();
		}while(x!=10);
		break;
	 case 3:do
		{
		cout<<"\n ********************************";
		cout<<"\n           DINNER  MENU          ";
		cout<<"\n ********************************";
		cout<<"\n\n Item\t\tPrice\n";
		cout<<"\n----Salad----";
		cout<<"\n 1.Chicken Salad.................20 Rs/plate";
		cout<<"\n 2.Greek Salad...................35 Rs/plate";
		cout<<"\n 3.Tomato & Cucumber Salad.......50 Rs/plate";
		cout<<"\n----Fried Rice----";
		cout<<"\n 4.Chicken fried rice..............50 Rs/cup";
		cout<<"\n 5.Shrimp fried rice...............70 Rs/cup";
		cout<<"\n 6.Vegetable fried rice............80 Rs/cup";
		cout<<"\n----Pasta----";
		cout<<"\n 7.Bolognese............80 Rs";
		cout<<"\n(tomato, minced meat, sauce)";
		cout<<"\n 8.Carbonara............85 Rs";
		cout<<"\n(bacon, fresh cream, egg )";
		cout<<"\n 9.Gerratin.............90 Rs";
		cout<<"\n(onion, mozzrella, mushroom, cream)";
		cout<<"\n 10.exit";
		cout<<"\n.\n.\n.enter you choice.....";
		cin>>x;
		 switch(x)
		  {
		   case 1:payment+=20;
			  break;
		   case 2:payment+=35;
			  break;
		   case 3:payment+=50;
			  break;
		   case 4:payment+=50;
			  break;
		   case 5:payment+=70;
			  break;
		   case 6:payment+=80;
			  break;
		   case 7:payment+=80;
			  break;
		   case 8:payment+=85;
			  break;
		   case 9:payment+=90;
			  break;
		   case 10:cout<<"\n bye bye";
			   break;
		   default:cout<<"\n invalid option";
		  }
		  getch();
		}while(x!=10);
		break;
	 case 4:do
		{
		cout<<"\n ********************************";
		cout<<"\n           DESSERT MENU          ";
		cout<<"\n ********************************";
		cout<<"\n\n Item\t\tPrice\n";
		cout<<"\n----Milkshakes----";
		cout<<"\n 1.Vanilla Milkshake...........125 Rs";
		cout<<"\n 2.Chocolate Milkshake.........125 Rs";
		cout<<"\n 3.Strawberry Milkshake........130 Rs";
		cout<<"\n 4.Butterscotch Milkshake......150 Rs";
		cout<<"\n 5.Mango Milkshake.............120 Rs";
		cout<<"\n----icecreams and drinks----";
		cout<<"\n 6.Vanilla icecream............35 Rs";
		cout<<"\n 7.Chocolate icecream..........40 Rs";
		cout<<"\n 8.Butterscotch................50 Rs";
		cout<<"\n 9.Coffee......................40 Rs";
		cout<<"\n 10.Mixed fruit juice..........35 Rs";
		cout<<"\n 11. exit";
		cout<<"\n.\n.\n.enter you choice.....";
		cin>>x;
		 switch(x)
		  {
		   case 1:payment+=125;
			  break;
		   case 2:payment+=125;
			  break;
		   case 3:payment+=130;
			  break;
		   case 4:payment+=150;
			  break;
		   case 5:payment+=120;
			  break;
		   case 6:payment+=35;
			  break;
		   case 7:payment+=40;
			  break;
		   case 8:payment+=50;
			  break;
		   case 9:payment+=40;
			  break;
		   case 10:payment+=35;
			   break;
		   case 11:cout<<"\n bye bye";
			   break;
		   default:cout<<"\n invalid option";
		  }
		  getch();
		}while(x!=11);
		break;
	 case 5:cout<<"\n bye bye";
		break;
	 default:cout<<"\n invalid option";
       }
       getch();
    }while(opt!=5);
    cout<<"\n*********************************";
    cout<<"\n your food payment = "<<payment;
    cout<<"\n*********************************";
    g=1;
    break;
   }
   if(g==0)
    cout<<"\n record not found";
 }
 f.close();
}
void hotel::bill(float r)
{
int vehicle=0,type_of_room=0,n=0;
double pay=0;
ifstream f("record.dat",ios::binary);
 if(!f)
  cout<<"\n file not found";
 else
 {
  hotel h;
  int g=0;
  while(f.read((char*)&h,sizeof(h)))
   if(h.room_status(r))
   {
    cout<<"\n please enter the no. of days the customer stayed here ->";
    cin>>n;
    cout<<"\n enter mode of convenience: ";
    cout<<"\n 1.public transport...............no parking charges";
    cout<<"\n 2.personal 2 wheeler.............Rs 10/day";
    cout<<"\n 3.personal 4 wheeler.............Rs 20/day";
    cin>>vehicle;
    if(vehicle==1)
     pay=pay+0;
    else if(vehicle==2)
     pay=pay+(10*n);
    else
     pay=pay+(20*n);
    cout<<"\n enter type of room";
    cout<<"\n 1.Non-AC (Single)...............500/per day";
    cout<<"\n 2.Non-AC (Family)...............1000/per day";
    cout<<"\n 3.AC room (Single)..............700/per day";
    cout<<"\n 4.AC room (Family)..............1200/per day";
    cin>>type_of_room;
    if(type_of_room==1)
     pay=pay+(500*n);
    else if(type_of_room==2)
     pay=pay+(1000*n);
    else if(type_of_room==3)
     pay=pay+(700*n);
    else
     pay=pay+(1200*n);
  cout<<"\n********************************";
  cout<<"\n your total amount is = "<<pay;
  cout<<"\n********************************";
    g=1;
    break;
   }
   if(g==0)
    cout<<"\n record not found";
 }
 f.close();
}
int main()
{
hotel h;
int opt=0,x=0;
cout<<"\n\t\t\t****************************";
cout<<"\n\t\t\t* HOTEL MANAGEMENT PROJECT *";
cout<<"\n\t\t\t****************************";
cout<<"\n\n\n\n\t\tMade By:  ";
cout<<"  ->Priyanka Singh";
cout<<"\n\n\n\tPress any key to continue..!!";
getch();
cout<<"\n\t\t\t**************************";
cout<<"\n\t\t\t***hotel specifications***";
cout<<"\n\t\t\t**************************";
cout<<"\n\n\t\tNAME : Hotel Park Hyatt";
cout<<"\n\t\tLocation : 269E Arossim Beach, Cansaulim, Utorda, Goa, 403712";
cout<<"\n\t\tContact no. : 98754483";
cout<<"\n\t\tLandmark : Mother Of God Church";
cout<<"\n\n\n\tPress any key to continue..!!";
getch();
do
  {
    cout<<"\n\t\t    ************************************";
    cout<<"\n\t\t            * CUSTOMER'S MENU *         ";
    cout<<"\n\t\t    ************************************";
    cout<<"\n\n\n\t\t\t1.Book Rooms";
    cout<<"\n\t\t\t2.Display all rooms allotted";
    cout<<"\n\t\t\t3.Display A Customer's Record";
    cout<<"\n\t\t\t4.Modify Record";
    cout<<"\n\t\t\t5.Delete Record";
    cout<<"\n\t\t\t6.Food Corner";
    cout<<"\n\t\t\t7.check out";
    cout<<"\n\t\t\t8.show all the customer's that stayed here in past";
    cout<<"\n\t\t\t9.Exit";
    cout<<"\n\n\t\t\tEnter Your Choice: ";
    cin>>opt;
     switch(opt)
      {
       case 1:create();
	       break;
       case 2:display();
	       break;
       case 3:cout<<"\n enter the room for search";
	      cin>>x;
	      search(x);
	      break;
       case 4:cout<<"\n enter the room no for modify";
	      cin>>x;
	      modify(x);
	      break;
       case 5:cout<<"\n enter the room no for delete";
	      cin>>x;
	      del(x);
	      break;
       case 6:cout<<"\n plz enter the room no of the customer";
	      cin>>x;
	      h.food_menu(x);
	      break;
       case 7:cout<<"\n plz enter the room no of the customer";
	      cin>>x;
	      h.bill(x);
	      del(x);
	      break;
       case 8:history();
	      break;
       case 9:cout<<"\n end of your working session..........!!!!!";
	      break;
       default: cout<<"\n wrong option";
       break;
      }
   getch();
  }while(opt!=9);
  return 0;
}




