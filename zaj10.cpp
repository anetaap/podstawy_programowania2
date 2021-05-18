#include <iostream>
#include <cstring>
using namespace std;

class String
{
    char* text;
    size_t size_;
public:

//A) Konstruktor bezargumentowy
    String(){
    size_ = 0;
    text = new char[0];
    }
// B) Konstruktor przyjmujący tekst
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
// D) Konstruktor kopiujący
    String(String& org){
        size_ = org.size_;
        text = new char[size_];
        copy(org.text, org.text + org.size_ + 1, text);
        cout<<"Głęboka kopia: "<<text<<endl;
    }
// C) Destruktor zwalniający pamięć
    ~String(){
        delete []text;
    }
//  F) Proszę o zdefiniowanie operatora=(const char* newText)
    String& operator=(const char* newText){
        if (newText == nullptr){ throw length_error("The text does not exist.");}
        else{
            size_ = sizeof(newText)/sizeof(char*);
            text = new char[size_];
            cout<<"operator"<<endl;
            copy(newText, newText + size_ + 1, text);
        }
    }
//   G) size() i text()
    size_t size1() const{
        return size_;
    }
    char* text_() const{
        return text;
    }
//  H) operator=(const String& newText)
    String & operator=(const String &NewText){
        if (this==&NewText)
            return *this;

        if (NewText.text == nullptr){ throw length_error("The text does not exist.");}

        text = new char[NewText.size_];
        copy(NewText.text, NewText.text + NewText.size_ + 1, text);
        size_ = NewText.size_;
        return *this;
    }

};


int main()
{
    String A("Fear is the mind-killer.");
    String B = A;
    cout <<"Kopia "<< B.text_() << endl;
    String s, s2, s3("Diuna");
    s=s2=s3;
    s3 = s3;
    cout<<"test: "<<s.text_() <<","<< s2.text_()<<","<<s3.text_()<<endl;
    return 0;
}
