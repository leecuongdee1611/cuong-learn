#include "my_ll.hpp"
using namespace std;

class Person
{
private:
    std::string name_;
    unsigned int age_;
    bool sex_;

public:
    Person(){};
    Person(std::string name, unsigned int age, bool sex);
    ~Person(){};
    void ShowInfo(void);
};
Person::Person(std::string name, unsigned int age, bool sex)
{
    name_ = name;
    age_ = age;
    sex_ = sex;
}
void Person::ShowInfo(void)
{
    std::cout << "\tName: " << name_;
    std::cout << ", Age: " << age_;
    std::cout << ", Sex: " << ((sex_ == 1) ? "Man" : "Woman");
    std::cout << std::endl;
}

void ShowAll(LinkedList<Person> obj)
{
    NodeLL<Person> *temp = obj.get_head();
    while (temp != NULL)
    {
        Person per = temp->get_data();
        per.ShowInfo();
        temp = temp->get_next();
    }
}

int main(void)
{
    Person me("Le Hung Cuong", 1995, 1);
    Person mommy("Vu Thi Tinh", 1968, 0);
    Person daddy("Le Xuan Truong", 1968, 1);
    Person sister("Le Thi Quynh Nga", 1998, 0);
    Person f1("Do Bao Anh", 1993, 1);
    Person f2("Do Thi Tam", 1996, 0);

    LinkedList<Person> obj;
    obj.Create_Node(me);
    obj.Create_Node(mommy);
    obj.Create_Node(daddy);

    /* Show all element */
    cout << "\n--------------------------------------------------\n";
    cout << "---------------Displaying All nodes---------------";
    cout << "\n--------------------------------------------------\n";
    ShowAll(obj);

    cout << "\n--------------------------------------------------\n";
    cout << "----------------Inserting At Start----------------";
    cout << "\n--------------------------------------------------\n";
    obj.Insert_Start(sister);
    ShowAll(obj);

    cout << "\n--------------------------------------------------\n";
    cout << "----------------Deleting At Start-----------------";
    cout << "\n--------------------------------------------------\n";
    obj.Delete_Start();
    ShowAll(obj);

    cout << "\n--------------------------------------------------\n";
    cout << "-----------------Inserting At End-----------------";
    cout << "\n--------------------------------------------------\n";
    obj.Create_Node(f1);
    ShowAll(obj);

    cout << "\n--------------------------------------------------\n";
    cout << "-------------Inserting At Particular--------------";
    cout << "\n--------------------------------------------------\n";
    obj.Insert_Position(2, f2);
    ShowAll(obj);

    cout << "\n--------------------------------------------------\n";
    cout << "-----------------Deleing At End-------------------";
    cout << "\n--------------------------------------------------\n";
    obj.Delete_End();
    ShowAll(obj);

    cout << "\n--------------------------------------------------\n";
    cout << "--------------Deleting At Particular--------------";
    cout << "\n--------------------------------------------------\n";
    obj.Delete_Position(2);
    ShowAll(obj);

    cout << "\n--------------------------------------------------\n";
    return 0;
}