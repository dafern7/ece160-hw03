#include <stdio.h>

typedef enum {
  NAME_ONLY = 0,
  MAJOR_AND_NAME = 1, 
  YEAR_AND_NAME = 2
} Mode;

typedef struct {
  char *first_name; //defined the structure 
  char *last_name;
  char *major;
  int  *year;
} Student;

void print_student(Mode m, Student s) { 
  switch (m) {
    case NAME_ONLY:
      printf("%s %s\n", s.first_name, s.last_name); 
      break;
	case MAJOR_AND_NAME:
	  printf("%s %s %s\n",s.major, s.first_name, s.last_name);
	break;
	case YEAR_AND_NAME:
	  printf("%d %s %s\n",s.year, s.first_name, s.last_name);
	break;
  }
}

/*
	argv[1] will be the Mode integer
	argv[2...] will be student info in the form [first_name, last_name, major, year]
	the fields are all strings (char[])
	except year is a number (int)
*/
int main(int argc, char *argv[]) {
 int n = argc; //number of arguments to be parsed
 int x = atoi(argv[1]); //first argument is the Mode
 int i = 0;
for (i = 2; i<n+1; i+=4) { //populating the structs, increment i by 4 because each struct has four components
   Student s;
   s.first_name = argv[i];
   s.last_name = argv[i+1];
   s.major = argv[i+2];
   s.year = atoi(argv[i+3]);
   print_student(x,s);
}
  return 0;
}
