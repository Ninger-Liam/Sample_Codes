// Implements Game of Fifteen (generalized to d x d)

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Constants
#define DIM_MIN 3
#define DIM_MAX 9
#define COLOR "\033[32m"

// Board
int board[DIM_MAX][DIM_MAX];

// Dimensions
int d;

// Saved locations of the blank tile
int blank_row;
int blank_col;

// Prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void print_grid_row(int d);
void print_tile(int tile);

int main(int argc, string argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // Ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
               DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // Open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // Greet user with instructions
    greet();

    // Initialize the board
    init();

    // Accept moves until game is won
    while (true)
    {
        // Clear the screen
        clear();

        // Draw the current state of the board
        draw();

        // Log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // Check for win
        if (won() == true)
        {
            printf("ftw!\n");
            break;
        }

        // Prompt for move
        int tile = get_int("Tile to move: ");

        // Quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // Log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // Move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // Sleep thread for animation's sake
        usleep(50000);
    }

    // Close log
    fclose(file);

    // Success
    return 0;
}

// Clears screen using ANSI escape sequences
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

// Greets player
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

// Initializes the game's board with tiles numbered 1 through d*d - 1
// (i.e., fills 2D array with values but does not actually print them)
void init(void)
{
    int x = d * d;
    if (x % 2 == 1)
    {
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                board[i][j] = x - 1;
                x = x - 1;
            }
        }
    }
    else
    {
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                board[i][j] = x - 1;
                x = x - 1;
            }
        }
        board[d - 1][d - 3] = 1;
        board[d - 1][d - 2] = 2;
    }

}

// Prints the board in its current state
void draw(void)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == 0)
            {
                printf(" _");
                blank_row = i;
                blank_col = j;
            }
            else
            {
                printf("%2i", board[i][j]);
            }
        }
        printf("\n");
    }
}

// If tile borders empty space, moves tile and returns true, else returns false
bool move(int tile)
{
    int ii;
    int jj;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == tile)
            {
                ii = i;
                jj = j;
                break;
            }
        }
    }
    if (board[ii][jj] == board[blank_row - 1][blank_col] || board[ii][jj] == board[blank_row][blank_col - 1] || board[ii][jj] == board[blank_row + 1][blank_col] || board[ii][jj] == board[blank_row][blank_col + 1])
    {
        board[ii][jj] = 0;
        board[blank_row][blank_col] = tile;
        blank_row = ii;
        blank_col = jj;
        return true;
    }
    // else
    // {
        return false;
    // }
}

// Returns true if game is won (i.e., board is in winning configuration), else false
bool won(void)
{
    int x = d * d;
    int check_board[x][x];
    // for (int m = 0; m < x; m++)
    // {
    //     for (int n = 0; n < x; n++)
    //     {
    //         check_board[m][n] = 0;
    //     }
    // }

    // for (int i = d - 1; i > 0; i--)
    // {
    //     for (int j = d - 1; j > 0; j--)
    //     {
            // if (i == d - 1 && j == d - 1)
            // {
            //     check_board[i][j] = 0;
            // }
            // else
            // {
            // check_board[i][j] = x - 1;
            // x = x - 1;
            // }
    //     }
    // }

    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (i == d - 1 && j == d - 1)
            {
                check_board[i][j] = 0;
            }
            else
            {
            check_board[i][j] = x - 1;
            x = x - 1;
            }

            if (check_board[i][j] != board[i][j])
            {
                return false;
            }
        }
    }
    return true;
}