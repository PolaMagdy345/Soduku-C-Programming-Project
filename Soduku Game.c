#include <stdio.h>
#include <stdlib.h>
char Array_scanf(int arr[][9],int p[][2],int *px,int* py)
{
    int i,x,y,k=0,flag=0,n=0;
    static char flag1=2;
    while(flag1)
    {
        if(flag1==2)
        {
            printf("  \t- Please enter row number: ");
            fflush(stdin);
            scanf("%d",&x);
            if(x>=0 && x<=9)
            {
                printf("  \t- Please enter coulumn number: ");
                flag1--;
            }
            else
            {
                printf("   \twrong entry\n ");
            }
        }

        if(flag1==1)
        {
            fflush(stdin);
            scanf("%d",&y);
            if(y>=0 && y<=9)
            {
                flag1--;
                for(i=0; i<=19 && n==0; i++)
                {
                    k=0;

                    if((x==p[i][k] && y==p[i][k+1]))
                    {
                        *px=x;
                        *py=y;
                        n=1;           //the space to write is accessed sucessfully
                        flag1=2;
                        return n;
                    }
                }
                        n=-1;                 //you can't write here
            }
            else
            {
                printf(" Wrong entry\n ");
                printf("  \t- Please enter coulumn number: ");
            }
        }
        if(flag1==2)
            return n;
    }
    flag1=2;
    return n;
}

char comparison_rows_coulumns(int arr[][9],int p[][2],int **px,int **py,int k,int num)
{
    int i,j,n,x,y;
    x=**px;
    y=**py;
    if(k==1)                //scanf checking state
    {
        for(i=0; i<9; i++)
        {
            if(num==arr[i][y])
            {
                printf("Repeated number in coulumn \n\n");
                return -1;                            //you can't write here due to repition of numbers in row
            }
            if(num==arr[x][i])
            {
                printf("Repeated number in row \n\n");
                return -1;                            //you can't write here due to repition of numbers in coulumns
            }
        }
    }
    if(num==0)
    {
        return 0;                                     //you can delete any thing here
    }
    return 1;                                         //you can write here
}

char Check_Space(int arr[][9],int p[][2],int x,int y)
{
    int n,k,comparison_check,num;
    static int c=1;
    int *px=0,*py=0;
    k=Array_scanf(arr,p,&x,&y);
    px=&x;
    py=&y;
    printf("  \t- Enter the number you need to write here: ");
    scanf("%d",&num);
    if(k==1)
    {
        if(num>=0 && num<=9)
        {
            comparison_check=comparison_rows_coulumns(arr,p,&px,&py,k,num);
            if(comparison_check==1)
            {
                arr[x][y]=num;
                //>>>YOU CAN EDIT HERE<<<
                system("cls");
                c=Array2D_Print(arr,9,p);
            }
            else if (comparison_check==0)
            {
                arr[x][y]=' ';
                //>>>YOU CAN EDIT HERE<<<
                system("cls");
                c=Array2D_Print(arr,9,p);
            }
            if(c==0)
            {
                return 0;
            }
        }
        else if(num>9)
        {
            printf("sorry!!..you must enter number from 0 to 9 only \n");
        }
    }
    else
        printf("you cannot edit here, you are going to access wrong space \n");
    if(c==0)
    {
        return 0;
    }
}


int Array2D_Print(int arr[][9],int size,int p[][2])
{
    int i,j,n=0;
    char k=0,count=0,row_table=0,coulumn_table=0;
    static char flag=0,c;           //the flag to maintain the adresses that saved at the array in its specific place statically..
    printf(" C/R ||");
    for(int a=0; a<9; a++)
    {
        printf("  %d  |",coulumn_table);
        coulumn_table++;
    }
    printf("\n");
    printf("-------------------------------------------------------------");
    //printf("=============================================================");
    printf("\n");
    printf("-------------------------------------------------------------");
    printf("\n");
    coulumn_table=0;

    for(i=0; i<size; i++)
    {
        printf("  %d  ||",coulumn_table);
        coulumn_table++;
        for(j=0; j<9; j++)
        {
            if(arr[i][j]==' ')
            {
                if(flag==0)
                {
                    k=0;
                    p[n][k]=i;
                    k++;
                    p[n][k]=j;
                    n++;
                    c++;
                }
                count++;
                printf("  %c  |",arr[i][j]);
            }
            else
                printf("  %d  |",arr[i][j]);
        }
        printf("\n");
        printf("=============================================================");
        printf("\n");

    }
    flag=1;
    if(count>0)
    {
        printf("\n  \t- Remaining places= %d\n\n",count);
    }
    if(count==0)
    {
        return 0;
    }
    count=0;
}



int main()
{

    printf("\t\t*****************************************************************\n");
    printf("\t\t*********************                      **********************\n");
    printf("\t\t*********************Welcome To Soduku Game**********************\n");
    printf("\t\t*********************                      **********************\n");
    printf("\t\t*********************     Made By Paula    **********************\n");
    printf("\t\t*********************                      **********************\n");
    printf("\t\t*****************************************************************\n\n");
    int x,y,c=1;
    int arr[9][9]= {{' ',1,3,8,4,' ',9,7,' '},
        {7,6,' ',9,' ',1,5,4,8},
        {4,' ',8,7,5,2,6,' ',3},
        {1,5,4,6,9,' ',2,' ',7},
        {9,' ',6,' ',2,7,8,5,1},
        {2,8,' ',5,1,' ',4,6,' '},
        {' ',7,9,2,6,5,' ',8,4},
        {8,2,5,1,' ',4,3,9,' '},
        {6,' ',1,' ',8,9,7,2,5}
    };
    int* arr_space[20][2]= {1};
    Array2D_Print(arr,9,arr_space);
    while(1)
    {
        if(c==0)
        {
            c=2;
            printf("Congratulations!....you won!! :), you can replay by REOPEN the game\n ");
        }
        else if(c!=2 && c!=0)
            c=Check_Space(arr,arr_space,&x,&y);

    }

}
