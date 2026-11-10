#include <iostream>
#include <string>
#include <vector>

class Movie {
private:
  std::string m_name;
  std::string m_rating; // I think I coulld add a enum or some how restric the
                        // person to choose between the list the rating;
  int m_num_movie_s_been_watched;
  inline static int m_s_count{};

  friend class Movies;
public:
  Movie(std::string name, std::string rating, int num_movie_s_been_watched);
  void getter_display_movie() const;
  int getter_number_of_movies() const;
 std::string get_name() const;
std::string get_rating() const;
  int get_num_movie_s_been_watched() const;
~Movie(){m_s_count--;}
  // void getter_display_movie()const{
  //   std::cout << "\t\t\t | Movie: " << m_name << " | Rating: " << m_rating <<
  //   " | Has been Watched: " << m_num_movie_s_been_watched << std::endl;
};

class Movies{
  private:
    std::vector<Movie> m_collection_movies;
  public:
    void add_movie(std::string name, std::string rating, int watched) {
      for (size_t i = 0; i < m_collection_movies.size(); ++i) {
          if (m_collection_movies.at(i).get_name() == name) {
              std::cout << "Error: Movie already exists!" << std::endl;
              return;
          }
      }

      m_collection_movies.push_back(Movie(name, rating, watched));
    }
    void display(){
      for(size_t i = 0; i < m_collection_movies.size() ; ++i ){
        std::cout<< m_collection_movies.at(i).get_name() << " ," << std::endl;}
    }


    bool increment_watched(std::string name){
      for (size_t i = 0; i < m_collection_movies.size(); ++i) {
        if (m_collection_movies.at(i).get_name() == name) {
          std::cout << "increase" << std::endl;
          m_collection_movies.at(i).m_num_movie_s_been_watched++;
          return true;
          }
        }
      return false;
    }

    int number_of_movies(){return Movie::m_s_count;}

};

Movie::Movie(std::string name, std::string rating, int num_movie_s_been_watched) : m_name{name}, m_rating{rating}, m_num_movie_s_been_watched{num_movie_s_been_watched} { m_s_count++;}

void Movie::getter_display_movie() const {
  std::cout << "\t\t\t | Movie: " << m_name << " | Rating: " << m_rating
            << " | Has been Watched: " << m_num_movie_s_been_watched
            << std::endl;
}
int Movie::getter_number_of_movies() const {return m_s_count;}

std::string Movie::get_name() const{return m_name;};
std::string Movie::get_rating() const{return m_rating;};
int Movie::get_num_movie_s_been_watched() const{return m_num_movie_s_been_watched;};


void increment_watched(Movies &movies, std::string name) {
    if (movies.increment_watched(name)) {
        std::cout << name << " watch incremented" <<  std::endl;
    } else {
        std::cout << name << " not found" <<  std::endl;
    }
}

int main() {
  Movies my_movies; 
  my_movies.display();
  my_movies.add_movie("Big", "PG-13",2);                 // OK
  my_movies.add_movie("Star Wars", "PG",5);             // OK
  my_movies.add_movie("Cinderella", "PG",7);           // OK.
  my_movies.display();    // Big, Star Wars, Cinderella, Ice Age
  increment_watched(my_movies,"Big");                    // OK
  increment_watched(my_movies,"Ice Age");              // OK
  my_movies.display();    // Big and Ice Age watched count incremented by 1
  increment_watched(my_movies,"XXX");         // XXX not found
  // std::cout << "\t\t\t | Movie: " <<  << std::endl;
  return 0;
}
