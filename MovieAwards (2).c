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

#include <stdio.h>
#include <string.h>
struct movie
{
    char name[35];
    int year;
    int awards;
};
void move_awarded_movies_to_front(struct movie *movies, int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (movies[i].awards == 1)
        {
            // swap movies[i] and movies[j]
            struct movie temp = movies[i];
            movies[i] = movies[j];
            movies[j] = temp;
            j++;
        }
    }
}
void sort_awarded_movies_by_name(struct movie *movies, int n)
{
    int j = 0;
    while (j < n && movies[j].awards != 1)
    {
        j++;
    }
    int k = j;
    while (k < n)
    {
        if (movies[k].awards == 1)
        {
            // Insertion sort
            int i = k;
            while (i > j && strcmp(movies[i - 1].name, movies[i].name) < 0)
            {
                struct movie temp = movies[i];
                movies[i] = movies[i - 1];
                movies[i - 1] = temp;
                i--;
            }
        }
        k++;
    }
}
int main()
{
    struct movie movies[5] = {
        {"The Shawshank Redemption", 1994, 1},
        {"The Godfather", 1972, 1},
        {"The Godfather: Part II", 1974, 1},
        {"The Dark Knight", 2008, 0},
        {"12 Angry Men", 1957, 1}};
     for (int i = 0; i < 5; i++)
    {
        printf("{%s, %d, %d}\n", movies[i].name, movies[i].year, movies[i].awards);
    }
    move_awarded_movies_to_front(movies, 5);
    printf("Array after calling move_awarded_movies_to_front:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("{%s, %d, %d}\n", movies[i].name, movies[i].year, movies[i].awards);
    }
    sort_awarded_movies_by_name(movies, 5);
    printf("Array after calling sort_awarded_movies_by_name:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("{%s, %d, %d}\n", movies[i].name, movies[i].year, movies[i].awards);
    }
    return 0;
}
