
#include <iostream>
#include <utility>
#include "movie.h"

int main()
{
    std::cout << "\n========================================\n";
    std::cout << "       MOVIE SPECIAL MEMBERS TEST\n";
    std::cout << "========================================\n";

    // ------------------------------------------------
    // STEP 1: Create the first Movie object
    // ------------------------------------------------

    std::cout << "\n[STEP 1] Creating movie1\n";
    std::cout << "Executing: Movie movie1{\"Inception\", \"PG-13\"};\n";

    Movie movie1{"Inception", "PG-13"};
    movie1.watched_movie();

    std::cout << "movie1 after creation:\n";
    movie1.getter_display_movie();


    // ------------------------------------------------
    // STEP 2: Copy constructor
    // ------------------------------------------------

    std::cout << "\n[STEP 2] COPY CONSTRUCTOR TEST\n";
    std::cout << "Executing: Movie movie2{movie1};\n";
    std::cout << "Expected: Copy constructor\n";

    Movie movie2{movie1};

    std::cout << "movie2 after copying movie1:\n";
    movie2.getter_display_movie();


    // ------------------------------------------------
    // STEP 3: Copy assignment
    // ------------------------------------------------

    std::cout << "\n[STEP 3] COPY ASSIGNMENT TEST\n";
    std::cout << "First, create movie3:\n";
    std::cout << "Executing: Movie movie3{\"Interstellar\", \"PG-13\"};\n";

    Movie movie3{"Interstellar", "PG-13"};

    std::cout << "\nNow execute: movie3 = movie1;\n";
    std::cout << "Expected: Copy assignment operator\n";

    movie3 = movie1;

    std::cout << "movie3 after copy assignment:\n";
    movie3.getter_display_movie();


    // ------------------------------------------------
    // STEP 4: Move constructor
    // ------------------------------------------------

    std::cout << "\n[STEP 4] MOVE CONSTRUCTOR TEST\n";
    std::cout << "Executing: Movie movie4{std::move(movie1)};\n";
    std::cout << "Expected: Move constructor\n";

    Movie movie4{std::move(movie1)};

    std::cout << "\nmovie4 (destination after move):\n";
    movie4.getter_display_movie();

    std::cout << "movie1 (source after move):\n";
    movie1.getter_display_movie();


    // ------------------------------------------------
    // STEP 5: Move assignment
    // ------------------------------------------------

    std::cout << "\n[STEP 5] MOVE ASSIGNMENT TEST\n";
    std::cout << "First, create movie5:\n";
    std::cout << "Executing: Movie movie5{\"The Matrix\", \"R\"};\n";

    Movie movie5{"The Matrix", "R"};

    std::cout << "\nNow execute: movie5 = std::move(movie2);\n";
    std::cout << "Expected: Move assignment operator\n";

    movie5 = std::move(movie2);

    std::cout << "\nmovie5 (destination after move):\n";
    movie5.getter_display_movie();

    std::cout << "movie2 (source after move):\n";
    movie2.getter_display_movie();


    // ------------------------------------------------
    // STEP 6: Display all final objects
    // ------------------------------------------------

    std::cout << "\n[STEP 6] FINAL STATE OF ALL OBJECTS\n";

    std::cout << "\nmovie1:\n";
    movie1.getter_display_movie();

    std::cout << "\nmovie2:\n";
    movie2.getter_display_movie();

    std::cout << "\nmovie3:\n";
    movie3.getter_display_movie();

    std::cout << "\nmovie4:\n";
    movie4.getter_display_movie();

    std::cout << "\nmovie5:\n";
    movie5.getter_display_movie();


    std::cout << "\n========================================\n";
    std::cout << "             TEST FINISHED\n";
    std::cout << "========================================\n";

    return 0;
}
