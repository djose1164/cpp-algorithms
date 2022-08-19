/* Singly linked list class to store ints */

#ifndef INTSLLIST_H
#define INTSLLIST_H

class IntSLLNode
{
public:
    IntSLLNode();

    IntSLLNode(int value, IntSLLNode *ptr = nullptr);

    int info;
    IntSLLNode *next;
};

class IntSLList
{
public:
    IntSLList();

    ~IntSLList();

    int is_empty() const;

    void add_to_head(int value);

    void add_to_tail(int value);

    /* Delete the head & return its info. */
    int delete_from_head();

    /* Delete the tail & return its info. */
    int delete_from_tail();

    void delete_node(int node_value);

    bool is_in_list(int node_value) const;

private:
    IntSLLNode *head;
    IntSLLNode *tail;
};

#endif // INTSLLIST_H
