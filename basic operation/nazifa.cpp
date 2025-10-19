#include <bits/stdc++.h>
using namespace std;

// Definition of a node
struct Node
{
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// 1️⃣ Insert at beginning
void insertAtBeginning(Node*& head, int val)
{
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// 2️⃣ Insert at end
void insertAtEnd(Node*& head, int val)
{
    Node* newNode = new Node(val);
    if (!head)
    {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

// 3️⃣ Insert at specific position (1-based index)
void insertAtPosition(Node*& head, int val, int pos)
{
    if (pos <= 0)
    {
        cout << "Invalid position!\n";
        return;
    }
    if (pos == 1)
    {
        insertAtBeginning(head, val);
        return;
    }

    Node* temp = head;
    for (int i = 1; temp && i < pos - 1; i++)
        temp = temp->next;

    if (!temp)
    {
        cout << "Position out of range!\n";
        return;
    }

    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

// 4️⃣ Delete from beginning
void deleteFromBeginning(Node*& head)
{
    if (!head)
    {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

// 5️⃣ Delete from end
void deleteFromEnd(Node*& head)
{
    if (!head)
    {
        cout << "List is empty!\n";
        return;
    }
    if (!head->next)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next)
        temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

// 6️⃣ Delete by value
void deleteByValue(Node*& head, int val)
{
    if (!head)
    {
        cout << "List is empty!\n";
        return;
    }

    if (head->data == val)
    {
        deleteFromBeginning(head);
        return;
    }

    Node* temp = head;
    while (temp->next && temp->next->data != val)
        temp = temp->next;

    if (!temp->next)
    {
        cout << "Value not found!\n";
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

// 7️⃣ Search for a value
bool search(Node* head, int val)
{
    Node* temp = head;
    while (temp)
    {
        if (temp->data == val)
            return true;
        temp = temp->next;
    }
    return false;
}

// 8️⃣ Count nodes
int countNodes(Node* head)
{
    int count = 0;
    Node* temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// 9️⃣ Display the list
void display(Node* head)
{
    if (!head)
    {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// 🔟 Main function to test all operations
int main()
{
    Node* head = nullptr;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    display(head); // 10 20 30

    insertAtBeginning(head, 5);
    display(head); // 5 10 20 30

    insertAtPosition(head, 15, 3);
    display(head); // 5 10 15 20 30

    deleteFromBeginning(head);
    display(head); // 10 15 20 30

    deleteFromEnd(head);
    display(head); // 10 15 20

    deleteByValue(head, 15);
    display(head); // 10 20

    cout << "Search 20: " << (search(head, 20) ? "Found" : "Not Found") << endl;
    cout << "Node Count: " << countNodes(head) << endl;

    return 0;
}
