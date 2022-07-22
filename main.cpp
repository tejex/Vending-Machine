#include <iostream>
#include "Vending.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

//GLOBAL VARIABLES
int ID;
int choices = 0;
float totalcost=0;
long totalcalories=0;
int numberOfSnacks=0;
float highestPrice =0;
vector<string> Chosensnacks;
vector<int> ChosensnackIDs;
vector <float> eachPrice;

//CONSTRUCTOR
Vending_Machine::Vending_Machine(){
  numberOfSnacks = 0;
}
string Vending_Machine::getSnacks(int ID){
  return snacks[ID];
}
float Vending_Machine::getPrices(int ID){
  return prices[ID];
}
long Vending_Machine::getCalories(int ID){
  return calories[ID];
}
// prints main Menu
void Vending_Machine::printMenu(){
  cout<< "ID"<< " "<< "Cost"<< " " << "Snack" << " " << "Calories"<< endl;
  cout << "--------------------------------" << endl;
  for (int i = 0; i <10; i++){
    cout<< i<< " - " << getPrices(i) << " "<< getSnacks(i) << " " << getCalories(i)<< endl;
    }
  cout << endl;
  cout << "--------------------------------" << endl;
  };

// Processes user input and asks if they want to choose new snack 
void Vending_Machine::output(){
  bool proceed = true;
  string userchoice;
  while(proceed){
    cout<< "Please enter Snack ID: ";
    cin >> ID;
    cout << " " << endl;
    cout<< "You Selected: " <<getSnacks(ID) <<". That Will be $" << getPrices(ID) <<", chosen Snack has: " <<  getCalories(ID)<< " calories" << endl;
    Chosensnacks.push_back(snacks[ID]);
    ChosensnackIDs.push_back(ID);
    eachPrice.push_back(prices[ID]);
    totalcost += prices[ID];
    totalcalories += calories[ID];
    choices +=1;
    numberOfSnacks +=1;
    cout << " " << endl;
    cout << "Would you like to choose another snack? Enter Y or N: ";
    cin>> userchoice;
  
  if (userchoice == "Y"|| userchoice == "y"){
    proceed = true;
    choices +=1;
  }
  else if(userchoice =="N"|| userchoice =="n"){
    proceed = false;  
  }
  else{
    cout<<"Wrong Input."<< endl;
    
  }  
    }
  };
// attempted code to output most expensive

string Vending_Machine::mostExpensive(){
  if (Chosensnacks.size() == 1)
    return getSnacks(ChosensnackIDs[0]);

  
    int mostExp = 0;
    for(int i = 0; i
      < Chosensnacks.size(); i++){
      if(getPrices(ChosensnackIDs[mostExp])< getPrices(ChosensnackIDs[i]))
        mostExp = i;
    }
    return getSnacks(ChosensnackIDs[mostExp]);
    }


//attempt for least expensive

string Vending_Machine::leastExpensive(){
  if (Chosensnacks.size() == 1)
    return getSnacks(ChosensnackIDs[0]);

  
    int leastExp = 0;
    for(int i = 0; i
      < Chosensnacks.size(); i++){
      if(getPrices(ChosensnackIDs[leastExp]) > getPrices(ChosensnackIDs[i]))
        leastExp = i;
    }
    return getSnacks(ChosensnackIDs[leastExp]);
    }


// calculates cost after tax
float Vending_Machine::aftertax(){
  float afterTaxCost = totalcost * 0.05 + totalcost;
  return afterTaxCost;
};
//searches through vector and returns true if the snack is already in the vector 
bool Vending_Machine::contains(vector<string> vec, const string & elem){
    bool result = false;
    if( find(vec.begin(), vec.end(), elem) != vec.end() ){
        result = true;
    }
    return result;
}

long Vending_Machine::averageCalories(){
  long average = totalcalories / numberOfSnacks;
  return average;
}

void Vending_Machine::receipt(){
  cout <<" "<< endl;
  cout << "--------------------------------"<< endl; 
  vector<string> duplicates {};
  cout << " " << endl;
  //if the snack is in the duplicates vector it counts it and outputs the number of times it counted as well as the snack at that position
  for(int i = 0; i<Chosensnacks.size();i++){
    if(contains(duplicates, Chosensnacks[i]) == false){
    cout <<Chosensnacks[i] <<" "<<
          count(Chosensnacks.begin(), Chosensnacks.end(), Chosensnacks[i]) << " pieces.";
    cout<<" "<<endl;
    duplicates.push_back(Chosensnacks[i]);
      }
    }
  
  cout <<" "<< endl;
  cout << "Cost of snacks: $"<< totalcost<< endl;
  cout << "Total Calories: "<<totalcalories<< endl;
  cout<< "Average number of calories: "<<averageCalories()<< endl;
  cout << "Most expensive snack is: " << mostExpensive() << endl;
  cout << "Least expensive snack is: " << leastExpensive() << endl;
  
  cout<<"Your total cost after tax is: " <<"$"<<aftertax()<< endl;
  
  cout << " "<< endl;
  
  cout << "Thank you, come again!!" << endl;
  }
int main() {
  Vending_Machine V = Vending_Machine();
  V.printMenu();
  V.output();
  V.receipt();
  
}