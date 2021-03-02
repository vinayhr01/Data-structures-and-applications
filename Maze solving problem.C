/*Maze Problem:
	A maze is a confusing network of paths through which it is very
diffcult to find ones ways.

-> A maze problem is a application of stack.
-> Before we move to program let us understand how the maze is represented.
-> The maze is represented using two dimensonalarray in which
1. zero represent the open path
2. ones represent the barriers

Genenral  way finding path in maze:
   entrance|
           V
	   0    0    0   0    0   1

	   1    1    1   1    1   0

	   1    0    0   0    0   1

	   0    1    1   1    1   1

	   1    0    0   0    0   1

	   1    1    1   1    1   0

	   1    0    0   0    0   1

	   0    1    1   1    1   1

	   1    0    0   0    0   0 -> exit



   Logical way of finding a path in maze:

   NW		  N                 NE

 i-1,j-1     |   i-1,j    |     i-1,j+1
	     |            |
   ......................................
	     |            |
 W  i, j-1        i,j          i,j+1           E
	     |            |
   .......................................

	     |            |
 i+1,j-1        i+1,j          i+1,j+1
	     |            |          SE
 SW		   S

 N -> North, NW-> North west  NE-> NorthEast, W-> West E-> East, SW->southwest
 s-> South SE-> South East

 Let (i,j)  is the current position of rat in the maze where i the row index
 and j is the ccolumn index. Now rat can move in 8 directions. The new rat position in the
 maze can obtained as follows.

  N -> North (Verically upwards)                (i-1,j)
  NW-> North west  (v up & HL)
  NE-> NorthEast,  (VU & HR)
  W-> West   ( horizontal left)
  E-> East,  (horizontal right)
  SW->southwest (VD & HL)
  S-> South    (VD)
  SE-> South East (VD & HR)

To implement in the programming fashion we use the below given method.
NW		  N                 NE

 i-1,j-1     |   i-1,j    |     i-1,j+1
	     |            |
   ......................................
	     |            |
 W  i, j-1        i,j          i,j+1           E
	     |            |
   .......................................

	     |            |
 i+1,j-1        i+1,j          i+1,j+1
	     |            |          SE
 SW		   S

 N -> North,    = i-1,j   =(i-1,j+0)  offset value = -1, 0
 NW-> North west= i-1,j-1 =(i-1,j-1)  offest value = -1,-1
 NE-> NorthEast,= i-1,j+1 =(i-1,j+1)  offest value = -1, 1
 W-> West       = i,j-1   = (i+0,j-1) offest value = 0,-1
 E-> East,      = i,j+1   =(i+0,j+1)  offest value = 0, 1
 SW->southwest  = i+1,j-1 =(i+1,j-1)  offest value = 1,-1
 s-> South      = i+1,j   =(i+1,j+0)  offest value = 1,0
 SE-> South East= i+1,j+1 =(i+1,j+1)  offest value = 1,1

Programming Example:
			       */
#include <stdio.h>

typedef struct
{
	int vert;
	int horz;
}offsets;

// In count 8 moves
offsets move[8]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

typedef struct
{
	int row;
	int col;
	int dir;
}element;

enum {FALSE,TRUE};

#define EXIT_ROW 12
#define EXIT_COL 15

int maze[20][20]={
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1},
		{1,1,0,0,0,1,1,0,1,1,1,0,0,1,1,1,1},
		{1,0,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1},
		{1,1,1,0,1,1,1,1,0,1,1,0,1,1,0,0,1},
		{1,1,1,0,1,0,0,1,0,1,1,1,1,1,1,1,1},
		{1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1},
		{1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1},
		{1,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1},
		{1,0,0,1,1,0,1,1,0,1,1,1,1,1,0,1,1},
		{1,1,1,0,0,0,1,1,0,1,1,0,0,0,0,0,1},
		{1,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,1},
		{1,0,1,0,0,1,1,1,1,1,0,1,1,1,1,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		};

void main()
{
	int row,col,nextRow,nextCol,dir,found=FALSE,top,i;
	int mark[20][20]={{0}};
	element s[200],pos;

	mark[1][1]=1;
	pos.row= 1;
	pos.col=1;
	pos.dir=0;

	top=0;
	s[top]=pos;

	while(top!=-1 && !found)
	{
		pos=s[top--];
		row=pos.row; //row=1
		col=pos.col; //col=1
		dir=pos.dir; //dir=0

		while(dir< 8 && !found)
		{
			nextRow=row+move[dir].vert; // 2
			nextCol=col+move[dir].horz; // 2
			//    12                        15
			if(nextRow==EXIT_ROW && nextCol==EXIT_COL)
			{
				found=TRUE;
			}
			else if(maze[nextRow][nextCol]==0 && mark[nextRow][nextCol]==0)
			{
				mark[nextRow][nextCol]=1;
				pos.row=row;// 2
				pos.col=col; //2
				pos.dir=++dir;
				s[++top]=pos;
				row=nextRow;
				col=nextCol;
				dir=0;

			}
			else
				++dir;
		}
	}

	if(found)
	{
		printf("The path is\n");
		printf("Row Col\n");
		for(i=0;i<=top;i++)
		{
			printf("%3d %3d\n", s[i].row,s[i].col);
		}
		printf("%3d %3d", row,col);
		printf("%3d %3d", EXIT_ROW,EXIT_COL);
	}
	else
		printf("Maze doesnot have path\n");
}
