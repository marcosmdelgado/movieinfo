#ifndef RESTOMDB_H
#define RESTOMDB_H

#include <iostream>
#include <list>
//#include <map>
#include <curl/curl.h>
//#include "libs/curl/curl.h"

#include <../external/json.hpp>
typedef nlohmann::json Json;

#include "Movie.h"

namespace MMD
{
    namespace Utilities
    {
        typedef enum class ErrorRestOMDB
        {
           NoError = 0,
           ErrorInit
        }ErrorRestOMDB;

        typedef enum class TypeMovie
        {
           none=0,
           movie,
           series,
           episode
        }TypeMovie;

        class RestOMDB
        {
        public:
            RestOMDB();
            RestOMDB(std::string url);
            ~RestOMDB();

            bool Search(std::string movie, TypeMovie typeMovie);
            bool Title(std::string movie, TypeMovie typeMovie);
            ErrorRestOMDB GetError(){return errorCode;}

            std::list<Movie> Movies();

            Json  Content(){ return bodyContent;}

        protected:
            static size_t WriteCallBack(void* contents, size_t size, size_t nmemb, void *userp);

        private:
            void          Initialize();
            bool          MakeMovieList();
            std::string   GetValueJson( Json* bodyContent, std::string key );
            CURL*         curl;
            CURLcode      res;
            std::string   url;
            std::string   readBuffer;
            std::string   body;
            ErrorRestOMDB errorCode;
            std::string   key;

            Json          bodyContent;
            std::list<Movie> movies;
        };


    } //!< @namespace Utilities
} //!< @namespace MMD

#endif // RESTOMDB_H
