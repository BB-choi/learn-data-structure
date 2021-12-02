#include <string.h>
#include <stdlib.h>
#include "InfixToPostfix.h"     // ConvToRPNExp 함수 호출용
#include "PostCalculator.h"     // EvalRPNExp 함수 호출용

int EvalInfixExp(char exp[])
{
    int len = strlen(exp);
    int ret;
    char * expcpy = (char *)malloc(len + 1);    // 문자열 저장공간을 마련해 둔다.
    strcpy(expcpy, exp);    // exp를 expcpy에 복사

    ConvToRPNExp(expcpy);   // 후위표기법 수식으로 변환
    ret = EvalRPNExp(expcpy);   // 변환된 수식을 계산

    free(expcpy);   // 문자열 저장공간을 해제한다
    return (ret);
}