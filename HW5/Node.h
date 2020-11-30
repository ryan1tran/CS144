#ifdef __cplusplus
#ifndef NODE_H
#define NODE_H

#include "NoodleReview.h"

class Node
{
    private:
        NoodleReview* nr;
        Node* next;

    public:
        Node();
        Node(NoodleReview* record); // additional constructor to initialize with a NoodleReview*
        void set_next_node(Node* new_node);
        Node* get_next_node();
        void set_data(NoodleReview* new_review);
        NoodleReview* get_data();
};

#endif
#endif
