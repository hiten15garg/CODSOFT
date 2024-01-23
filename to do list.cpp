#include <iostream>
#include <list>
#include <ctime>
#include <string>
using namespace std;

class todolist
{
private:
    string description;
    int rand_num;
    bool is_compl;
    bool is_delete;

public:
    int r;
    string d;
    todolist()
    {
        rand_num = 0;
        description = "";
        is_compl = false;
        is_delete = false;
    }
    ~todolist() = default;

    bool new_data(string new_description)
    {
        rand_num = rand() % 100 + 1;
        description = new_description;
        return true;
    }

    void iscompleted(bool val)
    {
        is_compl = val;
    }

    void isdeleted(bool val, int c, string s)
    {
        is_delete = val;
        if (val == true)
        {
            rand_num = c;
            description = s;
            // cout << rand_num << " true | " << endl;
        }
        else if (val == false)
        {
            rand_num = c;
            description = s;
        }
    }

    int get_id() { return rand_num; }
    bool id_compl() { return is_compl; }
    string description_id() { return description; }
    bool deletion() { return is_delete; }
};

// int dl_item(int id, list<todolist> listitems)
// {
//     int r;
//     list<todolist>::iterator list;
//     for (list = listitems.begin(); list != listitems.end(); list++)
//     {
//         if (list->get_id() == id)
//         {

//         }
//     }
//     return r;
// }

int main()
{
    string new_description;
    int compl_id;
    char intput_choice;
    int id_del;
    char e;
    char choose_comp, choose_del;

    list<todolist> listitems;
    list<todolist>::iterator list;
    todolist newlist;
    string n;

    srand(time(NULL));

    listitems.clear();

    while (n != "quit")
    {
        system("cls");
        cout << "Your current todolist:" << endl;
        for (list = listitems.begin(); list != listitems.end(); list++)
        {
            string id_compl = list->id_compl() ? "done" : "not done";
            string id_delete = list->deletion() ? "true" : "false";
            if (id_delete != "true" && list->get_id() != -1)
            {
                cout << list->get_id() << " | " << list->description_id() << " | " << id_compl << endl;
            }
        }

        cout << "Choose one from below:" << endl;
        cout << "1 - Add:" << endl
             << "2 - Complete:" << endl
             << "3 - Delete:" << endl
             << "4 - Quit:" << endl;
        cin >> intput_choice;

        switch (intput_choice)
        {
        case '1':
            cout << "Add your new list:" << endl;
            cin.clear();
            cin.ignore();
            getline(cin, new_description);

            newlist.new_data(new_description);
            listitems.push_back(newlist);
            break;
        case '2':
            cout << "Enter the id Number:" << endl;
            cin >> compl_id;

            for (list = listitems.begin(); list != listitems.end(); list++)
            {
                if (list->get_id() == compl_id)
                {
                    list->iscompleted(true);
                    cout << "Want to revert: Y or N" << endl;
                    cin >> choose_comp;
                    if (choose_comp == 'Y')
                    {
                        list->iscompleted(false);
                    }
                    else if (choose_comp == 'N')
                    {
                        break;
                    }
                }
            }
            break;
        case '3':
            cout << "Enter the id Number:" << endl;
            cin.clear();
            cin.ignore();
            cin >> id_del;

            for (list = listitems.begin(); list != listitems.end(); list++)
            {
                if (list->get_id() == id_del)
                {
                    string des = list->description_id();
                    list->isdeleted(true, -1, "");
                    // list->iscompleted(false);
                    cout << "Want to revert: Y or N" << endl;
                    cin >> choose_del;
                    if (choose_del == 'Y')
                    {
                        list->isdeleted(false, id_del, des);
                    }
                    else if (choose_del == 'N')
                    {
                        break;
                    }
                }
            }
            break;
        case '4':
            cout << "Hope!! you will not forget anything from the list." << endl;
            cout << "Want to exit: Y or N" << endl;
            cin >> e;
            if (e == 'Y')
            {
                n = "quit";
            }
            else if (e == 'N')
            {
                break;
            }
            break;
        default:
            cout << "Wrong choice." << endl
                 << flush;
            system("pause");
            break;
        }
    }
    return 0;
}
