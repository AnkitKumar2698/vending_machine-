#ifndef SDDS_DRINK_H 
#define SDDS_DRINK_H

namespace sdds
{
	struct Drink
	{
		char name[10];
		int volume;
		double price;
		int quantity;
	};

	void loadDrinks();
	void drinkMenu();
	void displayDrink(const Drink* drink);
	int chooseDrink();
	bool updateDrink(int sel);


}
#endif
