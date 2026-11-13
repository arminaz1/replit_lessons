
#include <iostream>
#include <string>
#include <utility>

#include "movie.h"
#include "get_rating_rank.h"

// Constructor
Movie::Movie(std::string name, std::string rating)
    : m_name{name},
      m_rating{rating},
      m_num_movie_s_been_watched{0}
{
    std::cout << "\n[CONSTRUCTOR]\n"
              << "A new Movie object was created.\n"
              << "Name: " << m_name << '\n'
              << "Rating: " << m_rating << '\n'
              << "Watched: " << m_num_movie_s_been_watched << '\n';
}

// Copy constructor
Movie::Movie(const Movie& other)
    : m_name{other.m_name},
      m_rating{other.m_rating},
      m_num_movie_s_been_watched{other.m_num_movie_s_been_watched}
{
    std::cout << "\n[COPY CONSTRUCTOR]\n"
              << "A new Movie object was created by COPYING another object.\n"
              << "Copied movie: " << m_name << '\n'
              << "Rating: " << m_rating << '\n'
              << "Watched: " << m_num_movie_s_been_watched << '\n';
}

// Copy assignment operator
Movie& Movie::operator=(const Movie& other)
{
    if (this != &other) {
        this->m_name = other.m_name;
        this->m_rating = other.m_rating;
        this->m_num_movie_s_been_watched =
            other.m_num_movie_s_been_watched;
    }

    std::cout << "\n[COPY ASSIGNMENT]\n"
              << "An EXISTING Movie object received a COPY of another object.\n"
              << "Destination movie: " << this->m_name << '\n'
              << "Source movie: " << other.m_name << '\n'
              << "Rating: " << this->m_rating << '\n'
              << "Watched: " << this->m_num_movie_s_been_watched << '\n';

    return *this;
}

// Move constructor
Movie::Movie(Movie&& other) noexcept
    : m_name{std::move(other.m_name)},
      m_rating{std::move(other.m_rating)},
      m_num_movie_s_been_watched{other.m_num_movie_s_been_watched}
{
    std::cout << "\n[MOVE CONSTRUCTOR]\n"
              << "A new Movie object was created by MOVING another object.\n"
              << "Destination movie: " << m_name << '\n'
              << "Source movie (moved-from): " << other.m_name << '\n'
              << "Watched: " << m_num_movie_s_been_watched << '\n';
}

// Move assignment operator
Movie& Movie::operator=(Movie&& other) noexcept
{
    if (this != &other) {
        this->m_name = std::move(other.m_name);
        this->m_rating = std::move(other.m_rating);
        this->m_num_movie_s_been_watched =
            other.m_num_movie_s_been_watched;
    }

    std::cout << "\n[MOVE ASSIGNMENT]\n"
              << "An EXISTING Movie object received another object's resources by MOVING.\n"
              << "Destination movie: " << this->m_name << '\n'
              << "Source movie (moved-from): " << other.m_name << '\n'
              << "Watched: " << this->m_num_movie_s_been_watched << '\n';

    return *this;
}

// Addition operator
Movie Movie::operator+(const Movie& other) const
{
    std::string new_movie_name = this->m_name + other.m_name;

    int a_rating = get_rating_rank(this->m_rating);
    int b_rating = get_rating_rank(other.m_rating);

    std::string rating{};

    if (a_rating > b_rating) {
        rating = this->m_rating;
    } else {
        rating = other.m_rating;
    }

    Movie new_movie{new_movie_name, rating};

    return new_movie;
}

// Display movie
void Movie::getter_display_movie() const
{
    std::cout << "\t | Movie: " << m_name
              << " | Rating: " << m_rating
              << " | Watched: " << m_num_movie_s_been_watched
              << '\n';
}

// Increment watched count
void Movie::watched_movie()
{
    m_num_movie_s_been_watched++;
}

// Getters
std::string Movie::getter_name() const
{
    return m_name;
}

std::string Movie::getter_rating() const
{
    return m_rating;
}

int Movie::getter_num_movie_watched() const
{
    return m_num_movie_s_been_watched;
}
