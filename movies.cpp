#include "movies.h"
#include <vector>
#include <string>

/// MOVIES ///
bool Movies::add_movie(const Movie& movie) {
    for (size_t i = 0; i < m_movies.size(); ++i) {
        if (movie.getter_name() == m_movies.at(i).getter_name()) {
            return false;
        }
    }

    m_movies.push_back(movie);
    return true;
}

