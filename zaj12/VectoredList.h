//KOD AUTORSTWA PAULINY GACEK Z DODATKAMI KODU ANETY POSTROŻNY 
#ifndef LABKI11_STRING_VECTOREDLIST_H
#define LABKI11_STRING_VECTOREDLIST_H
#define N 10
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class VectoredList{
public:
    class Bucket{
    public:
        Bucket *previous;
        Bucket *next;
        size_t count;//ilosc el w koszyczku
        string *tab;
        Bucket()
        {
            tab=new string[N];
            count=0;
            next=nullptr;
            previous=nullptr;
        }
        void append(string v)
        {
            tab[count]=std::move(v);
            count++;
        }
    };
    //////////////
    class VectoredListIterator{
    public:
        const VectoredList& vector_list;
        VectoredList::Bucket *bucket_cursor;
        string *int_cursor;
        explicit VectoredListIterator(const VectoredList&vector_list):
                vector_list{vector_list}, int_cursor{vector_list.return_head()->tab}, bucket_cursor{vector_list.return_head()}{}

        VectoredListIterator(const VectoredList&vector_list, size_t index):
                vector_list{vector_list}, int_cursor{vector_list.return_head()->tab}, bucket_cursor{vector_list.return_head()}
        {
            if(index > vector_list.get_size())
                throw std::out_of_range("Too large number");
            size_t buckets_to_skip = (index - index%10)/10;
            //std::cout << "Buckets to skip: "<< buckets_to_skip << std::endl;
            for(int i = 0; i < buckets_to_skip; ++i)
            {
                bucket_cursor=bucket_cursor->next;
            }
            int_cursor = bucket_cursor->tab;
            for(int i = 0; i < index%10 ; ++i)
            {
                int_cursor++;
            }
        }

        const VectoredListIterator& operator++()
        {
            if( int_cursor != &(bucket_cursor->tab[bucket_cursor->count-1]))
            {
                int_cursor++;
            }
            else{
                bucket_cursor= bucket_cursor->next;
                int_cursor = bucket_cursor->tab;
            }
            return *this;
        }
        string operator*()const{
            return *(this->int_cursor);
        }
        bool operator!=(const VectoredList::VectoredListIterator& iterator) const
        {
            return iterator.int_cursor!=this->int_cursor;
        }
        bool operator==(const VectoredList::VectoredListIterator& iterator) const
        {
            return iterator.int_cursor==this->int_cursor;
        }
        [[nodiscard]] string get()const{return *int_cursor;}
        [[nodiscard]] size_t return_index(const VectoredList &vector_to_copy)const;
    };
    /////////////
    Bucket *head;
    Bucket *tail;
    size_t size;
    int capacity;
    VectoredList()
    {
        head= tail = nullptr;
        size=0;//ilosc blokow
        capacity=0;//ile zmiesci sie do blokow
    }
    VectoredList(const VectoredList& newV) = default;

    void push_back(string new_element);
    string& pop_back();
    void erase(VectoredListIterator &iterator);
    void erase(VectoredListIterator &start_iterator, VectoredListIterator &end_iterator);
    void clean_vector();
    size_t get_size()const{
        if(size == 0)
            return 0;
        return (size-1)*10+tail->count;
    }
    Bucket* return_head()const{return head;}
    Bucket* return_tail()const{return tail;}
    size_t return_size()const{return size;}
    [[nodiscard]] int return_capacity()const{return capacity;}
    string& operator[](size_t number_of_element)const;
    //VectoredList& operator=(const VectoredList& new_vector);
    bool is_empty();
    VectoredListIterator begin()const;
    VectoredListIterator end()const;
/////////////////////////////////////////////////////
///////////// ZAJĘCIA 12 ////////////////////////////

VectoredList(VectoredList&& v): head(nullptr), tail(nullptr), size(0), capacity(0)
    {
        head = v.head;
        tail = v.tail;
        size = v.size;
        capacity = v.capacity;
        v.head = nullptr;
        v.tail = nullptr;
        v.size = 0;
        v.capacity = 0;
    }
VectoredList& operator=(VectoredList&& v)
    {
        if(this != &v)
        {
        delete[] head;
        head = v.head;
        tail = v.tail;
        size = v.size;
        capacity = v.capacity;
        v.head = nullptr;
        v.tail = nullptr;
        v.size = 0;
        v.capacity = 0;
        }
    return *this;
    }

VectoredList operator+(const VectoredList& rhs) const
    {
        VectoredList new_(*this);
        for(int i = 0; i<rhs.get_size();++i)
        {
            new_.push_back(rhs[i]);
        }
        return new_;
    }

void assign(vector<string> v)
    {
        tail = nullptr;
        head = nullptr;
        capacity = 0;
        size = 0;
        for(auto i: v)
        {
            this->push_back(i);
        }
    }
};
#endif //LABKI11_STRING_VECTOREDLIST_H

