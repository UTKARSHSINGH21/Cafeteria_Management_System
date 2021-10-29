#include <iostream>
#include "admin.h"
#include "cafe.h"
using namespace std;
int mainMenu()
{
    int mainMenuChoice;
    cout << "\n\n<<<<<============ LOGIN ============>>>>>\n\n";
    cout << "1: Admin Login\n";
    cout << "2: Student Login\n";
    cout << "0: Exit\n\n";
    cout << "Select an option: ";
    cin >> mainMenuChoice;
    return mainMenuChoice;
}

int main()
{
   
    system("cls");
    Admin A;
    Cafe c;

    bool t;
    cout << "<<<<<<<<<<============ WELCOME TO NMIMS CAFE ============>>>>>>>>>>";
    while (true)
    {
        t = true;
        switch (mainMenu())
        {
            system("cls");
        case 1:
            if (A.adminLogin())
            {
                int c1;
                while (t == true)
                {

                    cout << "\n\n<<<<<====== Welcome Admin ======>>>>>\n\n";
                    cout << "1: Add Student Record\n";
                    cout << "2: View Student Records\n";
                    cout << "3: Add Food to Menu\n";
                    cout << "4: Display Menu\n";
                    cout << "0: Exit\n\n";
                    cout << "Select an option: ";
                    cin >> c1;
                    switch (c1)
                    {
                    case 1:
                        A.addStudentDetails();
                        break;

                    case 2:
                        A.viewStudentDetails();
                        break;

                   
                    case 3:
                        c.addFood2Menu();
                        break;

                    case 4:
                        c.dispMenu();
                        break;
                    
                    case 0:
                         t = false;
                        break;
                    

                    default:
                        cout << "Invalid Choice !";

                    }
                }
            }
            break;

        case 2:
            while (true)
            {
                t = true;
                cin.clear();
                string sap;
                cout << "\nEnter SAPID: ";
                cin >> sap;
                int schoice;
                if (c.studentLogin(sap))
                {
                    cout << "\n\n<<<<<========== Welcome " << sap << " ==========>>>>>\n";
                    while (t == true)
                    {
                        cout << "\n1: Menu\n";
                        cout << "2: Order\n";
                        cout << "0: Exit\n\n";
                        cout << "Select an option: ";
                        cin >> schoice;

                        switch (schoice)
                        {
                        case 1:
                            c.dispMenu();
                            break;

                        case 2:
                            c.takeOrder();
                            break;

                        case 0:
                            t = false;
                            break;

                        default:
                            cout << "Invalid Choice\n";
                        }
                        getch();
                    }
                }
            }
            break;

        case 0:
            exit(0);

        default:
            cout << "\nInvalid Choice! Try Again!\n";
        }
    }
}
