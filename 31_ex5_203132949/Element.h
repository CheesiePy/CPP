#ifndef MULTIDGENERICSIM_ELEMENT_H
#define MULTIDGENERICSIM_ELEMENT_H
/*
 * Please Read!
 * using this class requires your class to implement the following:
 * operator ==;
 * operator<
 * operator<=
 * operator>=
 * operator>
 * operator+=
 * */
#include <iomanip>
#include <iostream>
#include <cstdlib>
//#include "Population.h"
using namespace std;

template <class S>
class Element {
public:
    //empty c'tor
    Element(): source(new S()),Xsize(0),dest(new S()),Fsize(0), rank(0){};
    // default c'tor;
    explicit Element(const S* setSource, uint ssize, uint dsize): source(new S[ssize]), Xsize(ssize), dest(new S[dsize]), Fsize(dsize), rank(0){
        for(int i = 0; i < ssize; i++)
        {
            source[i] = setSource[i];
        }
        for(int j = 0; j < dsize; j++){
            dest[j] = S();
        }
    };
    //
    Element(const Element<S>& other): source(new S[other.Xsize]), Xsize(other.Xsize), dest(new S[other.Fsize]), Fsize(other.Fsize), rank(other.rank){
        *this = other;
    }

    Element& operator=(const Element<S>& other){
        if(this == &other){
            return *this;
        }
        Assign(other);
        return *this;
    }

    void Assign(const Element<S>& other){
        Xsize = other.Xsize;
        Fsize = other.Fsize;
        rank = other.rank;
        for(int i = 0; i < other.Xsize; i++){
            source[i] = other.getSource()[i];
        }
        for(int i = 0; i < other.Fsize; i++){
            dest[i] = other.getDest()[i];
        }

    }


    //d'tor
    ~Element(){
    };

    // getters
    S* getSource() const {return source;};
    S* getDest()   const {return dest;};


    friend bool operator<(const Element<S>& lhs,const Element<S>& rhs){
            for (int i = 0; i < lhs.Xsize; i++) {
                if (lhs.getDest()[i] < rhs.getDest()[i])
                    return true;
                if (lhs.getDest()[i] > rhs.getDest()[i])
                    return false;
            }
            return true;
    }
    friend bool operator>(const Element<S>& lhs,const Element<S>& rhs){ return rhs < lhs;}
    friend bool operator<=(const Element<S>& lhs,const Element<S>& rhs){return !(lhs > rhs);}
    friend bool operator>=(const Element<S>& lhs,const Element<S>& rhs){return !(lhs < rhs);}


    friend ostream& operator<<(ostream& out, const Element<S>& e){
//        out << "source: ";
//        for(int i = 0; i < e.Xsize; i++){
//            out  << setprecision(4) << e.getSource()[i] << " ";
//        }
        //out << "dest: ";
        for(int i = 0; i < e.Fsize; i++){
            out  << setprecision(6) << e.getDest()[i] << " ";
        }
        //out << "\t rank: " << e.rank << " ";
        return out;
    }

    void rankUp(){this->rank++;};

    unsigned int getRank(){return rank;}

    void setDest(S setDest, int index){
        dest[index] = setDest;
    }
    void setSource(const S* val){
        for(int i = 0; i < Xsize; i++){
            source[i] = val[i];
        }
    }
private:
    S* source;
    uint Xsize;
    S* dest;
    uint Fsize;
    unsigned int rank;
};



#endif //MULTIDGENERICSIM_ELEMENT_H
