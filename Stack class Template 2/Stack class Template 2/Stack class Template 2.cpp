// Stack class Template 2.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;
const int LEN = 80;     //maximum numbers of the names

						/////////////////////////////////////////////////////////////////////////////////////////
class employee            //employee class
{
private:
	char name[LEN];          //employee name
	unsigned long number;    // employee number
public:
	friend istream& operator >> (istream& s, employee& e);
	friend ostream& operator << (ostream& s, employee& e);
};
//-----------------------------------------------------------------------------------
istream& operator >> (istream& s, employee& e)
{
	cout << "\n Enter last name:  "; cin >> e.name;
	cout << "Enter number:  ";   cin >> e.number;
	return s;
}
//--------------------------------------------------------------------------------------
ostream& operator << (ostream& s, employee& e)
{
	cout << "\n Name: " << e.name;
	cout << " \n Number: " << e.number;
	return s;
}
/////////////////////////////////////////////////////////////////////////////////////////
template<class TYPE>                //struct "link<TYPE>"
struct link
{
	TYPE data;         //data item
	link * next;       //pointer to next link
};
/////////////////////////////////////////////////////////////////////////////////////////
template<class TYPE>                //class "linklist<TYPE>"
class linklist                      //a list of links
{
private:
	//pointer to first link
	link<TYPE>* first;

public:
	linklist()                        //no argument constructor
	{
		first = NULL;                 //no first link
	}
	void additem(TYPE d);             //add data item (one link)
	void display();
};
//----------------------------------------------------------------------------------------
template<class TYPE>
void linklist<TYPE>::additem(TYPE d)        //add data item
{
	link<TYPE> * newlink = new link<TYPE>;  //make a new link
	newlink->data = d;                      // give it data
	newlink->next = first;                  // it points to next link
	first = newlink;                       //now first points to this
}
//------------------------------------------------------------------------------------------
template<class TYPE>
void linklist<TYPE>::display()             //display all links
{
	link<TYPE>* current = first;          //set ptr to first link
	while (current != NULL)               //quit on the last link
	{
		cout << endl << current->data;    //display data
		current = current->next;          // move to next link
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////
int main()
{                             //lemp is object of 
	linklist<employee>lemp;     //class"linklist<employee>"
	employee emptemp;         //temporary employee storage
	char ans;                  //user's response('y ' or 'no')
	do {
		cin >> emptemp;      //get employee data from user
		lemp.additem(emptemp);  //add it to linked list 'lemp'
		cout << "\n Add another (y/n)?";
		cin >> ans;
	} while (ans != 'n');       //when user is done
	lemp.display();
	cout << endl;
	return 0;
}