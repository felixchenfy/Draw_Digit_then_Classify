
I recorded some notes and bugs I met.
You probably don't want/need to read this file.

### 1.h and 2.h include each other sometimes cause wrong

I have 1.h and 2.h, if 2.h includes 1.h, and 1.h includes 2.h as well,  
then, their might be an error.  
Use *forward declare* might solve the problem.

### global variables need to be defined for each executable

If I put "const int x;" in head.h,   
and then I add head.cpp as a SHARED library to CMakelists.txt,  
and then I target_link_libraries with this SHARED library in 2 executables,  
then, **both of these executables** need to define the value of x: external const int x=1;  
