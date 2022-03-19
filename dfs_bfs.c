#include<stdio.h>
#include<stdlib.h>
#define n 5  			// Enter the matrix size

int a[n][n];
void dfs()
{
	int TOP,j,k,i,x;
	printf("\nDFS Traversal");
	printf("\nEnter the source: ");
	scanf("%d",&x);
	TOP=-1;
	int stack[n];
	int visited[n];
	for(i=1;i<=n;i++)
		visited[i]=0;
	stack[++TOP]=x;
	visited[x]=1;
	printf("\nDFS Traversal: ");
	printf("END -> ");
	i=stack[TOP];
	while(TOP!=-1)
	{

		for(j=1;j<=n;j++)
		{		
	        if(a[i][j]==1 && visited[j]!=1)
    	      {
				  stack[++TOP]=j;
				  visited[j]=1;
				  
				 
			  }
		  }	 
		     printf("%d -> ",stack[TOP]);
			 --TOP;    
			i=stack[TOP];
	}
	printf("START");
}

void bfs()
{
	int rear,front,j,i,x;
	printf("\nBFS Traversal");
	printf("\nEnter the source: ");
	scanf("%d",&x);
	front=rear=-1;
	int queue[n];
	int visited[n];
	for(i=1;i<=n;i++)
		visited[i]=0;
	queue[++rear]=x;
	++front;
	visited[x]=1;
	printf("\nBFS Traversal: ");
	printf("START -> ");
	i=queue[front];
	while(rear<=front)
	{
	
		for(j=1;j<=n;j++)
		{		
	        if(a[i][j]==1 && visited[j]!=1)
    	      {
				  queue[++front]=j;
				  visited[j]=1;
				 
			  }
		  }	 
		     printf("%d -> ",queue[rear]);
			 ++rear;    
			i=queue[rear];
	}
	printf(" END\n");
}
void display_matrix()
{
	int i,j;
	printf("\nInput Adjacent Matrix is :-\n");

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	bfs();
	dfs();
}

void input_matrix()
{
	int x,i,g,k,j,h,flag;
	
	for(i=1;i<=n;i++)
	{
		flag=0;
		printf("Enter the number of neighbours for %d : ",i);
		scanf("%d",&x);

		for(j=1;j<=n;j++)
			a[i][j]=0;
		
		
		for(k=1;k<=x;k++)
		{
		   printf("Enter the number %d : ",k);
		   scanf("%d",&g);
	       for(j=1;j<=n;j++)
		   {
		   	
		    if(j==g)
			 a[i][j]=1;
			 
			else if(a[i][j]==1)
			 continue;
			 
			}	
	   	}
		
	}	
	display_matrix();
}

void matrix()
{
	int i,j;		 
	for(i=1;i<=n;i++)
	{
		printf("** Row %d **\n",i);
		for(j=1;j<=n;j++)
		{
			printf("Column %d :",j);
			scanf("%d",&a[i][j]);
		}
		printf("\n");
	}
	display_matrix();
}
void file_matrix()
{
	FILE *fp;
	char loc[50];
	int i,j;
	printf("Enter the file location: ");
	scanf("%s",loc);
	//fgets(loc);
	fp=fopen(loc,"r");
	if(fp==NULL)
	{
		printf("FIle Invalid\n");
		exit(1);
	}
	for(i=1;i<=n;i++)
	{
	 for(j=1;j<=n;j++)
	  fscanf(fp,"%d ",&a[i][j]);
	 
	 fscanf(fp,"\n");
	}
	fclose(fp);
	display_matrix();
	
}
	
int main()
{
	int x;
	printf("1.Input a Matrix \n");
	printf("2.Make a Matrix:\n");
	printf("3.Input Matrix from file:\n");
	printf("Enter your choice: ");
	scanf("%d",&x);
	switch(x)
	{
		case 1:
		    matrix();
		    break;
		case 2:
		    input_matrix();
		    break;
		case 3:
		    file_matrix();
		    break;
		default:
			printf("Wrong Choice");
	}
	return 0;		
}

