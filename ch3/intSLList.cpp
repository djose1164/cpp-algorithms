#include "intSLList.h"

IntSLLNode::IntSLLNode()
{
    next = nullptr;
}

IntSLLNode::IntSLLNode(int value, IntSLLNode *ptr)
{
    info = value;
    next = ptr;
}

/* IntSLList */

IntSLList::IntSLList()
{
    head = tail = nullptr;
}

int IntSLList::is_empty() const
{
    return head == nullptr;
}

IntSLList::~IntSLList()
{
    for (IntSLLNode *p; !is_empty();)
    {
        p = head->next;
        delete head;
        head = p;
    }
}

void IntSLList::add_to_head(int value)
{
    head = new IntSLLNode(value, head);
    if (tail == nullptr)
        tail = head;
}

void IntSLList::add_to_tail(int value)
{
    if (tail != nullptr) // If list not empty.
    {
        tail->next = new IntSLLNode(value);
        tail = tail->next;
    }
    else
        head = tail = new IntSLLNode(value);
}

int IntSLList::delete_from_head()
{
    auto value = head->info;
    auto temp = head;
    if (head == tail) // If only one node in the list
        head = tail = nullptr;
    else
        head = head->next;
    delete temp;
    return value;
}

int IntSLList::delete_from_tail()
{
    auto value = tail->info;
    if (head == tail) // If only one node in the list;
    {
        delete head;
        head = tail = nullptr;
    }
    else // If there are multiple nodes,
    {
        auto tmp = head;
        for (; tmp->next != tail; tmp = tmp->next)
            ; // find the predecessor to tail,
        delete tail;
        tail = tmp; // predecessor becomes tail.
        tail->next = nullptr;
    }
    return value;
}

void IntSLList::delete_node(int el)
{
    if (!head)                            // If list is empty,
        return;                           // just return.
    if (head == tail && el == head->info) // If only one node in the list;
    {
        delete head;
        head = tail = nullptr;
    }
    else if (el == head->info) // If more than one node in the list
    {
        auto tmp = head;
        head = head->next;
        delete tmp; // and old head is deleted.
    }
    else // If more than one node in the list
    {
        IntSLLNode *pred;
        IntSLLNode *tmp;
        for (pred = head, tmp = head->next;
             tmp && !(tmp->info == el);
             pred = pred->next, tmp = tmp->next)
            ;
        pred->next = tmp->next;
        if (tmp == tail)
            tail = pred;
        delete tmp; // and deleted a nonhead node.
    }
}

bool IntSLList::is_in_list(int el) const
{
    IntSLLNode *tmp;
    for (tmp = head; tmp && !(tmp->info == el); tmp = tmp->next);
    return tmp != nullptr;
}