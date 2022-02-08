#include "Frankenstain_List.hpp"

int main()
{
    FrankenstainList<int>* obj = new FrankenstainList<int>();
    obj->push_front(15);
    obj->push_back(18);
    obj->push_front(12);
    obj->display();
    delete obj;
}