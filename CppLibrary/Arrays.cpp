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

int32_t Arrays::compareB(int8_t a, int8_t b) {
    return a - b;
}

int32_t Arrays::compareC(char a, char b) {
    return a - b;
}

int32_t Arrays::compareF(float a, float b) {
    Float *f1 = new Float(a);
    Float *f2 = new Float(b);

    return f1->compareTo(f2);
}

int32_t Arrays::compareD(double a, double b) {
    Double *d1 = new Double(a);
    Double *d2 = new Double(b);

    return d1->compareTo(d2);
}

int32_t Arrays::compareI(int32_t a, int32_t b) {
    return a - b;
}

int32_t Arrays::compareL(int64_t a, int64_t b) {
    return a - b;
}

int32_t Arrays::compareS(int16_t a, int16_t b) {
    return a - b;
}

bool Arrays::equalsBool(bool a, bool b) {
    return a == b;
}

bool Arrays::equalsB(int8_t a, int8_t b) {
    return a == b;
}

bool Arrays::equalsC(char a, char b) {
    return a == b;
}

bool Arrays::equalsD(double a, double b) {
    Double d1(a);
    Double d2(b);

    return (&d1)->equals(&d2);
}

bool Arrays::equalsF(float a, float b) {
    Float f1(a);
    Float f2(b);

    return (&f1)->equals(&f2);
}

bool Arrays::equalsI(int32_t a, int32_t b) {
    return a == b;
}

bool Arrays::equalsL(int64_t a, int64_t b) {
    return a == b;
}

bool Arrays::equalsS(int16_t a, int16_t b) {
    return a == b;
}

int32_t Arrays::binarySearch(int8_t *a, int32_t length, int8_t key) {
    return binarySearchGeneric(a, 0, length, key, compareB);
}

int32_t Arrays::binarySearch(int8_t *a, int32_t fromIndex, int32_t toIndex, int8_t key) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, compareB);
}

int32_t Arrays::binarySearch(char *a, int32_t length, char key) {
    return binarySearchGeneric(a, 0, length, key, compareC);
}

int32_t Arrays::binarySearch(char *a, int32_t fromIndex, int32_t toIndex, char key) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, compareC);
}

int32_t Arrays::binarySearch(double *a, int32_t length, double key) {
    return binarySearchGeneric(a, 0, length, key, compareD);
}

int32_t Arrays::binarySearch(double *a, int32_t fromIndex, int32_t toIndex, double key) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, compareD);
}

int32_t Arrays::binarySearch(float *a, int32_t length, float key) {
    return binarySearchGeneric(a, 0, length, key, compareF);
}

int32_t Arrays::binarySearch(float *a, int32_t fromIndex, int32_t toIndex, float key) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, compareF);
}

int32_t Arrays::binarySearch(int32_t *a, int32_t length, int32_t key) {
    return binarySearchGeneric(a, 0, length, key, compareI);
}

int32_t Arrays::binarySearch(int32_t *a, int32_t fromIndex, int32_t toIndex, int32_t key) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, compareI);
}

int32_t Arrays::binarySearch(int64_t *a, int32_t length, int64_t key) {
    return binarySearchGeneric(a, 0, length, key, compareL);
}

int32_t Arrays::binarySearch(int64_t *a, int32_t fromIndex, int32_t toIndex, int64_t key) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, compareL);
}

int32_t Arrays::binarySearch(void **a, int32_t length, void *key, int32_t (*c)(void *, void *)) {
    return binarySearchGeneric(a, 0, length, key, c);
}

int32_t Arrays::binarySearch(void **a, int32_t fromIndex, int32_t toIndex, void *key, int32_t (*c)(void *, void *)) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, c);
}

int32_t Arrays::binarySearch(int16_t *a, int32_t length, int16_t key) {
    return binarySearchGeneric(a, 0, length, key, compareS);
}

int32_t Arrays::binarySearch(int16_t *a, int32_t fromIndex, int32_t toIndex, int16_t key) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, compareS);
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
    sortGeneric(a, 0, length, compareB);
}

void Arrays::sort(int8_t *a, int32_t fromIndex, int32_t toIndex) {
    sortGeneric(a, fromIndex, toIndex, compareB);
}

void Arrays::sort(char *a, int32_t length) {
    sortGeneric(a, 0, length, compareC);
}

void Arrays::sort(char *a, int32_t fromIndex, int32_t toIndex) {
    sortGeneric(a, fromIndex, toIndex, compareC);
}

void Arrays::sort(double *a, int32_t length) {
    sortGeneric(a, 0, length, compareD);
}

void Arrays::sort(double *a, int32_t fromIndex, int32_t toIndex) {
    sortGeneric(a, fromIndex, toIndex, compareD);
}

void Arrays::sort(float *a, int32_t length) {
    sortGeneric(a, 0, length, compareF);
}

void Arrays::sort(float *a, int32_t fromIndex, int32_t toIndex) {
    sortGeneric(a, fromIndex, toIndex, compareF);
}

void Arrays::sort(int32_t *a, int32_t length) {
    sortGeneric(a, 0, length, compareI);
}

void Arrays::sort(int32_t *a, int32_t fromIndex, int32_t toIndex) {
    sortGeneric(a, fromIndex, toIndex, compareI);
}

void Arrays::sort(int64_t *a, int32_t length) {
    sortGeneric(a, 0, length, compareL);
}

void Arrays::sort(int64_t *a, int32_t fromIndex, int32_t toIndex) {
    sortGeneric(a, fromIndex, toIndex, compareL);
}

void Arrays::sort(void **a, int32_t length, int32_t (*c)(void *, void *)) {
    sortGeneric(a, 0, length, c);
}

void Arrays::sort(void **a, int32_t fromIndex, int32_t toIndex, int32_t (*c)(void *, void *)) {
    sortGeneric(a, fromIndex, toIndex, c);
}

void Arrays::sort(int16_t *a, int32_t length) {
    sortGeneric(a, 0, length, compareS);
}

void Arrays::sort(int16_t *a, int32_t fromIndex, int32_t toIndex) {
    sortGeneric(a, fromIndex, toIndex, compareS);
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
