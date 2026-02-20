#include "map.h"

struct position
{
    char y;
    int x;
    struct position *next;
};
struct change_place
{
    char name[10];
    int x;
    int y;
    struct change_place *next;
};
int move_possible(char name[], int move)
{
    if (strcmp(name, "SH") == 0)
    {
        if (move <= 3 && move >= 1)
        {
            return 1;
        }
    }
    if (strcmp(name, "JW") == 0)
    {
        if (move <= 3 && move >= 1)
        {
            return 1;
        }
    }
    if (strcmp(name, "JS") == 0)
    {
        if (move <= 3 && move >= 1)
        {
            return 1;
        }
    }
    if (strcmp(name, "IL") == 0)
    {
        if (move <= 3 && move >= 1)
        {
            return 1;
        }
    }
    if (strcmp(name, "MS") == 0)
    {
        if (move <= 4 && move >= 1)
        {
            return 1;
        }
    }
    if (strcmp(name, "SG") == 0)
    {
        if (move <= 3 && move >= 1)
        {
            return 1;
        }
    }
    if (strcmp(name, "WG") == 0)
    {
        if (move <= 3 && move >= 1)
        {
            return 1;
        }
    }
    if (strcmp(name, "JB") == 0)
    {
        if (move <= 3 && move >= 1)
        {
            return 1;
        }
    }
    return 0;
}
struct position *possible_moves(char name[], struct tile **matrix, int x, int y, int move_status)
{
    int xrecord, yrecord;
    for (int i = 0; i < y + 2; i++)
    {
        for (int j = 0; j < x + 2; j++)
        {
            if (strcmp(matrix[i][j].character, name) == 0)
            {
                yrecord = i;
                xrecord = j;
            }
        }
    }
    struct position *head, *current;
    head = current = (struct position *)malloc(sizeof(struct position));
    head->next = NULL;
    if (matrix[yrecord][xrecord].type == 3)
    {
        for (int i = 0; i < y + 2; i++)
        {
            for (int j = 0; j < x + 2; j++)
            {
                if (matrix[i][j].type == 3 && yrecord != i && xrecord != j)
                {
                    if (move_status == 1)
                    {
                        if (strcmp(matrix[i][j].character, "NA") == 0)
                        {
                            current->y = (char)(i + 64);
                            current->x = j;
                            current->next = (struct position *)malloc(sizeof(struct position));
                            current = current->next;
                            current->next = NULL;
                        }
                    }
                    else
                    {
                        current->y = (char)(i + 64);
                        current->x = j;
                        current->next = (struct position *)malloc(sizeof(struct position));
                        current = current->next;
                        current->next = NULL;
                    }
                }
            }
        }
    }
    if (matrix[yrecord][xrecord + 1].type != 0 || (strcmp(name, "MS") == 0 && move_status != 1))
    {
        if (move_status == 1)
        {
            if (strcmp(matrix[yrecord][xrecord + 1].character, "NA") == 0)
            {
                current->y = (char)(yrecord + 64);
                current->x = xrecord + 1;
                current->next = (struct position *)malloc(sizeof(struct position));
                current = current->next;
                current->next = NULL;
            }
        }
        else
        {
            current->y = (char)(yrecord + 64);
            current->x = xrecord + 1;
            current->next = (struct position *)malloc(sizeof(struct position));
            current = current->next;
            current->next = NULL;
        }
    }
    if ((matrix[yrecord][xrecord - 1].type != 0 && matrix[yrecord][xrecord - 1].type != 2 && matrix[yrecord][xrecord - 1].type != 5) || (strcmp(name, "MS") == 0 && move_status != 1))
    {
        if (move_status == 1)
        {
            if (strcmp(matrix[yrecord][xrecord - 1].character, "NA") == 0)
            {
                current->y = (char)(yrecord + 64);
                current->x = xrecord - 1;
                current->next = (struct position *)malloc(sizeof(struct position));
                current = current->next;
                current->next = NULL;
            }
        }
        else
        {
            current->y = (char)(yrecord + 64);
            current->x = xrecord - 1;
            current->next = (struct position *)malloc(sizeof(struct position));
            current = current->next;
            current->next = NULL;
        }
    }
    if ((matrix[yrecord + 1][xrecord].type != 0 && matrix[yrecord + 1][xrecord].type != 2 && matrix[yrecord + 1][xrecord].type != 5) || (strcmp(name, "MS") == 0 && move_status != 1))
    {
        if (move_status == 1)
        {
            if (strcmp(matrix[yrecord + 1][xrecord].character, "NA") == 0)
            {
                current->y = (char)(yrecord + 64 + 1);
                current->x = xrecord;
                current->next = (struct position *)malloc(sizeof(struct position));
                current = current->next;
                current->next = NULL;
            }
        }
        else
        {
            current->y = (char)(yrecord + 64 + 1);
            current->x = xrecord;
            current->next = (struct position *)malloc(sizeof(struct position));
            current = current->next;
            current->next = NULL;
        }
    }
    if ((matrix[yrecord - 1][xrecord].type != 0 && matrix[yrecord - 1][xrecord].type != 2 && matrix[yrecord - 1][xrecord].type != 5) || (strcmp(name, "MS") == 0 && move_status != 1))
    {
        if (move_status == 1)
        {
            if (strcmp(matrix[yrecord - 1][xrecord].character, "NA") == 0)
            {
                current->y = (char)(yrecord + 64 - 1);
                current->x = xrecord;
                current->next = (struct position *)malloc(sizeof(struct position));
                current = current->next;
                current->next = NULL;
            }
        }
        else
        {
            current->y = (char)(yrecord + 64 - 1);
            current->x = xrecord;
            current->next = (struct position *)malloc(sizeof(struct position));
            current = current->next;
            current->next = NULL;
        }
    }
    if (xrecord % 2 == 1)
    {
        if ((matrix[yrecord + 1][xrecord + 1].type != 0 && matrix[yrecord + 1][xrecord + 1].type != 2 && matrix[yrecord + 1][xrecord + 1].type != 5) || (strcmp(name, "MS") == 0 && move_status != 1))
        {
            if (move_status == 1)
            {
                if (strcmp(matrix[yrecord + 1][xrecord + 1].character, "NA") == 0)
                {
                    current->y = (char)(yrecord + 64 + 1);
                    current->x = xrecord + 1;
                    current->next = (struct position *)malloc(sizeof(struct position));
                    current = current->next;
                    current->next = NULL;
                }
            }
            else
            {
                current->y = (char)(yrecord + 64 + 1);
                current->x = xrecord + 1;
                current->next = (struct position *)malloc(sizeof(struct position));
                current = current->next;
                current->next = NULL;
            }
        }
        if ((matrix[yrecord + 1][xrecord - 1].type != 0 && matrix[yrecord + 1][xrecord - 1].type != 2 && matrix[yrecord + 1][xrecord - 1].type != 5) || (strcmp(name, "MS") == 0 && move_status != 1))
        {
            if (move_status == 1)
            {
                if (strcmp(matrix[yrecord - 1][xrecord - 1].character, "NA") == 0)
                {
                    current->y = (char)(yrecord + 64 + 1);
                    current->x = xrecord - 1;
                    current->next = (struct position *)malloc(sizeof(struct position));
                    current = current->next;
                    current->next = NULL;
                }
            }
            else
            {
                current->y = (char)(yrecord + 64 + 1);
                current->x = xrecord - 1;
                current->next = (struct position *)malloc(sizeof(struct position));
                current = current->next;
                current->next = NULL;
            }
        }
    }
    else
    {
        if ((matrix[yrecord - 1][xrecord + 1].type != 0 && matrix[yrecord - 1][xrecord + 1].type != 2 && matrix[yrecord - 1][xrecord + 1].type != 5) || (strcmp(name, "MS") == 0 && move_status != 1))
        {
            if (move_status == 1)
            {
                if (strcmp(matrix[yrecord - 1][xrecord + 1].character, "NA") == 0)
                {
                    current->y = (char)(yrecord + 64 - 1);
                    current->x = xrecord + 1;
                    current->next = (struct position *)malloc(sizeof(struct position));
                    current = current->next;
                    current->next = NULL;
                }
            }
            else
            {
                current->y = (char)(yrecord + 64 - 1);
                current->x = xrecord + 1;
                current->next = (struct position *)malloc(sizeof(struct position));
                current = current->next;
                current->next = NULL;
            }
        }
        if ((matrix[yrecord - 1][xrecord - 1].type != 0 && matrix[yrecord - 1][xrecord - 1].type != 2 && matrix[yrecord - 1][xrecord - 1].type != 5) || (strcmp(name, "MS") == 0 && move_status != 1))
        {
            if (move_status == 1)
            {
                if (strcmp(matrix[yrecord - 1][xrecord - 1].character, "NA") == 0)
                {
                    current->y = (char)(yrecord + 64 - 1);
                    current->x = xrecord - 1;
                    current->next = (struct position *)malloc(sizeof(struct position));
                    current = current->next;
                    current->next = NULL;
                }
            }
            else
            {
                current->y = (char)(yrecord + 64 - 1);
                current->x = xrecord - 1;
                current->next = (struct position *)malloc(sizeof(struct position));
                current = current->next;
                current->next = NULL;
            }
        }
    }
    return head;
}
void move_player(char name[], struct tile **matrix, int x, int y)
{
    int n;
    int status = 0;

    int flag = 1;
    while (flag == 1)
    {
        printf("\nhow many steps would you like to move? ");
        scanf("%d", &n);
        if (move_possible(name, n) == 1)
        {
            flag = 0;
            break;
        }
        printf("wrong amount of moves");
    }
    struct change_place *head_change, *current_change;
    head_change = current_change = (struct change_place *)malloc(sizeof(struct change_place));
    current_change->next = NULL;
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            status = 1;
        }
        struct position *posibble = possible_moves(name, matrix, x, y, status);
        struct position *current;
        int flag = 1;
        char input[10];
        while (flag == 1)
        {
            char y_index;
            int x_index;
            current = posibble;
            printf("possible step(s) are : ");
            while (current->next != NULL)
            {
                if(current->y>='A' && current->y<='I' && current->x>=1 && current->x<=x){
                    printf("%c%d ", current->y, current->x);
                }
                
                current = current->next;
            }
            printf("\nwhere would you like to go? ");
            scanf("%s", input);
            y_index = input[0];
            x_index = atoi(input + 1);
            current = posibble;
            while (current->next != NULL)
            {
                if (y_index == current->y && x_index == current->x)
                {
                    flag = 0;
                    break;
                }
                current = current->next;
            }
            if (flag == 1)
            {
                printf("wrong step!\n");
            }
            else
            {
                int xrecord, yrecord;

                for (int i = 0; i < y + 2; i++)
                {
                    for (int j = 0; j < x + 2; j++)
                    {
                        if (strcmp(matrix[i][j].character, name) == 0)
                        {
                            yrecord = i;
                            xrecord = j;
                        }
                    }
                }

                if (strcmp(matrix[(int)(y_index)-64][x_index].character, "NA") != 0)
                {
                    strcpy(current_change->name, matrix[(int)(y_index)-64][x_index].character);
                    current_change->x = x_index;
                    current_change->y = (int)(y_index)-64;
                    current_change->next = (struct change_place *)malloc(sizeof(struct change_place));
                    current_change = current_change->next;
                }
                strcpy(matrix[(int)(y_index)-64][x_index].character, name);
                strcpy(matrix[yrecord][xrecord].character, "NA");
            }
        }
    }
    while (head_change->next != NULL)
    {
        strcpy(matrix[head_change->y][head_change->x].character, head_change->name);
        head_change = head_change->next;
    }
}
void move_player_SG(char name[], struct tile **matrix, int x, int y, int n, int x_SG, int y_SG)
{
    int xplayer, yplayer;
    for (int i = 0; i < y + 2; i++)
    {
        for (int j = 0; j < x + 2; j++)
        {
            if (strcmp(matrix[i][j].character, name) == 0)
            {
                yplayer = i;
                xplayer = j;
            }
        }
    }
    int status = 0;

    struct change_place *head_change, *current_change;
    head_change = current_change = (struct change_place *)malloc(sizeof(struct change_place));
    current_change->next = NULL;
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            status = 1;
        }
        struct position *posibble = possible_moves(name, matrix, x, y, status);
        struct position *current;
        int flag = 1;
        char input[10];
        while (flag == 1)
        {
            char y_index;
            int x_index;
            current = posibble;
            printf("possible step(s) are : ");
            while (current->next != NULL)
            {
                if (abs(((int)current->y) - 64 - y_SG) + abs(current->x - x_SG) <= abs(yplayer - y_SG) + abs(xplayer - x_SG))
                {
                    printf("%c%d ", current->y, current->x);
                }

                current = current->next;
            }
            printf("\nwhere would you like to go? ");
            scanf("%s", input);
            y_index = input[0];
            x_index = atoi(input + 1);
            current = posibble;
            while (current->next != NULL)
            {
                if (y_index == current->y && x_index == current->x && abs(((int)current->y) - 64 - y_SG) + abs(current->x - x_SG) <= abs(yplayer - y_SG) + abs(xplayer - x_SG))
                {
                    flag = 0;
                    break;
                }
                current = current->next;
            }
            if (flag == 1)
            {
                printf("wrong step!\n");
            }
            else
            {
                int xrecord, yrecord;

                for (int i = 0; i < y + 2; i++)
                {
                    for (int j = 0; j < x + 2; j++)
                    {
                        if (strcmp(matrix[i][j].character, name) == 0)
                        {
                            yrecord = i;
                            xrecord = j;
                        }
                    }
                }

                if (strcmp(matrix[(int)(y_index)-64][x_index].character, "NA") != 0)
                {
                    strcpy(current_change->name, matrix[(int)(y_index)-64][x_index].character);
                    current_change->x = x_index;
                    current_change->y = (int)(y_index)-64;
                    current_change->next = (struct change_place *)malloc(sizeof(struct change_place));
                    current_change = current_change->next;
                }
                strcpy(matrix[(int)(y_index)-64][x_index].character, name);
                strcpy(matrix[yrecord][xrecord].character, "NA");
            }
        }
    }
    while (head_change->next != NULL)
    {
        strcpy(matrix[head_change->y][head_change->x].character, head_change->name);
        head_change = head_change->next;
    }
}
