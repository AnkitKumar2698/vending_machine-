#include <iostream>
#include<fstream>
#include<sstream>
#include <iomanip>
#include "drink.h"
#include "util.h"
using namespace std;

namespace sdds
{
	const int MAXDRINKS = 5;

	Drink machine[MAXDRINKS];
    void loadDrinksFromFile(const char* filename)
    {
          ifstream out_file;
          string item;
          out_file.open(filename,ios::in);
          int i=0;
        while(getline(out_file,item))
        {
          istringstream each(item);
          string word;
          int j=0;
          string name,volume,price,quantity;
          while(each>>word)
          {
            if(j==0)
            name=word.c_str();
            else if(j==1)
            volume=word.c_str();
            else if(j==2)
            price=word.c_str();
            else if(j==3)
            quantity=word.c_str();
            j++;
          }
          for(int k=0;k<name.length();k++)
          {
              machine[i].name[k]=name[k];
          }
          machine[i].price=stod(price);
          machine[i].quantity=stoi(quantity);
          machine[i].volume=stoi(volume);
          i++;
        }
    }

    void drinkMenu()
    {
        cout << "-----------Available Drinks-----------" << endl;
        cout << left << setw(10) << "Drink" << setw(10) << "Volume";
        cout << setw(10) << "Price" << setw(10) << "Quantity" << endl;
        for (int i = 0; i < MAXDRINKS; ++i) {
            cout << i + 1 << ".";
            displayDrink(&machine[i]);
        }
    }

    void displayDrink(const Drink* drink)
    {
        cout << left << setw(10) << drink->name << setw(10) << drink->volume
            << setw(10) << drink->price << setw(10) << drink->quantity << endl;
    }

    int chooseDrink()
    {
        bool done = false;
        int sel = 0;
        cout << "Select a drink from the menu (1-" << MAXDRINKS << "): ";
        do {
            cin >> sel;
            clearBuffer();
            if (sel >= 1 && sel <= MAXDRINKS) {
                if (updateDrink(sel) == true)
                    done = true;
                else
                    cout << "Out of stock for that drink, try again: ";
            }
            else
                cout << "Selection was was invalid try again: ";
        } while (!done);
        return sel;
    }

    bool updateDrink(int sel)
    {
        bool res = false;
        if (machine[sel - 1].quantity > 0) {
            machine[sel - 1].quantity--;
            res = true;
        }
        return res;
    }

}