#include <iostream>

using namespace std;

int main()
{
    cout << "This program draws spiral and rhombus figure!" << endl
         << "Enter a number that is minimum 6 and even!" << endl;
    int figureSize = 0;
    cin >> figureSize;
    if (figureSize < 6) figureSize = 6;
    else if (figureSize % 2 == 1) figureSize--;

    // Spiral grid
    char grid[figureSize][figureSize];
    for(int column = 0; column < figureSize; column++){
        for(int row = 0; row < figureSize; row++){
            grid[column][row] = ' ';
        }
    }
    int topLimit    = 0;
    int bottomLimit = figureSize;
    int leftLimit   = 0;
    int rightLimit  = figureSize - 1;
    while (topLimit <= bottomLimit) {
        // top
        for (int row = leftLimit; row <= rightLimit; row++)
            grid[topLimit][row] = '*';
        bottomLimit--;

        // right
        for (int column = topLimit; column <= bottomLimit; column++)
            grid[column][rightLimit] = '*';
        leftLimit++;

        // bottom
        for (int row = rightLimit; row >= leftLimit; row--)
            grid[bottomLimit][row] = '*';
        topLimit++;

        // left
        for (int column= bottomLimit; column > topLimit; column--)
            grid[column][leftLimit] = '*';
        rightLimit--;

        topLimit++;
        rightLimit--;
        leftLimit++;
        bottomLimit--;
    }

    // Sprial print
    cout << "Spiral:" << endl;
    for(int column = 0; column < figureSize; column++){
        for(int row = 0; row < figureSize; row++){
            cout << grid[column][row];
        }
        cout << endl;
    }

    cout << endl << "=================" << endl << endl;

    // Rhombus
    cout << "Rhombus:" << endl;
    int rhombusFigureSize = figureSize-2;
    for(int row = 0; row <= rhombusFigureSize; row++){
        for (int column = 0; column <= rhombusFigureSize; column++){

            if( column >= abs(row%rhombusFigureSize - rhombusFigureSize/2) &&
                column <= rhombusFigureSize/2 + (rhombusFigureSize/2 - abs(row%rhombusFigureSize - rhombusFigureSize/2) )   ){
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
