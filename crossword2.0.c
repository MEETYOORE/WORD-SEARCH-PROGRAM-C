#include<stdio.h>
#include<string.h>

char crossword[100][100],word[100];
int l;

void searching(int n,int a,int b)
{
    static int count=1;

    switch(n)
    {
        case 1:
            {
                if(count==l)
                {
                    printf("%d,%d to %d,%d\n",a+l,b+l,a+1,b+1);
                    count=1;
                    return;
                }

                else if(crossword[a-1][b-1]==word[count])
                {
                    count++;
                    searching(1,a-1,b-1);
                }
                else count=1;
                return;
            }

        case 2:
        {
            if(count==l)
            {
                printf("%d,%d to %d,%d\n",a+l,b+1,a+1,b+1);
                count=1;
                return;
            }

            else if(crossword[a-1][b]==word[count])
            {
                count++;
                searching(2,a-1,b);
            }
            else count=1;
            return;
        }

        case 3:
        {
            if(count==l)
            {
                printf("%d,%d to %d,%d\n",a+l,b-l+2,a+1,b+1);
                count=1;
                return;
            }

            else if(crossword[a-1][b+1]==word[count])
            {
                count++;
                searching(3,a-1,b+1);
            }
            else count=1;
            return;
        }

        case 4:
        {
            if(count==l)
            {
                printf("%d,%d to %d,%d\n",a,b+l,a+1,b+1);
                count=1;
                return;
            }

            else if(crossword[a][b-1]==word[count])
            {
                count++;
                searching(4,a,b-1);
            }
            else count=1;
            return;
        }

        case 6:
        {
            if(count==l)
            {
                printf("%d,%d to %d,%d\n",a+1,b-l+2,a+1,b+1);
                count=1;
                return;
            }

            else if(crossword[a][b+1]==word[count])
            {
                count++;
                searching(6,a,b+1);
            }
            else count=1;
            return;
        }

        case 7:
        {
            if(count==l)
            {
                printf("%d,%d to %d,%d\n",a-l+2,b+l,a+1,b+1);
                count=1;
                return;
            }

            else if(crossword[a+1][b-1]==word[count])
            {
                count++;
                searching(7,a+1,b-1);
            }
            else count=1;
            return;
        }

        case 8:
        {
            if(count==l)
            {
                printf("%d,%d to %d,%d\n",a-l+2,b+1,a+1,b+1);
                count=1;
                return;
            }

            else if(crossword[a+1][b]==word[count])
            {
                count++;
                searching(8,a+1,b);
            }
            else count=1;
            return;
        }

        case 9:
        {
            if(count==l)
            {
                printf("%d,%d to %d,%d\n",a-l+2,b-l+2,a+1,b+1);
                count=1;
                return;
            }

            else if(crossword[a+1][b+1]==word[count])
            {
                count++;
                searching(9,a+1,b+1);
            }
            else count=1;
            return;
        }

        default:
            {
                count=1;
                return;
            }
    }
}




void square(int i,int j)
{
    int x,y;
    int d=0;

    for(x=i-1;x<i+2;x++)
    {
        for(y=j-1;y<j+2;y++)
        {
            d++;
            if(x==i&&y==j) continue;
            else if(crossword[x][y]==word[1]) searching(d,i,j);
        }
    }
}




void main()
{
    int i,j,k,m;

    printf("enter size of crossword-");
    scanf("%d",&m);

    printf("enter the crossword\n");

    for(i=0;i<m;i++)
    {
        scanf("%s",&crossword[i]);
    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%c ",crossword[i][j]);
        }
        printf("\n");
    }


    printf("enter word to search:");

    scanf("%s",word);

    l=strlen(word);

    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            if(crossword[i][j]==word[0])
            {
                square(i,j);
            }
        }
    }

}

