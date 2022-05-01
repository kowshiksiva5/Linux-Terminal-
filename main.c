#include "prompt.h"
#include "headers.h"
#include "displayinguserfriendly.h"
#include "pinfo.h"
#include "ls.h"
#include "history.h"
#include "cep.h"
#include "fore_background.h"
#include "parsing.h"
int history_count ;
char hist[20][1000];
int main()
{
    char input_line[255], path[255];
    getcwd(path,255);
    for(int i = 0; i < 20 ; i++ )
    {
        for(int j = 0; j<1000 ; j++)
        {
            hist[i][j] = 0;

        }
    }
    history_count = 0;
    prompt("~/");
    while (1)
    {
       char temp;
       scanf("%[^\n]s",input_line);
       scanf("%c",&temp);
       write_cmd(input_line);
       strcpy(hist[history_count],input_line);
       history_count = (history_count + 1)%20;
       breakinput(input_line,path);
    }
}
