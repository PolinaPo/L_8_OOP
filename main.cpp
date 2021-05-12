#include <iostream>
#include <fstream>
#include "container.h"

using namespace std;
using namespace type_phrases;

int main(int argc, char const *argv[])
{
    if (argc != 3) {
        cout << "Incorrect command line!\n" << "Waited: command infile outfile" << endl;
        exit(1);
    }
    cout << argv[1] << endl;
    cout << argv[2] << endl;
    ifstream ifst(argv[1]);
    if (!ifst.is_open()) {
        cout << "Input file is not open!" << endl;
    }
    else {
        ofstream ofst(argv[2]);
        if (!ofst.is_open())
        {
            cout << "Output file is not open!" << endl;
        }
        else {
            cout << "Start" << endl;
            container c;
            c.container_Fill(ifst);
            cout << "Filled container" << endl;
            c.container_Output(ofst);
            ofst << "\n" << endl;
            c.sort();
            cout << "Sorted container" << endl;
            c.container_Output(ofst);
            ofst << "\n" << endl;
            c.container_OutputAphos(ofst);
            cout << "Output only aphorism" << endl;
            c.container_Clear();
            cout << "Empty container" << endl;
            c.container_Output(ofst);
            cout << "Stop" << endl;

            ifst.close();
            ofst.close();
        }
    }
    system("pause");
    return 0;
}