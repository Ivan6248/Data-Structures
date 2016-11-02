/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}


template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    Node* temp = t->right;
    t->right=temp->left;
    temp->left=t;
   
    t->height = max(heightOrNeg1(t->left),heightOrNeg1(t->right)) +1;
    temp->height = max(heightOrNeg1(temp->left),heightOrNeg1(temp->right)) +1;

    t=temp;
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    Node* temp = t->left;
    t->left=temp->right;
    temp->right=t;
    
    t->height = max(heightOrNeg1(t->left),heightOrNeg1(t->right)) +1;
    temp->height = max(heightOrNeg1(temp->left),heightOrNeg1(temp->right)) +1;

    t=temp;
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    // your code here

    if(subtree==NULL)
        return;

    int balance = heightOrNeg1(subtree->right)-heightOrNeg1(subtree->left);

    if(balance==-2)
    {
        int leftBalance = heightOrNeg1(subtree->left->right) - heightOrNeg1(subtree->left->left);
        if(leftBalance==-1)
        {
            rotateRight(subtree);
        }
        else
            rotateLeftRight(subtree);
    }
    else if(balance==2)
    {
        int rightBalance = heightOrNeg1(subtree->right->right)- heightOrNeg1(subtree->right->left);
        if(rightBalance==1)
            rotateLeft(subtree);
        else
            rotateRightLeft(subtree);
    }
    subtree->height = max(heightOrNeg1(subtree->left),heightOrNeg1(subtree->right)) + 1;
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    if(subtree==NULL)
    {
        subtree = new Node(key, value);
    }
    else if(key<subtree->key)
    {
        insert(subtree->left,key,value);
        rebalance(subtree);
    }
    else if(key>subtree->key)
    {
        insert(subtree->right,key,value);
        rebalance(subtree);
    }

    subtree->height = max(heightOrNeg1(subtree->left),heightOrNeg1(subtree->right))+1;
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL)
        return;

    if (key < subtree->key) {
        // your code here
        remove(subtree->left,key);
        rebalance(subtree);
    } else if (key > subtree->key) {
        // your code here
        remove(subtree->right,key);
        rebalance(subtree);
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here
            Node* temp = subtree;
            subtree=NULL;
            delete temp;
        } else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            // your code here
            Node* iop = subtree->left;
            while(iop->right!=NULL)
            {
                iop=iop->right;
            }
            swap(iop,subtree);
            if(iop->left!=NULL){
                swap(iop->left,iop);
                remove(iop,iop->left->key);
            }
            remove(subtree->left, iop->key);
            


        } else {
            /* one-child remove */
           // your code here
            Node* child = subtree;
            if(subtree->left!=NULL)
            {
                child=child->left;
                while(child->right!=NULL)
                    child=child->right;
            }
            else
                child=subtree->right;
            swap(subtree,child);
            if(child->left!=NULL){
                swap(child->left,child);
                remove(child->left,child->left->key);
            }
            else{
                if(subtree->left!=NULL)
                    remove(subtree->left,child->key);
                else
                    remove(subtree->right,child->key);
            }
            
        }
        // your code here
        
    }
}
