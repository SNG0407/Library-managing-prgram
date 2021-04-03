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
#define FEE_SIZE 16
#define BOOK_MAX 10


struct _TagBook
{
    char strBookName[NAME_SIZE];
    char strBookFee[FEE_SIZE];
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
    _TagBook bookArr[BOOK_MAX] = {};
    int iBookNumber = 1;
    int iBookCount = 0;
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
            system("cls");
            cout << "-------Resister books-------" << endl;

            //When the number of books is fully stucked
            if (iBookNumber == BOOK_MAX + 1) {
                cout <<"You have exceeded the maximum number of books that you can resister." << endl;
                break;
            }
            cin.ignore(1024, '\n');
            cout << "Enter the name of your book : ";
            cin.getline(bookArr[iBookCount].strBookName, NAME_SIZE);
            cout << "Enter the rental fee of your book : ";
            cin.getline(bookArr[iBookCount].strBookFee, FEE_SIZE);
            bookArr[iBookCount].bAvailable = true;
            bookArr[iBookCount].iBookNumber = iBookNumber;

            iBookNumber++;
            iBookCount++;

            break;

        case MENU_RENTING:
            cout << "-------Renting books-------" << endl;
            break;

        case MENU_RETURNING:
            cout << "-------Returning books-------" << endl;
            break;
                  
        case MENU_LIST:
            system("cls");
            cout << "-------List of books-------" << endl;
            for (int i = 0; i < iBookCount; i++) {
                cout << "Book number : " << bookArr[i].iBookNumber << endl;
                cout << "Book name : " << bookArr[i].strBookName << endl;
                cout << "Book rent fee : " << bookArr[i].strBookFee << endl;
                if(bookArr[i].bAvailable){
                cout << "Book available : Yes" << endl;
                }else  cout << "Book available : No " << endl;
                cout << endl << endl;
            }
            break;

        default:
            cout << "You gave us the wrong one" << endl;
            break;
        }
        system("pause");
    }
    

    return 0;
}
