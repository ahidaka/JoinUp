// JoinupTest.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <tchar.h>
#include <Windows.h>
#include <stdio.h>

#include "joinup.h"

int main()
{
    BOOLEAN ret;

    printf("Start!\n");

    ret = joinup_start((PTSTR) L"JoinUp", (PTSTR) L"Start");

    printf("joinup_stark OK=%d\n", ret);

    ret = joinup_setopt((JOINUP_OPT) 1, (PTSTR)L"First");

    printf("joinup_setopt(1) OK=%d\n", ret);;

    ret = joinup_setopt((JOINUP_OPT) 2, (PTSTR)L"Second");

    printf("joinup_setopt(2) OK=%d\n", ret);

    ret = joinup_stop((PTSTR)L"JoinUp", (PTSTR)L"Start");

    printf("joinup_stop OK=%d\n", ret);

    return 0;
}
