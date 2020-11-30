#include "LinkedList.h"

LinkedList::LinkedList()
{
    head = nullptr;
}

void LinkedList::set_head(Node* n)
{
    this->head = n;
}

Node* LinkedList::get_head()
{
    return this->head;
}

bool LinkedList::is_empty()
{
    return get_head() == nullptr;
}

void LinkedList::add_data(NoodleReview* nr)
{
    // if the linked list is empty, set the node as the head
    if (is_empty())
        set_head(new Node(nr));
    else
    {
        // otherwise create a dummy node to traverse to the end of the linked list
        Node* current = get_head();
        while (current->get_next_node() != nullptr)
            current = current->get_next_node();

        // add the node to the end of the linked list
        current->set_next_node(new Node(nr));
    }
}