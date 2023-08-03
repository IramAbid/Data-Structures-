/******************************************************************************
Name – Iram Abid,
Faculty roll no. - 20COB051
Enrolment no. -GJ8239
Serial no- 06
            Question-b) Binary Search in 2 Dimentional Array
*******************************************************************************/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void binarySearchIn2D( int row, int col,int arr[][col], int numb){
    
     int r1=0,r2=row-1,mid, count=0;
     while(r1<=r2){
        count++;
        mid=(r1+r2)/2;
        if(arr[mid][col-1]<numb){
            r1=mid+1;
        }
        else if(arr[mid][0]>numb){
            r2=mid-1;
        }
        else{
            r1=mid;
            break;
        }
          
    }
    
    int c1=0,c2=col-1;
    while(c1<=c2){
        count++;
        mid=(c1+c2)/2;
        if(arr[r1][mid]<numb)
           c1=mid+1;
        else if(arr[r1][mid]>numb)
            c2=mid-1;
        else  {
           printf("index of search %d,%d",r1,mid);
           printf("\nNumber of attempts are %d",count);
           break;
          }
    }
    
    if(c1>c2){
    printf("not found");
    printf("\nNumber of attempts are %d",count);
    }
    return;
     
 }
    
    
 int main(){

    int row,col;
    printf("\n Enter the number of rows and columns for 2D Array :");
    scanf("%d %d", &row ,&col);
    
    int arr[row][col];
    
    srand(time(0));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            arr[i][j]=rand()%150;
        }
             
    }
    
    int temp[row*col],k=0,numb;
    
    //copying this array to a temp array for sorting
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            temp[k]=arr[i][j];
            k++;
        }
             
    }
    
    k=0;
    for (int i = 0; i < row*col; i++) {
        for (int j = i + 1; j < row*col; j++) {
            if (temp[i] > temp[j]) {
                k = temp[i];
                temp[i] = temp[j];
                temp[j] = k;
            }
        }
    }
    
    k=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            arr[i][j]=temp[k];
            k++;
        }
             
    }
    
    // printing sorted array
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d\t",arr[i][j]);
        }
        
        printf("\n");
             
    }
    
    printf("\nEnter the No. to be searched  ");
    scanf("%d",&numb);
    
    binarySearchIn2D(row,col,arr,numb);
 
    return 0;
}