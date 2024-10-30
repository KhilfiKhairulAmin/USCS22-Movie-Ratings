#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "Movie.h"
using namespace std;


void loadMovies(Movie* movies)
{
  ifstream inFile("movies.txt");

  if (!inFile)
  {
    cout << "Load Movies failed." << endl;
    return;
  }

  string line;
  getline(inFile, line);
  int cur = 0;
  while (getline(inFile, line))
  {
    int i = 0;
    int temp = line.find("|");
    while(i != temp) movies[cur].title += line[i++];
    i++;
    temp = line.find("|", i);
    while(i != temp) movies[cur].releaseYear += line[i++];
    i++;
    while(i < line.length()) movies[cur].ratings += line[i++];
  }
}

void saveMovies(Movie* movies)
{
  ofstream outFile("movies.txt");

  if (!outFile)
  {
    cout << "Save Movies failed." << endl;
    return;
  }

  cout << "Title|Release_Year|Ratings\n";

  int cur = 0;
  while(movies->title != "")
  {
    outFile << movies->title << "|" << movies->releaseYear << "|" << movies->ratings << "\n";
  }
}






int main()
{
  Movie movies[100];
  Movie* moviesPtr = movies;
  movies[1].title = "John Wick 2";
  loadMovies(moviesPtr);
  movies[1].releaseYear = 2018;
  movies[1].ratings = 100;
  cout << movies[0].title << endl;
  cout << movies[1].title << endl;
  saveMovies(moviesPtr);
}


