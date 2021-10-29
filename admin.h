#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

class Admin
{
    string name;
    string password;
    string sapid;
    string student_pass;

public:
    Admin()
    {
        name = "admin";
        password = "pass1234";
    }

    int adminLogin() 
    {

        int pchoice = 3;
        string uname, upass;
        cout << "\nUsername: ";
        cin >> uname;
        cout << "Password: ";
        cin >> upass;

        if (name == uname)
        {
            while (true && pchoice != 0)
            {
                if (password == upass)
                {
                    return 1;
                    break;
                }
                else
                {
                    cout << "\nWrong password\n";
                    pchoice--;
                    cout << "You only have " << pchoice << " attempts left !!!\n\n";
                    cout << "Password: ";
                    cin >> upass;
                }
            }
        }
        else
        {
            cout << "Incorrect username or password\n";
        }
        return 0;
    }

    void addStudentDetails()
    {
        int c = 0;
        cin.clear();
        cout << "Enter Student's SAPID: ";
        cin >> sapid;

        ifstream fin("Student_details.txt");
        string line;
        cout << line;
        while (getline(fin, line))
        {
            int pos = line.find(":");
            string usern = line.substr(0, pos);
            if (usern == sapid)
            {
                cout << "\nSAPID already exists\n";
                getch();
                c++;
                break;
            }
        }
        if (c == 0)
        {
            cout << "Enter their password: ";
            cin >> student_pass;

            ofstream out("Student_details.txt", ios ::app);
            out << sapid << ":" << student_pass << "\n";
            out.close();
        }
}
void viewStudentDetails()
{
    ifstream fin("Student_details.txt");
    if (!fin)
        cout << "File not found\n";
    else
    {
        string line;
        cout << line;
        while (getline(fin, line))
        {
            int pos = line.find(":");
            string usern = line.substr(0, pos);
            cout << usern << endl;
        }
    }
    fin.close();
}

int studentLogin(string uid)
{
    int pchoice = 3; int c = 0;
    string pass;
    cout << "Enter Password: ";
    cin >> pass;
    ifstream fin("Student_details.txt");

    if (!fin)
        cout << "File not found\n";
    else
    {
        string line;
        cout << line;
        while (getline(fin, line))
        {
            int pos = line.find(":");
            string usern = line.substr(0, pos);
            string p = line.substr(pos + 1);
            if (usern == uid)
            {
                while (true && pchoice != 0)
                {
                    if (pass == p)
                    {
                        return 1;
                        c++;
                        break;
                    }
                    else
                    {
                        cout << "\nWrong SAPID or password\n";
                        pchoice--;
                        cout << "You only have " << pchoice << " attempts left !!!\n\n";
                        cout << "Password: ";
                        cin >> pass;
                    }
                }
            }
        }
            if (c == 0)
            {
                cout << "SAPID does not exist\n";
            }
            return 0;
        }
        fin.close();
    }
}
;
