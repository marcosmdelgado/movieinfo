#ifndef RATING_H
#define RATING_H

#include <iostream>

namespace MMD
{
    namespace Utilities
    {
        class Rating
        {
        public:
            Rating();

	    void Clear();
	    void JsonToRatings(std::string text);

	    std::string Source();
	    void Source(std::string source);

	    std::string Value();
	    void Value(std::string  value);

	 private:
	    std::string  source;
	    std::string  value;
	};

    } //!< @namespace Utilities
} //!< @namespace MyCompany

#endif // RATING_H
