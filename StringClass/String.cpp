#include <iostream>
#include <cstdio>
#include "String.h"

String::String()
{
  c_str[1] = '\0';
}

String::String(const char* str){
    this->c_str[1] = '\0';
    strcpy(c_str,str);
}

String::~String(){
    delete c_str;
}

String &String::operator=(const String& str){
    if(this != &str){
        c_str = str.c_str;
    }
    return *this;
}
char String::at(const String& str, int i){
    if ((int)strlen(Get_c_str()) > i)
        return  str.c_str[i];
    cerr<< "invalid index" << endl;
    return 0;
}

String &String::substring(const String& str, int starts, int ends){
    int i = 0;
    for(starts; starts < ends; starts++){
        c_str[i] += str.c_str[starts];
        i++;
    }
    return *this;
}
//String String::Substring(const String& str, int starts){
//
//
//}
//void String::replace(int index, char subChar){
//
//}
//bool String::equals(const String& str1, const String& str2){
//
//}

String::String(const String& str){
    c_str = str.c_str;
}