#include <stdio.h>
#include <string.h>

#include "../wordComponent/wordComponent.h"
#include "../validation/validation.h"

#include "../../keywords/kw_arr/kw_arr.h"
#include "../../keywords/kw_end/kw_end.h"
#include "../../keywords/kw_exit/kw_exit.h"
#include "../../keywords/kw_goif/kw_goif.h"
#include "../../keywords/kw_goto/kw_goto.h"
#include "../../keywords/kw_if/kw_if.h"
#include "../../keywords/kw_out/kw_out.h"
#include "../../keywords/kw_sleep/kw_sleep.h"
#include "../../keywords/kw_var/kw_var.h"

void parseStatement(Word *statement)
{
    if (strcmp(statement[0].type, "Keyword") == 0)
    {
        char *keyword = statement[0].value;

        int output = 0;

        if (strcmp(keyword, keywords[0]) == 0)
            output = kw_var_grammar(statement);
        else if (strcmp(keyword, keywords[1]) == 0)
            output = kw_arr_grammar(statement);
        else if (strcmp(keyword, keywords[2]) == 0)
            output = kw_out_grammar(statement);
        else if (strcmp(keyword, keywords[3]) == 0)
            output = kw_goto_grammar(statement);
        else if (strcmp(keyword, keywords[4]) == 0)
            output = kw_sleep_grammar(statement);
        else if (strcmp(keyword, keywords[5]) == 0)
            output = kw_goif_grammar(statement);
        else if (strcmp(keyword, keywords[6]) == 0)
            output = kw_if_grammar(statement);
        else if (strcmp(keyword, keywords[7]) == 0)
            output = kw_end_grammar(statement);
        else if (strcmp(keyword, keywords[8]) == 0)
            output = kw_exit_grammar(statement);
        else
        {
            // FIXME Implement error handling
            printf("KEYWORD ERROR\n");
        }

        if (output)
        {
            // FIXME Implement error handling
            printf("GRAMMAR ERROR\n");
        }
    }
}
