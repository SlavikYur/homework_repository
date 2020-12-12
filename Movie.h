#pragma once
#include <iostream>
#include <vector>

using namespace std;

enum MovieType
{
  ACTION,
  COMEDY,
  DRAMA,
  FANTASY,
  THRILLER
};

class Cinema;

class Movie
{
private:
    float ranking;
    int releaseDate;
    int characterNumber;
    int ticketPrice;
    string id;
    string title;
    string comment;
    MovieType type;


public:

    Movie();
    Movie(string, string, float, int, int, int, string, MovieType);
    ~Movie();

    string getTitle();

    friend void filter(vector <Movie> &);

    friend void sortByDate(vector <Movie> &, int, int);

    friend int calculateProfit(vector <Cinema> &, Movie*, int);
};


class Cinema
{
private:
    string name;
    string location;
    vector <Movie> moviesInCinema;
    int moviesNumber=0;
    vector <int*> money;


public:
    Cinema();
    Cinema(string, string);
    ~Cinema();

    int getMovNum();

    void addMovie(Movie);

    void setTicketsSold (int, int, int);

    friend int calculateProfit(vector <Cinema> &, Movie*, int);
};



void filter (vector <Movie> &);

//int CalculateProfit(vector <Cinema> &, Movie*, int);

void initialization(vector <Movie> &, vector <Cinema> &);

void sortByDate(vector <Movie> &, int, int);
