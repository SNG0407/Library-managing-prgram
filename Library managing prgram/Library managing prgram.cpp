// Library managing prgram
/*The program for Library
1. Resister books
2. Renting books
3. Returning books
4. List of books
5. EXIT

    Structure consists of name of book, Renting fee, Book number, Whether it's available or not 
*/
#include <iostream>

#define NAME_SIZE 32
#define BOOK_MAX 10


struct _TagBook
{
    char strBookName[NAME_SIZE];
    float fBookFee;
    int iBookNumber;
    bool bAvailable;
};

enum MENU {
    MENU_NONE,
    MENU_RESISTER,
    MENU_RENTING,
    MENU_RETURNING,
    MENU_LIST,
    MENU_EXIT
};

using namespace std;
int main()
{
    _TagBook bookArr[BOOK_MAX];
    int iBookNumber = 1;
    int iBookcount = 0;
    char strCurrentBookName[NAME_SIZE];

    while (true) {
        system("cls");
        // Show the menu and get what you want
        cout << "Enter one of the number of Menu" << endl;
        cout << "1. Resister books \n" << "2. Renting books \n"
            << "3. Returning books \n" << "4. List of books \n" << "5. EXIT " << endl;
        int iMenu;
        cin >> iMenu;

        // When you entered the wrong one
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }

        // How are you going to handle it when you choose the Menu
        if (iMenu == 5) {
            break;
        }
        switch (iMenu)
        {
        case MENU_NONE:

            break;

        case    MENU_RESISTER:
            cout << "-------Resister books-------" << endl;
            bookArr->strBookName
            break;

        case MENU_RENTING:
            cout << "-------Renting books-------" << endl;
            break;

        case MENU_RETURNING:
            cout << "-------Returning books-------" << endl;
            break;
                  
        case MENU_LIST:
            cout << "-------List of books-------" << endl;
            break;

        default:
            continue;
        }
    }


    return 0;
}
