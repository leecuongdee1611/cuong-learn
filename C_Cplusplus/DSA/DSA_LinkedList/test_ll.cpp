#include <iostream>
using namespace std;

/* Define a single node 
    - At least one data section and a pointer for the next node
*/
struct node
{
    int data;
    node *next;
};

/* Class for handle the nodes
    - It should be have 2 important pointer: head and tail
*/
class list
{
private:
    node *head, *tail;

public:
    list()
    {
        head = NULL;
        tail = NULL;
    }
    void createNode(int value)
    {
        node *temp = new node;
        temp->data = value;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    void display()
    {
        node *temp = new node;
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
    void insert_start(int value)
    {
        node *temp = new node;
        temp->data = value;
        temp->next = head;
        head = temp;
    }
    void insert_position(int pos, int value)
    {
        node *pre = new node;
        node *cur = new node;
        node *temp = new node;
        cur = head;
        for (int i = 1; i < pos; i++)
        {
            pre = cur;
            cur = cur->next;
        }
        temp->data = value;
        pre->next = temp;
        temp->next = cur;
    }
    void delete_first()
    {
        node *temp = new node;
        temp = head;
        head = head->next;
        delete temp;
    }
    void delete_last()
    {
        node *pre = new node;
        node *cur = new node;
        cur = head;
        while (cur->next != NULL)
        {
            pre = cur;
            cur = cur->next;
        }
        tail = pre;
        pre->next = NULL;
        delete cur;
    }
    void delete_position(int pos)
    {
        node *pre = new node;
        node *cur = new node;
        cur = head;
        for (int i = 1; i < pos; i++)
        {
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
    }
};

int main(void)
{
    cout << "Test singly linked list" << endl;

    list obj;
    obj.createNode(25);
    obj.createNode(50);
    obj.createNode(90);
    obj.createNode(40);
    cout << "\n--------------------------------------------------\n";
    cout << "---------------Displaying All nodes---------------";
    cout << "\n--------------------------------------------------\n";
    obj.display();
    cout << "\n--------------------------------------------------\n";
    cout << "-----------------Inserting At End-----------------";
    cout << "\n--------------------------------------------------\n";
    obj.createNode(100);
    obj.display();
    cout << "\n--------------------------------------------------\n";
    cout << "----------------Inserting At Start----------------";
    cout << "\n--------------------------------------------------\n";
    obj.insert_start(10);
    obj.display();
    cout << "\n--------------------------------------------------\n";
    cout << "-------------Inserting At Particular--------------";
    cout << "\n--------------------------------------------------\n";
    obj.insert_position(5, 200);
    obj.display();
    cout << "\n--------------------------------------------------\n";
    cout << "----------------Deleting At Start-----------------";
    cout << "\n--------------------------------------------------\n";
    obj.delete_first();
    obj.display();
    cout << "\n--------------------------------------------------\n";
    cout << "-----------------Deleing At End-------------------";
    cout << "\n--------------------------------------------------\n";
    obj.delete_last();
    obj.display();
    cout << "\n--------------------------------------------------\n";
    cout << "--------------Deleting At Particular--------------";
    cout << "\n--------------------------------------------------\n";
    obj.delete_position(6);
    obj.display();
    cout<<"\n--------------------------------------------------\n";
	system("pause");

    return 0;
}
