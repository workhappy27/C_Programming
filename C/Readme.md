
##### Datatype  
*char* character - a single byte  
*short* short integer  
*int* integers, exactly 32 bits, not platform dependent.  
*long* long integer  
*double* double-precision floating point  
*size_t* Platform dependent an unsigned integer type and an implementation‑defined unsigned integer type  
         designed to hold the size of any object in memory  
32‑bit system → 32‑bit unsigned  
64‑bit system → 64‑bit unsigned  
   
local variable are called automatic variables.  
Variables external to functions are called external variables declared with *extern keyword* .  

##### Constants
Character constants ``#define CHAR_CONSTANTS 'c'  ``  
String constants ```#define STRING_CONSTANTS "c"   ```   
Qualifier constants ``` const double e = 2.71828182845905; ```  
Enumeration constants ```enum boolean { NO, YES }  ```  

##### Arithmetic operators  
``` +, -, *, / ```  

##### Relational and Logical operators  
Relational operators are ``` > >= < <= ```  
Equality operators are ``` == and != ```  
Logical operators are ``` && and || ```  

##### Type conversions  
Convert a narrower operand into a wider operand.  
i) char - int   
     char c = '7';  
     int n = c-'0'; Though int n = c-48; is corrent, it may be intepretted as magic number.   

· If either operand is long double, convert the other to long double.   
· Otherwise, if either operand is double, convert the other to double.   
· Otherwise, if either operand is float, convert the other to float.   
· Otherwise, convert char and short to int.   
· Then, if either operand is long, convert the other to long.  

##### Bitwise Operators  
``` & ```bitwise AND  
``` | ```bitwise inclusive OR  
``` ^ ```bitwise exclusive OR  
``` << ```left shift  
``` >>``` right shift  
``` ~ ```one's complement (unary)  

##### Variables
static or global variable  
external variable  
local or automatic variable  
register variable  
  
#### Derived datatype
