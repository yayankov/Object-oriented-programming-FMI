#include "store.h"
#include<iostream>
#include<cstring>

using namespace std;

Laptop::Laptop()
{
    setSKU("unknown");
    setBrand("unknown");
    setModel("unknown");
    setCategory("unknown");
    setPrice(0);
    cnt++;
}

Laptop::Laptop(const Laptop& laptop)
{
    setSKU(laptop.getSKU());
    setBrand(laptop.getBrand());
    setModel(laptop.getModel());
    setCategory(laptop.getCategory());
    setPrice(laptop.getPrice());
    cnt++;
}

Laptop& Laptop::operator=(const Laptop& laptop)
{
    if(this != &laptop)
    {
        setSKU(laptop.getSKU());
        setBrand(laptop.getBrand());
        setModel(laptop.getModel());
        setCategory(laptop.getCategory());
        setPrice(laptop.getPrice());
    }

    return *this;
}

bool Laptop::operator==(const Laptop& laptop) const
{
    if(this->SKU == laptop.SKU && this->brand == laptop.brand && this->model == laptop.model && this->category == laptop.category && this->price == laptop.price)
    {
        return true;
    }
    return false;
}

Laptop::~Laptop()
{
    delete[] this->SKU;
    delete[] this->brand;
    delete[] this->model;
    delete[] this->category;
    cnt--;
}

Laptop::Laptop(const char* SKU, const char* brand, const char* model, const char* category, double price)
{
    setSKU(SKU);
    setBrand(brand);
    setModel(model);
    setCategory(category);
    setPrice(price);
    cnt++;
}

void Laptop::setSKU(const char* SKU)
{
    delete[] this->SKU;

    int len = strlen(SKU) + 1;
    this->SKU = new char[len];

    strcpy(this->SKU, SKU);
}

void Laptop::setBrand(const char* brand)
{
    delete[] this->brand;

    int len = strlen(brand) + 1;
    this->brand = new char[len];

    strcpy(this->brand, brand);
}

void Laptop::setModel(const char* model)
{
    delete[] this->model;

    int len = strlen(model) + 1;
    this->model = new char[len];

    strcpy(this->model, model);
}

void Laptop::setCategory(const char* category)
{
    delete[] this->category;

    int len = strlen(category) + 1;
    this->category = new char[len];

    strcpy(this->category, category);
}

void Laptop::setPrice(double price)
{
    this->price = price;
}

const char* Laptop::getSKU() const
{
    return this->SKU;
}

const char* Laptop::getBrand() const
{
    return this->brand;
}

const char* Laptop::getModel() const
{
    return this->model;
}

const char* Laptop::getCategory() const
{
    return this->category;
}

double Laptop::getPrice() const
{
    return this->price;
}

unsigned int Laptop::getCount() const
{
    return this->cnt;
}

void Laptop::print() const
{
    cout << "SKU: " << this->SKU << " brand: " << this->brand << " model: " << this->model << " category: " << this->category << " price: " << this->price << endl;
}

unsigned int Laptop::cnt=0;

Store::Store()
{
    this->countInStore = 0;
    this->capacity = 5;
    this->listOfLaptops = nullptr;
}

Laptop** Store::getListOfLaptops() const
{
    return this->listOfLaptops;
}

void Store::addExistingLaptop( Laptop& newLaptop)
{
    if(this->listOfLaptops == nullptr)
    {
        this->listOfLaptops = new Laptop*[this->capacity];
    }
    if(capacityIsFull())
    {
        growCapacity();
    }
    this->listOfLaptops[countInStore] = &newLaptop;
    countInStore++;
}

void Store::addNewLaptop()
{
    if(this->listOfLaptops == nullptr)
    {
        this->listOfLaptops = new Laptop*[this->capacity];
    }
    if(capacityIsFull())
    {
        growCapacity();
    }
    Laptop* newLaptop = new Laptop;
    this->listOfLaptops[this->countInStore] = newLaptop;
    cout << "Choose option: " << endl;
    cout << "1 - default laptop" << endl;
    cout << "2 - specify laptop manualy" << endl;
    int choice1;
    cin >> choice1;
    if (choice1 == 2)
    {
        cout << "Choose SKU: ";
        char newSKU[100];
        cin >> newSKU;
        this->listOfLaptops[this->countInStore]->setSKU(newSKU);

        cout << "Choose Brand: ";
        char newBrand[100];
        cin >> newBrand;
        this->listOfLaptops[this->countInStore]->setBrand(newBrand);

        cout << "Choose Model: ";
        char newModel[100];
        cin >> newModel;
        this->listOfLaptops[this->countInStore]->setModel(newModel);

        cout << "Choose Category: ";
        char newCategory[100];
        cin >> newCategory;
        this->listOfLaptops[this->countInStore]->setCategory(newCategory);

        cout << "Choose Price: ";
        double newPrice;
        cin >> newPrice;
        this->listOfLaptops[this->countInStore]->setPrice(newPrice);
    }
    cout << "Congratulations, you added brand new laptop: " << endl;
    this->listOfLaptops[this->countInStore]->print();
    this->countInStore++;
}

bool Store::listContainsLaptop(const Laptop& laptop) const
{
    bool containsLaptop = false;
    unsigned int indexOfLaptopInList = 0;
    while(indexOfLaptopInList < this->countInStore)
    {
        if(*this->listOfLaptops[indexOfLaptopInList]==laptop)
        {
            containsLaptop = true;
            break;
        }
        indexOfLaptopInList++;
    }
    return containsLaptop;
}

void Store::deleteLaptop(const Laptop& laptop)
{
    if(listContainsLaptop(laptop))
    {
        unsigned int indexOfLaptopInList = 0;
        while(!(*this->listOfLaptops[indexOfLaptopInList]==laptop))
        {
            indexOfLaptopInList++;
        }
        delete this->listOfLaptops[indexOfLaptopInList];
        for(; indexOfLaptopInList < countInStore - 1; indexOfLaptopInList++)
        {
            this->listOfLaptops[indexOfLaptopInList] = this->listOfLaptops[indexOfLaptopInList+1];
        }
        this->listOfLaptops[indexOfLaptopInList] = nullptr;
        this->countInStore--;
    }
    else
    {
        cout << endl << "Sorry, but there is not such a laptop in this store :(. Please look up in the others!" << endl;
    }
}

void Store::changeLaptop(const Laptop& laptop)
{
    if(listContainsLaptop(laptop))
    {
        int indexOfLaptopInList = 0;
        while(!(*this->listOfLaptops[indexOfLaptopInList]==laptop))
        {
            indexOfLaptopInList++;
        }

        cout << endl;
        cout << "1 - Change SKU" << endl;
        cout << "2 - Change brand" << endl;
        cout << "3 - Change model" << endl;
        cout << "4 - Change category" << endl;
        cout << "5 - Change price" << endl;
        cout << "Please choose what you want to change exactly: ";

        int choice;
        cin >> choice;

        if(choice == 1)
        {
            cout << "Please insert the new SKU: ";
            char newSKU[100];
            cin >> newSKU;
            this->listOfLaptops[indexOfLaptopInList]->setSKU(newSKU);
        }
        else if(choice == 2)
        {
            cout << "Please insert the new brand name: ";
            char newBrand[100];
            cin >> newBrand;
            this->listOfLaptops[indexOfLaptopInList]->setBrand(newBrand);
        }
        else if(choice == 3)
        {
            cout << "Please insert the new model name: ";
            char newModel[100];
            cin >> newModel;
            this->listOfLaptops[indexOfLaptopInList]->setModel(newModel);
        }
        else if(choice == 4)
        {
            cout << "Please insert the new category: ";
            char newCategory[100];
            cin >> newCategory;
            this->listOfLaptops[indexOfLaptopInList]->setCategory(newCategory);
        }
        else if(choice == 5)
        {
            cout << "Please insert the new price: ";
            double newPrice;
            cin >> newPrice;
            this->listOfLaptops[indexOfLaptopInList]->setPrice(newPrice);
        }
    }
    else
    {
        cout << endl << "Sorry, but there is not such a laptop in this store :(. Please look up in the others!" << endl;
    }
}

void Store::printListOfAllLaptops() const
{
    for(unsigned int i = 0; i < this->countInStore; i++)
    {
        cout << i+1 << " - ";
        this->listOfLaptops[i]->print();
    }
}

void Store::growCapacity()
{
        Laptop** newListOfLaptops = new Laptop*[this->capacity*2];
        for(unsigned int i = 0; i < capacity; i++)
        {
            newListOfLaptops[i] = this->listOfLaptops[i];
        }
        delete[] this->listOfLaptops;
        this->capacity *= 2;
        this->listOfLaptops = newListOfLaptops;
}

bool Store::capacityIsFull() const
{
    if(this->countInStore == this->capacity)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Store::isEmpty() const
{
    if(this->countInStore == 0) {return true;}
    else {return false;}
}

Store::~Store()
{
    delete[] listOfLaptops;
}
