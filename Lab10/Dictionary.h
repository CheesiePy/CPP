#ifndef LAB10_DICTIONARY_H
#define LAB10_DICTIONARY_H
#include <vector>
using namespace std;
/*
 * Please Read!
 * using this class requires your class to implement the following:
 * operator ==;
 *
 * */
template<class Key, class Value>
class Dictionary{
public:

    Dictionary(): size(0), keys(vector<Key>()), values(vector<Value>()){};


    ~Dictionary(){
        keys.clear();
        values.clear();
    };

    void put(const Key& k, const Value& v){
        for(int i = 0; i < keys.size(); i++){
            if(k == keys[i]){
                values[i] = v;
                return;
            }
        }
        keys.push_back(k);
        values.push_back(v);
    };

    Value& get(const Key& k){
        for(int i = 0; i < keys.size(); i++)
        {
            if(k == keys[i])
            {
                return values[i];
            }
        }
        cerr << "No Matching Keys" << endl;
    };

    vector<Key> getKeys() const {return keys;}

    vector<Value> getValues() const {return values;}

private:
    unsigned int size;
    vector<Key> keys;
    vector<Value> values;

};



#endif //LAB10_DICTIONARY_H
