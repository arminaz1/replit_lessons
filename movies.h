#ifndef MOVIES_H
#define MOVIES_H
#include <vector>
#include "movie.h"

class Movies{
  private:
  std::vector<Movie> m_movies;

  public:

  // Movies(const Movie& add_movie)
  // {
  //     m_movies.push_back(add_movie);
  // }
  // int number_of_movies(){std::cout<<Movie::m_s_count << std::endl; return Movie::m_s_count;}
bool add_movie(const Movie& movie);
const std::vector<Movie>& get_collection() const {
    return m_movies;
}


};

#endif