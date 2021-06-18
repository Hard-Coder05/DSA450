#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void moveToFront(Node **head_ref)
{
    if (*head_ref == NULL || (*head_ref)->next == NULL)
        return;

    Node *previous = NULL;
    Node *current = *head_ref;

    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }

    previous->next = NULL;

    current->next = *head_ref;
    *head_ref = current;
}
