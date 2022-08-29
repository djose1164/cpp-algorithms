#ifndef CircularSLLIST_H
#define CircularSLLIST_H

template <class T>
class CircularSLLNode
{
public:
    CircularSLLNode();

    CircularSLLNode(const T &info_, CircularSLLNode *ptr = nullptr)
        : info{info_}, next{ptr}
    {
    }

    T info;
    CircularSLLNode *next;
};

template <class T>
class CircularSLList
{
public:
    CircularSLList()
        : tail{nullptr}
    {
    }

    ~CircularSLList() = default;

    bool is_empty() const;

    void add_to_head(const T &info_);

    void add_to_tail(const T &info_);

    /* Delete the head & return its info. */
    T delete_from_head();

    /* Delete the tail & return its info. */
    T delete_from_tail();

    void delete_node(const T &info_);

    bool is_in_list(const T &info_) const;

private:
    CircularSLLNode<T> *tail;
};

template <class T>
bool CircularSLList<T>::is_empty() const
{
    return tail == nullptr;
}

template <class T>
void CircularSLList<T>::add_to_head(const T &info_)
{
    if (is_empty()) // If list is empty,
    {
        tail = new CircularSLLNode<T>(info_); // create a new node
        tail->next = tail;                    // and set it to point to itself.
    }
    else // If one o more nodes in the list;
        tail->next = new CircularSLLNode<T>(info_, tail->next);
}

template <class T>
void CircularSLList<T>::add_to_tail(const T &info_)
{
    if (is_empty())
    {
        tail = new CircularSLLNode<T>(info_);
        tail->next = tail;
    }
    else
    {
        tail->next = new CircularSLLNode<T>(info_, tail->next);
        tail = tail->next;
    }
}

template <class T>
T CircularSLList<T>::delete_from_head()
{
    auto el = tail->next->info;

    if (tail == tail->next) // if only one node in the list;
    {
        delete tail;
        tail = nullptr;
    }
    else // If more than one node in the list;
    {
        auto tmp = tail->next;
        tail->next = tail->next->next;
        delete tmp;
    }

    return el;
}

template <class T>
T CircularSLList<T>::delete_from_tail()
{
    auto el = tail->info;
    if (tail == tail->next) // If only one node in the list;
    {
        delete tail;
        tail = nullptr;
    }
    else // If more than one node in the list;
    {
        CircularSLLNode<T> *prev{tail->next};
        CircularSLLNode<T> *tmp{prev->next};

        for (; tmp != tail; prev = prev->next, tmp = tmp->next)
            ;
        prev->next = tail->next;
        tail = prev;
        delete tmp;
    }
    return el;
}

template <class T>
void CircularSLList<T>::delete_node(const T &info_)
{
    if (tail->next == tail && tail->info == info_)
    {
        delete tail;
        tail = nullptr;
    }
    else if (tail->next->info == info_) // If node is head
    {
        auto head = tail->next;
        tail->next = head->next;
        delete head;
    }
    else
    {
        CircularSLLNode<T> *prev;
        CircularSLLNode<T> *tmp;

        for (prev = tail->next, tmp = tail->next->next;
             tmp != tail;
             prev = prev->next, tmp = tmp->next)
            ;
        prev->next = tmp->next;
        delete tmp;
    }
}

template <class T>
bool CircularSLList<T>::is_in_list(const T &info_) const
{
    auto tmp = tail->next;
    for (; tmp && !(tmp->info == info_); tmp = tmp->next)
        ;

    return tmp != nullptr;
}

#endif // CircularSLLIST_H
