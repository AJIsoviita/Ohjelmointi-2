#include "cards.hh"

// TODO: Implement the methods here

Cards::Cards():top_(nullptr){}

Cards::~Cards()
{
    while(top_ != nullptr)
    {
        Card_data* to_release = top_;
        top_ = top_->next;
        delete to_release;
    }
}

int Cards::recursive_print(Cards::Card_data *top, std::ostream &s, int running)
{
    if(top == nullptr)
        return 0;
    running--;
    recursive_print(top->next,s, running);
    s << running << ": " << top->data << "\n";
    return 0;
}

void Cards::add(int id)
{
    Card_data* new_item = new Card_data();
    new_item->data = id;
    new_item->next = top_;
    top_ = new_item;
}

void Cards::print_from_top_to_bottom(std::ostream &s)
{
    Card_data* item = top_;
    int running = 1;

    while(item != nullptr)
    {
        s << running << ": " << item->data << "\n";
        item = item->next;
        running++;
    }

}

bool Cards::remove(int &id)
{
    if(top_ == nullptr)
        return false;
    else if(top_->next == nullptr)
        delete top_;
    else
    {
        Card_data* second_last = top_;
        while (second_last->next->next != nullptr)
        {
            second_last = second_last->next;
            id = second_last->data;
        }
        delete (second_last->next);
        second_last->next = nullptr;
    }
    return true;
}

bool Cards::bottom_to_top()
{
    if(top_ == nullptr)
        return false;
    else
    {
        Card_data* sec_last = nullptr;
        Card_data* last = top_;
        while(last->next != nullptr)
        {
            sec_last = last;
            last = last->next;
        }
        sec_last->next=nullptr;
        last->next=top_;
        top_ = last;
    }
    return true;
}

bool Cards::top_to_bottom()
{
    if(top_ == nullptr)
        return false;
    else
    {
        Card_data* first = top_;
        Card_data* last = top_;
        while(last->next != nullptr)
            last = last->next;
        top_ = first->next;
        first->next = nullptr;
        last->next = first;
    }
    return true;
}

void Cards::print_from_bottom_to_top(std::ostream &s)
{
    if(top_ == nullptr)
        return;
    int count = 0;
    Card_data* current = top_;
    while(current != nullptr)
    {
        count++;
        current = current ->next;
    }
    int running = count;
    recursive_print(top_->next, s, running);
    s << running << ": " << top_->data << "\n";

}
