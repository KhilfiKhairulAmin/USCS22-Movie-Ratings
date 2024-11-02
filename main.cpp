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

/*---------------------------------------- STRUCT & FUNCTION PROTOTYPES -----------------------------------------*/

struct Movie
{
    int id;
    string title;
    int year;
    int ratings;
};

void loadMovies(Movie* movies);
void saveMovies(Movie* movies);
int mainProgram();

/*----------------------------------------------- MAIN FUNCTION ------------------------------------------------*/

int main()
{

}

/*-------------------------------------------- FUNCTION DEFINITION ---------------------------------------------*/

void loadMovies(Movie* movies)
{
    ifstream inFile("movies.txt");

    if (!inFile)
    {
        // Create new text file if it failed to open
        ofstream outFile("movies.txt");
        outFile << "id|title|year|ratings\n";
        outFile.close();
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
        while(i != temp) movies[cur].year += line[i++];
        i++;
        while(i < line.length()) movies[cur].ratings += line[i++];
    }
    inFile.close();
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
    outFile << movies->title << "|" << movies->year << "|" << movies->ratings << "\n";
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
            cin >> s.rating;
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
