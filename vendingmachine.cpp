#include <iostream>
#include"drink.cpp"
#include "util.cpp"
#include "drink.h"
#include "util.h"
using namespace std;
using namespace sdds;

int main()
{
    bool done = false;
    loadDrinksFromFile("drinks.txt");
    // loadDrinks();
    cout << "Welcome to the Seneca Vending Machine" << endl << endl;
    while (!done) {
        drinkMenu();
        chooseDrink();
        cout << "\nDo you want to order another drink? (Y)es or (N)o: ";
        done = !confirm();
        cout << endl;
    }
    drinkMenu();

    cout << "\nThank you and come again" << endl;
     char exit;
    cin>>exit;
    return 0;
}