#include<stdio.h>
#include<stdlib.h>

typedef struct items
{
	char name[20];
	unsigned int weight;
	float profit;
};

float max( float a, float b )
{
	return ((a>b)?a:b);
}

//Function to solve knapsack
float knapsack(unsigned int n, struct items object[], unsigned int capacity)
{
	float table[n+1][capacity+1];
	
	for(unsigned int i=0; i<=n; i++)
	{
		for(unsigned int j=0; j<=capacity; j++)		
		{		
			if( i==0 || j==0 )
				table[i][j] = 0.0;
			else if( object[i-1].weight <= j )
				table[i][j] = max( (object[i-1].profit + table[i-1][j-object[i-1].weight]), table[i-1][j] );
			else
				table[i][j] = table[i-1][j];
		}
	}
	
	//Printing table
	printf("Printing profit table\n");
	for(unsigned int i=0; i<=n; i++)
	{
		for(unsigned int j=0; j<=capacity; j++)		
			printf("%.1f\t",table[i][j]);
		printf("\n");
	}
	
	return table[n][capacity];
}

int main(void)
{
	//Input for Bag capacity
	unsigned int capacity;
	printf("Enter bag's capacity: ");
	scanf("%u",&capacity);

	//Input for number of items
	unsigned int n;
	printf("Enter total number of items: ");
	scanf("%d",&n);

	struct items item[n];
	
	//Input object details from user 
	printf("Enter Asked Details:\n");	
	for(unsigned int i=0; i<n; i++)
	{
		printf("==========Item No. %d ==========\n",i+1);
		printf("Item Name: ");
		scanf("%s",item[i].name);
		printf("Weight: ");
		scanf("%u",&item[i].weight);
		printf("Profit: ");
		scanf("%f",&item[i].profit);
	}

	//Solving knapsack problem
	float max_profit = knapsack(n, item, capacity);
	
	printf("Maximum Profit is %.2f.",max_profit);

	return 0;
}
