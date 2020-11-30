#include <iostream>
#include <vector>
#include "Movie.h"
#include <iomanip>

#define MOVIENUMBER 5
#define CINEMANUMBER 3
#define DAYSNUMBER 30

using namespace std;


int main()
{
    vector <Movie> movies;
    vector <Cinema> cinemas;

    int day;

    initialization(movies, cinemas);

    for (int k=0; k<CINEMANUMBER; k++)
        for (int i=0; i<cinemas[k].getMovNum(); i++)
            for (int j=0; j<DAYSNUMBER; j++)
                cinemas[k].setTicketsSold(i, j, (i+1)*(DAYSNUMBER-j));

    cout << "Filtering by ranking and release date. Write the lowest desired bound of ranking, release year and genre:" << endl;
    Filter(movies);

    cout << "Calculating profit earned by <<" << movies[0].getTitle() <<">> for the certain day. Write the number of the day:" << endl;
    cin >> day;
    cout << CalculateProfit(cinemas, &movies[0], --day) << endl << endl;

    cout << "Sorting by release date:" << endl;
    sortbydate(movies, 0, MOVIENUMBER-1);

    for (int i=0; i<MOVIENUMBER; i++)
        cout << movies[i].getTitle() << endl;

    return 0;
}
