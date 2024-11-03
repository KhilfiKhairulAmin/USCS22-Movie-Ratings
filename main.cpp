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
using namespace std;

/*---------------------------------------------- STRUCT AND CLASS -----------------------------------------------*/

struct Movie
{
    int id;
    string title;
    int year;
    int ratings;
};

class MovieManager
{
    private:
        const int SIZE = 200;
        Movie* const movies = new Movie[SIZE]();

        static int totalMovies;
        
        void save();

    public:
        MovieManager();
        void printMovies();
        int mainProgram();
        int getTotalMovies() { return totalMovies; }
};

int MovieManager::totalMovies = 0;

/*----------------------------------------------- MAIN FUNCTION ------------------------------------------------*/

int main()
{
    MovieManager manager = MovieManager();
    manager.printMovies();
}

/*-------------------------------------------- FUNCTION DEFINITION ---------------------------------------------*/

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
        movies[cur].year = stoi(year);
        movies[cur].ratings = stoi(ratings);

        totalMovies += 1;
    }
    inFile.close();
}

void MovieManager::save()
{
  ofstream outFile("movies.txt");

  cout << "id|title|year|ratings\n";
  int cur = 0;
  while(movies->title != "")
  {
    outFile << movies->title << "|" << movies->year << "|" << movies->ratings << "\n";
  }
}

void MovieManager::printMovies()
{

    for (int i = 0; i < totalMovies; i++)
    {
        Movie m = *(movies+i);
        cout << "Movie ID: " << m.id << ", Title: " << m.title << ", Year: " << m.year << ", Ratings: " << m.ratings << "\n"; 
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
            cin >> s.year;
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
