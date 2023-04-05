#include <stdio.h>
#include <math.h>



//display function//
    void display (){
    printf("\n");
    printf("\n");
    printf("Choose an operation to perform: \n");
    printf("[a] Modify matrix \n");
    printf("[b] Transpose matrix \n");
    printf("[c] Find the maximum element in each row of the matrix \n");
    printf("[d] Check whether the matrix is symmetric \n");
    printf("[e] Find the determinant of the matrix \n");
    printf("[f] Find the inverse of the matrix \n");
    printf("[q] Quit \n");
    printf("\n");
    // user to choose between various operations//
    }



//modify function//
    void modify (int matrix[3][3]){
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                matrix[i][j] = (-1)*matrix[i][j];
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    }



//transpose function//
    void transpose (int matrix[3][3]){
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                matrix[i][j] = matrix[j][i];
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }

    }



//findMaxInRow function//
    void maximum(int myArr[3][3]){
        int i = 0, j;
        int max = 0;
        while (i < 3)   //Check for the largest element in an array
        {
        for ( j = 0; j < 3; j++)
        {
            if (myArr[i][j] > max)
            {
                max = myArr[i][j];
            }

            }
            printf("Largest element in row is %d \n", max);
            max = 0;
            i++;
        }
    }



//isSymmetric function//
    void isSymmetric(int myArray[3][3]){
        int j=2;
        for (int i = 0; i < 3; i++){
            if(myArray[i][j] == myArray[j][i]){
                printf("this is not symmetric");
                printf("\n");
                j--;
            }else{
                printf("this is symmetric");
                printf("\n");
                j--;
            }
        }
    }



//determinant function//
    void determinant(int a[3][3]){
        int result = a[0][0] * ((a[1][1]*a[2][2]) - (a[2][1]*a[1][2])) -a[0][1] * (a[1][0]* a[2][2] - a[2][0] * a[1][2]) + a[0][2] * (a[1][0] * a[2][1] - a[2][0] * a[1][1]);
        printf("determinant of matrix is %d", result);
    }



//inverse function//
    void inverse (int a[3][3]){
        int i,j;
        int determinant=0;
        for(i=0;i<3;i++)
        determinant = determinant + (a[0][i]*(a[1][(i+1)%3]*a[2][(i+2)%3] - a[1][(i+2)%3]*a[2][(i+1)%3]));

        printf("\nInverse of matrix is: \n\n");
        for(i=0;i<3;i++){
        for(j=0;j<3;j++)
           printf("%d ",(((a[(i+1)%3][(j+1)%3] * a[(i+2)%3][(j+2)%3]) - (a[(i+1)%3][(j+2)%3]*a[(i+2)%3][(j+1)%3]))/ determinant));
       printf("\n");
   }

}



//quit function//
    void quit (){
        printf("BYEE!!");
    }



//Input a 3x3 matrix from the user//
int i,j;
char m;
int arr[3][3];


//main function//
int main ()
{
        printf("Enter the array: \n");
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                printf("%d  ",arr[i][j]);
            }
            printf("\n");
        }


        //calling display func.//
    while( m != 'q'){          ///////this while loop is created to display our menu again and again till you choose quit.////////////////
        display();

        //user chooses a coice//
        printf("Enter your choice: ");
        scanf("%s", &m);

        //Perform the operation chosen by the user//
        switch(m){
            case 'a':
                modify(arr);
                break;
            case 'b':
                transpose(arr);
                break;
            case 'c':
                maximum(arr);
            case 'd':
                isSymmetric(arr);
                break;
            case 'e':
                determinant(arr);
                break;
            case 'f':
                inverse(arr);
                break;
            case 'q':
                quit(arr);
                break;
            default:
                printf("Default choice!");
        }
    }
    return 0;

}
