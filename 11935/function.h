#include <cstddef>

class _node{
    public:
        int data;
        _node* next,*prev;
        _node(int d=0){data = d; next=prev=NULL;}

};
class _dequeue{
    protected:
        _node* Begin,*End;

    public:
        _dequeue(){
            Begin = new _node(0);
            End = new _node(0);
            Begin->next=End;
            End->prev=Begin;
        }
        bool Empty(){
            if(Begin==NULL || Begin->next==End) return true;
            return false;
        }
        virtual void push(const _node) = 0;
        virtual void pop() = 0;
        virtual _node* get_data() = 0;
};


class _stack : public _dequeue{
    public:
        _stack():_dequeue(){}
        void push(const _node N);
        void pop();
        _node* get_data();

};
class _queue : public _dequeue{
    public:
        _queue():_dequeue(){}
        void push(const _node N);
        void pop();
        _node* get_data();

};

void
_stack::push(const _node N)
{
    _node* ptr = new _node;
    ptr->data = N.data;
    ptr->next = Begin->next;
    ptr->next->prev = ptr; 
    ptr->prev = Begin;
    Begin->next = ptr;
}

void
_stack::pop()
{
    if(Begin->next != End)
    {
        _node* tmp = Begin->next;
        Begin->next = tmp->next;
        tmp->next->prev = Begin;
        delete tmp;
    }
}

_node* 
_stack::get_data()
{
    if(Begin->next == End) return NULL;
    return Begin->next;
}

void
_queue::push(const _node N)
{
    _node* ptr = new _node;
    ptr->data = N.data;
    ptr->next = Begin->next;
    ptr->next->prev = ptr; 
    ptr->prev = Begin;
    Begin->next = ptr;
}

void
_queue::pop()
{
    if(End->prev != Begin)
    {
        _node* tmp = End->prev;
        End->prev = tmp->prev;
        tmp->prev->next = End;
        delete tmp;
    }
}

_node* 
_queue::get_data()
{
    if(Begin->next == End) return NULL;
    return End->prev;
}
