#include "MasterList.h"
#include <iostream>

using namespace std;

MasterList::MasterList()
{
    list = new FoodPlaces();
}

void MasterList::createMaster()
{
    list->setUpList();
}
//have to make the other lists double pointers
void MasterList::createSitDown()
{

}

void MasterList::createPrice()
{

}

void MasterList::createType()
{

}

void MasterList::createDistance()
{

}

void MasterList::getRandomPlace()
{

}

MasterList::~MasterList()
{
    if(list != nullptr)
    {
        delete list;
    }
}