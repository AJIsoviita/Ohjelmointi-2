#include "queue.hh"
#include <iostream>

// Implement the member functions of Queue here

Queue::Queue(unsigned int cycle)
{
    cycle_ = cycle;
}

Queue::~Queue()
{
    while (first_ != nullptr)
    {
        Vehicle* remove = first_;
        first_ = first_->next;
        delete remove;
    }
}

void Queue::enqueue(string reg)
{
    Vehicle* queue = new Vehicle{reg, nullptr};
    if(is_green_ == true)
        cout << "GREEN: The vehicle " << reg << " need not stop to wait" << endl;
    else if(first_ == nullptr)
    {
        first_ = queue;
        last_ = queue;
    }
    else
    {
        last_->next = queue;
        last_ = queue;
    }
}

void Queue::switch_light()
{
    if(is_green_ == true)
        is_green_ = false;
    else
        is_green_ = true;

    if ( first_ == nullptr )
    {
       if(is_green_ == true)
        cout << "GREEN: No vehicles waiting in traffic lights" << endl;
       else
           cout<<"RED: No vehicles waiting in traffic lights" << endl;
    }
    else
    {
        cout << "GREEN: Vehicle(s) ";
        Vehicle* printing = first_;
        unsigned int count = 1;
        if(printing->next == nullptr)
        {
            cout << printing->reg_num << " ";
            first_ = nullptr;
            delete first_;
            is_green_ = false;
        }
        else
        {
            while(count <= cycle_)
            {
                cout << printing->reg_num << " ";
                printing = printing->next;
                count++;
            }

            unsigned int amount = 1;

                while(amount <= cycle_)
                {
                    Vehicle* item_to_be_removed = first_;
                    if ( first_ == last_ )
                    {
                       first_ = nullptr;
                       last_ = nullptr;
                       break;
                    }
                    else
                       first_ = first_->next;
                    delete item_to_be_removed;
                    amount++;
                }
                is_green_ = false;
        }
        cout << "can go on" << endl;
    }


}

void Queue::reset_cycle(unsigned int cycle)
{
    cycle_ = cycle;
}

void Queue::print()
{
    if(!is_green_)
    {

        if(first_ == nullptr)
        {
            cout << "RED: No Vehicles waiting in traffic lights" << endl;
        }
        else
        {
            cout << "RED: Vehicle(s) ";
            Vehicle* printing = first_;
            while(printing != nullptr)
            {
                cout << printing->reg_num << " ";
                printing = printing->next;
            }
            cout << "waiting in traffic lights" << endl;
        }
    }
    else
    {

        if(first_ == nullptr)
        {
            cout << "GREEN: No Vehicles waiting in traffic lights" << endl;
        }
        else
        {
            cout << "GREEN: Vehicle(s) ";
            Vehicle* printing = first_;
            while(printing != nullptr)
            {
                cout << printing->reg_num << " ";
                printing = printing->next;
            }
            cout << "waiting in traffic lights" << endl;
        }
    }
}
