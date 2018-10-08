#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h> //this library for Sleep()
#include <time.h>
#include "sorted_list.h"


int UpB=9999;
int LoB=0;
int midP;


bool search(int value){
    while(1){   //infinite loop
    midP=(UpB+LoB)/2;   //mathematical equation to find midP index
                        // accurate upto 2^30 size integer arrays
    Sleep(100);     //100ms sleep is used to get an accurate measurement of time complexity

    if(value==sorted_list[midP]){
            return true;
            break;

        }
        else{
        if(UpB==LoB){   //this is the  mathematical property used to get out of loop if value not in array
            return false;
            break;
        }

        else{
            if(value>midP){
                LoB=midP+1;

            }
            else{
                UpB=midP-1;
            }
        }
        }
    }
}
float code_time(clock_t a,clock_t b){   //this function is used to measure time for one search
    float duration = (float)(a - b) / CLOCKS_PER_SEC;


return duration;
}
int main()
{
    int i;
    clock_t start, end;

    printf("Enter the value to search: ");
    scanf("%d",&i);
    start = clock();
    if(search(i)==true){
    printf("Number is found :Index is %d\n",midP);
    }
    else
    printf("Number is not in the array\n");

    end = clock();
    printf("Total time taken to do the search: %f\n",code_time(end,start));// code_time is to calculate time duration
    printf("Exiting of the program...\n");
return 0;
}
