#include <iostream>
#include<stdio.h>
#include<fstream>
#include<string.h>
#define File "moviedetails.dat"
#define CFile "clientdetails.dat"
#define temp "temp.dat" 
using namespace std;
struct date
{
    int dd,mm,yy;
};
class Movies		//CLASS FOR MOVIE 
{
	int mno;
	char mname[50];
    char mlanguage[20];
    date mDATE;
    char genre[20];                                          
    int rating;
    char p[0];
    char review[100];
    
public:
	void getMovieName(char name[50])
    {
        strcpy(name,mname);
    }
    int getMno()
    {
    	return mno;
	}
	int getRating()
    {
    	return rating;
	}
	void getMovieLang(char lang[20])
    {
        strcpy(lang,mlanguage);
    }
	void getMovieGenre(char gen[20])
    {
        strcpy(gen,genre);
    }
    void getMovieReview(char rev[100])
    {
        strcpy(rev,review);
    }
    void inMovieName()
    {
        cout<<"\nEnter new Movie name:";
		gets(p);
		gets(mname);
	
    }
    void inMno()
    {
    	cout<<"\nEnter new Movie number:";
		cin>>mno;
	}
	void inRating()
    {
    	cout<<"\nEnter new rating:";
		cin>>rating;
	}
	void inMovieLang()
    {
        cout<<"\nEnter new language:";
		gets(p);
		gets(mlanguage);
	
    }
	void inMovieGenre()
    {
        cout<<"\nEnter new genre:";
		gets(p);
		gets(genre);
	
    }
    void inMovieReview()
    {
        cout<<"\nEnter new review:";
		gets(p);
		gets(review);

    }
    void getdata()
    {
        cout<<"\nEnter Movie number:";
        cin>>mno;
		cout<<"Enter movie name:";
		gets(p);			
        gets(mname);
        cout<<"Enter Movie language:";
        gets(mlanguage);
        cout<<"Enter Movie Genre:";
        gets(genre);
        cout<<"Enter rating:";
        cin>>rating;
        cout<<"Enter Movie review:";
        gets(review);
        cout<"  ";
        gets(p);
        
    }
   
    void displaydata()
    {
    	cout<<"\n\n";
        cout<<"Mno:";
        cout<<mno;
		cout<<"\nMovie name:";
        cout<<mname;
        cout<<"\nLanguage:";
        cout<<mlanguage;
        cout<<"\nGenre:";
        cout<<genre;
        cout<<"\nRating:";
        cout<<rating;
        cout<<"\nReview:";
        cout<<review;
        cout<<"\n\n";
        
    }
   

};

class Client 	// CLASS FOR CLIENT
{
	private: 
			int cid;
			char cname[30];
			char cmovie[50]; 
			int cseats;
			float cprice;
			float ctotal;
			char p[0];
	public:
			void getdata1()
    		{
    			
        		cout<<"\nEnter Client ID: ";
        		cin>>cid;
				cout<<"\nEnter Client's Name: ";
				gets(p);
        		gets(cname);
            }
            void getdata2()
            {        
            	int type;
        		cout<<"\nEnter the number of seats: ";
       			cin>>cseats;
        		cout<<"\nEnter the price of the seat:\n\n1.Normal Ticket:- QR.35.00\n2.Premium Ticket:- QR.45.00\n";
        		cin>>type; 
        		incprice(type);
        		/*if(type==1)
				{
				cprice=35.00; 
				}
				else
				{
				cprice=45.00; 
				}*/
        	    CalculateTotal();
    		}
    		void inClientMovie(char movie[])
    		{
    			strcpy(cmovie,movie); 
			}
    		void displaydata()
    		{
    			cout<<"\n\n";
       			cout<<"CLIENT ID:";
        		cout<<cid;
				cout<<"\nClient name: ";
        		cout<<cname;
        		cout<<"\nSeats booked: ";
        		cout<<cseats;
        		cout<<"\nTotal price of booking: ";
        		cout<<ctotal;
    		}
    		void CalculateTotal()
    		{
    			ctotal= ((cseats)*(cprice));
			}
			int getClientID()
			{
				return (cid);
			}
			char getClientName (char name[])
			{
				strcpy(name,cname);
			}
			float getCprice()
			{
				return (cprice); 
			}
			float getCtotal()
			{
				return (ctotal); 
			}
			int getClientSeats()
			{
				return (cseats);
			}
			void inClientID()
			{
				cout<<"\nEnter New Client ID: ";
				cin>>cid; 
			}
			void inClientName( )
			{
				cout<<"\nEnter new Client Name: ";
				gets(p);
				gets(cname); 
			}
			void inClientSeats()
			{
				cout<<"\nEnter New Seats:-";
				cin>>cseats;
			}
			void incprice(int newtype)
			{
				if(newtype==1)
				{
				cout<<"Normal Ticket:- QR.35.00";
				cprice=35.00; 
				}
				else
				{
				cout<<"Premiun Ticket:- QR.45.00";
				cprice=45.00; 
				}
			}
			float getTotalPrice()
			{
				return(ctotal); 
			}


};

void searchMovies(char a[])		//Function to search for a movie 
{
    Movies M1; 
	int count=0;
    char checkname[50];
    ifstream fmovies;
    fmovies.open(File,ios::binary);
    while(fmovies.read((char*)&M1,sizeof(Movies)))
    {        
                M1.getMovieName(checkname);
            
				if(strcmpi(checkname,a)==0)
                {
                	count++;
                	M1.displaydata();
				}
							
    }
	if (count==0)	cout<<"THE MOVIE DOES NOT EXIST";
    fmovies.close();
}
void createMovie()	//Function to add and create movies 
{
    Movies M1;
    ofstream fmovies;
    fmovies.open(File,ios::binary|ios::app);
    M1.getdata();
    fmovies.write((char*)&M1,sizeof(Movies));
    fmovies.close();
}
void editClientBooking(int b)
{ 
	Client C1;
	Movies M1; 
  	int cho,cho2;
	int id;
	fstream fclient;
	fstream fmovies; 
	fmovies.open(File,ios::in|ios::out|ios::binary); 
	fclient.open(CFile,ios::in| ios::out|ios::binary);
	if(!fclient)
	{
		cout<<"File not Found";
	}
	else
	{
	   while(fclient.read((char*)&C1, sizeof(Client)))
	  {
		 id=C1.getClientID();
		 if(id==b)
		   {
			
				cout<<"\n\nEDIT:\n1. Client ID\n2. Client Name\n3. Seats\n\n";
				cout<<"ENTER YOUR OPTION:";
				cin>>cho2;
				switch(cho2)
				{
					case 1:
						{
							int x,y;
							cout<<"\n\nPrevious Client ID:"<<C1.getClientID();
							C1.inClientID();
							x=C1.getClientID();
							y=fclient.tellg();
							fclient.seekp(-sizeof(C1),ios::cur);
						    fclient.write((char*)&x,sizeof(x));
						    break;
						}
					case 2:
						{
							int y,z;
							char x[50];
							C1.getClientName(x);
							cout<<"\n\nPrevious Client name:"<<x;
							C1.inClientName();
							C1.getClientName(x);
							fclient.seekp(-sizeof(C1)+(sizeof(C1.getClientID())),ios::cur);
							fclient.write((char*)&x,sizeof(x));
						    break;
						}
					case 3:
						{
						    int y,z;
						    y=C1.getClientSeats();
						    cout<<"Previous number of seats:"<<y;
						    cout<<"\nRemoving all booked seats.";
						    char cho[4],name[30];
						    int s;
						    float t;
						    do
                              {
	                             C1.getdata2();
	                             cout<<"\n\nTotal Ticket Cost = QR "<<C1.getTotalPrice();
	                             cout<<"\n\nProceed to payment?";
	                             cin>>cho;
                              }while(strcmpi(cho,"no")==0);
                            cout<<"Booking Complete";
                            s=C1.getClientSeats();
                            t=C1.getCtotal();
						    fclient.seekp(-sizeof(C1)+(sizeof(C1.getClientID())+C1.getClientName(name)),ios::cur);
							fclient.write((char*)&s,sizeof(s));
							fclient.write((char*)&t,sizeof(t));
						    break;
						}
				
				
				}
				break;
		 	  } 
			
		 	
		}
    }
  fclient.close();
	
}
void editMovies(char b[])   //Editing record function (full data edit & particular data member edit) 
{ 
  	Movies M1;
  	int cho,cho2;
	char check[40];
	fstream fil;
	fil.open(File,ios::in| ios::out|ios::binary);
	 if(!fil)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{
	   
	   while(fil.read((char*)&M1, sizeof(M1)))
	  {
		
		 M1.getMovieName(check);
		 if(strcmpi(check,b)==0)
		   {
				cout<<"\n\n1. Edit specific movie detail\n2. Edit entire movie";
			    cout<<"\nENTER YOUR OPTION: ";
			    cin>>cho;
			    if(cho==1)
			   {
				cout<<"\n\nEDIT:\n1. Movie Number\n2. Movie Name\n3. Language\n4. Genre\n5. Rating\n6. Review\n\n";
				cout<<"ENTER YOUR OPTION:";
				cin>>cho2;
				switch(cho2)
				{
					case 1:
						{
							int x,y;
							cout<<"\n\nPrevious movie number:"<<M1.getMno();
							M1.inMno();
							x=M1.getMno();
							fil.seekp(-sizeof(M1),ios::cur);
						    fil.write((char*)&x,sizeof(x));
						    break;
						}
					case 2:
						{
							int y,z;
							char x[50];
							M1.getMovieName(x);
							cout<<"\n\nPrevious movie name:"<<x;
							M1.inMovieName();
							M1.getMovieName(x);
							fil.seekp(-sizeof(M1)+(sizeof(M1.getMno())),ios::cur);
							z=fil.tellp();
						    fil.write((char*)&x,sizeof(x));
						    break;
						}
					case 3:
						{
							int y,z;
							char x[20];
							M1.getMovieLang(x);
							cout<<"\n\nPrevious language:"<<x;
							M1.inMovieLang();
							M1.getMovieLang(x);
							fil.seekp(-sizeof(M1)+(sizeof(M1.getMno())+50),ios::cur);
						    fil.write((char*)&x,sizeof(x));
						    break;
						}
					case 4:
						{
							int y,z;
							char x[20];
							M1.getMovieGenre(x);
							cout<<"\n\nPrevious Genre:"<<x;
							M1.inMovieGenre();
							M1.getMovieGenre(x);
							fil.seekp(-124,ios::cur);
							fil.write((char*)&x,sizeof(x));
						    break;
						}
					case 5:
						{
							int x,y;
							cout<<"\n\nPrevious rating:"<<M1.getRating();
							M1.inRating();
							x=M1.getRating();
							y=fil.tellg();
							fil.seekp(-104,ios::cur);
						    fil.write((char*)&x,sizeof(x));
						    break;
						}
					case 6:
						{
							int y,z;
							char x[100];
							M1.getMovieReview(x);
							cout<<"\n\nPrevious review:"<<x;
							M1.inMovieReview();
							M1.getMovieReview(x);
							fil.seekp(-100,ios::cur);
							fil.write((char*)&x,sizeof(x));
						    break;
						}
				}
				break;
		 	   } 
			else if(cho==2)
		 	   {
	           	fil.seekg(0,ios::cur);
	           	cout<<"Enter New Record:\n\n";
	        	M1.getdata();
	        	int y;
	        	y=fil.tellg();
	         	fil.seekp(y - sizeof(M1));
	        	fil.write((char*)&M1, sizeof(M1));
	        	break;
	            	
	           } 
		 	break;
		    }
       }
     }
	fil.close();
	
}


void deleteClient(int b) //function to delete client 
{
	Client C;
	int check;
	ifstream fin(CFile,ios::binary);
	ofstream fout(temp,ios::binary);
	while(fin.read((char*)&C,sizeof(C)))
	{
		check=C.getClientID();
		if(check!=b)
		 {
		 	fout.write((char*)&C,sizeof(C));
		 }
	}
	fin.close();
	fout.close();
	remove(CFile);
	rename(temp,CFile);
	cout<<"Client Deleted.";
}
void displayClients()		//function to display the clients 
{
	Client C1;
	fstream fclient;
	fclient.open(CFile,ios::binary|ios::in);
	char name[100]; int id; 
	while(fclient.read((char*)&C1,sizeof(Client)))
	{
			C1.getClientName (name);
			id=C1.getClientID();
			
			cout<<"\n"<<id<<"  "<<name; 
	}
	fclient.close(); 
}
void deleteMovies(char b[]) //delete function
{
	Movies M;
	char check[40];
	ifstream fin(File,ios::binary);
	ofstream fout(temp,ios::binary);
	while(fin.read((char*)&M,sizeof(M)))
	{
		M.getMovieName(check);
		if(strcmpi(check,b)!=0)
		 {
		 	fout.write((char*)&M,sizeof(M));
		 }
	}
	fin.close();
	fout.close();
	remove(File);
	rename(temp,File);
}
void displayMovieName()	//display function to display movie name
{
    Movies M1;
    char x[50];
    int i=1;
    ifstream fmovies;
    fmovies.open(File,ios::binary);
    if(!fmovies)
	{
		cout<<"\n\nFile not Found";
	}
	else
	{
	
       while(fmovies.read((char*)&M1,sizeof(Movies)))
       {
            M1.getMovieName(x);
            cout<<"\n"<<i<<". "<<x;
            i++;
       }
   }
   

    fmovies.close();
}
void displayMovies()	//displaying movies function
{
    Movies M1;
    ifstream fmovies;
    fmovies.open(File,ios::binary);
    if(!fmovies)
	{
		cout<<"\n\nFile not Found";
	}
	else
	{
	
       while(fmovies.read((char*)&M1,sizeof(Movies)))
       {
            M1.displaydata();
       }
   }
   

    fmovies.close();
}



void Booking()	//function to making a booking for a client 
{
	Movies M1;
	Client C1;
	fstream fclient;
	fstream fmovies; 
	fclient.open(CFile,ios::binary|ios::app);
	C1.getdata1(); 
	fmovies.open(File,ios::in| ios::out|ios::binary);
	char p[50],c[0],cho[4];
	int ID;
	cout<<"\n\n Select a movie:";
    displayMovieName();
    cout<<"\n\n ENTER YOUR OPTION (type movie name):";
    //gets(c);
    gets(p);
    C1.inClientMovie(p); 
    do
    {
	   C1.getdata2();
	   cout<<"\n\nTotal Ticket Cost = QR "<<C1.getTotalPrice();
	   cout<<"\n\nProceed to payment?";
	   cin>>cho;
    }while(strcmpi(cho,"no")==0);
    fclient.write((char*)&C1,sizeof(Client));
    cout<<"Booking Complete";
}
void mainscreen() //function to display menu during runtime
{
    int opp,n,mc,ID;
	char b[20],c[2],d[4];
    cout<<"***************************Welcome to AA CINEMA***************************\n";
    cout<<"                             Welcome staff!\n";
    cout<<"1. MOVIE HANDLING 				          2.CLIENT BOOKING 			 \n";
    cout<<"\nENTER YOUR OPTION:";
    cin>>mc;
    switch(mc)
    {case 1: 
    		{
    			cout<<"\n\n--------------------WELCOME TO THE STAFF PORTAL-----------------------";
    			cout<<"\n\n1. Enter Movies\n2. Search for a Movie\n3. Edit a Movie\n4. Create New Movie\n5. Delete a Movie\n6. Displaying All movies\n7. Displaying All Clients\n8. Editing a Client\n";
    			cout<<"\nENTER YOUR OPTION:";
   	 			cin>>opp;
    			switch  (opp)
   				{
    				case 1:
        				{
						cout<<"\n\n------------------------------ENTERING MOVIES------------------------------";
        				cout<<"\nEnter the number of movies";
        				cin>>n;
        				for (int i=0;i<n;i++)
        				{
            				cout<<"\nEnter Details of the movie "<<(1+i);
            				createMovie();
        				}
        				cout<<"\n\nYOU HAVE CREATED FINIDHED ENTERING THE MOVIES";
       					break;
        				}
    				case 2:
       					{		
						cout<<"\n\n-------------------------SEARCHING FOR A MOVIE-------------------------";
        				do
						{
        					cout<<"\nEnter the movie name";
        				    gets(c);
       					    gets(b);
        				    searchMovies(b);
        				    cout<<"\n\nDo you want to search another movie?(yes/no)";
        				    cin>>d;
						}while(strcmpi(d,"yes")==0);
        				break;
        			}
    				case 3:
        			{		
						cout<<"\n\n----------------------------EDITING A MOVIE----------------------------";
						do
						{
						   cout<<"\nEnter the movie name:";
						   gets(c);
						   gets(b);
						   editMovies(b);
						   cout<<"\n\nDo you want to edit another movie?(yes/no)";
        				   cin>>d;
						}while(strcmpi(d,"yes")==0);
        				break;
        			}
    				case 4:
       				{
	    				cout<<"\n\n-------------------------ADDING A NEW MOVIE-------------------------";
        				do
						{
        					createMovie();
        					cout<<"\n\nDo you want to create another movie?(yes/no)";
        				    cin>>d;
						}while(strcmpi(d,"yes")==0);
        				break;
      				}
    				case 5:
    				{
    					cout<<"\n\n----------------------------DELETING MOVIES----------------------------";
    					do
						{
						    cout<<"\nEnter a movie name:";
    					    gets(c);
						    gets(b);
						    deleteMovies(b);
						    cout<<"\n\nDo you want to delete another movie?(yes/no)";
        				    cin>>d;
						}while(strcmpi(d,"yes")==0);
						break;
					}
    				case 6:
    				{
    					cout<<"\n\n-------------------------DISPLAYING ALL MOVIES-------------------------";
    					displayMovies();
    					break;
					}   
					case 7:
    				{
    					cout<<"\n\n-------------------------DISPLAYING ALL CLIENTS-------------------------";
    					displayClients();
    					break;
					}   
					case 8:
    				{
    					cout<<"\n\n----------------------------EDITING A BOOKING----------------------------";
    					cout<<"\nEnter Client ID:";
    					cin>>ID;
    					editClientBooking(ID);
    					break;
					}
    			}
    			break;
			}
		case 2: 
			{
				int p;
				cout<<"\n\n--------------------WELCOME TO THE CLIENT PORTAL-----------------------";
				cout<<"\n\n1. Make a booking\n2. Delete a booking\n3. Edit a booking\n";
				cout<<"\nENTER YOUR OPTION:";
   	 			cin>>opp;
    			switch  (opp)
    			{
    				case 1:
    				{
    					cout<<"\n\n----------------------------MAKING A BOOKING----------------------------";
    					Booking();
    					break;
    				}
    				case 2:
    				{
    					cout<<"\n\n----------------------------DELETING A BOOKING----------------------------";
    					cout<<"\nEnter Client ID:";
    					cin>>ID;
    					deleteClient(ID);
    					break;
					}
					case 3:
    				{
    					cout<<"\n\n----------------------------EDITING A BOOKING----------------------------";
    					cout<<"\nEnter Client ID:";
    					cin>>ID;
    					editClientBooking(ID);
    					break;
					}
				}
				
				break;
			}
	}
    
}

int main()
{
	char cont[4];	
    do
	{    	
	mainscreen();
	cout<<"\n\nDo you want to do back to the main menu?(yes/no) ";
	cin>>cont;
	cout<<"\n\n";
	}while( strcmpi(cont,"yes")==0);
	cout<<"\n\n\n\n\n\n THANKYOU FOR VISITING OUR SITE";

    return 0;
}
