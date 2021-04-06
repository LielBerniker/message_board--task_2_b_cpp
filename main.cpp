#include "Board.hpp"
#include <string>
#include <iostream>
#include <array>
#include "Direction.hpp"
using namespace ariel;
using namespace std;
int main()
{

    
    Board test;

    while (1)
    {
        cout << "\n please choose :\n 1.post\n 2.read\n 3.show\n 4.exit\n";
        int opr;
        cin >> opr;
        switch (opr)
        {
        case 1:
        {
            unsigned int row, col;
            string mas;
            int d = 0;
            cout << "\nplease enter row number\n";
            cin >> row;
            cout << "\nplease enter column number\n";
            cin >> col;
            cout << "\nplease enter direction\n1.Horizontal\n2.Vertical\n";
            cin >> d;
            cout << "\nplease enter massage\n\n";
            cin >> mas;
            if (d == 1)
            {
                test.post(row, col, Direction::Horizontal, mas);
            }
            else
            {
                test.post(row, col, Direction::Vertical, mas);
            }
            break;
        }
        case 2:
        {
            unsigned int row, col;
            unsigned int len;
            int d = 0;
            cout << "\nplease enter row number\n";
            cin >> row;
            cout << "\nplease enter column number\n";
            cin >> col;
            cout << "\nplease enter direction\n1.Horizontal\n2.Vertical\n";
            cin >> d;
            cout << "\nplease enter length\n";
            cin >> len;
            if (d == 1)
            {
                cout<< "\n"<<test.read(row, col, Direction::Horizontal, len) << "\n";
            }
            else
            {
                cout<< "\n"<<test.read(row, col, Direction::Vertical, len) << "\n";
            }
              cout << endl;
            break;
        }
        case 3:
        {
            test.show();
        }
        default:
        {
            break;
        }
        }
        if (opr == 4)
        {
            break;
        }
    }
}
// clang++-9 -std=c++11 main.cpp Board.cpp -o main_run