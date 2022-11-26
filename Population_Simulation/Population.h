#ifndef MULTIDGENERICSIM_POPULATION_H
#define MULTIDGENERICSIM_POPULATION_H
#include "Element.h"
#include <cstdlib>
#include <cmath>

/*
 * Please Read!
 * using this class requires your class to implement the following:
 * operator ==;
 * operator ;
 * operator += from D to S
 * */





template<class S>
class POPULATION{
public:

    POPULATION(): Identity(new S*[dsize]), container(new Element<S>[psize]), psize(0), ssize(0), dsize(0) {};
    POPULATION(uint psize, uint ssize, uint dsize, S** graph): Identity(new S*[psize]) ,container(new Element<S>*[psize]), psize(psize), ssize(ssize), dsize(dsize){
        for(int i = 0; i < psize; i++){
            container[i] = new Element<S>(graph[i], ssize, dsize);
        }
        for(int i = 0; i < dsize; i++) {
            Identity[i] = new S[ssize];
            for (int j = 0; j < dsize+1; j++) {
                Identity[i][j] = i+1;
            }
        }
    };

    ~POPULATION(){
        for (int i = 0; i < psize; i++){
            delete container[i];
        }
        delete container;
        delete Identity;
    };



    // this function will populate the container vector;

    void rank(Element<S>* e, int pos=0){
        for(int i = pos; i < psize; i++){

            for (int j = 0; j < dsize; j++){
                if (e->getDest()[j] == container[i]->getDest()[j])
                    continue;
                if (e->getDest()[j] < container[i]->getDest()[j]){
                    container[i]->rankUp();
                    break;
                }
                if (e->getDest()[j] > container[i]->getDest()[j]){
                    e->rankUp();
                    break;

                }


            }
        }
    } // this function will compare e with all the element in the container and rank e accordingly

    void rankAll(){
        for(int i = 0; i < psize ; i++)
        {
            rank(container[i], i);

        }
    }// will rank() every element in the container.

    int getSize() const {return psize;}
    Element<S>* getContainer() {return container;}

    void ElementsReordering(){
        for(int i = 0; i < psize; i++)
        {
            for(int j = 0; j < psize-i-1; j++)
            {
                if(container[j]->getRank() > container[j+1]->getRank()){
                    std::swap(*container[j], *container[j+1]);
                }
            }
        }
    }
    friend ostream& operator<<(ostream& out, const POPULATION<S>& p){
        for(int i = 0; i < p.psize; i++){
            out << *p.container[i] << endl;
        }
        return out;
    }

    void RankAndSort(){
        rankAll();
        ElementsReordering();
    }
    S sum(const S* self, const S* other, uint size){
        S result = 0;
        for(int i = 0; i < size; i++){
            result += pow((self[i] - other[i]), 2);
        }
        return result;
    }

    void setFunc(uint size){
        int index;
        for(int k = 0; k < size; k++){
            index = 0;
            for(int i = 0; i < dsize; i++){
                container[k]->setDest(sum(container[k]->getSource(), Identity[index], ssize), index);
                index++;
            }
        }


    }

    Element<S>* Fusion(const Element<S>* X){
        S* val = new S[ssize];
        Element<S>* R = new Element<S>(*X);
        S tmp, div;
        for(int i = 0; i < ssize; i++){
            tmp = (rand() & 10) + 1;
            div = (rand() & 100) + 1;
            div *= 10000;
            tmp /= div;
            val[i] = tmp;
        }

        for(int i = 0; i < ssize; i++){
            val[i] += X->getSource()[i];

        }

        (*R).setSource(val);


        return R;
    }

    void Evolve(){
        /*
         * first im creating a graph
         * then im creating new population inside the function with double the size
         * then ranking and sorting the new population
         * and taking the element lowest ranks from the new population to current one
         */
        S** pGraph = new S*[psize*2];

        for(int i = 0; i < psize; i++){
            pGraph[i] = new S[ssize];
            for(int j = 0; j < ssize; j++){
                pGraph[i][j] = container[i]->getSource()[j];
            }

        }

        Element<S>* e = new Element<S>();
        for(int i = 0; i < psize; i++){
            e = Fusion(container[i]);

            pGraph[i+psize] = new S[ssize];

            for(int j = 0; j < ssize; j++){
                pGraph[i+psize][j] = e->getSource()[j];
            }
        }

        POPULATION<S>* p = new POPULATION(psize*2, ssize, dsize, pGraph);
        p->setFunc(psize*2);
        p->RankAndSort();
       // cout <<  "here:\n" << *p << endl;
        *container[0] = *p->container[0];
        int rank = 0;
        int counter = 0;
        for(int k = 0; k < 2*psize; k++){
            if(p->container[k]->getRank() == rank)
                continue;

            rank = p->container[k]->getRank();
            if(counter < psize)
                *container[counter] = *p->container[k];

            counter++;
        }
        delete p;

    }

private:
    S** Identity;
    Element<S>** container;
    uint psize, ssize, dsize;
};



#endif //MULTIDGENERICSIM_POPULATION_H
