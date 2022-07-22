#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Vending_Machine {

public:
 
  Vending_Machine();

  string getSnacks(int ID);
  float getPrices(int ID);
  long getCalories(int ID);
  void output();
  void receipt();
  void printMenu();
  string mostExpensive();
  string leastExpensive();
  float aftertax();
  long averageCalories();
  int amountOfSnacks(int ID);
  bool contains(vector<string> vec, const string & elem);
  
  

private:  

string snacks[10] = {"Chips", "Cookies", "Skittles", "Gum", "Sunchips", "M and Ms", "Oreos", " Doritos", "Chocolate", "Sour Patch Kids"};
float prices[10] = {1.2,1.1,1.2,1.2,0.85,1.2,1.1,2.2,1.5,1.8};  
long calories[10] = {110,100,160,70,110,150,200,110,900,250}; 

};