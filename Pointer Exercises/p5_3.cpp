/*
## Exercise P5.3: When There Is No Target

*(Covers: null check inside a function, leaving early with `return;`)*

**Requirements:**

1. Start from your P5.2 program. In `main`, declare `int speed{50};`.
2. Before changing anything, call `set_speed(nullptr, 999);` as the last line of `main`, run it, and copy what the shell reports into a comment. Then remove or comment out that call.
3. Edit `set_speed`. As its first action, check whether `target` is null. If it is, print `set_speed: no target` and leave the function immediately, so nothing below the check runs.
4. In `main`, make three calls, printing `speed` after each:
   - `set_speed(&speed, 70);`
   - `set_speed(nullptr, 999);`
   - `set_speed(&speed, 80);`
5. Add a comment: what would happen if the null branch printed the message but didn't leave the function? Which line would crash?

**Hints:**
- A function that returns nothing can leave early with a bare `return;`.
- You've written this check before, in P4. The new part is what happens after the message.
- Put the final `speed` print last, to confirm the program ran to the end.

Compile with `-Wall -Wextra -Werror -pedantic`. Paste the code and its output.*/

#include <iostream> 

void set_speed(int* target, int new_value);


int main(){
  int speed{50};
  // set_speed(&speed, 999);
  set_speed(&speed, 70);
  set_speed(nullptr, 999);
  set_speed(&speed, 80);
  
  return 0;
}
void set_speed(int* target, int new_value){
  
  std::cout << "\n↓↓↓↓↓↓↓↓*set_speed*↓↓↓↓↓↓↓↓\n" << std::endl;
  if (target == nullptr) {
    std::cout << "!!!!!!!NO TARGET!!!!!! " << std::endl;
    return;
  }
  
  *target = new_value;
  std::cout << "target : " << target << " | &target : " << &target << std::endl; // target itself is addresss holder, and the &target is the address of this address holder
  std::cout << "\n*target : " << *target << std::endl; 
  
  std::cout << "\n↑↑↑↑↑↑↑*set_speed*↑↑↑↑↑↑↑↑\n" << std::endl;
}


/*↓↓↓↓↓↓↓↓*set_speed*↓↓↓↓↓↓↓↓

Segmentation fault*/



/*↓↓↓↓↓↓↓↓*set_speed*↓↓↓↓↓↓↓↓

target : 0x7ffd4cf50b74 | &target : 0x7ffd4cf50b48

*target : 70

↑↑↑↑↑↑↑*set_speed*↑↑↑↑↑↑↑↑


↓↓↓↓↓↓↓↓*set_speed*↓↓↓↓↓↓↓↓

!!!!!!!NO TARGET!!!!!! 

↑↑↑↑↑↑↑*set_speed*↑↑↑↑↑↑↑↑


↓↓↓↓↓↓↓↓*set_speed*↓↓↓↓↓↓↓↓

target : 0x7ffd4cf50b74 | &target : 0x7ffd4cf50b48

*target : 80

↑↑↑↑↑↑↑*set_speed*↑↑↑↑↑↑↑↑*/