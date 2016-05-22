#include <iostream>
#include <cstdlib> 

class BST
{
    
/*
    Κάποιες συναρτήσεις έχουν 2 εκδοχές. Την public και την private. 
    Οι public είναι προσβάσιμες από το κύριο πρόγραμμα και δίνουν πάντα
    ως κόμβο αφετηρία την ρίζα (root) ενώ οι Private αναλαμβάνουν τις 
    αναδρομικές κλήσεις στους ευατούς τους με αφετηρία διαφορετικούς 
    κόμβους κάθε φορά.
 
*/
    
private:
	struct node
	{
		int key;
		node* left;
		node* right;
	};
	node* CreateLeaf(int key);
	node* root;
	void AddLeafPrivate(int key, node* Ptr);
	void PrintInOrderPrivate(node* Ptr);
	node* ReturnNode(int key);
	node* ReturnNodePrivate(int key, node* Ptr);
	int FindSmallestPrivate(node* Ptr);
    void RemoveNodePrivate(int key, node* parent);
    void RemoveRootMatch();
    void RemoveMatch(node* parent, node* match, bool isLeft);
    void PrintPostOrderPrivate(node* ptr);
    void RemoveSubtree(node* ptr);
public:
	BST();
    ~BST();
	void AddLeaf(int key); 
	void PrintInOrder();
	int ReturnRootKey();
	void PrintChildren(int key);
	int FindSmallest();
    void RemoveNode(int key);
    void PrintPostOrder();
};
