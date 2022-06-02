#include <stdio.h>
#include <stdlib.h>
#define M 512
int graph[M][M];
void path_find(int i, int j, int num_island); //my recursive function starts checking the first function I get until the branching ends
int main(void)
{

  int y,i,j;
  int L;
  FILE *fptr;
  fptr = fopen("input.txt", "r+");  //opening the input file
  fscanf(fptr,"%d",&y); //taking the water level
   L=y;
   i=0,j=0;
   while(fscanf(fptr,"%d",&y)==1)  //assignment of numbers to indexes
   {
      graph[i][j]=y;
      j++;
      if(j==(512))
      {
         i++;
         j=0;
      }
      
   }

   fclose(fptr);  //closing the file
  for(i=0;i<512;i++)
   {
     for(j=0;j<512;j++)
     {
        if(graph[i][j]<=L) graph[i][j]=0; //those that are below the water level and equal to it are equal to zero
        else if(graph[i][j]>L) graph[i][j]=1; //those above the water level are equalized to one
     }
  }   
            
            
            int a,b;
	int island_num=1;
	fptr = fopen("output.txt", "w"); //opening the output file
	for(a=0; a < M;a++){
		for(b=0; b <M; b++){
			
			if(graph[a][b] == 1){  //the first 1 is located in the loop
				
				fprintf(fptr,"%d_coordinate%d \t %d_coordinate%d    \n",a,island_num,b,island_num);  //any point is printed to the file
				path_find(a,b,island_num);  //the recursive function is called
				island_num++; //switch to the other island
			}
			
		}
	}
	
	fclose(fptr);  //closing the file

   
return 0;
}
void path_find(int i, int j, int num_island){  //my recursive function starts checking the first function I get until the branching ends
	
          if (graph[i][j] == 1)
          {
		
	graph[i][j] = 0; // visited
	
	if(j < M-1) path_find(i,j+1,num_island); //the right of the index is checked
	
	if(i < M-1) path_find(i+1,j,num_island); //the following directory is checked
	
	if(j > 0) path_find(i,j-1,num_island);  //the directory on the left is checked
	
	if(i > 0) path_find(i-1,j,num_island);  //the above directory is checked
	
         }
	
};

