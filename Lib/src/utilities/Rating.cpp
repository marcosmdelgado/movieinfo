
#include "Rating.h"
#include <../external/json.hpp>

using namespace std;
using namespace MMD::Utilities;

typedef nlohmann::json Json;

Rating::Rating()
: source{""}
, value{""}
{
}

void Rating::Clear()
{
    source.clear();
    value.clear();
}

string Rating::Source()
{
    return source;
}

void Rating::Source(std::string source)
{
    this->source = source;
}

std::string Rating::Value()
{
    return value;
}

void Rating::Value(std::string value)
{
    this->value = value;
}

