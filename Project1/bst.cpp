#include "bst.h"

template < typename DT, typename KT >
BST<DT, KT> ::Node::Node(const DT& nodeItem, Node* leftPtr, Node* rightPtr)
    : item(nodeItem), left(leftPtr), right(rightPtr)
{}


template < typename DT, typename KT >
BST<DT, KT> ::BST()
    : root(0)
{}


template < typename DT, typename KT >
BST<DT, KT> ::BST(const BST<DT, KT>& original)
    : root(0)
{
    copyTree(original);
}


template < typename DT, typename KT >
BST<DT, KT>:: ~BST()
{
    clear();
}


template < typename DT, typename KT >
BST<DT, KT>& BST<DT, KT> ::operator= (const BST<DT, KT>& originalTree)
{
    if (this != &originalTree)
    {
        clear();
        copyTree(originalTree);
    }
   
        return *this;
}


template < typename DT, typename KT >
void BST<DT, KT>::copyTree(const BST<DT, KT>& otherTree)
{
    copyTreeHelper(root, otherTree.root);
}


template < typename DT, typename KT >
void BST<DT, KT>::copyTreeHelper(Node*& p, const Node* otherPtr)
{
    if (p != 0) {
        p = new BST<DT,KT>(otherPtr->item, 0, 0);
        copyTreeHelper(p->left, otherPtr->left);
        copyTreeHelper(p->right, otherPtr->right);
    }
}


template < typename DT, typename KT >
void BST<DT, KT>::clear()
{
    clearHelper(root);
    root = 0;
}


template < typename DT, typename KT >
void BST<DT, KT>::clearHelper(Node* p)
{
    if (p != 0)
    {
        clearHelper(p->left);
        clearHelper(p->right);
        delete p;
    }
}


template < typename DT, typename KT >
int BST<DT, KT>::getCount() const
{
    return getCountHelper(root);
}


template < typename DT, typename KT >
bool BST<DT, KT>::isEmpty() const
{
    return root == 0;
}


template < typename DT, typename KT >
int BST<DT, KT>::getCountHelper(Node* p) const
{
    int result;

    if (p == 0)
        result = 0;

    else
        result = getCountHelper(p->left) + getCountHelper(p->right) + 1;

    return result;
}


template < typename DT, typename KT >
void BST<DT, KT>::insert(const DT& newItem)
{
    insertHelper(root, newItem);
}


template < typename DT, typename KT >
void BST<DT, KT>::insertHelper(Node*& p, const DT& newItem)
{
    if (p == 0)
        p = new Node<DT,KT>(newItem, 0, 0);

    else if (newItem.getKey() < p->item.getKey())
        insertHelper(p->left, newItem);    

    else if (newItem.getKey() > p->item.getKey())
        insertHelper(p->right, newItem);   

    else
        p->item = newItem;                        
}


template < typename DT, typename KT >
bool BST<DT, KT>::retrieve(const KT& searchKey, DT& searchItem) const
{
    return retrieveHelper(root, searchKey, searchItem);
}


template < typename DT, typename KT >
bool BST<DT, KT>::retrieveHelper(Node* p, const KT& searchKey, DT& searchItem) const
{
    bool result;  

    if (p == 0)
        result = false;
    
    else if (searchKey < p->item.getKey())
        result = retrieveHelper(p->left, searchKey, searchItem);
    
    else if (searchKey > p->item.getKey())
        result = retrieveHelper(p->right, searchKey, searchItem);
    
    else
    {
        searchItem = p->item;
        result = true;
    }

    return result;
}


template < typename DT, typename KT >
bool BST<DT, KT>::remove(const KT& deleteKey)
{
    return removeHelper(root, deleteKey);
}


template < typename DT, typename KT >
bool BST<DT, KT>::removeHelper(Node*& p, const KT& deleteKey)
{
    Node* delPtr;  
    bool result;                 

    if (p == 0)
        result = false;                          

    else if (deleteKey < p->item.getKey())
        result = removeHelper(p->left, deleteKey);    

    else if (deleteKey > p->item.getKey())
        result = removeHelper(p->right, deleteKey);   

    else
    {                                       
        delPtr = p;
        if (p->left == 0)
        {
            p = p->right;                    
            delete delPtr;
        }

        else if (p->right == 0)
        {
            p = p->left;                     
            delete delPtr;
        }

        else
        {
            Node* temp = p->left;
            while (temp->right) 
                temp = temp->right;
           
            p->item = temp->item;
 
            removeHelper(p->left, temp->item.getKey());
        }

        result = true;
    }

    return result;
}


template < typename DT, typename KT >
void BST<DT, KT>::printKeys() const
{
    printKeysHelper(root);
    cout << endl;
}


template < typename DT, typename KT >
void BST<DT, KT>::printKeysHelper(Node* p) const
{
    if (p != 0)
    {
        printKeysHelper(p->left);
        cout << p->item.getKey() << " ";
        printKeysHelper(p->right);
    }
}