#include "Arrays.h"

#include "Boolean.h"
#include "Byte.h"
#include "Character.h"
#include "Double.h"
#include "Float.h"
#include "Integer.h"
#include "Long.h"
#include "Short.h"

Arrays::Arrays() {
}

Arrays::~Arrays() {
}

bool Arrays::equalsBool(bool a, bool b) {
    Boolean x(a);
    Boolean y(b);

    return (&x)->equals(&y);
}

bool Arrays::equalsB(int8_t a, int8_t b) {
    Byte x(a);
    Byte y(b);

    return (&x)->equals(&y);
}

bool Arrays::equalsC(char a, char b) {
    Character x(a);
    Character y(b);

    return (&x)->equals(&y);
}

bool Arrays::equalsD(double a, double b) {
    Double x(a);
    Double y(b);

    return (&x)->equals(&y);
}

bool Arrays::equalsF(float a, float b) {
    Float x(a);
    Float y(b);

    return (&x)->equals(&y);
}

bool Arrays::equalsI(int32_t a, int32_t b) {
    Integer x(a);
    Integer y(b);

    return (&x)->equals(&y);
}

bool Arrays::equalsL(int64_t a, int64_t b) {
    Long x(a);
    Long y(b);

    return (&x)->equals(&y);
}

bool Arrays::equalsS(int16_t a, int16_t b) {
    Short x(a);
    Short y(b);

    return (&x)->equals(&y);
}

int32_t Arrays::binarySearch(int8_t *a, int32_t length, int8_t key) {
    return binarySearchGeneric(a, 0, length, key, Byte::compare);
}

int32_t Arrays::binarySearch(int8_t *a, int32_t fromIndex, int32_t toIndex, int8_t key) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, Byte::compare);
}

int32_t Arrays::binarySearch(char *a, int32_t length, char key) {
    return binarySearchGeneric(a, 0, length, key, Character::compare);
}

int32_t Arrays::binarySearch(char *a, int32_t fromIndex, int32_t toIndex, char key) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, Character::compare);
}

int32_t Arrays::binarySearch(double *a, int32_t length, double key) {
    return binarySearchGeneric(a, 0, length, key, Double::compare);
}

int32_t Arrays::binarySearch(double *a, int32_t fromIndex, int32_t toIndex, double key) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, Double::compare);
}

int32_t Arrays::binarySearch(float *a, int32_t length, float key) {
    return binarySearchGeneric(a, 0, length, key, Float::compare);
}

int32_t Arrays::binarySearch(float *a, int32_t fromIndex, int32_t toIndex, float key) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, Float::compare);
}

int32_t Arrays::binarySearch(int32_t *a, int32_t length, int32_t key) {
    return binarySearchGeneric(a, 0, length, key, Integer::compare);
}

int32_t Arrays::binarySearch(int32_t *a, int32_t fromIndex, int32_t toIndex, int32_t key) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, Integer::compare);
}

int32_t Arrays::binarySearch(int64_t *a, int32_t length, int64_t key) {
    return binarySearchGeneric(a, 0, length, key, Long::compare);
}

int32_t Arrays::binarySearch(int64_t *a, int32_t fromIndex, int32_t toIndex, int64_t key) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, Long::compare);
}

int32_t Arrays::binarySearch(void **a, int32_t length, void *key, int32_t (*c)(void *, void *)) {
    return binarySearchGeneric(a, 0, length, key, c);
}

int32_t Arrays::binarySearch(void **a, int32_t fromIndex, int32_t toIndex, void *key, int32_t (*c)(void *, void *)) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, c);
}

int32_t Arrays::binarySearch(int16_t *a, int32_t length, int16_t key) {
    return binarySearchGeneric(a, 0, length, key, Short::compare);
}

int32_t Arrays::binarySearch(int16_t *a, int32_t fromIndex, int32_t toIndex, int16_t key) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, Short::compare);
}

bool *Arrays::copyOf(bool *original, int32_t length, int32_t newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength);
}

int8_t *Arrays::copyOf(int8_t *original, int32_t length, int32_t newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength);
}

char *Arrays::copyOf(char *original, int32_t length, int32_t newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength);
}

double *Arrays::copyOf(double *original, int32_t length, int32_t newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength);
}

float *Arrays::copyOf(float *original, int32_t length, int32_t newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength);
}

int32_t *Arrays::copyOf(int32_t *original, int32_t length, int32_t newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength);
}

int64_t *Arrays::copyOf(int64_t *original, int32_t length, int32_t newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength);
}

int16_t *Arrays::copyOf(int16_t *original, int32_t length, int32_t newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength);
}

bool *Arrays::copyOfRange(bool *original, int32_t length, int32_t from, int32_t to) {
    return copyOfRangeGeneric(original, length, from, to);
}

int8_t *Arrays::copyOfRange(int8_t *original, int32_t length, int32_t from, int32_t to) {
    return copyOfRangeGeneric(original, length, from, to);
}

char *Arrays::copyOfRange(char *original, int32_t length, int32_t from, int32_t to) {
    return copyOfRangeGeneric(original, length, from, to);
}

double *Arrays::copyOfRange(double *original, int32_t length, int32_t from, int32_t to) {
    return copyOfRangeGeneric(original, length, from, to);
}

float *Arrays::copyOfRange(float *original, int32_t length, int32_t from, int32_t to) {
    return copyOfRangeGeneric(original, length, from, to);
}

int32_t *Arrays::copyOfRange(int32_t *original, int32_t length, int32_t from, int32_t to) {
    return copyOfRangeGeneric(original, length, from, to);
}

int64_t *Arrays::copyOfRange(int64_t *original, int32_t length, int32_t from, int32_t to) {
    return copyOfRangeGeneric(original, length, from, to);
}

int16_t *Arrays::copyOfRange(int16_t *original, int32_t length, int32_t from, int32_t to) {
    return copyOfRangeGeneric(original, length, from, to);
}

bool Arrays::equals(bool *a, int32_t length, bool *a2, int32_t length2) {
    return equalsGeneric(a, length, a2, length2, equalsBool);
}

bool Arrays::equals(int8_t *a, int32_t length, int8_t *a2, int32_t length2) {
    return equalsGeneric(a, length, a2, length2, equalsB);
}

bool Arrays::equals(char *a, int32_t length, char *a2, int32_t length2) {
    return equalsGeneric(a, length, a2, length2, equalsC);
}

bool Arrays::equals(double *a, int32_t length, double *a2, int32_t length2) {
    return equalsGeneric(a, length, a2, length2, equalsD);
}

bool Arrays::equals(float *a, int32_t length, float *a2, int32_t length2) {
    return equalsGeneric(a, length, a2, length2, equalsF);
}

bool Arrays::equals(int32_t *a, int32_t length, int32_t *a2, int32_t length2) {
    return equalsGeneric(a, length, a2, length2, equalsI);
}

bool Arrays::equals(int64_t *a, int32_t length, int64_t *a2, int32_t length2) {
    return equalsGeneric(a, length, a2, length2, equalsL);
}

bool Arrays::equals(void **a, int32_t length, void **a2, int32_t length2, bool (*equals)(void *, void *)) {
    return equalsGeneric(a, length, a2, length2, equals);
}

bool Arrays::equals(int16_t *a, int32_t length, int16_t *a2, int32_t length2) {
    return equalsGeneric(a, length, a2, length2, equalsS);
}

void Arrays::fill(bool *a, int32_t length, bool val) {
    fillGeneric(a, 0, length, val);
}

void Arrays::fill(bool *a, int32_t fromIndex, int32_t toIndex, bool val) {
    fillGeneric(a, fromIndex, toIndex, val);
}

void Arrays::fill(int8_t *a, int32_t length, int8_t val) {
    fillGeneric(a, 0, length, val);
}

void Arrays::fill(int8_t *a, int32_t fromIndex, int32_t toIndex, int8_t val) {
    fillGeneric(a, fromIndex, toIndex, val);
}

void Arrays::fill(char *a, int32_t length, char val) {
    fillGeneric(a, 0, length, val);
}

void Arrays::fill(char *a, int32_t fromIndex, int32_t toIndex, char val) {
    fillGeneric(a, fromIndex, toIndex, val);
}

void Arrays::fill(double *a, int32_t length, double val) {
    fillGeneric(a, 0, length, val);
}

void Arrays::fill(double *a, int32_t fromIndex, int32_t toIndex, double val) {
    fillGeneric(a, fromIndex, toIndex, val);
}

void Arrays::fill(float *a, int32_t length, float val) {
    fillGeneric(a, 0, length, val);
}

void Arrays::fill(float *a, int32_t fromIndex, int32_t toIndex, float val) {
    fillGeneric(a, fromIndex, toIndex, val);
}

void Arrays::fill(int32_t *a, int32_t length, int32_t val) {
    fillGeneric(a, 0, length, val);
}

void Arrays::fill(int32_t *a, int32_t fromIndex, int32_t toIndex, int32_t val) {
    fillGeneric(a, fromIndex, toIndex, val);
}

void Arrays::fill(int64_t *a, int32_t length, int64_t val) {
    fillGeneric(a, 0, length, val);
}

void Arrays::fill(int64_t *a, int32_t fromIndex, int32_t toIndex, int64_t val) {
    fillGeneric(a, fromIndex, toIndex, val);
}

void Arrays::fill(void **a, int32_t length, void *val) {
    fillGeneric(a, 0, length, val);
}

void Arrays::fill(void **a, int32_t fromIndex, int32_t toIndex, void *val) {
    fillGeneric(a, fromIndex, toIndex, val);
}

void Arrays::fill(int16_t *a, int32_t length, int16_t val) {
    fillGeneric(a, 0, length, val);
}

void Arrays::fill(int16_t *a, int32_t fromIndex, int32_t toIndex, int16_t val) {
    fillGeneric(a, fromIndex, toIndex, val);
}

void Arrays::sort(int8_t *a, int32_t length) {
    sortGeneric(a, 0, length, Byte::compare);
}

void Arrays::sort(int8_t *a, int32_t fromIndex, int32_t toIndex) {
    sortGeneric(a, fromIndex, toIndex, Byte::compare);
}

void Arrays::sort(char *a, int32_t length) {
    sortGeneric(a, 0, length, Character::compare);
}

void Arrays::sort(char *a, int32_t fromIndex, int32_t toIndex) {
    sortGeneric(a, fromIndex, toIndex, Character::compare);
}

void Arrays::sort(double *a, int32_t length) {
    sortGeneric(a, 0, length, Double::compare);
}

void Arrays::sort(double *a, int32_t fromIndex, int32_t toIndex) {
    sortGeneric(a, fromIndex, toIndex, Double::compare);
}

void Arrays::sort(float *a, int32_t length) {
    sortGeneric(a, 0, length, Float::compare);
}

void Arrays::sort(float *a, int32_t fromIndex, int32_t toIndex) {
    sortGeneric(a, fromIndex, toIndex, Float::compare);
}

void Arrays::sort(int32_t *a, int32_t length) {
    sortGeneric(a, 0, length, Integer::compare);
}

void Arrays::sort(int32_t *a, int32_t fromIndex, int32_t toIndex) {
    sortGeneric(a, fromIndex, toIndex, Integer::compare);
}

void Arrays::sort(int64_t *a, int32_t length) {
    sortGeneric(a, 0, length, Long::compare);
}

void Arrays::sort(int64_t *a, int32_t fromIndex, int32_t toIndex) {
    sortGeneric(a, fromIndex, toIndex, Long::compare);
}

void Arrays::sort(void **a, int32_t length, int32_t (*c)(void *, void *)) {
    sortGeneric(a, 0, length, c);
}

void Arrays::sort(void **a, int32_t fromIndex, int32_t toIndex, int32_t (*c)(void *, void *)) {
    sortGeneric(a, fromIndex, toIndex, c);
}

void Arrays::sort(int16_t *a, int32_t length) {
    sortGeneric(a, 0, length, Short::compare);
}

void Arrays::sort(int16_t *a, int32_t fromIndex, int32_t toIndex) {
    sortGeneric(a, fromIndex, toIndex, Short::compare);
}

String *Arrays::toString(bool *a, int32_t length) {
    return toStringGeneric(a, length, Boolean::toString);
}

String *Arrays::toString(int8_t *a, int32_t length) {
    return toStringGeneric(a, length, Byte::toString);
}

String *Arrays::toString(char *a, int32_t length) {
    return toStringGeneric(a, length, Character::toString);
}

String *Arrays::toString(double *a, int32_t length) {
    return toStringGeneric(a, length, Double::toString);
}

String *Arrays::toString(float *a, int32_t length) {
    return toStringGeneric(a, length, Float::toString);
}

String *Arrays::toString(int32_t *a, int32_t length) {
    return toStringGeneric(a, length, Integer::toString);
}

String *Arrays::toString(int64_t *a, int32_t length) {
    return toStringGeneric(a, length, Long::toString);
}

String *Arrays::toString(void **a, int32_t length, String *(*toString)(void *)) {
    return toStringGeneric(a, length, toString);
}

String *Arrays::toString(int16_t *a, int32_t length) {
    return toStringGeneric(a, length, Short::toString);
}
