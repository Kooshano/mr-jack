#include "move.h"

char JW_direction[5];

void special_JB(struct tile **matrix, int x, int y)
{
    int flag = 1;
    int y_index, x_index;
    char input[10];
    int x_lift, y_lift;
    while (flag == 1)
    {
        printf("Which well would you like to lift? \n");
        for (int i = 0; i < y + 2; i++)
        {
            for (int j = 0; j < x + 2; j++)
            {
                if (matrix[i][j].type == 4)
                {
                    printf("%c%d ", (char)(i + 64), j);
                }
            }
        }
        printf("\n");
        scanf("%s", input);
        y_index = (int)(input[0]) - 64;
        x_index = atoi(input + 1);

        if (matrix[y_index][x_index].type == 4)
        {
            flag = 0;
            y_lift = y_index;
            x_lift = x_index;
            break;
        }
        printf("wrong one!\n");
    }
    flag = 1;
    while (flag == 1)
    {
        printf("Where would you like to put the well ? \n");
        for (int i = 0; i < y + 2; i++)
        {
            for (int j = 0; j < x + 2; j++)
            {

                if (matrix[i][j].type == 3)
                {
                    printf("%c%d ", (char)(i + 64), j);
                }
            }
        }
        printf("\n");
        scanf("%s", input);
        y_index = (int)(input[0]) - 64;
        x_index = atoi(input + 1);
        if (matrix[y_index][x_index].type == 3)
        {

            flag = 0;
            matrix[y_index][x_index].type = 4;
            break;
        }
        printf("wrong one!\n");
    }
    matrix[y_lift][x_lift].type = 3;
}
void special_JS(struct tile **matrix, int x, int y)
{
    int flag = 1;
    int y_index, x_index;
    char input[10];
    int x_lift, y_lift;
    while (flag == 1)
    {
        printf("Which light would you like to turn off? \n");
        for (int i = 0; i < y + 2; i++)
        {
            for (int j = 0; j < x + 2; j++)
            {
                if (matrix[i][j].type == 2)
                {
                    printf("%c%d ", (char)(i + 64), j);
                }
            }
        }
        printf("\n");
        scanf("%s", input);
        y_index = (int)(input[0]) - 64;
        x_index = atoi(input + 1);

        if (matrix[y_index][x_index].type == 2)
        {
            flag = 0;
            y_lift = y_index;
            x_lift = x_index;
            break;
        }
        printf("wrong one!\n");
    }
    flag = 1;
    while (flag == 1)
    {
        printf("Which light would you like to turn on? \n");
        for (int i = 0; i < y + 2; i++)
        {
            for (int j = 0; j < x + 2; j++)
            {

                if (matrix[i][j].type == 5)
                {
                    printf("%c%d ", (char)(i + 64), j);
                }
            }
        }
        printf("\n");
        scanf("%s", input);
        y_index = (int)(input[0]) - 64;
        x_index = atoi(input + 1);
        if (matrix[y_index][x_index].type == 5)
        {

            flag = 0;
            matrix[y_index][x_index].type = 2;
            break;
        }
        printf("wrong one!\n");
    }
    matrix[y_lift][x_lift].type = 5;
}
void special_WG(struct tile **matrix, int x, int y)
{
    char input[10];
    printf("who would you like to change position with ? ");
    scanf("%s", input);
    int xrecord, yrecord;
    int x_WG, y_WG;
    for (int i = 0; i < y + 2; i++)
    {
        for (int j = 0; j < x + 2; j++)
        {
            if (strcmp(matrix[i][j].character, input) == 0)
            {
                yrecord = i;
                xrecord = j;
            }
        }
    }
    for (int i = 0; i < y + 2; i++)
    {
        for (int j = 0; j < x + 2; j++)
        {
            if (strcmp(matrix[i][j].character, "WG") == 0)
            {
                y_WG = i;
                x_WG = j;
            }
        }
    }
    strcpy(matrix[yrecord][xrecord].character, "WG");
    strcpy(matrix[y_WG][x_WG].character, input);
}
void special_IL(struct tile **matrix, int x, int y, struct Escape *Gates)
{
    (void)x;
    (void)y;
    int flag = 1;
    char input[10];
    int store;
    while (flag == 1)
    {
        printf("\nWhat gate would you like to lift ?\n");
        for (int i = 0; i < 4; i++)
        {
            if (Gates[i].mode == 0)
            {
                printf("%s ", Gates[i].place);
            }
        }
        printf("\n");
        scanf("%s", input);
        for (int i = 0; i < 4; i++)
        {
            if (strcmp(input, Gates[i].place) == 0 && Gates[i].mode == 0)
            {
                store = i;
                flag = 0;
            }
        }
        if (flag == 1)
        {
            printf("Wrong input!");
        }
    }
    flag = 1;
    while (flag == 1)
    {
        printf("\nWhat gate would you like to place ?\n");
        for (int i = 0; i < 4; i++)
        {
            if (Gates[i].mode == 1)
            {
                printf("%s ", Gates[i].place);
            }
        }
        printf("\n");
        scanf("%s", input);
        for (int i = 0; i < 4; i++)
        {
            if (strcmp(input, Gates[i].place) == 0 && Gates[i].mode == 1)
            {
                flag = 0;
                matrix[(int)(Gates[i].gate1)[0] - 64][atoi(Gates[i].gate1 + 1)].type = 0;
                matrix[(int)(Gates[i].gate2)[0] - 64][atoi(Gates[i].gate2 + 1)].type = 0;
            }
        }
        if (flag == 1)
        {
            printf("Wrong input!");
        }
    }
    matrix[(int)(Gates[store].gate1)[0] - 64][atoi(Gates[store].gate1 + 1)].type = 1;
    matrix[(int)(Gates[store].gate2)[0] - 64][atoi(Gates[store].gate2 + 1)].type = 1;
}
void make_visible(struct tile **matrix, int xrecord, int yrecord, int x, int y, char input[])
{
    if (xrecord == 0 || xrecord == x + 1 || yrecord == 0 || yrecord == y + 1)
    {
    }
    else
    {
        matrix[yrecord][xrecord].visibility = 1;
        if (strcmp(input, "N") == 0)
        {
            strcpy(JW_direction, "N");
            make_visible(matrix, xrecord, yrecord - 1, x, y, "N");
        }
        else if (strcmp(input, "S") == 0)
        {
            strcpy(JW_direction, "S");
            make_visible(matrix, xrecord, yrecord + 1, x, y, "S");
        }
        else if (strcmp(input, "NE") == 0)
        {

            strcpy(JW_direction, "NE");
            if (xrecord % 2 == 0)
            {
                make_visible(matrix, xrecord + 1, yrecord - 1, x, y, "NE");
            }
            else
            {
                make_visible(matrix, xrecord + 1, yrecord, x, y, "NE");
            }
        }
        else if (strcmp(input, "NW") == 0)
        {
            strcpy(JW_direction, "NW");
            if (xrecord % 2 == 0)
            {
                make_visible(matrix, xrecord - 1, yrecord - 1, x, y, "NW");
            }
            else
            {
                make_visible(matrix, xrecord - 1, yrecord, x, y, "NW");
            }
        }
        else if (strcmp(input, "SE") == 0)
        {
            strcpy(JW_direction, "SE");
            if (xrecord % 2 == 0)
            {
                make_visible(matrix, xrecord + 1, yrecord, x, y, "SE");
            }
            else
            {
                make_visible(matrix, xrecord + 1, yrecord + 1, x, y, "SE");
            }
        }
        else if (strcmp(input, "SW") == 0)
        {
            strcpy(JW_direction, "SW");
            if (xrecord % 2 == 0)
            {
                make_visible(matrix, xrecord - 1, yrecord, x, y, "SW");
            }
            else
            {
                make_visible(matrix, xrecord - 1, yrecord + 1, x, y, "SW");
            }
        }
    }
}
void special_JW(struct tile **matrix, int x, int y)
{
    int flag = 1;
    char input[10];
    int xrecord, yrecord;
    for (int i = 0; i < y + 2; i++)
    {
        for (int j = 0; j < x + 2; j++)
        {
            if (strcmp(matrix[i][j].character, "JW") == 0)
            {
                yrecord = i;
                xrecord = j;
            }
        }
    }
    while (flag == 1)
    {
        printf("What is JW's direction?\nN NW NE S SW SE\n");
        scanf("%s", input);
        if (strcmp(input, "N") == 0 || strcmp(input, "NE") == 0 || strcmp(input, "NW") == 0 || strcmp(input, "S") == 0 || strcmp(input, "SW") == 0 || strcmp(input, "SE") == 0)
        {
            flag = 0;
            make_visible(matrix, xrecord, yrecord, x, y, input);
            matrix[yrecord][xrecord].visibility = 0;
        }
        else
        {
            printf("Wrong input!\n");
        }
    }
}
void special_SG(struct tile **matrix, int x, int y)
{
    int xrecord, yrecord;
    for (int i = 0; i < y + 2; i++)
    {
        for (int j = 0; j < x + 2; j++)
        {
            if (strcmp(matrix[i][j].character, "SG") == 0)
            {
                yrecord = i;
                xrecord = j;
            }
        }
    }
    char input[10];
    int move_counter;
    for (int i = 0; i < 3; i++)
    {
        int flag = 1;
        while (flag == 1)
        {
            printf("who would you like to move closer? ");
            scanf("%s", input);
            for (int j = 0; j < 8; j++)
            {
                if (strcmp(input, CARDS[j]) == 0 && strcmp(input, "SG") != 0)
                {
                    flag = 0;
                }
            }
            if (flag == 0)
            {

                int flag_movement = 1;
                while (flag_movement == 1)
                {
                    printf("how many moves would you like to move? ");
                    scanf("%d", &move_counter);
                    if (i + move_counter - 1 <= 3)
                    {
                        i = i + move_counter - 1;
                        flag_movement = 0;
                    }
                }
                move_player_SG(input, matrix, x, y, move_counter, xrecord, yrecord);
            }
            else
            {
                printf("Wrong Input!\n");
            }
        }
    }
}
