#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;



bool str_to_int(int& number, string str){
    istringstream(str) >> number;
    return (atoi(str.c_str()) == number);

}
void str_to_ints(vector<int> numbers , string str){
    string word;
    stringstream ss;
    int i = 0;
    while(ss >> word){
        str_to_int(numbers.pop() , word);
        i++;
    }
    for(i = 0; i < numbers.size();)

}

void Rec_printLine(){
    string line;
    if(getline(cin,line).eof()){
        cout << line << endl;
        return;
    }
    Rec_printLine();
    cout << line << endl;
}


int main() {
    int x[4];
    string str = "67 77 31 737";
    str_to_ints(x,str);

    return 0;
}
