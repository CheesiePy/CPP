#ifndef CPPLAB03_STRING_H
#define CPPLAB03_STRING_H

#include <cstring>
#include <cstddef>
#include <iostream>

using namespace std;

class String{
    public:
        // Big Three
        String(); // default constructor
        String(const String& str); // copy constructor
        ~String(); // destructor
        String& operator =(const String& str); // assignment operator

        //Getter / Setters
        char* Get_c_str(){ return c_str; }
        void Set_c_str(const char* str){strcpy(c_str, str); }

        // requested functions;
        String(const char* str);// rq constructor

        void assign(const char* str){Set_c_str(str);}
        void print(){cout << Get_c_str() << endl;}
        String copy(const String& str){c_str = str.c_str;return *this;}
        int length(const String& str){return (int)strlen(str.c_str);}
        char at(const String& str, int i);
        String& substring(const String& str, int starts, int ends);
//        String Substring(const String& str, int starts);
//        void replace(int index, char subChar);
//        bool equals(const String& str1, const String& str2);


    private:
        char* c_str;
};

#endif
