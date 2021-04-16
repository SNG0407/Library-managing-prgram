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
using namespace std;

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


int main()
{
    _TagBook bookArr[BOOK_MAX] = {};
    int iBookNumber = 1;
    int iBookCount = 0;
    int iConfirmRenting;
    char strCurrentBookName[NAME_SIZE];
    char strBookName[NAME_SIZE];


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

            cout << endl << "Your resistering is done now. Thanks a lot" << endl << endl;

            break;

        case MENU_RENTING:
            system("cls");
            cout << "-------Renting books-------" << endl;
            cin.ignore(1024, '\n');
            cout << "Enter the name of your book : ";
            cin.getline(strBookName, NAME_SIZE);
            
            for (int i = 0; i < iBookCount; i++) {
                if (strcmp(strBookName, bookArr[i].strBookName) == 0) {
                    if (bookArr[i].bAvailable) {
                        cout << bookArr[i].strBookName << "  is available at the moment." << endl;
                        cout << "Renting fee is " << bookArr[i].strBookFee << endl;
                        cout << "If you want to rent this, enter 1 or 0   ";
                        cin >> iConfirmRenting;
                        //I will leave the cin error for later
                        if (iConfirmRenting == 1) {
                            cout << "Here you are. Thank you for renting this book" << endl;
                            bookArr[i].bAvailable = false;
                            break;
                        }
                        else {
                            cout << "Thank you for visiting our Library" << endl;
                            break;
                        }
                    }else{
                        cout << "This book is not available at the moment." << endl;
                        break;
                    }
                }
                cout << "We don't have such a book you asked" << endl;
            }
               

            break;

        case MENU_RETURNING:
            system("cls");
            cout << "-------Returning books-------" << endl;
            cout << "What book would you like to return?" << endl;
            cin >> strBookName;
            
            for (int i = 0; i < iBookCount; i++) {
                
                if (strcmp(strBookName, bookArr[i].strBookName) == 0) {
                    if (bookArr[i].bAvailable) {
                        cout << "We already have this book here. Are you sure you rented it here?" << endl;
                    }
                    else if (!bookArr[i].bAvailable) {
                        cout << "Thank you for returning it. Have a good day!" << endl;
                        bookArr[i].bAvailable = true;
                    }
                }
            }
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
