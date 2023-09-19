// Write a C program to check if a given array of 5 elements is found as a sub-array of a bigger array of 20 integers. (A sub-array is part of the array with consecutive elements.) Create the bigger array and assign elements by randomly generating integers below 100. ( Use rand() %100. rand() is available in math.h ). Print this array. Read the smaller array from standard input and check for the match.
    #include<stdio.h>
    #include<stdlib.h>
    int main()
    {
        int a[20],b[5],i,j,flag=0;
        for(i=0;i<20;i++)
        {
            a[i]=rand()%100;
        }
        printf("The array is:\n");
        for(i=0;i<20;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\nEnter the sub-array:\n");
        for(i=0;i<5;i++)
        {
            scanf("%d",&b[i]);
        }
        for(i=0;i<20;i++)
        {
            if(a[i]==b[0])
            {
                for(j=1;j<5;j++)
                {
                    if(a[i+j]!=b[j])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    printf("The sub-array is found at index %d\n",i);
                    break;
                }
            }
        }
        if(flag==1)
        {
            printf("The sub-array is not found\n");
        }
        return 0;
    }


sample input output
1 : The array is:
92 41 61 59 79 18 94 57 36 83 68 87 84 76 50 87 88 18 53 45
Enter the sub-array:
87 84 76 50 87
The sub-array is found at index 12

2 : The array is:
92 41 61 59 79 18 94 57 36 83 68 87 84 76 50 87 88 18 53 45
Enter the sub-array:
87 84 76 50 88
The sub-array is not found
