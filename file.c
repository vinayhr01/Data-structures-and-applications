
Define a file. Explain its attributes.
File Input/Output in C. A file represents a sequence of bytes on the disk where a group of related data is stored. 
File is created for permanent storage of data. It is a ready made structure. 
In C language, we use a structure pointer of file type to declare a file.

When you issue an ‘ls -l’ shell command on a file, it gives you information about the size of the file, who owns it, when it was last modified, etc. These are called the file attributes, and are associated with the file itself and not a particular one of its names.

This section contains information about how you can inquire about and modify the attributes of a file.

• Attribute Meanings	  	The names of the file attributes, and what their values mean.
• Reading Attributes	  	How to read the attributes of a file.
• Testing File Type	  	Distinguishing ordinary files, directories, links…
• File Owner	  	How ownership for new files is determined, and how to change it.
• Permission Bits	  	How information about a file’s access mode is stored.
• Access Permission	  	How the system decides who can access a file.
• Setting Permissions	  	How permissions for new files are assigned, and how to change them.
• Testing File Access	  	How to find out if your process can access a file.
• File Times	  	About the time attributes of a file.
• File Size	  	Manually changing the size of a file.
• Storage Allocation	  	Allocate backing storage for files.

A text file stores data in the form of alphabets, digits and other special symbols 
by storing their ASCII values and are in a human-readable format. ... whereas binary file contains a 
sequence or a collection of bytes which are not in a human-readable format. text files follow some 
simple rules whereas binary files do not.


Basic File opeartions in C
-> File creation
-> File opening Modes

-> File handling Functions
-> Flie closeing
