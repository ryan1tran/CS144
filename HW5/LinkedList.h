#ifdef __cplusplus
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"

class LinkedList
{
    private:
        Node* head;

    public:
        LinkedList();
        void set_head(Node* n);
        Node* get_head();
        bool is_empty();
        void add_data(NoodleReview* nr);
};

#endif
#endif
