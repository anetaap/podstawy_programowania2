#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Object
{
public:
    virtual void whatAmI()=0;
    virtual string toString()=0;
    virtual Object* clone()=0;
    virtual ~Object(){}
};

class StringObject : public Object
{
private:
    char* value;
    size_t size;
public:
    StringObject();
    StringObject(char* a)
    {
        this->value=a;
        this->size=strlen(a);
    }
    void whatAmI() override
    {
        cout<<"String object"<<endl;
    }
    string toString() override
    {
        return "StringObject";
    }
    StringObject* clone() override
    {
        return new StringObject(*this);
    }
};

class IntObject : public Object
{
private:
    int value;
public:
    IntObject();
    IntObject(int b)
    {
        this->value=b;
    }
    void whatAmI()
    {
        cout<<"Int object"<<endl;   
    }
    string toString() override
    {
        return "IntObject";
    }
    IntObject* clone() override
    {
        return new IntObject(*this);
    }
};

class DoubleObject : public Object
{
private:
    double value;
public:
    DoubleObject();
    DoubleObject(double c)
    {
        this->value=c;
    }
    void whatAmI() 
    {
        cout<<"Double object"<<endl;
    }
    string toString() override
    {
        return "DoublegObject";
    }
    DoubleObject* clone() override
    {
        return new DoubleObject(*this);
    }
};

int main()
{   
    StringObject str("something");
    IntObject obj(9);
    Object *wsk;
    wsk=&obj;
    wsk->whatAmI();
    DoubleObject a(8);
    wsk=&a;
    wsk->whatAmI();
    wsk=&str;
    wsk->whatAmI();
    return 0;
}
