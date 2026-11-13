#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <utility>

class Movie {
private:
  std::string m_name;
  std::string m_rating;
  int m_num_movie_s_been_watched;
  

public:

  Movie(std::string name, std::string rating);
  Movie(const Movie& other);
  Movie& operator=(const Movie& other);
  
  Movie(Movie&& other) noexcept;
  Movie& operator=(Movie&& other) noexcept;


  Movie operator+(const Movie& other) const;
  void getter_display_movie() const;
  

  void watched_movie();

  std::string getter_name() const;
  std::string getter_rating() const;
  int getter_num_movie_watched() const; 

};

#endif