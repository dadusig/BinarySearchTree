#include <iostream>
#include <cstdlib>

#include "BST.h"
using namespace std;

BST::BST()
{
	root = NULL;
}

BST::node* BST::CreateLeaf(int key)
{
	node* n = new node; //δημιουργία ενός νέου κόμβου και δεικτη σε αυτόν
	n->key = key;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void BST::AddLeaf(int key) // κάθε φορά που προσθέτω κόμβο είναι πάντα φύλλο
{
	AddLeafPrivate(key, root); //δώσε ως αφετηρία την ρίζα
}

void BST::AddLeafPrivate(int key, node* Ptr)
{
	if (root == NULL) // Αν το δέντρο είναι κενό
	{
		root = CreateLeaf(key); //Θέσε αυτόν τον κόμβο ως ρίζα
	}
	else if (key < Ptr->key) //αλλιως αν το κλειδι που θελω να προσθέσω είναι μικρότερο από αυτό που κοιτάω
	{ // πηγαινε αριστερά και
		if (Ptr->left != NULL) //αν ο κόμβος που κοιτάω έχει αριστερό παιδί
		{
			AddLeafPrivate(key, Ptr->left); //κάλεσε αναδρομικά τον εαυτό σου με αφετηρία το αριστερό παιδί
		}
		else //αλλιως αν δεν έχει παιδί
		{
			Ptr->left = CreateLeaf(key); //καλά γεννητούρια βρε!
		}
	}
	else if (key > Ptr->key) //αντίστοιχα αν το κλειδί που θέλω να προσθέσω είναι μεγαλύτερο απο αυτό που κοιτάω
	{//πήγαινε δεξιά και
		if (Ptr->right != NULL) //αν ο κόμβος που κοιτάω έχει δεξί παιδί
        {
			AddLeafPrivate(key, Ptr->right); //κάλεσε αναδρομικά τον εαυτό σου με αφετηρία το δεξί παιδί
		}
		else //αλλιως αν δεν έχει παιδί
		{
			Ptr->right = CreateLeaf(key); //να του ζήσει!
		}
	}
	else //σε περίπτωση που υπάρχει ήδη το κλειδί
	{
		cout << "The key " << key << " has already been added to the tree!\n";
	}
}

void BST::PrintInOrder() //public δωσε ως αφετηρια την ρίζα
{
	PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(node* Ptr) 
{
	if (root != NULL) //αν το δέντρο δεν ειναι άδειο
	{
		if (Ptr->left !=NULL) //αν ο κομβος που ειμαι εχει αριστερο παιδι
		{
			PrintInOrderPrivate(Ptr->left); //ξανακαλεσε τον εαυτο μου απο αυτο
		}
		cout << Ptr->key << " "; //οταν βγει απο το if (δεν θα υπαρχει άλλο παιδι αριστερα), εκτύπωσε το
		if (Ptr->right != NULL) //αν ο κομβος που ειμαι εχει δεξι παιδι
		{
			PrintInOrderPrivate(Ptr->right); //ξανακαλεσε τον εαυτο μου απο αυτο
		}
	}
	else
	{
		cout << "The tree is empty!\n";
	}
}

BST::node* BST::ReturnNode(int key) //επέστρεψε αν υπάρχει τον κόμβο με κλειδί key
{
	return ReturnNodePrivate(key, root);
}

BST::node* BST::ReturnNodePrivate(int key, node* Ptr)
{
	if (Ptr != NULL) //αν ο κόμβος που κοιτάω δεν είναι άδειος
	{
		if (Ptr->key == key) //αν τον βρηκα
		{
			return Ptr; //επεστρεψε τον
		}
		else //αλλιως
		{
			if (key < Ptr->key) //αν το κλειδι που ψάχνω είναι μικότερο απο αυτό του κομβου που βρίσκομαι
			{
				return ReturnNodePrivate(key, Ptr->left); //κάλεσε το εαυτό μου για το αριστερό παιδί
			}
			else
			{
				return ReturnNodePrivate(key, Ptr->right); //αλλιώς κάλεσε με για το δεξι παιδί
			}
		}
	}
	else
	{
		return NULL; //αν ο κοβος ειναι κενος, επεστρεψε NULL
	}
}

int BST::ReturnRootKey()
{
	if (root != NULL)
		return root->key;
	else
		return -1000;
}

void BST::PrintChildren(int key)
{
	node* Ptr = ReturnNode(key);

	if (Ptr != NULL)
	{
		cout << "Parent node = " << Ptr->key << endl;

		Ptr->left == NULL ?
			cout << "Left Child = NULL" << endl:
			cout << "Left Child = " << Ptr->left->key << endl;

		Ptr->right == NULL ?
			cout << "Right Child = NULL"<< endl :
			cout << "Right Child = " << Ptr->right->key << endl;
	}
	else
		cout << "The key " << key << " is not in the tree!\n";
	
}

int BST::FindSmallest()
{
	return FindSmallestPrivate(root);
}

int BST::FindSmallestPrivate(node* Ptr)
{
	if (root == NULL)
	{
		cout << "The tree is empty";
		return -1000;
	}
	else
	{
		if (Ptr->left != NULL)
		{
			return FindSmallestPrivate(Ptr->left);
		}
		else
		{
			return Ptr->key;
		}
        
	}
}

void BST::RemoveNode(int key)
{
    RemoveNodePrivate(key, root);
}

void BST::RemoveNodePrivate(int key, node* parent)
{
    if (root!=NULL)
    {
        if (key == root->key)
        {
            RemoveRootMatch();
        }
        else
        {
            if (key < parent->key && parent->left != NULL)
            {
                parent->left->key == key ?
                RemoveMatch(parent, parent->left, true):
                RemoveNodePrivate(key, parent->left);
            }
            else if (key > parent->key && parent->right != NULL)
            {
                parent->right->key == key ?
                RemoveMatch(parent, parent->right, false):
                RemoveNodePrivate(key, parent->right);
            }
            else
                cout << "The key "<< key << " was not found in the tree!";
        }
    }
    else
        cout << "The tree is empty!\n";
    
}

void BST::RemoveRootMatch()
{
    if (root != NULL)
    {
        node* delPtr = root;
        int rootKey = root->key;
        int smallestInRightSubTree;
        
        //case 0 - 0 children
        if (root->left == NULL && root->right==NULL)
        {
            root = NULL;
            delete delPtr;
        }
        //case 1 - 1 child
        else if (root->left==NULL && root->right != NULL)
        {
            root = root->right;
            delPtr->right = NULL;
            delete delPtr;
           // cout << "The root node with key " << rootKey << "was deleted. \n" <<
           // "The new root contains key " << root->key << endl;
        }
        else if (root->left!=NULL && root->right == NULL)
        {
            root = root->left;
            delPtr->left = NULL;
            delete delPtr;
            //cout << "The root node with key " << rootKey << "was deleted. \n" <<
            //"The new root contains key " << root->key << endl;
        }
        //case 2 - 2 children
        else
        {
            smallestInRightSubTree = FindSmallestPrivate(root->right);
            RemoveNodePrivate(smallestInRightSubTree, root);
            root->key = smallestInRightSubTree;
            //cout << "The root key " << rootKey << " was overwritten by " << smallestInRightSubTree << endl;
        }
    }
    else
        cout << "Cannot remove root! The tree is empty!\n";
}

void BST::RemoveMatch(node* parent, node* match, bool isLeft)
{
    if (root != NULL)
    {
        node* delPtr;
        int matchKey = match->key;
        int smallestInRightSubtree;
        
        //case 0 - 0 children
        if (match->left == NULL && match->right==NULL)
        {
            delPtr = match;
            isLeft == true?
            parent->left = NULL:
            parent->right = NULL;
            delete delPtr;
            //cout << "The node containing key " << matchKey << " was deleted\n";
        }
        //case 1 - 1 child
        else if (match->left==NULL && match->right!=NULL)
        {
            isLeft == true?
            parent->left = match->right:
            parent->right = match->right;
            
            match->right = NULL;
            delPtr = match;
            delete delPtr;
            //cout << "The node containing key " << matchKey << " was deleted\n";
        }
        else if (match->left!=NULL && match->right==NULL)
        {
            isLeft == true?
            parent->left = match->left:
            parent->right = match->left;
            
            match->left = NULL;
            delPtr = match;
            delete delPtr;
            //cout << "The node containing key " << matchKey << " was deleted\n";
        }
        //case 2 - 2 children
        else
        {
            smallestInRightSubtree = FindSmallestPrivate(match->right);
            RemoveNodePrivate(smallestInRightSubtree, match);
            match->key = smallestInRightSubtree;
        }
    }
    else
        cout << "Cannot remove match. Tree is empty! \n";
}
