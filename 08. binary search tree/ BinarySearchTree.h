#include "Tree.h"

template <class K, class E>
class Dictionary {
public:
    virtual bool IsEmpty() const = 0;
    // return true iff the dictionary is empty
    virtual pair<K, E>* Get(const K&) const = 0;
    // return pointer to the pair with specified key; return 0 if no such pair
    virtual void Insert(const pair<K, E>&) = 0;
    // insert the given pair; if key is a duplicate update associated element
    virtual void Delete(const K&) = 0;
    // delete pair with specified key
};

template <class K, class E>
class BST {
public:
    virtual pair<K, E>* Get(const K& k);
    virtual pair<K, E>* GetTreeNode(TreeNode<pair<K, E> >* p, const K& k);
    virtual pair<K, E>* RankGet(int r);
    void Insert(const pair<K, E>& thePair);
    void Split(const K& k, BST<K, E>& small, pair<K, E>*& mid, BST<K, E>& big);
};

template <class K, class E>  // Driver
pair<K, E>* BST<K, E>::Get(const K& k)
{// Search the binary search tree (*this) for a pair with key k.
// If such a pair is found, return a pointer to this pair; otherwise, return 0.
    Tree<pair<K, E>> tree;
    TreeNode<pair<K, E>> root = tree.getRoot();
    return Get(root, k);
}

template <class K, class E>  // Workhorse
pair<K, E>* BST<K, E>::GetTreeNode(TreeNode<pair<K, E> >* p, const K& k)
{
    if (!p) return 0;
    if (k < p->data.first) return Get(p->leftChild, k);
    if (k > p->data.first) return Get(p->rightChild, k);
    return &p->data;
}

template <class K, class E>  // Iterative version
pair<K, E>* BST<K, E>::Get(const K& k)
{
    Tree<pair<K, E>> tree;
    TreeNode<pair<K, E>> root = tree.getRoot();
    TreeNode<pair<K, E> >* currentNode = root;
    while (currentNode) {
        if (k < currentNode->data.first)
            currentNode = currentNode->leftChild;
        else if (k > currentNode->data.first)
            currentNode = currentNode->rightChild;
        else return &currentNode->data;
    }

    // no matching pair
    return 0;
}

template <class K, class E>  // search by rank
pair<K, E>* BST<K, E>::RankGet(int r)
{// Search the binary search tree for the rth smallest pair.
    Tree<pair<K, E>> tree;
    TreeNode<pair<K, E>> root = tree.getRoot();
    TreeNode<pair<K, E> >* currentNode = root;
    while (currentNode)
        if (r < currentNode->leftSize) currentNode = currentNode->leftChild;
        else if (r > currentNode->leftSize)
        {
            r -= currentNode->leftSize;
            currentNode = currentNode->rightChild;
        }
        else return &currentNode->data;
    return 0;
}

template <class K, class E>
void BST<K, E>::Insert(const pair<K, E>& thePair)
{// Insert thePair into the binary search tree.
// search for thePair.first, pp is parent of p
    Tree<pair<K, E>> tree;
    TreeNode<pair<K, E>> root = tree.getRoot();
    TreeNode<pair<K, E> >* p = root, * pp = 0;
    while (p) {
        pp = p;
        if (thePair.first < p->data.first) p = p->leftChild;
        else if (thePair.first > p->data.first) p = p->rightChild;
        else //  duplicate, update associated element
        {
            p->data.second = thePair.second; return;
        }
    }

    // perform insertion
    p = new TreeNode<pair<K, E> >(thePair);
    Tree<pair<K, E>> tree;
    TreeNode<pair<K, E>> root = tree.getRoot();
    if (root)  // tree not empty
        if (thePair.first < pp->data.first) pp->leftChild = p;
        else pp->rightChild = p;
    else root = p;
}

template <class K, class E>
void BST<K, E>::Split(const K& k, BST<K, E>& small,
    pair<K, E>*& mid, BST<K, E>& big)
{// Split the binary search tree with respect to key k.
    Tree<pair<K, E>> tree;
    TreeNode<pair<K, E>> root = tree.getRoot();
    if (!root) { small.root = big.root = 0; return; } // empty tree
    // create header nodes for small and big
    TreeNode<pair<K, E> >* sHead = new TreeNode<pair<K, E> >,
        * s = sHead,
        * bHead = new TreeNode<pair<K, E> >,
        * b = bHead,
        * currentNode = root;
    while (currentNode)
        if (k < currentNode->data.first) {// add to big
            b->leftChild = currentNode;
            b = currentNode; currentNode = currentNode->leftChild;
        }
        else if (k > currentNode->data.first) {// add to small
            s->rightChild = currentNode;
            s = currentNode; currentNode = currentNode->rightChild;
        }
        else {// split at currentNode
            s->rightChild = currentNode->leftChild;
            b->leftChild = currentNode->rightChild;
            small.root = sHead->rightChild; delete sHead;
            big.root = bHead->leftChild; delete bHead;
            mid = new pair<K, E>(currentNode->data.first,
                currentNode->data.second);
            delete currentNode;
            return;
        }
    // no pair with key k
    s->rightChild = b->leftChild = 0;
    small.root = sHead->rightChild; delete sHead;
    big.root = bHead->leftChild; delete bHead;
    mid = 0;
    return;
}
