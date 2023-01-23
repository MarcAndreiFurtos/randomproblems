/*Let there be an array of structures in the form of struct movie (char name [35]; int year; int
awards). (The prize field is set to 1 if the movie was awarded a prize and 0 if not).
Knowing that the array has the size N, implement a function for:
a. Moving, in the most efficient way, the first positions in the vector of the movies that received
awards,
b. Sort in reverse alphabetical order by name, the awarded movies (only the awarded movies will
be sorted).
Draw an example with at least 5 such movies and exemplify what the array will look like after
calling each of the above functions.
Note:
Algorithm may be written in C-like pseudocode
It is mandatory to comment on the algorithm and specify its complexity in terms of O (f (n),
comment on the chosen data structures, as well as justify their choice.
It is mandatory to exemplify the call effect of the functions implemented on a chosen example.*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Movie{
    char name[35];
    int year;
    int awards;
}movie;

// fuction that moves awarded movies to the front of the array
void moveAwardedToFront(movie arr[] ,int n){
    int j=0;
    // checks if each movie has award and if it does it moves it to the front
    for(int i=0;i<n;i++){
        if(arr[i].awards == 1){
            movie tmp = arr[i];
            arr[i] = arr[j];
            arr[j] =tmp;
            j++;
        }
    }
}

// function that sorts movies uses a standard insertion sort because we know the location
// of the awarded movies (at the begining of the array)
void sortAwardedMovies(movie arr[],int n){
    int j = 0 ;
    // increment to find out the ammount of movies that are not award winners 
    while(j<n && arr[j].awards != 1){
        j++;
    }
    for(int k = 1 ; k < n-j ; j++){
            int h = k-1;
            movie tmp = arr[k];
            while(h>=0&&strcmp(arr[h].name,arr[k].name)){
                arr[h+1] = arr[h];
                h--;
            }
            arr[h+1] = tmp;
    }
}




int main(){

}