#ifndef STORE_H_INCLUDED
#define STORE_H_INCLUDED

class Laptop
{
    char* SKU = nullptr;
    char* brand = nullptr;
    char* model = nullptr;
    char* category = nullptr;
    double price;
    static unsigned int cnt;

public:

    Laptop();

    Laptop(const Laptop&);

    Laptop& operator=(const Laptop&);

    bool operator==(const Laptop&) const;

    Laptop(const char*, const char*, const char*, const char*, double);

    //setters
    void setSKU(const char*);

    void setBrand(const char*);

    void setModel(const char*);

    void setCategory(const char*);

    void setPrice(double price);

    //getters
    const char* getSKU() const;

    const char* getBrand() const;

    const char* getModel() const;

    const char* getCategory() const;

    unsigned int getCount() const;

    double getPrice() const;

    //functions
    void print() const;

    //destructor
    ~Laptop();
};

class Store
{
    Laptop** listOfLaptops;
    unsigned int countInStore;
    unsigned int capacity;
public:
    Store();

    Store(const Store&);

    Store& operator=(const Store&);

    Laptop** getListOfLaptops() const;

    void addExistingLaptop(Laptop&);

    void addNewLaptop();

    bool listContainsLaptop(const Laptop&) const;

    void deleteLaptop(const Laptop&);

    void changeLaptop(const Laptop&);

    void printListOfAllLaptops() const;

    void growCapacity();

    bool capacityIsFull() const;

    bool isEmpty() const;

    ~Store();

};

#endif // STORE_H_INCLUDED
