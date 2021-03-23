#pragma once

// Joinup.h - Contains declarations of Joinup functions
#pragma once

#ifdef JOINUP_EXPORTS
#define JOINUP_API __declspec(dllexport)
#else
#define JOINUP_API __declspec(dllimport)
#endif

typedef enum class Joinup_opt {

    Stop = 0,
    Start = 1,
    Transfer = 2

} JOINUP_OPT;

//
// Extern declaration
//
extern "C" JOINUP_API BOOLEAN joinup_start(PTSTR Path, PTSTR Name);

extern "C" JOINUP_API BOOLEAN joinup_stop(PTSTR Path, PTSTR Name);

extern "C" JOINUP_API BOOLEAN joinup_setopt(JOINUP_OPT Option, PTSTR Name);
