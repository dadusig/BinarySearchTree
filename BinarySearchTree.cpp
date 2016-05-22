// BinarySearchTree.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <cstdlib>

#include "BST.h"

using namespace std;

int main()
{
	cout << "Hello World\n";

	int TreeKeys[16] = { 50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80 };
	BST myTree;

	cout << "Printing the tree in order\nBefore adding numbers\n";

	myTree.PrintInOrder();

	for (int i = 0; i < 16 ; i++)
	{
		myTree.AddLeaf(TreeKeys[i]);
	}

	cout << "Printing the tree in order\nAfter adding numbers\n";

	myTree.PrintInOrder();
	
	cout << "\n";

	//myTree.PrintChildren(myTree.ReturnRootKey());
	
	for (int i = 0; i < 16; i++)
	{
		myTree.PrintChildren(TreeKeys[i]);
		cout << endl;
	}

	

	cout << "The smallest value in the tree is " << myTree.FindSmallest() << endl;
    
    
    cout << "Enter a key value to delete (-1 to stop):\n";
    int input=0;
    while (input!=-1)
    {
        cout << "Delete node: ";
        cin >> input;
        {
            if (input!=-1)
            {
                cout << "\n";
                myTree.RemoveNode(input);
                myTree.PrintInOrder();
                cout << "\n";
            }
        }
    }
     
    




    return 0;
}

