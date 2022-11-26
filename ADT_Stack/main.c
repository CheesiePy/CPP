/*
 * lab0.c
 *
 *  Created on: Oct 29, 2021
 *  Author:     May lindenberg
 */

#include "ADTStack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LENGTH 16

typedef struct intl_passenger {
    char given_name[MAX_LENGTH];
    char surname[MAX_LENGTH];
    char passport_id[MAX_LENGTH];
    char country[MAX_LENGTH];
}intlPassenger;

void* cpy_elm(void* elm){
    intlPassenger* elm_copy = malloc(sizeof(intlPassenger));
    strcpy(elm_copy->given_name,((intlPassenger*)elm)->given_name);
    strcpy(elm_copy->surname,((intlPassenger*)elm)->surname);
    strcpy(elm_copy->passport_id,((intlPassenger*)elm)->passport_id);
    strcpy(elm_copy->country,((intlPassenger*)elm)->country);
    return elm_copy;
}

void free_elm(void* elm){
    free(elm);
}

char* label_elm(void* elm){
    intlPassenger* sourceElm = (intlPassenger*) elm;
    char* output = malloc(MAX_LENGTH*3);
    strcpy(output,sourceElm->given_name);
    strcat(output, " ");
    strcat(output,sourceElm->surname);
    strcat(output, " ");
    strcat(output, sourceElm->passport_id);
    return output;
}

int main(){
        /*### declarations ###*/
        //intlPassenger* myElm;
        //intlPassenger* copiedElm;
        //char* label;
        //char buffer[56];
        const char *fileNameToRead = "international_passengers.dat";
        //const char *fileNameToWrite = "textToWrite.txt";
        FILE *fpRead; //*fpWrite;
        Stack stack = init(56,cpy_elm,free_elm,label_elm);
/*
 * ###############################################-inner functions test-#################################################
       #### Initialize ####
        myElm = malloc(sizeof(intlPassenger*));
        if(!myElm){
            free_elm(myElm);
            return -1;
        }

        strcpy(myElm->given_name, "May");
        strcpy(myElm->surname, "Lindenberg");
        strcpy(myElm->passport_id,"203132949");
        strcpy(myElm->country , "Israel");

        label = label_elm(myElm);
        printf("%s", label);


     * #### copy_elm test ####
        copiedElm = cpy_elm(myElm);
        printf("%s \n", copiedElm->given_name); // should print May to terminal
        #### end copy_elm test ####


        #### label_elm test ####

        label = label_elm(copiedElm);
        printf("%s \n", label);

        #### end label_elm test ####

        #### free_elm test ####
        free_elm(&copiedElm);
        label = label_elm(copiedElm);
        printf("%s \n", label); // should print (null) to terminal
        #### end free_elm test ####

    //#################################################inner function tests#################################################
         //logic and operations

        //### file reader and writer ###
    */

        fpRead = fopen(fileNameToRead, "r");
        intlPassenger* tempPassenger = (intlPassenger*)malloc(sizeof(intlPassenger));
        while(fscanf(fpRead, "%s %s %s %s", tempPassenger->given_name,tempPassenger->surname, tempPassenger->passport_id, tempPassenger->country) != EOF)
            push(stack, tempPassenger);
        // push in it stack
        //after this while loop we should have a stuck full of passengers

        print(stack);


        //cleaning...
    fclose(fpRead);
    free_elm(tempPassenger);
    destroy(stack);

    return 0;
}
