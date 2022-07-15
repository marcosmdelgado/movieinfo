
#include <iostream>
//#include <stdlib.h>
#include "RestOMDB.h"

using namespace std;
using namespace MMD::Utilities;

#define KEY  "852159f0"

///
/// \brief RestOMDB::RestOMDB
///
RestOMDB::RestOMDB() : errorCode{ErrorRestOMDB::NoError}
{
    Initialize();
}

///
/// \brief RestOMDB::RestOMDB
/// \param url
///
RestOMDB::RestOMDB( string url) : url{url}, errorCode{ErrorRestOMDB::NoError}
{
    Initialize();
}

///
/// \brief RestOMDB::~RestOMDB
///
RestOMDB::~RestOMDB()
{
    curl_easy_cleanup(curl);
}

///
/// \brief RestOMDB::Initialize
///
void RestOMDB::Initialize()
{
    if(!(curl = curl_easy_init()))
    {
        errorCode = ErrorRestOMDB::ErrorInit;
        throw( "RestOMDB - Object initialization error.");
    }

    key = KEY;
}

///
/// \brief RestOMDB::Movies
/// \return
///
std::list<Movie> RestOMDB::Movies()
{
    return movies;
}

///
/// \brief RestOMDB::Search
/// \param movie
/// \param typeMovie
/// \return
///
bool RestOMDB::Search(string movie, TypeMovie typeMovie)
{
    if(errorCode != ErrorRestOMDB::NoError)
        return false;

    string urlSearch;
    urlSearch.assign(url).append("?apikey=").append(key).append("&s=").append(movie);
    switch(typeMovie)
    {
      case TypeMovie::movie:
          urlSearch.append("&type=movie");
          break;
      case TypeMovie::series:
          urlSearch.append("&type=series");
          break;
      case TypeMovie::episode:
          urlSearch.append("&type=episode");
          break;

      case TypeMovie::none:
      default:
          break;
    }

    int page=1;
    bool abort = false;

    int maxPages = 100;

    while((!abort) && (page < maxPages))
    {
        string urlSearchWithPage(urlSearch);
        string response="";
        long http_code=0;

        urlSearchWithPage.append("&page=").append(to_string(page++));

        curl_easy_setopt(curl, CURLOPT_URL, urlSearchWithPage.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallBack);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response );

        res = curl_easy_perform(curl);

        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);

        if(res!=0)
        {
            return false;
        }
        else if (!response.empty())
        {
            bodyContent.clear();
            bodyContent = Json::parse(response);
            if(!MakeMovieList())
               abort = true;
        }
        else
        {
           abort = true;
        }
    }
    return true;
}

///
/// \brief RestOMDB::Search
/// \param movie
/// \param typeMovie
/// \return
///
bool RestOMDB::Title(string movie, TypeMovie typeMovie)
{
   if(errorCode != ErrorRestOMDB::NoError)
        return false;

    string urlSearch;
    urlSearch.assign(url).append("?apikey=").append(key).append("&t=").append(movie);
    switch(typeMovie)
    {
      case TypeMovie::movie:
          urlSearch.append("&type=movie");
          break;
      case TypeMovie::series:
          urlSearch.append("&type=series");
          break;
      case TypeMovie::episode:
          urlSearch.append("&type=episode");
          break;
      case TypeMovie::none:
      default:
          break;
    }

    string response="";
    long http_code=0;

    curl_easy_setopt(curl, CURLOPT_URL, urlSearch.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallBack);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response );

    res = curl_easy_perform(curl);

    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);

    if(res!=0)
    {
        return false;
    }
    else if (!response.empty())
    {
        bodyContent.clear();
        bodyContent = Json::parse(response);
        if(!MakeMovieList())
           return false;
    }
    else
    {
       return false;
    }

    return true;
}

///
/// \brief RestOMDB::GetValueJson
/// \param bodyContent
/// \param key
/// \return
///
string RestOMDB::GetValueJson( Json* bodyContent, string key )
{
    if (! (*bodyContent)[key].empty())
       return (*bodyContent)[key].get<std::string>();
    return "";
}

///
/// \brief RestOMDB::MakeMovieList
/// \return
///
bool RestOMDB::MakeMovieList()
{
    if (!bodyContent["Error"].empty())
    {
        return false;
    }

    if (!bodyContent["Search"].empty())
    {
       Json search = bodyContent["Search"];
       for (auto& x : search.items())
       {
          Json jsonMovie = x.value();
          Movie movie;          
          movie.Title(GetValueJson( &jsonMovie, "Title" ));
          movie.Year(GetValueJson( &jsonMovie, "Year" ));
          movie.Type(GetValueJson( &jsonMovie, "Type" ));
          movie.Poster(GetValueJson( &jsonMovie, "Poster" ));
          movies.push_back(movie);
       }
    }
    else  // By Title
    {
       Movie movie;
       movie.Title(GetValueJson( &bodyContent, "Title" ));
       movie.Year(GetValueJson( &bodyContent, "Year" ));
       movie.Rated(GetValueJson( &bodyContent, "Rated" ));
       movie.Released(GetValueJson( &bodyContent, "Released" ));
       movie.Runtime(GetValueJson( &bodyContent, "Runtime" ));
       movie.Genre(GetValueJson( &bodyContent, "Genre" ));
       movie.Director(GetValueJson( &bodyContent, "Director" ));
       movie.Writer(GetValueJson( &bodyContent, "Writer" ));
       movie.Actors(GetValueJson( &bodyContent, "Actors" ));
       movie.Plot(GetValueJson( &bodyContent, "Plot" ));
       movie.Language(GetValueJson( &bodyContent, "Language" ));
       movie.Country(GetValueJson( &bodyContent, "Country" ));
       movie.Awards(GetValueJson( &bodyContent, "Awards" ));
       movie.Poster(GetValueJson( &bodyContent, "Poster" ));
       movie.Type(GetValueJson( &bodyContent, "Type" ));
       movie.DVD(GetValueJson( &bodyContent, "DVD" ));
       movie.BoxOffice(GetValueJson( &bodyContent, "BoxOffice" ));
       movie.Production(GetValueJson( &bodyContent, "Production" ));
       movie.Website(GetValueJson( &bodyContent, "Website" ));

       //Ratings
       if (!bodyContent["Ratings"].empty())
       {
           Json jsonRatings = bodyContent["Ratings"];
           for (auto& x : jsonRatings.items())
           {
               Json jsonRating= x.value();
               Rating rating;
               rating.Source(GetValueJson( &jsonRating, "Source" ));
               rating.Value(GetValueJson( &jsonRating, "Value" ));
               movie.AddRating(rating);
           }
       }
       movies.push_back(movie);
   }
   return true;
}


///
/// \brief RestOMDB::WriteCallBack
/// \param contents
/// \param size
/// \param nmemb
/// \param userp
/// \return
///
size_t RestOMDB::WriteCallBack(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}
