/**********************************************************************\
* Aufgabe 25.4.3
*
* Datum: 01.11.2021
* Autor: Daniel Gran
*
\**********************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

int next_space(char *str, int begin);
void print_substr(char *str, int begin, int end);
int read_line(char *buf, int max_len);
int is_palin(char *buf, int start, int stop);
int chr_comp_i(char a, char b);

int main() {
    char inp_str[MAX];
    int length, current_space, following_space, cont;

    cont = 1;
    while (cont)
    {
        printf("Eingabe (max 1000 Zeichen): ");
        fflush(stdin);

        if (read_line(inp_str, MAX) < 0)
        {
            cont = 0;
        } else
        {
            length = strlen(inp_str);

            current_space = -1;
            following_space = 0;
            while (following_space != -1)
            {
                following_space = next_space(inp_str, current_space + 1);

                if (is_palin(inp_str, current_space + 1, following_space))
                {
                    printf("Palindrom: ");
                    print_substr(inp_str, current_space + 1, following_space);
                    printf("\n");
                }

                current_space = following_space;
            }
        }
    }

    return 0;
}

/// Return Pos of next space or -1
int next_space(char *str, int begin)
{
    int length = strlen(str);
    int idx_next = begin;

    while (idx_next < length && str[idx_next] != ' ')
        idx_next++;

    if (idx_next < length)
        return idx_next;
    else
        return -1;
}

/// Print palindrome
void print_substr(char *str, int begin, int end_index)
{
    int i = 0, end;

    if (end_index == -1)
        end = strlen(str);
    else
        end = end_index;

    for (i = begin; i < end; i++)
        putchar(str[i]);
}

/// Read Input from User
int read_line(char *buf, int max_len)
{
    int i = 0;
    unsigned char cont = 1;

    do
    {
        buf[i] = getchar();

        if (buf[i] == EOF || buf[i] == '\n')
            cont = 0;

        i++;
    } while (i < max_len && cont);

    if (buf[0] == EOF)
        return -1;
    else
        buf[i - 1] = '\0';
    return i;
}

/// Compare 2 chars
int chr_comp_i(char a, char b)
{
    return tolower(a) == tolower(b);
}

/// Check if word is a palindrome
int is_palin(char *str, int start, int stop_index)
{
    int i, stop;

    if (stop_index == -1)
        stop = strlen(str);
    else
        stop = stop_index;

    for (i = start; i < stop; i++)
        if (!chr_comp_i(str[i], str[stop - i + start - 1]))
            return 0;

    return 1;
}
