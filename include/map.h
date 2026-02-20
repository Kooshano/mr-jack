#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ANSI_COLOR_GREEN "\x1B[32m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_YELLOW "\x1B[33m"
int inocent[8] = {1, 1, 1, 1, 1, 1, 1, 1};
char CARDS[][10] = {"SH", "JW", "JS", "IL", "MS", "SG", "WG", "JB"};

struct Escape
{
    char place[10];
    char gate1[10];
    char gate2[10];
    int mode;
};
struct tile
{
    char character[10];
    int type;
    int visibility;
};
char *CreateMap(FILE *map)
{
    char *hexagonal;
    hexagonal = (char *)malloc(10000);
    char c;
    if (hexagonal == NULL)
    {
        printf("no storage!");
    }
    int j;
    for (j = 0; (c = fgetc(map)) != EOF; j++)
    {
        hexagonal[j] = c;
    }
    hexagonal[j + 1] = '\0';
    return hexagonal;
}

struct tile **LoadMap(FILE *base, int x, int y)
{
    struct tile **matrix;
    matrix = (struct tile **)malloc((y + 2) * sizeof(struct tile *));
    for (int i = 0; i < y + 2; i++)
    {
        matrix[i] = (struct tile *)malloc((x + 2) * sizeof(struct tile));
    }

    for (int i = 0; i < y + 2; i++)
    {
        for (int j = 0; j < x + 2; j++)
        {
            if (i == 0 || i == y + 1 || j == 0 || j == x + 1)
            {
                matrix[i][j].type = 0;
            }
            else
            {
                fscanf(base, "%d", &matrix[i][j].type);
            }
        }
    }
    for (int i = 0; i < y + 2; i++)
    {
        for (int j = 0; j < x + 2; j++)
        {
            if (i == 0 || i == y + 1 || j == 0 || j == x + 1)
            {
                strcpy(matrix[i][j].character, "NA");
            }
            else
            {
                char name[10];
                fscanf(base, "%s", name);
                strcpy(matrix[i][j].character, name);
            }
        }
    }

    return matrix;
}
void DisplayMap(char *hexagonal, struct tile **map, int x, int y)
{
    (void)x;
    (void)y;
    int char_count = 0;
    int type_count = 0;
    for (size_t i = 0; i < strlen(hexagonal); i++)
    {
        if (hexagonal[i] == 'c' && hexagonal[i + 1] == 'h')
        {
            if (strcmp(map[char_count / (2 * 13) + 1][(char_count + 1) % 13 + 1].character, "NA") == 0)
            {
                printf("  ");
            }
            else
            {
                int indicator;
                for (int k = 0; k < 8; k++)
                {
                    if (strcmp(map[char_count / (2 * 13) + 1][(char_count + 1) % 13 + 1].character, CARDS[k]) == 0)
                    {
                        indicator = k;
                    }
                }
                if (inocent[indicator] == 0)
                {
                    printf(ANSI_COLOR_GREEN     "%s"     ANSI_COLOR_RESET, map[char_count / (2 * 13) + 1][(char_count + 1) % 13 + 1].character);
                }
                else{
                    printf(ANSI_COLOR_YELLOW    "%s"     ANSI_COLOR_RESET, map[char_count / (2 * 13) + 1][(char_count + 1) % 13 + 1].character);
                }
                
            }

            char_count += 2;
            i++;
        }
        else if (hexagonal[i] == 't')
        {
            if (map[type_count / (2 * 13) + 1][(type_count + 1) % 13 + 1].type == 1)
            {
                printf("  ");
            }
            else if (map[type_count / (2 * 13) + 1][(type_count + 1) % 13 + 1].type == 0)
            {
                printf("\U0001F3E1");
            }
            else if (map[type_count / (2 * 13) + 1][(type_count + 1) % 13 + 1].type == 3)
            {
                printf("\U0001F535");
            }
            else if (map[type_count / (2 * 13) + 1][(type_count + 1) % 13 + 1].type == 4)
            {
                printf("\U0001F534");
            }
            else if (map[type_count / (2 * 13) + 1][(type_count + 1) % 13 + 1].type == 2)
            {
                printf("\U0001F4A1");
            }
            else if (map[type_count / (2 * 13) + 1][(type_count + 1) % 13 + 1].type == 5)
            {
                printf("\U0001F311");
            }

            else
            {
                printf("%d ", map[type_count / (2 * 13) + 1][(type_count + 1) % 13 + 1].type);
            }

            type_count += 2;
            i++;
        }
        else
        {
            printf("%c", hexagonal[i]);
        }
    }
}
struct Escape *Load_Escape(FILE *base)
{
    struct Escape *Gates = (struct Escape *)malloc(4 * sizeof(struct Escape));
    for (int i = 0; i < 4; i++)
    {
        fscanf(base, "%s %d %s %s", Gates[i].place, &Gates[i].mode, Gates[i].gate1, Gates[i].gate2);
    }
    return Gates;
}
void Clear_Visibility(struct tile **matrix, int x, int y)
{
    for (int i = 0; i < y + 2; i++)
    {
        for (int j = 0; j < x + 2; j++)
        {
            matrix[i][j].visibility = 0;
        }
    }
}
void check_Visibility(struct tile **matrix, int x, int y)
{
    for (int i = 1; i < y + 1; i++)
    {
        for (int j = 1; j < x + 1; j++)
        {
            if (matrix[i - 1][j].type == 2 || strcmp(matrix[i - 1][j].character, "NA") != 0)
            {
                matrix[i][j].visibility = 1;
            }
            if (matrix[i + 1][j].type == 2 || strcmp(matrix[i + 1][j].character, "NA") != 0)
            {
                matrix[i][j].visibility = 1;
            }
            if (matrix[i][j + 1].type == 2 || strcmp(matrix[i][j + 1].character, "NA") != 0)
            {
                matrix[i][j].visibility = 1;
            }
            if (matrix[i][j - 1].type == 2 || strcmp(matrix[i][j - 1].character, "NA") != 0)
            {
                matrix[i][j].visibility = 1;
            }
            if (j % 2 == 0)
            {
                if (matrix[i - 1][j + 1].type == 2 || strcmp(matrix[i - 1][j + 1].character, "NA") != 0)
                {
                    matrix[i][j].visibility = 1;
                }
                if (matrix[i - 1][j - 1].type == 2 || strcmp(matrix[i - 1][j - 1].character, "NA") != 0)
                {
                    matrix[i][j].visibility = 1;
                }
            }
            else
            {
                if (matrix[i + 1][j + 1].type == 2 || strcmp(matrix[i + 1][j + 1].character, "NA") != 0)
                {
                    matrix[i][j].visibility = 1;
                }
                if (matrix[i + 1][j - 1].type == 2 || strcmp(matrix[i + 1][j - 1].character, "NA") != 0)
                {
                    matrix[i][j].visibility = 1;
                }
            }
        }
    }
}
int if_visible(struct tile **matrix, int x, int y, char mrjack[10])
{
    for (int i = 0; i < y + 2; i++)
    {
        for (int j = 0; j < x + 2; j++)
        {
            if (strcmp(matrix[i][j].character, mrjack) == 0)
            {
                return matrix[i][j].visibility;
            }
        }
    }
    return 0;
}
