Defining structure body:
 Let me create a structure for student.
 -> USN   ->   1RN19CS001  ->DT : char usn[11]
 -> NAME  ->   AKASH       ->DT : char name[20];
 -> MARKS  ->  90          ->DT : int  marks
 -> percent -> 95.5        -> DT :float percentage;


struct student
{
    char usn[11];      // memroy will not allocated for structure memebers
    char name[20];
    int marks;
    float percentage;
};
struct student s1,s2,s3; // Mem will be allocted for structure varibles.

Memory  Allocatio  for structure varible.
how much memroy allocated by s1 -> 37 bytes usn+name+marks+percentage
			     s2 -> 37 bytes     usn+name+marks+percentage
			     s3 -> 37 bytes    usn+name+marks+percentage

-> (the keyword structre name togeather acts as data type)
-> data type of s1,s2,s3 is
struct student

