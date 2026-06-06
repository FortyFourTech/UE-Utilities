#pragma once

/**
 * Universal Guard Macro
 * @param Condition - The condition that MUST be true to continue
 * @param Action    - What to do if false (return, return Value, break, continue)
 * @param LogMsg    - (Optional) Message to print to UE_LOG
 */
#define GUARD(Condition, Action, ...) \
do { \
    if(!(Condition)) { \
        if (!FString(#__VA_ARGS__).IsEmpty()) { \
            UE_LOG(LogTemp, Warning, TEXT("Guard Failed: %s"), *FString(__VA_ARGS__)); \
        } \
        Action; \
    } \
} while(0)

#define GUARD_RETURN(x) GUARD(x, return)
#define GUARD_RET_VAL(x,val) GUARD(x, return val)
#define GUARD_CONTINUE(x) GUARD(x, continue)
#define GUARD_BREAK(x) GUARD(x,break)

#define FINALLY ON_SCOPE_EXIT
