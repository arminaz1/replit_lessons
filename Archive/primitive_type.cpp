#include <iostream>
#include "primitve_type.h"
using namespace std;
#include <iostream>
#include <cstddef> // Required for nullptr_t

using namespace std;

void primitiveType() {
  cout << "Type\t\t\tSize (bytes)\tExample Value\n";
      cout << "---------------------------------------------------------\n";

      // Boolean
      bool val_bool = true;
      cout << "bool\t\t\t" << sizeof(val_bool) << "\t\t" << val_bool << "\n";

      // Character Types
      char val_char = 'A';
      cout << "char\t\t\t" << sizeof(val_char) << "\t\t" << val_char << "\n";

      signed char val_schar = -65;
      cout << "signed char\t\t" << sizeof(val_schar) << "\t\t" << (int)val_schar << "\n";

      unsigned char val_uchar = 200;
      cout << "unsigned char\t\t" << sizeof(val_uchar) << "\t\t" << (int)val_uchar << "\n";

  #ifdef __cpp_char8_t
      char8_t val_char8 = u8'X';
      cout << "char8_t\t\t\t" << sizeof(val_char8) << "\t\t" << (char)val_char8 << " = " << (unsigned int)val_char8 << "\n";
  #endif

      char16_t val_char16 = u'A';
      cout << "char16_t\t\t" << sizeof(val_char16) << "\t\t" << (char)val_char16 << " = " << (unsigned int)val_char16 << "\n";

      char32_t val_char32 = U'A';
      cout << "char32_t\t\t" << sizeof(val_char32) << "\t\t" << (char)val_char32 << " = " << (unsigned int)val_char32 << "\n";

      wchar_t val_wchar = L'Z';
      cout << "wchar_t\t\t\t" << sizeof(val_wchar) << "\t\t" << (char)val_wchar << " = " << (unsigned int)val_wchar << "\n";

      // Signed Integers
      short val_short = -32768;
      cout << "short\t\t\t" << sizeof(val_short) << "\t\t" << val_short << "\n";

      int val_int = -2147483648;
      cout << "int\t\t\t" << sizeof(val_int) << "\t\t" << val_int << "\n";

      long val_long = -2147483648L;
      cout << "long\t\t\t" << sizeof(val_long) << "\t\t" << val_long << "\n";

      long long val_llong = -9223372036854775807LL;
      cout << "long long\t\t" << sizeof(val_llong) << "\t\t" << val_llong << "\n";

      // Unsigned Integers
      unsigned short val_ushort = 65535U;
      cout << "unsigned short\t\t" << sizeof(val_ushort) << "\t\t" << val_ushort << "\n";

      unsigned int val_uint = 4294967295U;
      cout << "unsigned int\t\t" << sizeof(val_uint) << "\t\t" << val_uint << "\n";

      unsigned long val_ulong = 4294967295UL;
      cout << "unsigned long\t\t" << sizeof(val_ulong) << "\t\t" << val_ulong << "\n";

      unsigned long long val_ullong = 18446744073709551615ULL;
      cout << "unsigned long long\t" << sizeof(val_ullong) << "\t\t" << val_ullong << "\n";

      // Floating-Point Types
      float val_float = 3.14159f;
      cout << "float\t\t\t" << sizeof(val_float) << "\t\t" << val_float << "\n";

      double val_double = 3.141592653589793;
      cout << "double\t\t\t" << sizeof(val_double) << "\t\t" << val_double << "\n";

      long double val_ldouble = 3.14159265358979323846L;
      cout << "long double\t\t" << sizeof(val_ldouble) << "\t\t" << val_ldouble << "\n";

      // Null Pointer Type
      nullptr_t val_nullptr = nullptr;
      cout << "nullptr_t\t\t" << sizeof(val_nullptr) << "\t\t" << "nullptr" << "\n";
}
