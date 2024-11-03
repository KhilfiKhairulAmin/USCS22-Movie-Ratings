/*---------------------------------------------------- TODOS ----------------------------------------------------*/

// [✓] Implement Struct for movies
// TODO: Implement file read and write + debug print
// TODO: Arrays and pointers movies
// TODO: Implement class for movie management
// TODO: Recursion for calculating average ratings
// TODO: Attractive GUI using string
// TODO: Report (cover page, table of content, intro about topic, explain important codes, example output)
// ** Program must contain string input/output, struct, class, array, pointer, recursion, file operations 

/*-------------------------------------------------- INCLUDES ---------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

/*---------------------------------------------- STRUCT AND CLASS -----------------------------------------------*/

struct Movie
{
    int id;
    string title;
    int *year;
    int ratings;
};

class MovieManager
{
    private:
        const int SIZE = 200;
        Movie* const movies = new Movie[SIZE]();

        static int movieCount;
        
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
        
        Movie* getAllMovies() { return movies; }
        int getMovieCount() { return movieCount; }
};

int MovieManager::movieCount = 0;

/*----------------------------------------------- MAIN FUNCTION ------------------------------------------------*/

int main()
{
    MovieManager manager = MovieManager();
    manager.printMovies();
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

        movies[cur].id = stoi(id);
        movies[cur].title = title;
        int* yearConvert = new int(stoi(year));
        movies[cur].year = yearConvert;
        movies[cur].ratings = stoi(ratings);

        movieCount += 1;
    }
    inFile.close();
}

/* Clears all DMA when program ends */
MovieManager::~MovieManager()
{
    // Make sure to save to text file before program ends
    save();

    // Deletes all year (because `year` is a DMA)
    for (int i = 0; i < movieCount; i++)
    {
        delete movies[i].year;
    }

    // Free movies from memory
    delete[] movies;
}

/* Write all movies data into text file */
void MovieManager::save()
{
  ofstream outFile("movies.txt");

  cout << "id|title|year|ratings\n";
  int cur = 0;
  while(movies->title != "")
  {
    outFile << movies->id << "|" << movies->title << "|" << movies->year << "|" << movies->ratings << "\n";
  }
}

/* Print all data about movies */
void MovieManager::printMovies()
{

    for (int i = 0; i < movieCount; i++)
    {
        Movie m = *(movies+i);
        cout << "Movie ID: " << m.id << ", Title: " << m.title << ", Year: " << m.year << ", Ratings: " << m.ratings << "\n"; 
    }
}

/* Create new movie and store it inside the pointer array */
Movie* MovieManager::addMovie(string title, int year, int ratings)
{
    int* yearDMA = new int(year);
    movies[movieCount].id = movieCount;
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
    return result;
}

/* Delete movie based on given id */
void MovieManager::deleteMovie(int id)
{
    Movie* m = searchId(id);

    // Id doesn't exist
    if (m->title == "")
    {
        return;
    }

    int curIndex = m - getAllMovies();
    movieCount--;
    delete m->year;
    if (curIndex == movieCount)
    {
        return;
    }
    else
    {
        for (int i = curIndex; i < movieCount; i++)
        {
            movies[curIndex] = movies[curIndex+1];
        }
    }
}

int mainProgram()
{
    while(true)
    {
        int func;
        cout << "what function do you want to do: " << endl << "1.See data\n2.Input data\n3.Calculate average rating\n";
        cout << "----------\nfunction: ";
        cin >> func;
        
        if(func==1)
        {
            //see data function
        }
        else if (func==2)
        {
            Movie s;
            //sini buat cls tapi aq punya macbook xleh (cls= clear screen)
            cout << "----------\nINPUT DATA\n------------\n";
            cin.ignore();
            cout << "Enter the movie name: ";
            getline(cin,s.title);
            cout << "Enter the year the movie was released: ";
            cin >> *(s.year);
            cout << "Enter the movie rating: ";
            cin >> s.ratings;
            //function file
        }
        else if(func==3)
        {
            //recursive function average
        }
        else
        {
            cout << "Wrong function number entered.";
        }
        //mungkin sini cls
        char repeat;
        cout << "Do you want to repeat <y,n> :";
        cin >> repeat;
        if(repeat=='y' || repeat=='Y')//mungkin boleh buat to_upper or lower
        {
            continue;
        }
        else
        {
            break;
        }
        
        
    }
    return 0;
}

/* Convert a string to lowercase */
string toLowerCase(const string &str)
{
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}
