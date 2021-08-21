//Tadeo Bennett
//September 24, 2020
//Pizza OOP with constructors

#include <iostream>
#include <cstring>
using namespace std;

class Pizza{ //new class
private:
	
	//instance variables
	char removal_choice; //stores the character/topping option that needs to be removed
	char topping_options[8]; //array that records the toppings listed from the user (A-G).
	string topping_names[8]; //array that stores the corresponding names of the options in the topping_options list (names of toppings).
	char size_option; //variable that records the size option from the user (A, B or C).
	char size_name[30]; //variable that stores the corresponding size option that relates to the size_option (small/medium/large pizza).
	
	char delivery_option; //char that stores a 'Y' if delivery was wanted		
	
	int purchase_total= 0; //stores the bill for the pizza object
	
public:
	Pizza(); //constructor
	Pizza(char sz, char * top, char rem, char del); //constructor with parameters given
	
	//methods
	void size_menu();
	void topping_menu();
	void get_order();	
	void remove_topping();
	void purchase_details();
};

Pizza::Pizza(){//constructor
	size_option = 'A'; //no toppings or delivery
}

Pizza::Pizza(char sz, char * top, char rem, char del){//constructor given parameters
	size_option = sz;
	strcpy(topping_options, top);
	removal_choice = rem;
	delivery_option = del;
}

void Pizza::purchase_details(){
	cout<<"You Ordered: 1 ";
	
	//Gives the size option a corressponding name along with having its particular price added to the purchase_total
	if (size_option == 'A'){strcpy(size_name, "Small Pizza $10"); purchase_total += 10;}
	if (size_option == 'B'){strcpy(size_name, "Medium Pizza $15");purchase_total += 15;}	
	if (size_option == 'C'){strcpy(size_name, "Large Pizza $20");purchase_total += 20;}

	cout<<size_name<<endl; //prints the string stored as the pizza size, which was set after testing the size_option for what was wanted
	
	//loop gives each topping option a correspoding name if they are found in the array of your topping options
	for(int t = 0; t<sizeof(topping_options)/*7*/; t++){
		if(topping_options[t] == 'A'){topping_names[t] = "Green Peppers";}
		if(topping_options[t] == 'B'){topping_names[t] = "Ham";}
		if(topping_options[t] == 'C'){topping_names[t] = "Pepperoni";}
		if(topping_options[t] == 'D'){topping_names[t] = "Pineapple";}
		if(topping_options[t] == 'E'){topping_names[t] = "Extra Cheese";}
		if(topping_options[t] == 'F'){topping_names[t] = "Roasted Tomatoes";}
		if(topping_options[t] == 'G'){topping_names[t] = "Grinded Meat";}
		if(topping_options[t] == 'R'){topping_names[t] = "Removed";} //if the option was removed
	}
		
	//checking topping details
	cout<<"Toppings: ";
	if(topping_names[0] != "") //testing if the array is empty first
	{
		cout<<endl; //new line to start print toppings
		for (int i = 0; i<7; i++)//loop that will print the topping names (Grinded Meat, pineapple, extra cheese, etc.)
		{ 
			if (topping_names[i] == ""){ i = 7;} //if toppings array is empty, end the loop immediately
			else if(topping_names[i] == "Removed"){ //if it finds "Removed" word then...
				topping_names[i+1]; // prints nothing and skips the current option
			}
			else{
				cout<<topping_names[i]<< " $1"<<endl; //print the topping and the cost($1)
				purchase_total += 1; //everytime it loops through a topping, add a dollar to the total
			}
		}//end for loop
	}
	else{cout<<"No toppings"<<endl;} // if the array is empty, output that it is
	
	//checking delivery details
	cout<<"Delivery: ";
	if (delivery_option == 'Y'){ //if you wanted delivery then it will show that it was wanted
		cout<<"+ delivery $3"<<endl;
		purchase_total += 3; //add 3 dollars to the total if delivery was wanted
	}
	else{ cout<<"No delivery"<<endl;}	//output if no delivery was wanted
	
	cout<<"Purchase total: $"<<purchase_total<<endl<<endl;		
}

void Pizza::size_menu(){
	cout<<"Enter Size of Pizza from available Options:"<<endl;
	cout<<"(A) Small for $10.00"<<endl;
	cout<<"(B) Medium for $15.00"<<endl;
	cout<<"(C) Large for $20.00"<<endl;	
}

void Pizza::topping_menu(){
	cout<<"(A) Green Peppers"<<endl;
	cout<<"(B) Ham"<<endl;
	cout<<"(C) Pepperoni"<<endl;
	cout<<"(D) Pineapple"<<endl;
	cout<<"(E) Extra Cheese"<<endl;
	cout<<"(F) Roasted Tomatoes"<<endl;
	cout<<"(G) Grinded Meat"<<endl;	
}

void Pizza::get_order(){
	Pizza::size_menu();//show the size_menu method
	cin>>size_option; //get the size option
	
	cout<<"Enter your topping choice. Refrain from duplication. Enter (Q) to EXIT."<<endl;	
	Pizza::topping_menu(); //show the topping_menu method
	
	for (int i = 0; i<7; i++){ //concatenating your options in an array
		cin>>topping_options[i]; //add to the toppings array
		if (topping_options[i] == 'Q'){ //stop input of topping options if 'Q' is entered
			topping_options[i] = '\0'; //removes the E from the list and makes it the end of the array.
			i = 7; //make i be 7 to end the loop
		}//end of if..
	} //end of loop..
	
	//asking if you want delivery
	cout<<"Delivery(Y) or No Delivery(N)"<<endl;
	cin>>delivery_option;
	cout<<endl; //newline most likely for the total's details
}

void Pizza::remove_topping(){
	
	if (topping_options[0] != '\0'){ //if the first value in the array is nothing, then the array is empty and this process can be skipped
		Pizza::purchase_details();
		cout<<"Remove a topping(A/B/C etc..)? Enter (Q) to EXIT/SKIP."<<endl;
	
		//loop that shows the list of topping options entered previously
		for(int i = 0; i<7; i++){
			if (topping_options[i] == '\0' or topping_options[i] == 'Q'){i = 7;} //end loop immediately if a space is found or Q is entered
			else{cout<<topping_options[i]<<endl;	} //output the option
		}
		cout<<"Enter choice here: "; cin>>removal_choice;
		cout<<endl;
		
		//Loop to find where the removal choice matches the list of options
		for (int r = 0; r<7; r++){
			if(topping_options[r] == removal_choice) //testing if the options entered matches the option you want to remove
			{
				topping_options[r] = 'R'; //add to the array position an R to tell that its a removed value
			}
		}
		
	}//end if...
	purchase_total = 0; //resets the purchase total for the new list to be checked again
}

int main(){
	
	Pizza customer1; //created a pizza for customer1
	customer1.purchase_details();
	
	cout<<endl;
	
	Pizza customer2 = Pizza('C'/*pizza_size*/, "ABDG"/*toppings*/, 'B'/*removal choice*/, 'Y'/*want_delivery*/); //constructor call for pizza object 2 for customer2
	customer2.purchase_details();
	
	cout<<endl;
	
	Pizza customer3; //pizza object 3 created
	customer3.get_order(); //get the order from user
	customer3.remove_topping(); //method to ask if the user wants to remove a topping
	customer3.purchase_details(); //method call to print the total with changes from removing a topping or not.
	
	return 0;
}
