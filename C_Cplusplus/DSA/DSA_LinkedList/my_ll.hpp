#include <iostream>

template <typename T>
class NodeLL
{
private:
    T data_;
    NodeLL<T> *p_next_;

public:
    NodeLL() : p_next_(NULL){};
    ~NodeLL(){};

    void set_data(T data) { data_ = data; }
    void set_next(NodeLL<T> *next) { p_next_ = next; }
    T get_data() const { return data_; }
    NodeLL<T> *get_next() const { return p_next_; }
};

template <typename T>
class LinkedList
{
private:
    NodeLL<T> *p_head_, *p_tail_;

public:
    LinkedList()
    {
        p_head_ = NULL;
        p_tail_ = NULL;
    }
    ~LinkedList(){};

    void Insert_Start(T val)
    {
        NodeLL<T> *temp = new NodeLL<T>;
        temp->set_data(val);
        temp->set_next(p_head_);
        p_head_ = temp;
    }

    void Create_Node(T val)
    {
        NodeLL<T> *temp = new NodeLL<T>;
        temp->set_data(val);
        temp->set_next(NULL);
        if (p_head_ == NULL)
        {
            p_head_ = temp;
            p_tail_ = temp;
            temp = NULL;
        }
        else
        {
            p_tail_->set_next(temp);
            p_tail_ = temp;
        }
    }

    void Insert_Position(int pos, T val)
    {
        NodeLL<T> *temp = new NodeLL<T>;
        NodeLL<T> *cur = p_head_;
        NodeLL<T> *pre = cur;
        for (int i = 1; i < pos; i++)
        {
            pre = cur;
            cur = cur->get_next();
        }
        temp->set_data(val);
        pre->set_next(temp);
        temp->set_next(cur);
    }

    void Delete_Start(void)
    {
        if (p_head_ != NULL)
        {
            NodeLL<T> *temp = p_head_;
            p_head_ = p_head_->get_next();
            delete temp;
        }
    }

    void Delete_End(void)
    {
        NodeLL<T> *cur = p_head_;
        NodeLL<T> *pre = cur;
        while (cur->get_next() != NULL)
        {
            pre = cur;
            cur = cur->get_next();
        }
        p_tail_ = pre;
        pre->set_next(NULL);
        delete cur;
    }

    void Delete_Position(int pos)
    {
        NodeLL<T> *cur = p_head_;
        NodeLL<T> *pre = cur;
        for (int i = 1; i < pos; i++)
        {
            pre = cur;
            cur = cur->get_next();
        }
        pre->set_next(cur->get_next());
        delete cur;
    }

    NodeLL<T> *get_head(void)
    {
        return p_head_;
    }
};
