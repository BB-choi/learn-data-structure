#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

int EvalRPNExp(char exp[])
{
    Stack stack;
    int expLen = strlen(exp);
    int i;
    char tok, op1, op2;

    StackInit(&stack);

    for (i = 0; i<expLen; i++)  // 수식을 구성하는 문자 각각을 대상으로 반복
    {
        tok = exp[i];   // 한 문자씩 tok에 저장하고

        if (isdigit(tok))   // 문자의 내용이 정수인지 확인
        {
            SPush(&stack, tok - '0');   // 정수이면, 숫자로 변화(-'0')하여 stack에 push
        }
        else
        {
            op2 = SPop(&stack); // 두번째 피연산자를 스택에서 꺼냄
            op1 = SPop(&stack); // 첫번째 피연산자를 스택에서 꺼냄
        
            switch(tok)
            {
                case '+' :
                    SPush(&stack, op1+op2);
                    break;
                case '-' :
                    SPush(&stack, op1-op2);
                    break;
                case '*' :
                    SPush(&stack, op1*op2);
                    break;
                case '/' :
                    SPush(&stack, op1/op2);
                    break;

            }
        } 
    }
    return (SPop(&stack));
}