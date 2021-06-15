#include <iostream>
#include <string>
#include <array>
#include <cstdio>

using namespace std;


class VectoredList
{
public:
    struct Bucket
    {
        Bucket* previous = nullptr;
        Bucket* next = nullptr;
        int size_ = 0;
        constexpr static int N = 10;
        array<string, N> bucket;
    };
    constexpr static int N = 10;
    Bucket* head;
    Bucket* tail;
    size_t size_1; //ilość bloczków
    int capacity_; //pojemność
    VectoredList()
    {
        head = tail = new Bucket;
        size_1 = 1;
    }
    int getCapacity(){return N*size_1;}

    void push_back(string v)
    {
        if(tail->size_<N)
        {
            tail->bucket[tail->size_] = v;
            tail->size_++;
            //cout<<tail->size_<<" aktualny rozmiar kubełka"<<endl;
        }
        else
        {
            tail->next = new Bucket;
            tail->next->previous = tail->next;
            tail = tail->next;
            tail->bucket[0] = v;
            size_1++;
            cout<<"-------------Witamy w nowym kubełku---------------"<<endl;
            cout<< getCapacity()<<" capacity"<<endl;
        }

    }
    string& operator[](const size_t &index) const{
        if(index<0)
            throw invalid_argument("argument is lower than 0");

        return this->head[index/N].bucket[index%N];
    }

    class VectoredListIterator
    {
        Bucket* cursor;
        int position=0;
    public:
        VectoredListIterator(const VectoredList&vl): cursor(vl.head){}
        VectoredListIterator& operator ++()
        {
            if(cursor)
            {
                position++;
                if(position == cursor->N)
                {
                    position = 0;
                    cursor = cursor->next;
                }
            }

            return *this;
        }
        Bucket&get()const{return *cursor;}
        bool operator!=(const VectoredListIterator& sth) { return cursor != sth.cursor; }
    };
    VectoredList& operator=(const VectoredList &NewV)
    {
        if (this==&NewV)
            return *this;
        head = tail = new Bucket[NewV.tail->size_];
        copy(NewV.head,NewV.tail, head);
        tail->size_ = NewV.tail->size_;
        cout<<"kopiowanie"<<endl;
        return *this;
    }
};


int main()
{
    VectoredList V1;
    cout<<V1.getCapacity()<<"- capacity"<<endl;
    V1.push_back("Hello");
    for(int i=0; i<=101; i++)
    {
        V1.push_back("Hello world!");
    }
    cout<<V1.head[6].bucket[7]<<endl;
    return 0;
}
