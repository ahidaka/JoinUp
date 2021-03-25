#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include "Joinup.h"

static TCHAR JoinupPath[MAX_PATH];
static TCHAR JoinupName[MAX_PATH];
static TCHAR JoinupOptName[4][MAX_PATH];
static ULONG JoinupLastOpt;
static const ULONG PathLimit = MAX_PATH;

BOOLEAN joinup_start(PTSTR Path, PTSTR Name)
{
	if (Path != NULL && wcslen(Path) > 0 && wcslen(Path) < PathLimit) {
		wcscpy_s(JoinupPath, PathLimit, Path);
	}
	else {
		SetLastError(ERROR_INVALID_PARAMETER);
		return FALSE;
	}

	if (Name != NULL && wcslen(Name) > 0 && wcslen(Name) < PathLimit) {
		wcscpy_s(JoinupName, PathLimit, Name);
	}
	else {
		SetLastError(ERROR_INVALID_PARAMETER);
		return FALSE;
	}
	return TRUE;
}

BOOLEAN joinup_stop(PTSTR Path, PTSTR Name)
{
	if (Path != NULL && wcscmp(JoinupPath, Path) == NULL) {
		;
	}
	else {
		SetLastError(ERROR_INVALID_PARAMETER);
		return FALSE;
	}

	if (Path != NULL && wcscmp(JoinupName, Name) == NULL) {
		;
	}
	else {
		SetLastError(ERROR_INVALID_PARAMETER);
		return FALSE;
	}

	JoinupPath[0] = '\0';
	JoinupName[0] = '\0';

	return TRUE;
}

BOOLEAN joinup_setopt(JOINUP_OPT Option, PTSTR Name)
{

	if (Name != NULL && wcslen(Name) > 0 && wcslen(Name) < PathLimit) {

		switch (Option)
		{
		case Joinup_opt::Stop:

			break;

		case Joinup_opt::Start:
			break;

		case Joinup_opt::Transfer:
			break;

		default:
			SetLastError(ERROR_INVALID_PARAMETER);
			return FALSE;
			break;

		}
		wcscpy_s(JoinupOptName[(INT) Option], PathLimit, Name);
	}
	else {
		SetLastError(ERROR_INVALID_PARAMETER);
		return FALSE;
	}

	return TRUE;
}

BOOLEAN joinup_getopt(JOINUP_OPT Option, PTSTR Name)
{

	if (Name != NULL) {

		switch (Option)
		{
		case Joinup_opt::Stop:
		case Joinup_opt::Start:
		case Joinup_opt::Transfer:
			break;

		default:
			SetLastError(ERROR_INVALID_PARAMETER);
			return FALSE;
			break;

		}

		wcscpy_s(Name, PathLimit, JoinupOptName[(INT) Option]);
	}
	else {
		SetLastError(ERROR_INVALID_PARAMETER);
		return FALSE;
	}

	return TRUE;
}
