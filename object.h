#ifndef clox_object_h
#define clox_object_h

#include "common.h"
#include "value.h"

#define OBJ_TYPE(value)		(AS_OBJ(value)->type)

#define IS_STRING(value)	isObjType(value, OBJ_STRING)

#define AS_STRING(value)	((ObjString *)AS_OBJ(value))
#define AS_CSTRING(value)	(((ObjString *)AS_OBJ(value))->chars)

typedef enum {
	OBJ_STRING
} ObjType;

struct sObj {
	ObjType type;
	struct sObj* next;
};

// Note: It's nice to store the length of the character so we don't need to
// walk the characters to find the null string to find out how long it is.
// Also, the first field is an Obj. This will make the memory of Obj line up
// perfectly with this struct (the first few bytes, though). In the book this
// is called "struct inheritance". This is because fields are laid out in memory
// in the order in which they are declared.
struct sObjString {
	Obj obj;
	int length;
	char* chars;
};

ObjString* takeString(char* chars, int length);
ObjString* copyString(const char* chars, int length);

// We could not have used a macro for this because that would mean the operation we
// did would have been done twice since we're using the value parameter twice.
// "A macro is expanded by inserting the argument expression ever place the parameter
// name appears in the body. If a macro uses a parameter more than once, that expression
// gets evaluated multiple times."
static inline bool isObjType(Value value, ObjType type) {
	return IS_OBJ(value) && AS_OBJ(value)->type == type;
}

void printObject(Value value);

#endif
