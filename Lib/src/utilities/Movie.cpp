
#include "Movie.h"

using namespace std;
using namespace MMD::Utilities;

Movie::Movie()
      : title{""}
      , year{""}
      , rated{""}
      , released{""}
      , runtime{""}
      , genre{""}
      , director{""}
      , writer{""}
      , actors{""}
      , plot{""}
      , language{""}
      , country{""}
      , awards{""}
      , type{""}
      , poster{""}
{
}

void Movie::Clear()
{
    title.clear();
    year.clear();
    rated.clear();
    released.clear();
    runtime.clear();
    genre.clear();
    director.clear();
    writer.clear();
    actors.clear();
    plot.clear();
    language.clear();
    country.clear();
    awards.clear();
    type.clear();
    poster.clear();
    ratings.clear();
}

string Movie::Title()
{
    return title;
}

void Movie::Title(std::string title)
{
    this->title = title;
}

string Movie::Year()
{
    return year;
}

void Movie::Year(std::string year)
{
    this->year = year;
}

string Movie::Rated()
{
    return rated;
}

void Movie::Rated(std::string rated)
{
    this->rated = rated;
}

std::string Movie::Released()
{
    return released;
}

void Movie::Released(std::string released)
{
    this->released = released;
}

string Movie::Runtime()
{
    return runtime;
}

void Movie::Runtime(std::string runtime)
{
    this->runtime = runtime;
}

string Movie::Genre()
{
    return genre;
}

void Movie::Genre(std::string genre)
{
    this->genre = genre;
}

string Movie::Director()
{
    return director;
}

void Movie::Director(std::string director)
{
    this->director = director;
}

std::string Movie::Writer()
{
    return writer;
}

void Movie::Writer(std::string writer)
{
    this->writer = writer;
}

string Movie::Actors()
{
    return actors;
}

void Movie::Actors(std::string actors)
{
    this->actors = actors;
}

string Movie::Plot()
{
    return plot;
}

void Movie::Plot(std::string plot)
{
    this->plot = plot;
}

string Movie::Language()
{
    return language;
}

void Movie::Language(std::string language)
{
    this->language = language;
}

string Movie::Country()
{
    return country;
}

void Movie::Country(std::string country)
{
    this->country = country;
}

string Movie::Awards()
{
    return awards;
}

void Movie::Awards(std::string awards)
{
    this->awards = awards;
}

string Movie::Type()
{
    return type;
}

void Movie::Type(std::string type)
{
    this->type = type;
}

string Movie::Poster()
{
    return poster;
}

void Movie::Poster(std::string poster)
{
    this->poster = poster;
}

list<Rating> Movie::Ratings()
{
    return ratings;
}

void Movie::Ratings(std::list<Rating>  ratings)
{
    this->ratings = ratings;
}

void Movie::AddRating(Rating rating)
{
    ratings.push_back(rating);
}

string Movie::DVD()
{
    return dvd;
}

void Movie::DVD(std::string dvd)
{
    this->dvd = dvd;
}

string Movie::BoxOffice()
{
    return boxOffice;
}

void Movie::BoxOffice(std::string boxOffice)
{
    this->boxOffice = boxOffice;
}

string Movie::Production()
{
    return production;
}

void Movie::Production(std::string production)
{
    this->production = production;
}

string Movie::Website()
{
    return website;
}

void Movie::Website(std::string website)
{
    this->website = website;
}
