#pragma once

template < typename DT, typename KT >    // DT : tree item
                                      // KT : key field
class BST       
{
protected:
    class Node                  // Inner class: facilitator for the BST class
    {
    public:
        Node(const DT& nodeItem, Node* leftPtr, Node* rightPtr);     // Initialization constructor
        DT item;         // BST data item
        Node* left;    // Pointer to left child
        Node* right;   // Pointer to right child
    };

    int  getCountHelper(Node* p) const;
    void copyTree(const BST<DT, KT>& otherTree);
    void copyTreeHelper(Node*& p, const Node* otherPtr);
    void insertHelper(Node*& p, const DT& newItem);
    bool retrieveHelper(Node* p, const KT& searchKey, DT& searchItem) const;
    bool removeHelper(Node*& p, const KT& deleteKey); 
    void printKeysHelper(Node* p) const;
    void clearHelper(Node* p);
   
    Node* root;   // Pointer to root node

public:
    BST();                         // Default constructor
    BST(const BST<DT, KT>& original);   // Copy constructor
    ~BST();                   // Destructor
    BST& operator= (const BST<DT, KT>& originalTree); // Assignment operator
    void insert(const DT& newItem);  // Insert item
    bool retrieve(const KT& searchKey, DT& searchItem) const;      // Retrieve data item
    bool remove(const KT& deleteKey);            // Remove item from tree
    void printKeys() const;                      // print keys
    void clear();                                // clear tree
    bool isEmpty() const;                       // check if 
    int getCount() const;			  // Number of nodes in tree
};