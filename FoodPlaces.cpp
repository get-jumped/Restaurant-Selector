#include "FoodPlaces.h"
#include <fstream>
#include <string>

using namespace std;

FoodPlaces::FoodPlaces()
{
    head = nullptr;
    tail = nullptr;
    sitDown = nullptr;
    price = nullptr;
    type = nullptr;
    distance = nullptr;
    size = 0;
    typeSize = 0;
}

int FoodPlaces::getSize()
{
    return size;
}

void FoodPlaces::setUpList()
{
    ifstream inFile;
    if(openFile(inFile))
    {
        string temp;
        getline(inFile, temp);
        
        string n;
        bool s;
        string p;
        string t;
        int d;
        Place * next;

        while(!inFile.eof())
        {
            getline(inFile, temp, '|');
            n = trim(temp);

            getline(inFile, temp, '|');
            temp = trim(temp);
            temp = temp.substr(1, temp.length()-1);
            if(temp == "YES")
            {
                s = true;
            }
            else
            {
                s = false;
            }

            getline(inFile, temp, '|');
            p = trim(temp);
            p = p.substr(1, p.length() - 1);

            getline(inFile, temp, '|');
            //cout << t << "|" << endl;
            t = trim(temp);
            //cout << t << "|" << endl;
            t = t.substr(1, t.length() - 1);
            //cout << t << "|" << endl;

            getline(inFile, temp);
            temp = trim(temp);
            temp = temp.substr(1, temp.length());
            if(temp == "Close")
                d = 1;
            else if(temp == "Mid")
                d = 2;
            else  
                d = 3;

            add(n, s, p, t, d);
        }
    }
}

bool FoodPlaces::openFile(ifstream& infile)
{
    infile.open("Food Places.txt");

    if(infile)
        return true;
    else
        return false;
}

string FoodPlaces::trim(string key)
{
    for(int i = key.length() - 1; i > 0; i--)
    {
        if(key.at(i) != ' ')
        {
            return key.substr(0, i + 1);
        }
    }

    return nullptr;
}

void FoodPlaces::add(string n, bool s, string p, string t, int d)
{
    Place* node = new Place(n, s, p, t, d);
    if(head == nullptr && tail == nullptr)
    {
        head = node;
        tail = node;
    }
    else if(head == tail)
    {
        head->setNext(node);
        tail = node;
    }
    else
    {
        tail->setNext(node);
        tail = node;
    }
    size++;
}

void FoodPlaces::add(Place* node)
{
    Place* hold = new Place(*node);
    if(head == nullptr && tail == nullptr)
    {
        head = hold;
        tail = hold;
    }
    else if(head == tail)
    {
        head->setNext(hold);
        tail = hold;
    }
    else
    {
        tail->setNext(hold);
        tail = hold;
    }
    size++;
}

Place& FoodPlaces::findNode(int index)
{
    Place* temp = head;

    while(temp != nullptr && index != 0)
    {
        temp = temp->getNext();
        index--;
    }

    temp->print();
    return *temp;
}

void FoodPlaces::makeSorted()
{
    if(head != nullptr)
    {
        makeSitDown();
        makePrice();
        makeType();
        makeDistance();
    }
}

void FoodPlaces::makeSitDown()
{
    sitDown = new FoodPlaces*[2];
    sitDown[0] = new FoodPlaces();
    sitDown[1] = new FoodPlaces();

    Place* transverse = head;
    Place* temp;

    while(transverse != nullptr)
    {
        cout << "ENTERED SITDOWN" << endl;
        if(transverse->getSitDown() == false)
        {
            sitDown[0]->add(transverse);
        }
        else
        {
            sitDown[1]->add(transverse);
        }
        transverse = transverse->getNext();
    }
}

void FoodPlaces::makePrice()
{
    price = new FoodPlaces*[3];
    price[0] = new FoodPlaces();
    price[1] = new FoodPlaces();
    price[2] = new FoodPlaces();

    Place* transverse = head;
    Place* temp;

    while(transverse != nullptr)
    {
        if(transverse->getPrice() == "$")
        {
            price[0]->add(transverse);
        }
        else if(transverse->getPrice() == "$$")
        {
            price[1]->add(transverse);
        }
        else
        {
            price[2]->add(transverse);
        }
        transverse = transverse->getNext();
    }
}

void FoodPlaces::makeType()
{
    vector<string> cuisine;

    string save;

    if(head != nullptr)
    {
        cuisine.push_back(head->getType());
    }

    Place* transverse = head->getNext();
    Place* temp;
    bool first = true;

    while(transverse != nullptr)
    {
        save = transverse->getType();
        for(int i = 0; i < cuisine.size(); i++)
        {
            if(save == cuisine[i])
            {
                first = false;
            }
        }
        if(first)
        {
            cuisine.push_back(transverse->getType());
        }
        first = true;
        transverse = transverse->getNext();
    }

    type = new FoodPlaces*[cuisine.size()];
    typeSize = cuisine.size();
    transverse = head;

    for(int i = 0; i < cuisine.size(); i++)
    {
        type[i] = new FoodPlaces();
    }

    while(transverse != nullptr)
    {
        for(int i = 0; i < cuisine.size(); i++)
        {
            if(transverse->getType() == cuisine[i])
            {
                type[i]->add(transverse);
                i = cuisine.size();
            }
        }
        transverse = transverse->getNext();
    }
}

void FoodPlaces::makeDistance()
{
    distance = new FoodPlaces*[3];
    distance[0] = new FoodPlaces();
    distance[1] = new FoodPlaces();
    distance[2] = new FoodPlaces();

    if(head != nullptr)
    {
        Place* transverse = head;
        Place* temp;

        while(transverse != nullptr)
        {
            if(transverse->getDistance() == 1)
            {
                distance[0]->add(transverse);
            }
            else if(transverse->getDistance() == 2)
            {
                distance[1]->add(transverse);
            }
            else
            {
                distance[2]->add(transverse);
            }
            transverse = transverse->getNext();
        }
    }
}

void FoodPlaces::print()
{
    Place* temp = head;
    while(temp != nullptr)
    {
        temp->print();
        temp = temp->getNext();
    }
}

FoodPlaces::~FoodPlaces()
{
    Place* temp;
    Place* trail;

    if(head != nullptr)
    {
        temp = head;

        while(temp != nullptr)
        {
            trail = temp->getNext();
            delete temp;
            temp = trail;
        }
    }

    FoodPlaces * save;

    if(sitDown != nullptr)
    {
        delete sitDown[0];
        delete sitDown[1];
        delete [] sitDown;
    }

    if(price != nullptr)
    {
        delete price[0];
        delete price[1];
        delete price[2];
        delete [] price;
    }

    if(type != nullptr)
    {
        for(int i = 0; i < typeSize; i++)
        {
            delete type[i];
        }
        
        delete [] type;
    }

    if(distance != nullptr)
    {
        delete distance[0];
        delete distance[1];
        delete distance[2];
        delete [] distance;
    }
}