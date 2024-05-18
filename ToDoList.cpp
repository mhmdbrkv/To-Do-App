#include <iomanip>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

class ToDo {
    
    string taskName;
    fstream list;

public:
    
    void add_task(string a) {
        taskName = a;
        list.open("Tasks.txt", ios::out | ios::app);
        list << taskName << "\n";
        list.close();
    }

    void view_tasks()
    {
        int cnt = 1;
        string c;

        system("cls");
        list.open("Tasks.txt", ios::in);

        while (list >> c)
        {
            cout << cnt << ") " << c << "\n\n";
            cnt++;
        }

        list.close();
        cout << "\n";
        system("pause");
    }

    void delete_task(int index) {

        string arr[100];
        list.open("Tasks.txt", ios:: in);
        int i = 0;
        while (list >> arr[i])
        {
            i++;
        }

        list.close();

        list.open("Tasks.txt", ios::out);
        for (int j = 0; j < i; j++)
        {
            if (j != (index - 1))
            {
                list << arr[j] << "\n";
            }
        }
        list.close();

    }

};

void Main_Menu() {
    system("cls");
    cout << "\n\t" << "Welcome to To Do List Project.\n";
    cout << "\t" << "==============================\n";
    cout << "\n\t" << "1) Add task.\n\n";
    cout << "\n\t" << "2) View tasks.\n\n";
    cout << "\n\t" << "3) Delete task.\n\n";
    cout << "\n\t" << "4) Exit.\n\n";
}

int main()
{
    ToDo x;
    int option = 1;

    while (option > 0 && option < 4 && option != 4)
    {
        Main_Menu();

        cout << "Choose option: ";
        cin >> option;

        switch (option)
        {
        case 1: {
            
            system("cls");
            string s;
            cout << "Enter your task: ";
            cin >> s;
            x.add_task(s);

        }
              break;

        case 2: x.view_tasks();
            break;

        case 3: {
            int idx;
            cout << "Enter task number: ";
            cin >> idx;
            x.delete_task(idx);
        }
            break;

        case 4: break;
        }
    }
    


    return 0;
}
