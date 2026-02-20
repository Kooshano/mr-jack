#include "specials.h"

char CARDS_for_SH[][10] = {"SH", "JW", "JS", "IL", "MS", "SG", "WG", "JB"};
void inocent_List(struct tile **matrix, int x, int y, char mrjack[10])
{
    int state = if_visible(matrix, x, y, mrjack);
    for (int i = 0; i < y + 2; i++)
    {
        for (int j = 0; j < x + 2; j++)
        {

            for (int k = 0; k < 8; k++)
            {
                if (strcmp(CARDS[k], matrix[i][j].character) == 0)
                {
                    if (matrix[i][j].visibility != state)
                    {
                        inocent[k] = 0;
                    }
                }
            }
        }
    }
}

void SH(struct tile **matrix, int x, int y, char mrjack[10])
{
    move_player("SH", matrix, x, y);
    int flag = 1;
    for (int i = 0; i < 8; i++)
    {
        if (strcmp(mrjack, CARDS_for_SH[i]) == 0)
        {
            strcpy(CARDS_for_SH[i], "\0");
        }
    }
    while (flag == 1)
    {
        srand(clock());
        int random = rand();
        random = random % 8;
        if (strcmp("\0", CARDS_for_SH[random]) != 0)
        {
            printf("%s is not Mr. Jack\n", CARDS_for_SH[random]);
            strcpy(CARDS_for_SH[random], "\0");
            flag = 0;
        }
    }
}

void JB(struct tile **matrix, int x, int y)
{
    printf("which to do first special or move? \n");
    char input[10];
    scanf("%s", input);
    if (strcmp(input, "special") == 0)
    {
        special_JB(matrix, x, y);
        move_player("JB", matrix, x, y);
    }
    else
    {
        move_player("JB", matrix, x, y);
        special_JB(matrix, x, y);
    }
}
void JS(struct tile **matrix, int x, int y)
{
    printf("which to do first special or move? \n");
    char input[10];
    scanf("%s", input);
    if (strcmp(input, "special") == 0)
    {
        special_JS(matrix, x, y);
        move_player("JS", matrix, x, y);
    }
    else
    {
        move_player("JS", matrix, x, y);
        special_JS(matrix, x, y);
    }
}
void WG(struct tile **matrix, int x, int y)
{
    printf("which to do special or move? \n");
    char input[10];
    scanf("%s", input);
    if (strcmp(input, "special") == 0)
    {
        special_WG(matrix, x, y);
    }
    else
    {
        move_player("WG", matrix, x, y);
    }
}
void MS(struct tile **matrix, int x, int y)
{
    move_player("MS", matrix, x, y);
}
void IL(struct tile **matrix, int x, int y, struct Escape *Gates)
{
    printf("which to do first special or move? \n");
    char input[10];
    scanf("%s", input);
    if (strcmp(input, "special") == 0)
    {
        special_IL(matrix, x, y, Gates);
        move_player("IL", matrix, x, y);
    }
    else
    {
        move_player("IL", matrix, x, y);
        special_IL(matrix, x, y, Gates);
    }
}
void JW(struct tile **matrix, int x, int y)
{
    move_player("JW", matrix, x, y);
    special_JW(matrix, x, y);
}
void SG(struct tile **matrix, int x, int y)
{

    printf("which to do special or move? \n");
    char input[10];
    scanf("%s", input);
    if (strcmp(input, "special") == 0)
    {
        special_SG(matrix, x, y);
        move_player("SG", matrix, x, y);
    }
    else
    {
        move_player("SG", matrix, x, y);
        special_SG(matrix, x, y);
    }
}
void Description(char name[])
{
    if (strcmp(name, "SH") == 0)
    {
        printf("1) Move 1 to 3 blocks 2) Seas a card from pile of supspects\n");
    }
    if (strcmp(name, "JW") == 0)
    {
        printf("1) Move 1 to 3 blocks 2) Light a direction\n");
    }
    if (strcmp(name, "JS") == 0)
    {
        printf("1) Move 1 to 3 blocks 2) Turn on one light and turn off another one\n");
    }
    if (strcmp(name, "IL") == 0)
    {
        printf("1) Move 1 to 3 blocks 2) Open a gate and block another one \n");
    }
    if (strcmp(name, "MS") == 0)
    {
        printf("1) Move 1 to 4 blocks while it can move into the buildings\n");
    }
    if (strcmp(name, "SG") == 0)
    {
        printf("1) Move 1 to 3 blocks 2) Whistle and bring other characters closer 3 times \n");
    }
    if (strcmp(name, "WG") == 0)
    {
        printf("1) Move 1 to 3 blocks 2) Change place with another character \n");
    }
    if (strcmp(name, "JB") == 0)
    {
        printf("1) Move 1 to 3 blocks 2) Open a well and block another one \n");
    }
}
