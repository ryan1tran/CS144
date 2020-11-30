#include "Node.h"

Node::Node()
{
    nr = nullptr;
    next = nullptr;
}

Node::Node(NoodleReview* record)
{
    nr = record;
    next = nullptr;
}

void Node::set_next_node(Node* new_node)
{
    this->next = new_node;
}

Node* Node::get_next_node()
{
    return this->next;
}

void Node::set_data(NoodleReview* new_review)
{
    this->nr = new_review;
}

NoodleReview* Node::get_data()
{
    return this->nr;
}
