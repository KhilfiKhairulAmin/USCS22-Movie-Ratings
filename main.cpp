//
//  main.cpp
//  movieAssign
//
//  Created by Apple on 10/29/24.
//

#include <iostream>
using namespace std;

struct Movie
{
    string title;
    int year;
    int rating;
};


int main()
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
