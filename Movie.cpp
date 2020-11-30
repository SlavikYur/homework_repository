#include <iostream>
#include "Movie.h"

#define MOVIENUMBER 5
#define CINEMANUMBER 3
#define DAYSNUMBER 30

using namespace std;

Movie::Movie() {}

Movie::Movie(string id, string title, float ranking, int date, int charn, int price, string com, MovieType type)
    {
        this -> Id = id;
        this -> Title = title;
        this -> Ranking = ranking;
        this -> ReleaseDate = date;
        this -> CharacterNumber = charn;
        this -> TicketPrice = price;
        this -> Comment = com;
        this -> Type = type;
    };

Movie::~Movie(){}


string Movie::getTitle()
    {
        return this -> Title;
    }

Cinema::Cinema() {}

Cinema::Cinema(string name, string location)
    {
        this -> Name = name;
        this -> Location = location;
    }

Cinema::~Cinema()
    {
        for (int i=0; i<this -> MoviesNumber; i++)
            delete[] money[i];
    }

int Cinema::getMovNum()
    {
        return this -> MoviesNumber;
    }


void Cinema::AddMovie(Movie movie)
    {
        MoviesInCinema.push_back(movie);
        this -> MoviesNumber++;
        money.push_back(new int[DAYSNUMBER*sizeof(int)]);
    }

void Cinema::setTicketsSold (int movienumber, int day, int number)
    {
            money[movienumber][day] = number;
    }


void Filter (vector <Movie> &movies)
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
        if ((movies[i].Ranking >= minrate) && (movies[i].ReleaseDate >= year) && (movies[i].Type == type)) cout << movies[i].Title << endl;
    cout << endl;
}

int CalculateProfit(vector <Cinema> &cinemas, Movie* movie, int day)
{
    int total=0;

    for (int i=0; i<CINEMANUMBER; i++)
        for (int j=0; j<cinemas[i].MoviesNumber; j++)
             if (cinemas[i].MoviesInCinema[j].Id == movie -> Id) {total += cinemas[i].money[j][day]; break;}

    return total*movie -> TicketPrice;
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


    cinemas[0].AddMovie(movies[0]); //The Shawshank Redemption
    cinemas[0].AddMovie(movies[1]); //The Green Mile
    cinemas[0].AddMovie(movies[4]); //8 Mile

    cinemas[1].AddMovie(movies[2]); //The Invisible Guest
    cinemas[1].AddMovie(movies[3]); //The Intouchables

    cinemas[2].AddMovie(movies[0]); //The Shawshank Redemption
    cinemas[2].AddMovie(movies[1]); // The Green Mile
    cinemas[2].AddMovie(movies[3]); // The Intouchables

}

void sortbydate(vector <Movie> &movies, int beginning0, int end0)
{
    Movie temporary;
    if (((end0-beginning0) <= 1) && (movies[beginning0].ReleaseDate >= movies[end0].ReleaseDate)) {temporary = movies[beginning0]; movies[beginning0] = movies[end0]; movies[end0] = temporary;}

        else

        {

    Movie pivot = movies[end0];
    int wall = beginning0;

    for (int i=beginning0; i<=end0-1; i++)
    {
        if (movies[i].ReleaseDate <= pivot.ReleaseDate) {temporary = movies[i]; movies[i] = movies[wall]; movies[wall] = temporary; wall++;}

    }


    if (wall == end0) {sortbydate(movies, beginning0, end0-1);} else
        if ((wall - beginning0) <= 1) { temporary = pivot; movies[end0] = movies[wall]; movies[wall] = temporary; sortbydate(movies, wall+1, end0);} else
    {

        temporary = pivot; movies[end0] = movies[wall]; movies[wall] = temporary;
        sortbydate(movies, beginning0, wall-1);
        sortbydate(movies, wall+1, end0);
    }

    }

}
