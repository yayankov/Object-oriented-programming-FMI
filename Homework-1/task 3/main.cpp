#include <iostream>
#include "store.h"

using namespace std;

int main()
{
    //Към магазинът могат да се добавят и предварително динамично разпределени обекти от клас Laptop
    /*
    Laptop* laptop1 = new Laptop("dell0798", "Dell", "Chromebook", "Lightweight", 1399.99);
    Laptop* laptop2 = new Laptop("asus0633", "Asus", "ZenBook 13", "Everyday-computing", 999.99);
    Laptop* laptop3 = new Laptop("dell0798", "Dell", "Latitude", "Desktop-Replacement", 1799.99);
    Laptop* laptop4 = new Laptop("acer0441", "Acer", "V15 Nitro", "Entertainment", 2100);
    Laptop* laptop5 = new Laptop("hp250117", "HP", "Elitebook", "Lightweight", 2348.00);
    */

    Store firstStore;

    while(true)
    {
        cout << endl;
        cout << "MAIN MENU" << endl;
        cout << "A - Add new product" << endl;
        cout << "B - Delete product" << endl;
        cout << "C - Change product" << endl;
        cout << "D - Display products" << endl;
        cout << "Q - Quit" << endl;
        cout << "Please choose an option: ";
        char choice;
        cin >> choice;
        cout << endl;

        if(choice == 'A' || choice == 'a')
        {
            firstStore.addNewLaptop();
        }
        else if(choice == 'B' || choice == 'b')
        {
            cout << "Choose laptop for delete: " << endl;
            firstStore.printListOfAllLaptops();
            unsigned int choiceB;
            cin >> choiceB;
            cout << endl;
            firstStore.deleteLaptop(*firstStore.getListOfLaptops()[choiceB-1]);
        }
        else if(choice == 'C' || choice == 'c')
        {
            cout << "Choose laptop for change: " << endl;
            firstStore.printListOfAllLaptops();
            unsigned int choiceC;
            cin >> choiceC;
            firstStore.changeLaptop(*firstStore.getListOfLaptops()[choiceC-1]);
        }
        else if(choice == 'D' || choice == 'd')
        {
            if(firstStore.isEmpty())
            {
                cout << "There are not any laptops in the store now. Come back later! :)" << endl;
            }
            else
            {
                cout << "These are all of the laptops in this store: " << endl;
                firstStore.printListOfAllLaptops();
            }
        }
        else if(choice == 'Q' || choice == 'q')
        {
            cout << "Goodbye and please come again some day! :)" << endl;
            break;
        }
    }

    //Разни допълнителни проверки
    /*
    Store s1;
    s1.addLaptop(*l1);
    s1.addLaptop(*l2);
    s1.addLaptop(*l3);
    cout << "List of all laptops in store1 before delete of laptop1:" << endl;
    s1.printListOfAllLaptops();
    s1.deleteLaptop(*l1);
    cout << "List of all laptops in store1 after delete of laptop1:" << endl;
    s1.printListOfAllLaptops();

    cout << endl << endl;

    s1.changeLaptop(*l2);

    s1.printListOfAllLaptops();
    */

    return 0;
}
