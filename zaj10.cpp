#include <iostream>
#include <cstring>
using namespace std;

class String
{
    char* text;
    size_t size_;
public:
    String(){
    size_ = 0;
    text = new char[0];
    }
    String(const char* txt){
        if (txt == nullptr){ throw length_error("The text does not exist.");}
        else{
            size_ = strlen(txt);
            text = new char[size_ + 1]{};
            cout << size_ << " size" << endl;
            copy(txt, txt + size_, text);
            cout << text << endl;
        }
    }
    String(String& org){
    size_ = org.size_;
    text = new char[size_];
    copy(org.text, org.text + org.size_, text);
    }
    ~String(){
        if (text != nullptr)
        delete text;
    }
    void operator=(const char* newText){
        if (newText == nullptr){ throw length_error("The text does not exist.");}
        else{
            size_ = sizeof(newText)/sizeof(char*);
            text = new char[size_];
            copy(newText, newText + size_, text);
        }
    }
    size_t size1(){
        return size_;
    }
    char* text_(){
        return text;
    }
};


int main()
{
    String A("Fear is the mind-killer.");
    cout << A.text_() << endl;
    return 0;
}
