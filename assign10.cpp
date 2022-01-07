#include <iostream>
#include <fstream>
using namespace std;
void create();
void display();
int search(int roll);
void add();
void del();
void modify();
int rollno;
char name[10];
char dept[10];
fstream f, r, temp;
int main()
{
    int x = 1, ch;
    while (x)
    {
        cout << "\nWhat you want to do:-\n1. Create\n2. Display\n3. Add\n4. Modify\n5. Delete\n6. Exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            add();
            break;
        case 4:
            modify();
            break;
        case 5:
            del();
            break;
        case 6:
            x = 0;
            break;
        default:
            cout << "\nPLease enter correct choice!\n";
            break;
        }
    }
}

void modify()
{
    int x, roll;
    cout << "\nEnter roll no:-\n";
    cin >> roll;
    x = search(roll);
    if (x == 1)
    {
        f.open("data.txt", ios::in);
        temp.open("temp.txt", ios::out);
        f >> rollno >> name >> dept;
        while (!f.eof())
        {
            if (roll == rollno)
            {
                cout << "\nEnter name and department:-\n";
                cin >> name >> dept;
                temp << rollno << "\t" << name << "\t" << dept << "\n";
                f >> rollno >> name >> dept;
                continue;
            }
            temp << rollno << "\t" << name << "\t" << dept << "\n";
            f >> rollno >> name >> dept;
        }
        f.close();
        temp.close();
        f.open("data.txt", ios::out);
        temp.open("temp.txt", ios::in);
        temp >> rollno >> name >> dept;
        while (!temp.eof())
        {
            f << rollno << "\t" << name << "\t" << dept << "\n";
            temp >> rollno >> name >> dept;
        }
        f.close();
        temp.close();
    }
    else
    {
        cout << "\nRecord not exist!\n";
    }
}

void del()
{
    int x, roll;
    cout << "\nEnter roll no:-\n";
    cin >> roll;
    x = search(roll);
    if (x == 1)
    {
        f.open("data.txt", ios::in);
        temp.open("temp.txt", ios::out);
        f >> rollno >> name >> dept;
        while (!f.eof())
        {
            if (roll != rollno)
            {
                temp << rollno << "\t" << name << "\t" << dept << "\n";
            }
            f >> rollno >> name >> dept;
        }
        f.close();
        temp.close();
        f.open("data.txt", ios::out);
        temp.open("temp.txt", ios::in);
        temp >> rollno >> name >> dept;
        while (!temp.eof())
        {
            f << rollno << "\t" << name << "\t" << dept << "\n";
            temp >> rollno >> name >> dept;
        }
        f.close();
        temp.close();
    }
    else
    {
        cout << "\nRecord not exist!\n";
    }
}
void add()
{
    int x, i, roll;
    cout << "\nEnter roll no\n";
    cin >> roll;
    x = search(roll);
    if (x == 1)
    {
        cout << "\nRecord already exist!\n";
    }
    else
    {
        f.open("data.txt", ios::app);
        cout << "\nEnter name and department:-\n";
        cin >> name >> dept;
        rollno = roll;
        f << rollno << "\t" << name << "\t" << dept << "\n";
        f.close();
    }
}
int search(int roll)
{
    r.open("data.txt", ios::in);
    while (!r.eof())
    {
        r >> rollno >> name >> dept;
        if (roll == rollno)
        {
            r.close();
            return 1;
        }
    }
    r.close();
    return 0;
}
void create()
{
    int n, i;
    f.open("data.txt", ios::out);
    cout << "\nHow many records you want to enter:-\n";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "\nEnter roll no, name and department:-\n";
        cin >> rollno >> name >> dept;
        f << rollno << "\t" << name << "\t" << dept << "\n";
    }
    f.close();
}
void display()
{
    f.open("data.txt", ios::in);
    cout << "Roll No"
         << "\t"
         << "Name"
         << "\t"
         << "Department"
         << "\n";
    f >> rollno >> name >> dept;
    while (!f.eof())
    {
        cout << rollno << "\t" << name << "\t" << dept << "\n";
        f >> rollno >> name >> dept;
    }
    f.close();
}
