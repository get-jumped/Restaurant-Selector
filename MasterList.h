#pragma once
#ifndef MASTERLIST_H
#define MASTERLIST_H

#include "FoodPlaces.h"

class MasterList
{
private:
    FoodPlaces* list;
    FoodPlaces* sitDown;
    FoodPlaces* price;
    FoodPlaces* type;
    FoodPlaces* distance;
public:
    MasterList();

    void createMaster();
    void createSitDown();
    void createPrice();
    void createType();
    void createDistance();

    void getRandomPlace();

    ~MasterList();
};

#endif