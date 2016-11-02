/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 *
 * @author Chase Geigle
 * @date (created) Fall 2011
 * @date (modified) Spring 2012, Fall 2012
 *
 * @author Jack Toole
 * @date (modified) Fall 2011
 */

/**
 * Destroys the current List. This function should ensure that
 * memory does not leak on destruction of a list.
 */
 #include <iostream>
 using namespace std;
template <class T>
List<T>::~List()
{
    /// @todo Graded in MP3.1
    clear();
}

/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <class T>
void List<T>::clear()
{
    /// @todo Graded in MP3.1
    ListNode *x;
    x=head;

    while(x!=NULL){
        head=x->next;
        delete x;
        x=head;
    }
    tail=NULL;
    head=NULL;


}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertFront(T const& ndata)
{
    /// @todo Graded in MP3.1
    if(head==NULL && tail==NULL){ //check if list is empty
        ListNode *x = new ListNode(ndata);
        x->prev = NULL;
        x->next = NULL;
        head = x;
        tail = x;
        x=NULL;
        length++;
    }
    else{
        ListNode *x = new ListNode(ndata);
        x->prev = NULL;
        x->next = head;
        head->prev = x;
        head = x;
        x=NULL;
        length++;
    }
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertBack(const T& ndata)
{
    /// @todo Graded in MP3.1
    if(head==NULL && tail==NULL){ //check if list is empty
        ListNode *x = new ListNode(ndata);
        x->prev = NULL;
        x->next = NULL;
        head = x;
        tail = x;
        x=NULL;
        length++;
    }
    else{
        ListNode *x = new ListNode(ndata);
        x->prev=tail;
        x->next=NULL;
        tail->next=x;
        tail=x;
        x=NULL;
        length++;
    }
}

/**
 * Reverses the current List.
 */
template <class T>
void List<T>::reverse()
{
    reverse(head,tail);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <class T>
void List<T>::reverse(ListNode*& startPoint, ListNode*& endPoint)
{
    /// @todo Graded in MP3.1
    if(startPoint == NULL || endPoint == NULL || startPoint == endPoint){
        return;
    }

    ListNode* tempStart= startPoint;
    ListNode* tempEnd = endPoint;
    ListNode* tempPrev = NULL;
    ListNode* current = NULL;
    ListNode* tempNext = NULL;
    ListNode* temp2=endPoint->next;
    ListNode* temp3=startPoint->prev;
  

    current = startPoint;
    while(current!=endPoint){
        tempNext=current->next;
        current->next=current->prev;
        current->prev=tempNext;
        tempPrev=current;
        current=tempNext;
    }
    tempPrev=current->prev;
    current->next=current->prev;
    current->prev=tempPrev;

    startPoint=tempEnd;
    endPoint=tempStart;
    startPoint->prev=temp3;
    endPoint->next=temp2;

    if(temp3!=NULL)
        temp3->next=startPoint;
    if(temp2!=NULL)
        temp2->prev=endPoint;

}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <class T>
void List<T>::reverseNth(int n)
{
    /// @todo Graded in MP3.1
    if(head==NULL){
        return;
    }
    if(n>length){
        reverse(head, tail);
    }
    else{
    ListNode* temp = head;
        while(temp!=NULL){
        ListNode* end = temp;
        int counter =0;
        while(end->next!=NULL && counter<n-1){
            end=end->next;
            counter++;
        }

        ListNode* tempPrev=temp->prev;
        ListNode* tempNext=end->next;
        reverse(temp,end);
        temp->prev=tempPrev;
        end->next=tempNext;
        
        while(head->prev!=NULL){
            head=head->prev;
        }
        while(tail->next!=NULL){
            tail=tail->next;
        }
        temp=end->next;
    }
}
}

/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <class T>
void List<T>::waterfall()
{
    /// @todo Graded in MP3.1
    if(length==0 || head == NULL || tail==NULL){
        return;
    }
    ListNode* curr = head;
    ListNode* temp = head;
    while(curr->next!=tail){
    temp=curr->next;
    ListNode* tempNext = temp->next;
    ListNode* tempPrev = temp->prev;

    temp->next=NULL;
    temp->prev=tail;
    tail->next=temp;
    tail=temp;

    curr->next=tempNext;
    tempNext->prev=tempPrev;
    curr=tempNext;

}
}

/**
 * Splits the given list into two parts by dividing it at the splitPoint.
 *
 * @param splitPoint Point at which the list should be split into two.
 * @return The second list created from the split.
 */
template <class T>
List<T> List<T>::split(int splitPoint)
{
    if (splitPoint > length)
        return List<T>();

    if (splitPoint < 0)
        splitPoint = 0;

    ListNode* secondHead = split(head, splitPoint);

    int oldLength = length;
    if (secondHead == head) {
        // current list is going to be empty
        head = NULL;
        tail = NULL;
        length = 0;
    } else {
        // set up current list
        tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        length = splitPoint;
    }

    // set up the returned list
    List<T> ret;
    ret.head = secondHead;
    ret.tail = secondHead;
    if (ret.tail != NULL) {
        while (ret.tail->next != NULL)
            ret.tail = ret.tail->next;
    }
    ret.length = oldLength - splitPoint;
    return ret;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List objects!
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <class T>
typename List<T>::ListNode* List<T>::split(ListNode* start, int splitPoint)
{
    /// @todo Graded in MP3.2
    ListNode* newHead = start;
    ListNode* newTail;
    if(start!=NULL){
    for(int i=0;i<splitPoint;i++){
        if(newHead->next!=NULL)
            newHead=newHead->next;
        else 
            newHead=NULL;
    }
    if(newHead==NULL)
        return start;
    newTail=newHead->prev;
    newTail->next=NULL;
    newHead->prev=NULL;

    return newHead;

    }
    else return start;
}

/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <class T>
void List<T>::mergeWith(List<T>& otherList)
{
    // set up the current list
    head = merge(head, otherList.head);
    tail = head;

    // make sure there is a node in the new list
    if (tail != NULL) {
        while (tail->next != NULL)
            tail = tail->next;
    }
    length = length + otherList.length;

    // empty out the parameter list
    otherList.head = NULL;
    otherList.tail = NULL;
    otherList.length = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <class T>
typename List<T>::ListNode* List<T>::merge(ListNode* first, ListNode* second)
{
    /// @todo Graded in MP3.2
    ListNode* tempFirst=first;
    ListNode* tempSecond=second;
    ListNode* newHead;
    ListNode* holder;

        if((tempFirst->data)<(tempSecond->data)){
            newHead=tempFirst;
            tempFirst=tempFirst->next;
            }
        else{
            newHead=tempSecond;
            tempSecond=tempSecond->next;
            }
    
    holder=newHead;
    while (tempFirst != NULL && tempSecond != NULL ){
        if(tempFirst->data<tempSecond->data){
            holder->next=tempFirst;
            tempFirst->prev=holder;
            tempFirst=tempFirst->next;
            holder=holder->next;
        }
        else{
            holder->next=tempSecond;
            tempSecond->prev=holder;
            tempSecond=tempSecond->next;
            holder=holder->next;
        }

    }
    if(tempFirst!=NULL){
        while(tempFirst!=NULL){
            holder->next=tempFirst;
            tempFirst->prev=holder;
            tempFirst=tempFirst->next;
            holder=holder->next;
        }
    }
    if(tempSecond!=NULL){
        while(tempSecond!=NULL){
            holder->next=tempSecond;
            tempSecond->prev=holder;
            tempSecond=tempSecond->next;
            holder=holder->next;
        }
    }
return newHead;


}

/**
 * Sorts the current list by applying the Mergesort algorithm.
 */
template <class T>
void List<T>::sort()
{
    if (empty())
        return;
    head = mergesort(head, length);
    tail = head;
    while (tail->next != NULL)
        tail = tail->next;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <class T>
typename List<T>::ListNode* List<T>::mergesort(ListNode* start, int chainLength)
{
    /// @todo Graded in MP3.2
    if(chainLength<=1)
        return start;
    else{
        ListNode* mid;
        ListNode* first;
        ListNode* second;

        mid = split(start,chainLength/2);
        first=mergesort(start,chainLength/2);
        second=mergesort(mid,chainLength-chainLength/2);

        return merge(first,second);
    }
    
}
