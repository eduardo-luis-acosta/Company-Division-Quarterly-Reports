#include <iostream>
#include <fstream>

using namespace std;

struct division {
    string region;
    int quarter;
    double sales;
};

int main() {

    //Division structs
    division north;
    division south;
    division east;
    division west;

    cout << "Please input the quarter sales for the the North, South, East, and West divisons.";

    //struct variables
    int regionIndic;
    int quarter;
    double sales;

    cout << "\n\nCompany Division:\n1. North\n2. South\n3. East\n4. West";
    for(int i = 0; i < 4; i++) {
        cout << "\n\nAnswer:  ";

        //get region
        while(!(cin >> regionIndic) || regionIndic < 1 || regionIndic > 4 ) {
            cout << "\nInvalid Input. Try Again.\nAnswer: ";
            cin.clear();
            cin.ignore(123, '\n');
        }

        //get quarter
        cout << "Quarter: ";
        while(!(cin >> quarter) || quarter < 1 || quarter > 4 ) {
            cout << "\nInvalid Input. Try Again.\nQuarter: ";
            cin.clear();
            cin.ignore(123, '\n');
        }

        //get sales
        cout << "Quarterly Sales: ";
        while(!(cin >> sales) || sales < 0) {
            cout << "\nInvalid Input. Try Again.\nQuarterly Sales: ";
            cin.clear();
            cin.ignore(123, '\n');
        }
        
        //assign variables to structs
        switch (regionIndic) {
            case 1:
                north.region = "North";
                north.quarter = quarter;
                north.sales = sales;

                break;
            case 2:
                south.region = "South";
                south.quarter = quarter;
                south.sales = sales;

                break;
            case 3:
                east.region = "East";
                east.quarter = quarter;
                east.sales = sales;

                break;
            case 4:
                west.region = "West";
                west.quarter = quarter;
                west.sales = sales;

                break;
        }
    }

    //open file
    ofstream file("Divisions.txt");

    //print information to file
    for(int i = 1; i <= 4; i++) {
        switch(i) {
            case 1:
                file << "North Division:\nQuarter: " << north.quarter << "\nQuarterly Sales: " << north.sales;
                break;
            case 2:
                file << "\n\nSouth Division:\nQuarter: " << south.quarter << "\nQuarterly Sales: " << south.sales;
                break;
            case 3:
                file << "\n\nEast Division:\nQuarter: " << east.quarter << "\nQuarterly Sales: " << east.sales;
                break;
            case 4:
                file << "\n\nWest Division:\nQuarter: " << west.quarter << "\nQuarterly Sales: " << west.sales;
                break;
        }
    }

    //close the file
    file.close();


    return 0;
}