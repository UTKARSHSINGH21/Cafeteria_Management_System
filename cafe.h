#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

class Cafe: public Admin
{
    string menu[10];
    int stock[10];
    int price[10];

public:

    void addFood2Menu()
    {
        static int counter = 0;

        if (counter < 10)
        {
            cout << "\n\n<<<<<------ Add food Items to Menu ------>>>>>";
            cout << "\n\nName of the food item to be added: ";
            cin >> menu[counter];
            cout << "Quantity Available: ";
            cin >> stock[counter];
            cout << "Price: ";
            cin >> price[counter];
            counter++;
        }

        else
        {
            cout << "\nNo Further items can be added\n\n";
        }
    }

    void dispMenu()
    {
        int c = 0;

        for (int i = 0; i < 9; i++)
        {
           
            if (menu[i] !=  "")
            {
                if (c == 0)
                {
                    cout << "\n\n<<<<<============ MENU ============>>>>>\n\n";
                    cout << "Id\tName  \tQuantity\tPrice\n\n";
                }
                cout << i << "  \t" << menu[i] << "\t" << stock[i] << "      \t" << price[i] << endl;
                c++;
            }
        }

        if (c == 0)
        {
            cout << "\nNo items in the menu\n";
        }

        getch();
    }

    void takeOrder()
    {
        static int orderID = 1;

        int order_quantity[10] = {0};
        string order_item[10] = {""};

        int c = 0; int id; int total = 0;
        dispMenu();

        cout << "\n\nEnter the id and quantity of the item you want to Order\n";

        for (int i = 0; i < 10; i++)
        {
            cout << "\nEnter item ID: ";
            cin >> id;
            order_item[i] = menu[id];
            cout << "Enter Quantity: ";
            cin >> order_quantity[i];
            if (order_quantity[i] <= stock[i])
            {
                stock[i] = stock[i] - order_quantity[i];
            }

            else
            {
               cout << "\nNot enough quantity available\n";     
            }

            char choice;

            cout << "\nWant to add more items? (y/n): ";
            cin >> choice;
            
            if ((choice == 'n' || choice == 'N') && c < 10)
                break;
        }

        cout << "\nYou have Ordered: \n\n";
        cout << "Order ID: " << orderID << endl;

        for (int i = 0; i < 10; i++)
        {
            if (order_quantity[i] >= 1)
            {
                cout << order_item[i] << " " << order_quantity[i] <<  " x " << price[i] << " = " << order_quantity[i] * price[i] << endl;
                total += order_quantity[i] * price[i];
            }
        }
        cout << "\nTotal = INR " << total << endl;
        orderID++;
        getch();
    }
};
