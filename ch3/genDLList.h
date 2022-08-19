/* Singly linked list class to store ints */

#ifndef GENDLLIST_H
#define GENDLLIST_H

template <class T>
class DLLNode
{
public:
    DLLNode();

    DLLNode(T info_, DLLNode *prev_ = nullptr, DLLNode *next_ = nullptr)
    : info{info_}
    , prev{prev_}
    , next{next_}
    {}

    T info;
    DLLNode *prev;
    DLLNode *next;
};

template <class T>
class GenDLList
{
public:
    GenDLList();

    bool is_empty() const;

    void add_to_head(const T &info_);

    void add_to_tail(const T &info_);

    /* Delete the head & return its info. */
    int delete_from_head();

    /* Delete the tail & return its info. */
    int delete_from_tail();

    void delete_node(const T &info_);

    bool is_in_list(const T &info_) const;

protected:
    DLLNode<T> *head;
    DLLNode<T> *tail;
};

template<class T>
DLLNode<T>::DLLNode()
    : prev{nullptr}
    , next{nullptr}
{}

template<class T>
GenDLList<T>::GenDLList()
    : head{nullptr}
    , tail{nullptr}
{}

template<class T>
bool GenDLList<T>::is_empty() const
{
    return head == nullptr;
}

template<class T>
void GenDLList<T>::add_to_head(const T &info_)
{
    if (head)
    {
        head = new DLLNode<T>(info_, nullptr, head);
        head->next->prev = head;
    }
    else
        head = tail = new DLLNode<T>(info_);
}

template<class T>
void GenDLList<T>::add_to_tail(const T &info_)
{
    if (head)
    {
        tail = new DLLNode<T>(info_, tail, nullptr);
        tail->prev->next = tail;
    }
    else
        head = tail = new DLLNode<T>(info_);
}

template<class T>
int GenDLList<T>::delete_from_head()
{
    auto el = head->info;
    if (head == tail) // If only one node in the list;
    {
        delete head;
        head = tail = nullptr;
    }
    else // If more than one node in the list;
    {
        head = head->next;
        delete head->prev;
        head->prev =  nullptr;
    }
    return el;
}

template<class T>
int GenDLList<T>::delete_from_tail()
{
    auto el = tail->info;
    if (head == tail) // If only one node in the list;
    {
        delete head;
        head = tail = nullptr;
    }
    else // If more than one node in the list;
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }
    return el;
}

template<class T>
void GenDLList<T>::delete_node(const T &info_)
{
    if (head == tail && info_ == head->info) // If only one node in the list;
    {
        delete head;
        head = tail = nullptr;
    }
    else if (info_ == head->info) // If only one node in the list
    {
        auto tmp = head;
        head = head->next;
        delete tmp; // and old head is deleted.
        head->prev = nullptr;
    }
    else
    {
        DLLNode<T> *tmp = head;
        for (; tmp && !(tmp->info == info_); tmp = tmp->next);
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        delete tmp;
    }
}

template<class T>
bool GenDLList<T>::is_in_list(const T &info_) const
{
    auto tmp = head;
    for (; tmp && !(tmp->info == info_); tmp = tmp->next);
    return tmp != nullptr;
}

#endif // GENDLLIST_H
