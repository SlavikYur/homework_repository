#include <iostream>
#include "Movie.h"

#define MOVIENUMBER 5
#define CINEMANUMBER 3
#define DAYSNUMBER 30

using namespace std;

Movie::Movie() {}

Movie::Movie(string id, string title, float ranking, int date, int charn, int price, string com, MovieType type)
    {
        this -> id = id;
        this -> title = title;
        this -> ranking = ranking;
        this -> releaseDate = date;
        this -> characterNumber = charn;
        this -> ticketPrice = price;
        this -> comment = com;
        this -> type = type;
    };

Movie::~Movie(){}


string Movie::getTitle()
    {
        return this -> title;
    }

Cinema::Cinema() {}

Cinema::Cinema(string name, string location)
    {
        this -> name = name;
        this -> location = location;
    }

Cinema::~Cinema()
    {
        for (int i=0; i<this -> moviesNumber; i++)
            delete[] money[i];
    }

int Cinema::getMovNum()
    {
        return this -> moviesNumber;
    }


void Cinema::addMovie(Movie movie)
    {
        moviesInCinema.push_back(movie);
        this -> moviesNumber++;
        money.push_back(new int[DAYSNUMBER*sizeof(int)]);
    }

void Cinema::setTicketsSold (int movienumber, int day, int number)
    {
            money[movienumber][day] = number;
    }


void filter (vector <Movie> &movies)
{
    int year;
    float minrate;
    string genre;
    MovieType type;

    cout << "Minimum Ranking:" << endl;
    cin >> minrate;
    cout << endl;

    cout << "Minimum Year:" << endl;
    cin >> year;
    cout << endl;

    cout << "Desired Genre(ACTION, DRAMA, COMEDY, THRILLER, FANTASY):" << endl;
    cin >> genre;
    cout << endl;

    if (genre == "ACTION") type = ACTION; else
    if (genre == "COMEDY") type = COMEDY; else
    if (genre == "DRAMA") type = DRAMA; else
    if (genre == "FANTASY") type = FANTASY; else
    if (genre == "THRILLER") type = THRILLER;

    cout << "Variants:" << endl;
    for (int i=0; i<MOVIENUMBER; i++)
        if ((movies[i].ranking >= minrate) && (movies[i].releaseDate >= year) && (movies[i].type == type)) cout << movies[i].title << endl;
    cout << endl;
}

int calculateProfit(vector <Cinema> &cinemas, Movie* movie, int day)
{
    int total=0;

    for (int i=0; i<CINEMANUMBER; i++)
        for (int j=0; j<cinemas[i].moviesNumber; j++)
             if (cinemas[i].moviesInCinema[j].id == movie -> id) {total += cinemas[i].money[j][day]; break;}

    return total*movie -> ticketPrice;
}

void initialization(vector <Movie> &movies, vector <Cinema> &cinemas)
{
    movies.push_back(Movie("0111161", "The Shawshank Redemption", 9.3, 1994, 15, 100, "No comments", DRAMA));
    movies.push_back(Movie("0120689", "The Green Mile", 8.6, 1999, 18, 90, "No comments", DRAMA));
    movies.push_back(Movie("4857264", "The Invisible Guest", 8.1, 2016, 12, 85, "No comments", THRILLER));
    movies.push_back(Movie("1675434", "The Intouchables", 8.5, 2011, 9, 90, "No comments", COMEDY));
    movies.push_back(Movie("0298203", "8 Mile", 7.1, 2002, 13, 75, "No comments", DRAMA));

    cinemas.push_back(Cinema("Effect","Heroiv Maidanu Street, 101"));
    cinemas.push_back(Cinema("CinemaPalace","Kobylianskoi Street, 23"));
    cinemas.push_back(Cinema("ChernivtsiCinema","Universytetska Street, 35"));


    cinemas[0].addMovie(movies[0]); //The Shawshank Redemption
    cinemas[0].addMovie(movies[1]); //The Green Mile
    cinemas[0].addMovie(movies[4]); //8 Mile

    cinemas[1].addMovie(movies[2]); //The Invisible Guest
    cinemas[1].addMovie(movies[3]); //The Intouchables

    cinemas[2].addMovie(movies[0]); //The Shawshank Redemption
    cinemas[2].addMovie(movies[1]); // The Green Mile
    cinemas[2].addMovie(movies[3]); // The Intouchables

}

void sortByDate(vector <Movie> &movies, int sortBegin, int sortEnd)
{
    Movie temporary;
    if (((sortEnd-sortBegin) <= 1) && (movies[sortBegin].releaseDate >= movies[sortEnd].releaseDate)) 
        {
            temporary = movies[sortBegin]; 
            movies[sortBegin] = movies[sortEnd]; 
            movies[sortEnd] = temporary;
        }

        else

    {

    Movie pivot = movies[sortEnd];
    int wall = sortBegin;

    for (int i=sortBegin; i<=sortEnd-1; i++)
    {
        if (movies[i].releaseDate <= pivot.releaseDate) 
            {
                temporary = movies[i]; 
                movies[i] = movies[wall]; 
                movies[wall] = temporary; 
                wall++;
            }

    }


    if (wall == sortEnd) 
        sortByDate(movies, sortBegin, sortEnd-1); 
            
    else
        
    if ((wall - sortBegin) <= 1) 
    { 
        temporary = pivot; 
        movies[sortEnd] = movies[wall]; 
        movies[wall] = temporary; 
        sortByDate(movies, wall+1, sortEnd);
    } 
    else
    {

        temporary = pivot; 
        movies[sortEnd] = movies[wall]; 
        movies[wall] = temporary;
        
        sortByDate(movies, sortBegin, wall-1);
        sortByDate(movies, wall+1, sortEnd);
    }

    }

}
