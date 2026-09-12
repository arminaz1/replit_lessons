#include <iostream>
#include "Vector_.h"
#include <vector> 
using namespace std;

void vector_example()
{
//   vector <int> vector1, vector2;
//   vector1.push_back(10); vector1.push_back(200);
// cout<< "vector1: " << vector1.at(0)<< "\t---\t" << vector1.at(1) <<  "\n" ;
//     vector2.push_back(100); vector2.push_back(200);
//   cout << "vector2: " <<vector2.at(0)<< "\t---\t" << vector2.at(1) <<  "\n" ;

//   vector <vector<int>> vector_2d;
//   vector_2d.push_back(vector1);
//   vector_2d.push_back(vector2);
//   cout << "\t---\t" << vector_2d.at(0).at(0) << "\t---\t" << 
//   vector_2d.at(0).at(1) << "\t---\t\n" <<
//   vector_2d.at(1).at(0) << "\t---\t" <<
//   vector_2d.at(1).at(1) <<  "\n" ;
//   vector1.at(0) = 33; 
//   cout << "\t---\t" << vector_2d.at(0).at(0) << "\t---\t" << 
//     vector_2d.at(0).at(1) << "\t---\t\n" <<
//     vector_2d.at(1).at(0) << "\t---\t" <<
//     vector_2d.at(1).at(1) << "\n\n";
//   cout<< "vector1: " << vector1.at(0)<< "\t---\t" << vector1.at(1) <<  "\n" ;
//   vector <vector<vector<int>>> vector_3d = 
//   {
//     {
//       {1,2,3},
//       {4,5,6},
//       {7,8,9}
//     },
//     {
//         {10,20,30},
//         {40,50,60},
//         {70,80,90}
//     },
//     {
//         {100,200,300},
//         {400,500,600},
//         {700,800,900}
//     }
//   };
//   vector_3d.at(0).at(0).at(0);

  vector<int> vector1, vector2;

  cout << "[1D] Size BEFORE allocation -> vector1: " << vector1.size() 
       << ", vector2: " << vector2.size() << "\n";

  vector1.push_back(10); 
  vector1.push_back(20);
  vector2.push_back(100); 
  vector2.push_back(200);

  cout << "[1D] Size AFTER allocation  -> vector1: " << vector1.size() 
       << ", vector2: " << vector2.size() << "\n";

  cout << "vector1: " << vector1.at(0) << "\t---\t" << vector1.at(1) << "\n";
  cout << "vector2: " << vector2.at(0) << "\t---\t" << vector2.at(1) << "\n\n";

  // ---------------------------------------------------------
  // 2. 2D Vector: Copy Semantics and Modification
  // ---------------------------------------------------------
  vector<vector<int>> vector_2d;
  cout << "[2D] Size BEFORE allocation -> vector_2d: " << vector_2d.size() << "\n";

  // push_back inserts a COPY of the vectors, not a reference
  vector_2d.push_back(vector1);
  vector_2d.push_back(vector2);

  cout << "[2D] Size AFTER allocation  -> Blocks: " << vector_2d.size() 
       << ", Elements in Block 0: " << vector_2d.at(0).size() << "\n";

  cout << "vector_2d (Initial State):\n" 
       << "\t---\t" << vector_2d.at(0).at(0) << "\t---\t" << vector_2d.at(0).at(1) << "\t---\t\n" 
       << "\t"      << vector_2d.at(1).at(0) << "\t---\t" << vector_2d.at(1).at(1) << "\n\n";

  // Modifying vector1 original variables
  vector1.at(0) = 33; 

  cout << "After changing vector1.at(0) to 33:\n";
  cout << "vector_2d (Remains Unchanged):\n" 
       << "\t---\t" << vector_2d.at(0).at(0) << "\t---\t" << vector_2d.at(0).at(1) << "\t---\t\n" 
       << "\t"      << vector_2d.at(1).at(0) << "\t---\t" << vector_2d.at(1).at(1) << "\n";
  cout << "vector1 (Changed): " << vector1.at(0) << "\t---\t" << vector1.at(1) << "\n\n";

  // ---------------------------------------------------------
  // 3. 3D Vector: Empty Declaration (No Initialization)
  // ---------------------------------------------------------
  vector<vector<vector<int>>> empty_3d;
  cout << "[3D Empty] Blocks (Z): " << empty_3d.size() << "\n\n";

  // ---------------------------------------------------------
  // 4. 3D Vector: Single Element Initialization
  // ---------------------------------------------------------
  vector<vector<vector<int>>> single_element_3d = { { { 42 } } };
  cout << "[3D Single] Sizes -> Blocks (Z): " << single_element_3d.size() 
       << ", Rows (Y): " << single_element_3d.at(0).size() 
       << ", Cols (X): " << single_element_3d.at(0).at(0).size() << "\n";
  cout << "Value retrieved: " << single_element_3d.at(0).at(0).at(0) << "\n\n";

  // ---------------------------------------------------------
  // 5. 3D Vector: Full Matrix and Mid-point Modification
  // ---------------------------------------------------------
  vector<vector<vector<int>>> vector_3d = {
      {
          {1, 2, 3}, {4, 5, 6}, {7, 8, 9}
      },
      {
          {10, 20, 30}, {40, 50, 60}, {70, 80, 90}
      },
      {
          {100, 200, 300}, {400, 500, 600}, {700, 800, 900}
      }
  };

  cout << "[3D Full] Sizes -> Blocks (Z): " << vector_3d.size() 
       << ", Rows (Y): " << vector_3d.at(0).size() 
       << ", Cols (X): " << vector_3d.at(0).at(0).size() << "\n";

  cout << "Original middle element [Block 1][Row 1][Col 1]: " 
       << vector_3d.at(1).at(1).at(1) << "\n";

  // Overwriting the center coordinate of the matrix
  vector_3d.at(1).at(1).at(1) = 9999;

  cout << "Modified middle element [Block 1][Row 1][Col 1]: " 
       << vector_3d.at(1).at(1).at(1) << "\n";

  // vector <char> char_list(5);
// vector <char> char_list_zero(5,0);
// vector <char> char_list_ini{'a', 'b', 'c', 'd', 'e'};
// vector <char> char_empty;
  // cout << char_list[0] << '\n';
  // cout << char_list[4]<< '\n';
  // cout << char_list_zero[2]<< '\n';
  // cout << char_list[0]<< '\n';
  // cout << char_empty[4]<< '\n';
  // cout << char_list[2]<< '\n';
  // cout << char_list_ini[3]<< '\n';
  // cout << char_list[4]<< '\n';
  // cout << char_list_ini[1]<< '\n';
  // cout << char_list[2]<< '\n';
  // cout << char_list_zero[3]<< '\n';
  // cout << char_empty[0] << '\n';
// vector <int> scores{1, 2, 3};
//   cout<< scores[0] << "\n" << scores[1] << "\n" << scores[2];
//   cout << "\nSizeof: " << sizeof(scores) << "--> " << scores.size();
  
//   scores.push_back(6);
  
//   cout << "\n" << scores[3];
//   cout<< scores.at(0) << "\n" << scores.at(1) << "\n" << scores.at(2) << "\n"<< scores.at(3) << "\n Size --> " << scores.size();
//   cout << "\nSizeof: " << sizeof(scores);
  

  
}