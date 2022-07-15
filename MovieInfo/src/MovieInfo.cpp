#include <iostream>
#include <boost/algorithm/string/trim.hpp>
#include "RestOMDB.h"

using namespace std;
using namespace MMD::Utilities;

#define SUCESS                    0
#define ERROR_INVALID_COMMAND     1
#define ERROR_INVALID_ARGUMENTS   2
#define ERROR_TITLE_NOT_FOUND     3

/*
string GetValueArgument(string argument)
{
    string response = "";
    if(argument.length()>2)
    {
       if((argument[0]=='[') && (argument[argument.length()-1]==']'))
       {
           response = argument.substr(1,argument.length()-2);
           boost::algorithm::trim(response);
       }
    }
    return response;
}
*/


///
/// \brief PrintHelpAndExit
///
///
void PrintHelpAndExit()
{
    cout << "Usage: movieinfo [-s <movie>]" << endl;
    cout << "   or: movieinfo [-s <movie>] [-t <type>]"  << endl;
    cout << "   or: movieinfo [-a <movie>]"  << endl;
    cout << "   or: movieinfo [-a <movie>] [-t <type>]"  << endl;
    cout << "   or: movieinfo [-h]"  << endl << endl;
    cout << "Options:" << endl;
    cout << "   -s, --search  movie title to search for." << endl;
    cout << "   -a, --all     all movie title to search for." << endl;
    cout << "   -t, --type    type of result to return. (movie, series or episode)." << endl;
    cout << "   -h, --help    give this help list." << endl<< endl;
    exit(SUCESS);
}

///
/// \brief PrintCommandError
/// \param command
///
void PrintCommandErrorAndExit(string command)
{
    cout << "movieinfo: '" << command << "' is not a movieinfo command. See 'movieinfo --help'" << endl<< endl;
    exit(ERROR_INVALID_COMMAND);
}

///
/// \brief PrintTitleNotFoundAndExit
///
void PrintTitleNotFoundAndExit(string movieTitle)
{
    cout << "movieinfo: Title: '" << movieTitle <<"' not found!" << endl<< endl;
    exit(ERROR_TITLE_NOT_FOUND);
}

///
/// \brief main
/// \param argc
/// \param argv
/// \return
///
int main(int argc, char* argv[])
{

    string command;
    string movieTitle;
    TypeMovie typeMovie = TypeMovie::none;
    bool   allMovies=true;

    if( argc == 2)
    {
        command = argv[1];
        if ((command == "-h") || (command == "--help"))
        {
            PrintHelpAndExit();
        }
        else
        {
            PrintCommandErrorAndExit(command);
        }

    }
    else if( argc == 3)
    {
        command = argv[1];
        if ((command == "-s") || (command == "--search"))
        {
            movieTitle  = argv[2];
            allMovies=false;
        }
        else if ((command == "-a") || (command == "--all"))
        {
            movieTitle  = argv[2];
        }
        else
        {
            PrintCommandErrorAndExit(command);
        }
    }
    else if( argc == 5)
    {
        command = argv[1];
        if ((command == "-s") || (command == "--search")
           || (command == "-a") || (command == "--all"))
        {
            if ((command == "-s") || (command == "--search"))
            {
                allMovies=false;
            }
            movieTitle = argv[2];

            command = argv[3];
            if ((command == "-t") || (command == "--type"))
            {
                string type = argv[4];
                if (type == "movie")
                {
                    typeMovie = TypeMovie::movie;
                }
                else if (type == "series")
                {
                    typeMovie = TypeMovie::series;
                }
                else if (type == "episode")
                {
                    typeMovie = TypeMovie::episode;
                }
                else
                {
                    PrintCommandErrorAndExit(command);
                }
            }
            else
            {
                PrintCommandErrorAndExit(command);
            }
        }
        else
        {
            PrintCommandErrorAndExit(command);
        }
    }
    else
    {
        PrintCommandErrorAndExit(command);
    }

    //cout << "MovieInfo" << endl;

    try
    {
       RestOMDB restOMDB("http://www.omdbapi.com/");

       if(allMovies)
       {
          restOMDB.Search(movieTitle, typeMovie);
       }
       else
       {
          restOMDB.Title(movieTitle, typeMovie);
       }

       std::list<Movie> movies = restOMDB.Movies();

       if(movies.size()==0)
       {
          PrintTitleNotFoundAndExit(movieTitle);
       }

       for(Movie movie : movies)
       {
           std::cout << "* Title     : " << movie.Title() <<  endl;
           std::cout << "  Year      : " << movie.Year() <<  endl;
           if(!allMovies)
           {
              std::cout << "  Rated     : " << movie.Rated() <<  endl;
              std::cout << "  Released  : " << movie.Released() << endl;
              std::cout << "  Runtime   : " << movie.Runtime() <<  endl;
              std::cout << "  Genre     : " << movie.Genre() << endl;
              std::cout << "  Director  : " << movie.Director() <<  endl;
              std::cout << "  Writer    : " << movie.Writer() << endl;
              std::cout << "  Actors    : " << movie.Actors() <<  endl;
              std::cout << "  Plot      : " << movie.Plot() << endl;
              std::cout << "  Language  : " << movie.Language() << endl;
              std::cout << "  Country   : " << movie.Country() <<  endl;
              std::cout << "  Awards    : " << movie.Awards() << endl;
              std::cout << "  Poster    : " << movie.Poster() << endl;
              std::cout << "  Ratings   : " << endl;
              std::list<Rating> ratings = movie.Ratings();
              for(Rating rating : ratings)
              {
                  std::cout << "      " << rating.Source() << ": " << rating.Value() << endl;
              }
              std::cout << "  Type      : " << movie.Type() << endl;
              std::cout << "  BoxOffice : " << movie.BoxOffice() << endl;
              std::cout << "  Production: " << movie.Production() <<  endl;
              std::cout << "  Website   : " << movie.Website() <<  endl;

           }
           else
           {
              std::cout << "  Poster    : " << movie.Poster() << endl;
              std::cout << "  Type      : " << movie.Type() <<  endl<< endl;
           }

       }
    }
    catch ( exception& e )
    {
        //LogMessageError( String("Exception!").append( e.what()) );
    }

    exit(SUCESS);
}
