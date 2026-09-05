// #include <iostream>
// #include <string>

// class Hero{
// public:
//   std::string name;
//   int hp;
// };
// int main(){
//   Hero h1;
//   h1.name = "M";
//   h1.hp = 100;
//   std::cout<< "Hero Hp = "<<h1.hp<< " \n";
// }

#include <iostream>
int thisMyF()
{
	std::cout << "Enter a Number: ";
	int x{0};
	std::cin >> x ;
	return x;
}

int main()
{
	int Value{thisMyF()};
	std::cout<<"The Value: " << Value << "\n";
	Value = thisMyF();
	std::cout<<"The Value: " << Value << "\n";
	
	return 0; 
}