#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <list>
//#include <map>
#include "Rating.h"

namespace MMD
{
    namespace Utilities
    {
        class Movie
        {
        public:
            Movie();

	    void Clear();
	    void JsonToRatings(std::string text);

	    std::string Title();
	    void Title(std::string title);

	    std::string Year();
	    void Year(std::string  year);

	    std::string Rated();
	    void Rated(std::string rated);

	    std::string Released();
	    void Released(std::string  released);

	    std::string Runtime();
	    void Runtime(std::string runtime);

	    std::string Genre();
	    void Genre(std::string  genre);

	    std::string Director();
	    void Director(std::string director);

	    std::string Writer();
	    void Writer(std::string  writer);

	    std::string Actors();
	    void Actors(std::string  actors);

	    std::string Plot();
	    void Plot(std::string plot);

	    std::string Language();
	    void Language(std::string  language);

	    std::string Country();
	    void Country(std::string country);

	    std::string Awards();
	    void Awards(std::string  awards);

	    std::string Type();
	    void Type(std::string  type);

	    std::string Poster();
	    void Poster(std::string poster);

	    std::list<Rating> Ratings();
	    void Ratings(std::list<Rating>  ratings);
	    void AddRating(Rating rating);

	    std::string DVD();
	    void DVD(std::string dvd);

	    std::string BoxOffice();
	    void BoxOffice(std::string  boxOffice);

	    std::string Production();
	    void Production(std::string  production);

	    std::string Website();
	    void Website(std::string website);

	 private:
	    std::string  title;
	    std::string  year;
	    std::string  rated;
	    std::string  released;
	    std::string  runtime;
	    std::string  genre;
	    std::string  director;
	    std::string  writer;
	    std::string  actors;
	    std::string  plot;
	    std::string  language;
	    std::string  country;
	    std::string  awards;
	    std::string  type;
	    std::string  poster;
	    std::list<Rating> ratings;
	    std::string  dvd;
	    std::string  boxOffice;
	    std::string  production;
	    std::string  website;
	};

    } //!< @namespace Utilities
} //!< @namespace MyCompany

#endif // MOVIE_H
