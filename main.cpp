/*-------------------------------------------------- INCLUDES ---------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

/*---------------------------------------------- STRUCT AND CLASS -----------------------------------------------*/

struct Movie
{
    int id = 0;
    string title = "";
    int *year;
    int ratings = 0;
};

class MovieManager
{
    private:
        const int SIZE = 200;
        Movie* const movies = new Movie[SIZE]();

        static int movieCount;
        static int highestId;
        
        void save();

    public:
        MovieManager();
        ~MovieManager();
        Movie* addMovie(string title, int year, int ratings);
        Movie* searchId(int id);
        Movie* searchTitle(string title);
        Movie* searchYear(int year);
        Movie* searchRatings(int ratings);
        void deleteMovie(int id);
        void printMovies();
        static void printMovies(Movie* movieArray);
        static void printMovie(Movie movie);
        
        Movie* getAllMovies() { return movies; }
        int getMovieCount() { return movieCount; }
};

int MovieManager::movieCount = 0;
int MovieManager::highestId = 0;

/*----------------------------------------------- MAIN FUNCTION ------------------------------------------------*/

int main()
{
    MovieManager manager = MovieManager();
    while(true)
    {
        int func;
        cout << "what function do you want to do: \n" << "1.View movies\n2.Input movie\n3.Calculate average rating\n4.Search movie\n5.Edit movie\n6.Delete movie\n7.Exit\n";
        cout << "----------\nfunction: ";
        cin >> func;
        cin.ignore();
        cout << endl;
        
        if(func==1)
        {
            string temp;
            if (manager.getMovieCount() == 0)
            {
                cout << "No movies available." << endl;
            }
            else
            {
                manager.printMovies();
            }
            getline(cin, temp);
            system("cls");
        }
        else if (func==2)
        {
            string s;
            int year, ratings;
            //sini buat cls tapi aq punya macbook xleh (cls= clear screen)
            cout << "----------\nINPUT DATA\n------------\n";
            cout << "Enter the movie name: ";
            getline(cin,s);
            cout << "Enter the year the movie was released: ";
            cin >> year;
            cin.ignore();
            cout << "Enter the movie rating: ";
            cin >> ratings;
            cin.ignore();
            manager.addMovie(s, year, ratings);
            cout << "Movie added.";
            getline(cin, s);
            system("cls");

            //function file
        }
        else if(func==3)
        {
            //recursive function average
        }
        else if(func==4)
        {
            cout << "Search by:\n1.Id    2.Title    3.Year    4.Ratings\nChoose: ";
            int choose;
            cin >> choose;
            cin.ignore();
            if (choose == 1)
            {
                cout << endl << "Enter ID to search: ";
                int id;
                cin >> id;
                cin.ignore();

                Movie* searchResult = manager.searchId(id);
                if (searchResult != NULL)
                {
                    manager.printMovie(*searchResult);
                }
                else
                {
                    cout << "Movie with ID " << id << " doesn't exist." << endl;
                }
            }
            else if (choose == 2)
            {
                cout << endl << "Enter Title to search: ";
                string title;
                getline(cin, title);

                Movie* searchResult = manager.searchTitle(title);
                if (searchResult != NULL)
                {
                    manager.printMovies(searchResult);
                }
                else
                {
                    cout << "None." << endl;
                }
            }
            else if (choose == 3)
            {
                cout << endl << "Enter Year to search: ";
                int year;
                cin >> year;
                cin.ignore();

                Movie* searchResult = manager.searchYear(year);
                if (searchResult != NULL)
                {
                    manager.printMovies(searchResult);
                }
                else
                {
                    cout << "None." << endl;
                }
            }
            else if (choose == 4)
            {
                cout << endl << "Enter Year to search: ";
                int ratings;
                cin >> ratings;
                cin.ignore();

                Movie* searchResult = manager.searchRatings(ratings);
                if (searchResult != NULL)
                {
                    manager.printMovies(searchResult);
                }
                else
                {
                    cout << "None." << endl;
                }
            }
            string temp;
            getline(cin, temp);
        }
        else if(func==5)
        {
            // Nantila buat, malas :3
        }
        else if(func==6)
        {
            int id;
            cout << "Enter Movie ID to delete: ";
            cin >> id;
            cin.ignore();

            manager.deleteMovie(id);
            cout << "Deleted.";
            string temp;
            getline(cin, temp);
        }
        else if(func==7)
        {
            return 0;
        }
        else
        {
            cout << "Wrong function number entered.";
        }
        system("cls");
    }
    return 0;
}

/*-------------------------------------------- FUNCTION DEFINITION ---------------------------------------------*/

/* When created, automatically loads all movies from text file and store them inside a pointer inside the class */
MovieManager::MovieManager()
{
    ifstream inFile("movies.txt");

    if (!inFile)
    {
        // Create new text file if it failed to open
        ofstream outFile("movies.txt");
        outFile << "id|title|year|ratings\n";
        outFile.close();
    }

    string line;
    getline(inFile, line);
    int cur = 0;
    while (getline(inFile, line))
    {
        string id, title, year, ratings;

        int i = 0;
        int temp = line.find("|");
        while(i != temp) id += line[i++];
        i++;
        temp = line.find("|", i);
        while(i != temp) title += line[i++];
        i++;
        temp = line.find("|", i);
        while(i != temp) year += line[i++];
        i++;
        while(i < line.length()) ratings += line[i++];

        //movies[cur].id = stoi(id);
        stringstream ss(id);
        ss >> movies[cur].id;
        movies[cur].title = title;
        stringstream ss2(year);
        int yearNumber;
        ss2 >> yearNumber;
        movies[cur].year = &yearNumber;
        stringstream ss3(ratings);
        ss3 >> movies[cur].ratings;

        highestId = movies[cur].id;
        movieCount += 1;
        cur++;
    }
    inFile.close();
}

/* Clears all DMA when program ends */
MovieManager::~MovieManager()
{
    // Make sure to save to text file before program ends
    save();

    // Free movies from memory
    delete[] movies;
}

/* Write all movies data into text file */
void MovieManager::save()
{
  ofstream outFile("movies.txt");

  outFile << "id|title|year|ratings\n";
  int cur = 0;
  for (int i = 0; i < movieCount; i++)
  {
    outFile << movies[i].id << "|" << movies[i].title << "|" << *(movies[i].year) << "|" << movies[i].ratings << "\n";
  }
}

/* Print all data about movies */
void MovieManager::printMovies()
{

    for (int i = 0; i < movieCount; i++)
    {
        Movie m = *(movies+i);
        cout << "Movie ID: " << m.id << ", Title: " << m.title << ", Year: " << *(m.year) << ", Ratings: " << m.ratings << "\n"; 
    }
}

/* Print all data about movies inside the given array pointer */
void MovieManager::printMovies(Movie* movieArray)
{
    int i = 0;
    while ((movieArray+i)->title != "")
    {
        Movie m = *(movieArray+i);
        printMovie(m);
        i++; 
    }
}

/* Print data about one movie inside the given array pointer */
void MovieManager::printMovie(Movie movie)
{
    cout << "Movie ID: " << movie.id << ", Title: " << movie.title << ", Year: " << *(movie.year) << ", Ratings: " << movie.ratings << "\n";
}

/* Create new movie and store it inside the pointer array */
Movie* MovieManager::addMovie(string title, int year, int ratings)
{
    int* yearDMA = new int(year);
    movies[movieCount].id = ++highestId;
    movies[movieCount].title = title;
    movies[movieCount].year = yearDMA;
    movies[movieCount].ratings = ratings;

    movieCount++;

    return movies+movieCount-1;
}

/* Search for a movie based on given movie id */
Movie* MovieManager::searchId(int id)
{
    for (int i = 0; i < movieCount; i++)
    {
        if (movies[i].id == id)
        {
            return movies+i;
        }
    }
    return NULL;
}

/* Convert a string to lowercase */
string toLowerCase(const string &str)
{
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

/* Search for movies based on given movie title */
Movie* MovieManager::searchTitle(string title)
{
    Movie* result = new Movie[SIZE]();
    title = toLowerCase(title);
    int cur = 0;
    for (int i = 0; i < movieCount; i++)
    {
        if (toLowerCase(movies[i].title).find(title) != string::npos)
        {
            result[cur] = movies[i];
            cur++;
        }
    }
    if (cur == 0)
    {
        return NULL;
    }
    return result;
}

/* Search for movies based on given year */
Movie* MovieManager::searchYear(int year)
{
    Movie* result = new Movie[SIZE]();
    int cur = 0;
    for (int i = 0; i < movieCount; i++)
    {
        if (*(movies[i].year) == year)
        {
            result[cur] = movies[i];
            cur++;
        }
    }
    if (cur == 0)
    {
        return NULL;
    }
    return result;
}

/* Search for movies based on given ratings */
Movie* MovieManager::searchRatings(int ratings)
{
    Movie* result = new Movie[SIZE]();
    int cur = 0;
    for (int i = 0; i < movieCount; i++)
    {
        if (movies[i].ratings == ratings)
        {
            result[cur] = movies[i];
            cur++;
        }
    }
    if (cur == 0)
    {
        return NULL;
    }
    return result;
}

/* Delete movie based on given id */
void MovieManager::deleteMovie(int id)
{
    Movie* m = searchId(id);

    // Id doesn't exist
    if (m == NULL)
    {
        return;
    }

    int curIndex = m - getAllMovies();
    movieCount--;
    delete m->year;
    if (curIndex == movieCount)
    {
        if (movieCount > 1)
        {
            highestId = (m-1)->id;
        }
        return;
    }
    else
    {
        for (int i = curIndex; i < movieCount; i++)
        {
            Movie* m_cur = movies+i, m_next = movies[i+1];
            m_cur->id = m_next.id;
            m_cur->title = m_next.title;
            m_cur->year = m_next.year;
            m_cur->ratings = m_next.ratings;
        }
    }
}
