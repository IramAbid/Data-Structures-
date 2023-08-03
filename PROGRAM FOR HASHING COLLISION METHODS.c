/******************************************************************************
Name - Iram Abid,
Faculty roll no. - 20COB051
Enrolment no. -GJ8239
Serial no- 06
                          PROGRAM FOR HASHING COLLISION METHODS    
*******************************************************************************/

#include<stdio.h>
//FUNCTION DECLARATIONS !!
int hash(int );
int primeHash(int );
int linearProbe(int [] ,int );
int quadraticProbe(int [],int );
int doubleProbe(int [],int );
int linearInsert(int [] ,int );
int quadraticInsert(int [],int );
int doubleInsert(int [],int );
int linearSearch(int [] ,int );
int quadraticSearch(int [],int );
int doubleSearch(int [],int );
int linearDelete(int ,int [],int []);
int quadraticDelete(int ,int [],int []);
int doubleDelete(int ,int [],int []);

#define rows 50
#define columns 5

//GLOBAL VARIABLES!!
int probe1=1,probe2=1,probe3=1;

int hash(int k)                           //HASH FUNCTION !
{
	return k%47;
}

int primeHash(int k)                      //PRIMEHASH FUNCTION FOR DOUBLE HASHING !!
{
	return 7-(k%7);
}

int linearProbe(int h[],int k)                                 //LINEAR PROBING FUNCTION!!
{
	int index=hash(k),i;
	probe1=1;
	for(i=0;h[(index+i)%47]!=0;i++)
	{
		probe1++;
	}
	return (index+i)%47;
}

int quadraticProbe(int h[],int k)                               //QUADRATIC PROBING FUNCTION !!
{
	int index=hash(k),i;
	probe2=1;
	for(i=0;h[(index+(i*i))%47]!=0;i++)
	{probe2++;}
	return (index+(i*i))%47;
}

int doubleProbe(int h[],int k)                                      //DOUBLE HASHING FUNCTION !!
{
	int index=hash(k),i;
	probe3=1;
	for(i=0;h[(hash(index)+i*primeHash(index))%47];i++)
	{probe3++;}
	return (index+i*primeHash(index))%47;
}

int linearInsert(int h[],int k)                                      //LINEAR PROBING INSERT !!
{
	int index=hash(k);
	if(h[index]!=0)
	{
		index=linearProbe(h,k);
	}
	h[index]=k;
}

int linearInsert1(int h[],int k)
{
	int index=hash(k),probe;
	if(h[index]!=0)
	{
		index=linearProbe(h,k);
		h[index]=k;
		printf("Number of probe for element %d are %d.\n",k, probe1);
		printf("Element %d is inserted at location %d.\n\n",k, index);
	}
	else {
	h[index]=k;
	probe=1;
	printf("Number of probe for element %d are %d.\n",k, probe);
    printf("Element %d is inserted at location %d.\n\n",h[index],index);
	}
}

int quadraticInsert(int h[],int k)                                  //QUADRATIC PROBING INSERT !!
{
	int index=hash(k);
	if(h[index]!=0)
	{
		index=quadraticProbe(h,k);
	}
	h[index]=k;
}

int quadraticInsert1(int h[],int k)
{
	int index=hash(k),probe;
	if(h[index]!=0)
	{
		index=quadraticProbe(h,k);
		h[index]=k;
		printf("Number of probe for element %d are %d.\n",k, probe2);
		printf("Element %d is inserted at location %d.\n\n",k, index);
	}
	else{
	h[index]=k;
	probe=1;
	printf("Number of probe for element %d are %d.\n",k, probe);
    printf("Element %d is inserted at location %d.\n\n",h[index],index);
	}
}

int doubleInsert(int h[],int k)                                         //DOUBLE HASHING INSERT !!
{
	int index=hash(k);
	if(h[index]!=0)
	{
		index=doubleProbe(h,k);
	}
	h[index]=k;
}

int doubleInsert1(int h[],int k)
{
	int index=hash(k),probe;
	if(h[index]!=0)
	{
		index=doubleProbe(h,k);
		h[index]=k;
		printf("Number of probe for element %d are %d.\n",k, probe3);
		printf("Element %d is inserted at location %d.\n\n",k, index);
	}
	else{
	h[index]=k;
	probe=1;
	printf("Number of probe for element %d are %d.\n",k, probe);
    printf("Element %d is inserted at location %d.\n\n",h[index],index);
	}
}

int linearSearch(int h[],int k)                                        //LINEAR PROBING SEARCH !!
{
	int index=hash(k),i=0;
		while(h[(index+i)%47]!=k)
		{
			i++;
			if(h[(index+i)%47]==0){
			
			return -1;}}
	return index+i%47;
}

int quadraticSearch(int h[], int k){                                     //QUADRATIC PROBING SEARCH !!
    int index = hash(k);
    int i = 0;
    while (h[(index+i*i) % 47] != k){
        i++;
        if (h[(index + i*i) % 47] == 0){
            return -1;
        }
    }
    return (index + i*i) % 47;
}

int doubleSearch(int h[], int k){                                            //DOUBLE HASHING SEARCH !!
    int index = hash(k);
    int i = 0;
    while (h[(hash(index) + i * primeHash(index)) % 47] != k){
        i++;
        if (h[(hash(index) + i * primeHash(index)) % 47] == 0){
            return -1;
        }
    }
    return (hash(index) + i * primeHash(index)) % 47;
}

int linearDelete(int k, int h[], int h1[])                                     //LINEAR PROBING DELETE!!
{
    int s=linearSearch(h,k),i;
    h[s]=0;
    for(i=0;i<50;i++)
  	{
  		if(h[i]!=0)
		linearInsert(h1,h[i]);
	}
}

int quadraticDelete(int k, int h[], int h1[])                                    //QUADRATIC PROBING DELETE !!
{
    int s=quadraticSearch(h,k),i;
    h[s]=0;
    for(i=0;i<50;i++)
  	{
  		if(h[i]!=0)
		quadraticInsert(h1,h[i]);
	}
}

int doubleDelete(int k, int h[], int h1[])                                         //DOUBLE HASHING DELETE !!
{
    int s=doubleSearch(h,k),i;
    h[s]=0;
    for(i=0;i<50;i++)
  	{
  		if(h[i]!=0)
		doubleInsert(h1,h[i]);
	}
}

int chainingInsert(int v,int h[rows][columns])                           //SEPARATE CHAINING INSERT !!
{
    int i, k, key1 = hash(v);
    if(h[key1][0]==0)
    {
        h[key1][0] = v;
    }
    else
    {
        for(i=0;i<5;i++)
		{
            if(h[key1][i]==0)
            {
                h[key1][i] = v;
                break;
            }
        }
    }
}

int chainingInsert1(int v, int h[rows][columns])                          
{
    int i, k, probe;
    int index = hash(v);                          
    if(h[index][0]==0)
    {
        probe = 1;
        h[index][0] = v;
        printf("Number of probe for element %d are %d.\n", v, probe);
        printf("Element %d is inserted at location %d.\n\n", v, index);
    }
    else
    {
        int probe4 = 1;
        for(i=0;i<5;i++)
        {
            probe4++;
            if(h[index][i]==0)
            {
                h[index][i] = v;
                printf("Number of probe for element %d are %d.\n", h[index][i], probe4);
                printf("Element %d is inserted at location %d->%d.\n\n", v, index,i);
                break;
            }
        }
    }
}

int chainingSearch(int k, int h[rows][columns])                               //SEPARATE CHAINING SEARCH !!
{
    int i, flag = 0, key1 = hash(k);
    for(i=0;i<5;i++)
    {
        if(h[key1][i] == k)
        {
            flag = 1;
            return i;
            break;
        }
    }
    if(flag == 0)
        return -1;
}

int chainingDelete(int k, int h2[rows][columns], int h3[rows][columns])                   //SEPARATE CHAINING DELETE !!
{
    int i, j, d = chainingSearch(k, h2), key = hash(k);
    h2[key][d] = 0;
    for(i=0;i<rows;i++)
    {
        for(j=0;j<columns;j++)
        {
            if(h2[i][j] != 0)
            {
                chainingInsert(h2[i][j], h3);
            }
        }
    }
}

void printArray(int h[])                        //PRINT FUNCTION OF ARRAY!!
{int i;
	 for(i=0;i<50;i++)
	 {
	 	printf("%d\t",h[i]);
	 }
}

void printArr(int h[rows][columns])
{
	int i, j;
    for(i=0;i<rows;i++)
    {
    	printf("\t");
        for(j=0;j<columns;j++)
        {
            if(j==0)
                printf("%d\t",h[i][j]);
            else
            {
                if(h[i][j]!=0)
                    printf("%d\t",h[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
	int i,ha[50]={0},h1[50]={0},n,n1,h3[rows][columns]={0};
	int randArray[40],result,c,m,h2[rows][columns]={0};
	printf("The randomly generated 40 numbers used to store in hash table : \n");
   	for(i=0;i<40;i++)
     	{
     	 randArray[i]=rand()%1000;
     	 printf("%d\t",randArray[i]);
  		}
  		printf("\n\n");
  	
	do{
  	printf("  Select the task you want perform!!!\n");
  	printf("****************************************\n");
  	printf("1. Linear Probing.\n");
  	printf("2. Quadratic Probing.\n");
    printf("3. Double Hashing.\n");
    printf("4. Separate Chaining.\n\n");

	printf("Enter Your choice : ");
	scanf("%d",&m);
	switch(m)
	{
		case 1:
				printf("\n  LINEAR PROBING !\n");
			    printf("    1. Insertion.\n");
  				printf("    2. Searching.\n");
    			printf("    3. Deletion.\n\n");
				printf("       Enter the task : ");
				scanf("%d",&c);
				printf("-----------------------------\n");
				switch(c)
				{
					case 1: for(i=0;i<40;i++)
        					{
            					linearInsert1(ha,randArray[i]);
       						}
        					printf("\n");
				        	printf("The Hash table :\n");
				        	printArray(ha);
				        	break;
				    case 2:	for(i=0;i<40;i++)
        					{
            					linearInsert(ha,randArray[i]);
        					}
        					printf("\n");
				        	printf("The Hash table :\n");
        					printArray(ha);
        					printf("\nEnter the number you want to search: ");
        					scanf("%d",&n);
        					result=linearSearch(ha,n);
							result==-1 ? printf("Element not found!!"):printf("Element %d is found at %d !!",n,result);
							break;
        			case 3: for(i=0;i<40;i++)
        					{
            					linearInsert(ha,randArray[i]);
        					}
					        printf("\nOld hash table: \n");
					        printArray(ha);
					        printf("\nEnter the number you want to delete: ");
        					scanf("%d",&n1);
					        linearDelete(n1, ha, h1);
					        printf("\nNew hash table: \n");
					        printArray(h1);
        		}break; 
		case 2:
				printf("  QUADRATIC PROBING !\n");
			    printf("    1. Insertion.\n");
  				printf("    2. Searching.\n");
    			printf("    3. Deletion.\n");
				printf("       Enter the task : ");
				scanf("%d",&c);
				printf("------------------------------\n");

				switch(c)
				{
					case 1: for(i=0;i<40;i++)
        					{
            					quadraticInsert1(ha,randArray[i]);
       						}
        					printf("\n");
        					printf("The Hash table : \n");
        					printArray(ha);
        					break;
				    case 2:	
        					for(i=0;i<40;i++)
        					{
            					quadraticInsert(ha,randArray[i]);
        					}
        					printf("\n");
				        	printf("The Hash table :\n");
        					printArray(ha);
        					printf("\nEnter the number you want to search: ");
        					scanf("%d",&n);
        					result=quadraticSearch(ha,n);
							result==-1 ? printf("Element not found !!"):printf("Element %d is found at %d !!",n,result);
							break;
        			case 3: for(i=0;i<40;i++)
        					{
            					quadraticInsert(ha,randArray[i]);
        					}
					        printf("\nOld hash table:\n");
					        printArray(ha);
					        printf("\nEnter the number you want to delete: ");
        					scanf("%d",&n1);
					        quadraticDelete(n1, ha, h1);
					        printf("\nNew hash table:\n");
					        printArray(h1);
        		}break;        	
		case 3:
				printf("  DOUBLE HASHING !\n");
			    printf("    1. Insertion.\n");
  				printf("    2. Searching.\n");
    			printf("    3. Deletion.\n");
				printf("       Enter the task : ");
				scanf("%d",&c);
				printf("-----------------------------\n");

				switch(c)
				{
					case 1: for(i=0;i<40;i++)
        					{
            					doubleInsert1(ha,randArray[i]);
       						}
        					printf("\n");
        					printf("The Hash table :\n");
        					printArray(ha);
        					break; 
				    case 2: for(i=0;i<40;i++)
        					{
            					doubleInsert(ha,randArray[i]);
        					}
        					printf("\n");
				        	printf("The Hash table :\n");
        					printArray(ha);
        					printf("\nEnter the number you want to search: ");
        					scanf("%d",&n);
        					result=doubleSearch(ha,n);
							result==-1 ? printf("Element not found !!"):printf("Element %d is found at %d !!",n,result);
							break;
        			case 3: for(i=0;i<40;i++)
        					{
            					doubleInsert(ha,randArray[i]);
        					}
					        printf("\nOld hash table:\n");
					        printArray(ha);
					        printf("\nEnter the number you want to delete: ");
        					scanf("%d",&n1);
					        doubleDelete(n1, ha, h1);
					        printf("\nNew hash table:\n");
					        printArray(h1);
					        break;
        		}break; 
		case 4:
				printf("  SEPARATE CHAINING !\n");
			    printf("    1. Insertion.\n");
  				printf("    2. Searching.\n");
    			printf("    3. Deletion.\n");
				printf("       Enter the task : ");
				scanf("%d",&c);
				switch(c)
				{
					case 1: for(i=0;i<40;i++)
        					{
            					chainingInsert1(randArray[i], h2);
        					}
        					printf("\n\n");
        					printf("The Hash table :\n");
        					printArr(h2);
        					break;
        			case 2: for(i=0;i<40;i++)
        					{
            					chainingInsert(randArray[i],h2);
        					}
        					printf("\n\n");
        					printf("The Hash table :\n");
        					printArr(h2);
        					printf("\nEnter the number you want to search: ");
        					scanf("%d",&n);
					      	result=chainingSearch(n,h2);
							result==-1 ? printf("Element not found !!"):printf("Element is found at %d ----> %d !!",hash(n),result);
							break;
				   	case 3: 
        					for(i=0;i<40;i++)
					        {
					            chainingInsert(randArray[i],h2);
					        }
					        printf("\nOld hash table:\n");
					        printArr(h2);
					        printf("\nEnter the number you want to delete: ");
        					scanf("%d",&n1);
					        chainingDelete(n1, h2, h3);
					        printf("\nNew hash table:\n");
					        printArr(h3);
					        break;
        		}break; 
	}
	break;	
  	}while(m<12);
return 0;
}
