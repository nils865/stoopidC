#include "../wordComponent/wordComponent.h"
#include "../validation/validation.h"

void parseStatement(Word *statement)
{
    // TODO implement Parser
    if (strcmp(statement[0].type, "Keyword") == 0)
    {
        Word keyword = statement[0];

        int output = 0;

        if (strmp(keyword, keywords[0]) == 0)
        {
            output = kw_var_grammar(statement);
        }
        else if (strcmp(keyword, keywords[1]) == 0)
        {
            output = kw_arr_grammar(statement);
        }
        else if (strcmp(keyword, keywords[2]) == 0)
        {
            output = kw_out_grammar(statement);
        }
        else if (strcmp(keyword, keywords[3]) == 0)
        {
            output = kw_goto_grammar(statement);
        }
        else if (strcmp(keyword, keywords[4]) == 0)
        {
            output = kw_sleep_grammar(statement);
        }
        else if (strcmp(keyword, keywords[5]) == 0)
        {
            output = kw_goif_grammar(statement);
        }
        else if (strcmp(keyword, keywords[6]) == 0)
        {
            output = kw_if_grammar(statement);
        }
        else if (strcmp(keyword, keywords[7]) == 0)
        {
            output = kw_end_grammar(statement);
        }
        else if (strcmp(keyword, keywords[8]) == 0)
        {
            output = kw_exit_grammar(statement);
        }
        else
        {
            // FIXME Implement error handling
            printf("ERROR\n");
        }
    }
}
