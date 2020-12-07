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
    string Id;
    string Title;
    float Ranking;
    int ReleaseDate;
    int CharacterNumber;
    int TicketPrice;
    string Comment;
    MovieType Type;


public:

    Movie();
    Movie(string, string, float, int, int, int, string, MovieType);
    ~Movie();

    string getTitle();

    friend void Filter(vector <Movie> &);

    friend void sortbydate(vector <Movie> &, int, int);

    friend int CalculateProfit(vector <Cinema> &, Movie*, int);
};


class Cinema
{
private:
    string Name;
    string Location;
    vector <Movie> MoviesInCinema;
    int MoviesNumber=0;
    vector <int*> money;


public:
    Cinema();
    Cinema(string, string);
    ~Cinema();

    int getMovNum();

    void AddMovie(Movie);

    void setTicketsSold (int, int, int);

    friend int CalculateProfit(vector <Cinema> &, Movie*, int);
};



void Filter (vector <Movie> &);

//int CalculateProfit(vector <Cinema> &, Movie*, int);

void initialization(vector <Movie> &, vector <Cinema> &);

void sortbydate(vector <Movie> &, int, int);
