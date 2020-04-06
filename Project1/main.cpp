/*
   Name: Emmanuel Idun
   Student #: 200418000
   Program: CS 210-001
   Assignment # 5

*/


#include "bst.h"
#include <iostream>
using namespace std;

void print_help() 
{
    cout << "\nCommands:" << endl;
    cout << "  +key : Insert (or update) data item (use integers)" << endl;
    cout << "  ?key : Retrieve data item" << endl;
    cout << "  -key : Remove data item" << endl;
    cout << "  K    : Write keys in ascending order" << endl;
    cout << "  C    : Clear the tree" << endl;
    cout << "  E    : Empty tree?" << endl;
    cout << "  G    : Get count of nodes          " << endl;
    cout << "  H    : Height                      " << endl;
    cout << "  Q    : Quit the test program\n" << endl;
}

class TestData
{
public:

    void setKey(int newKey)
    {
        keyField = newKey;
    }   // Set the key

    int getKey() const
    {
        return keyField;
    }     // Returns the key

private:

    int keyField;                // Key for the data item
};


int main()
{
    BST<TestData, int> testTree;   // Test binary search tree
    TestData testData;               // Binary search tree data item
    int inputKey;                    // User input key
    char cmd;                        // Input command

    print_help();

    do
    {
        cout << endl << "Command: ";                  // Read command
        cin >> cmd;
        if (cmd == '+' || cmd == '?' || cmd == '-' || cmd == '<')
            cin >> inputKey;

        switch (cmd)
        {
        case 'P': case 'p':
            print_help();
            break;

        case '+':                                  // insert
            testData.setKey(inputKey);
            cout << "Insert : key = " << testData.getKey() << endl;
            testTree.insert(testData);
            break;

        case '?':                                  // retrieve
            if (testTree.retrieve(inputKey, testData))
                cout << "Retrieved" << endl;
            else
                cout << "Not found" << endl;
            break;

        case '-':                                  // remove
            if (testTree.remove(inputKey))
                cout << "Removed data item" << endl;
            else
                cout << "Not found" << endl;
            break;

        case 'K': 
        case 'k':                       
            cout << "Keys:" << endl;
            testTree.printKeys();
            break;

        case 'C': 
        case 'c':                       // clear
            testTree.clear();
            cout << "Tree cleared" << endl;
            break;

        case 'E': 
        case 'e':                       // empty
            if (testTree.isEmpty())
                cout << "Tree is empty" << endl;
            else
                cout << "Tree is not empty" << endl;
            break;

        case 'G': 
        case 'g':                   
            cout << "Tree nodes count = " << testTree.getCount() << endl;
            break;

        case 'Q': 
        case 'q':                   // Quit test program
            break;

        default:                               // Invalid command
            cout << "Inactive or invalid command. 'P' prints help." << endl;
        }
    } while (cin && (cmd != 'Q') && (cmd != 'q'));

    if (!cin) 
    {
        cerr << "Error in console input. Exiting." << endl;
    }

    return 0;
}
