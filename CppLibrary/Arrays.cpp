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

bool Arrays::equalsI(int a, int b) {
    return a == b;
}

bool Arrays::equalsL(long a, long b) {
    return a == b;
}

bool Arrays::equalsS(short a, short b) {
    return a == b;
}

int Arrays::compareC(char a, char b) {
    return a - b;
}

int Arrays::compareF(float a, float b) {
    Float *f1 = new Float(a);
    Float *f2 = new Float(b);

    return f1->compareTo(f2);
}

int Arrays::compareD(double a, double b) {
    Double *d1 = new Double(a);
    Double *d2 = new Double(b);

    return d1->compareTo(d2);
}

int Arrays::compareI(int a, int b) {
    return a - b;
}

int Arrays::compareL(long a, long b) {
    return a - b;
}

int Arrays::compareS(short a, short b) {
    return a - b;
}

int Arrays::binarySearch(char *a, int length, char key) {
    return binarySearchGeneric(a, 0, length, key, compareC);
}

int Arrays::binarySearch(char *a, int fromIndex, int toIndex, char key) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, compareC);
}

int Arrays::binarySearch(double *a, int length, double key) {
    return binarySearchGeneric(a, 0, length, key, compareD);
}

int Arrays::binarySearch(double *a, int fromIndex, int toIndex, double key) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, compareD);
}

int Arrays::binarySearch(float *a, int length, float key) {
    return binarySearchGeneric(a, 0, length, key, compareF);
}

int Arrays::binarySearch(float *a, int fromIndex, int toIndex, float key) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, compareF);
}

int Arrays::binarySearch(int *a, int length, int key) {
    return binarySearchGeneric(a, 0, length, key, compareI);
}

int Arrays::binarySearch(int *a, int fromIndex, int toIndex, int key) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, compareI);
}

int Arrays::binarySearch(long *a, int length, long key) {
    return binarySearchGeneric(a, 0, length, key, compareL);
}

int Arrays::binarySearch(long *a, int fromIndex, int toIndex, long key) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, compareL);
}

int Arrays::binarySearch(void **a, int length, void *key, int (*c)(void *, void *)) {
    return binarySearchGeneric(a, 0, length, key, c);
}

int Arrays::binarySearch(void **a, int fromIndex, int toIndex, void *key, int (*c)(void *, void *)) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, c);
}

int Arrays::binarySearch(short *a, int length, short key) {
    return binarySearchGeneric(a, 0, length, key, compareS);
}

int Arrays::binarySearch(short *a, int fromIndex, int toIndex, short key) {
    return binarySearchGeneric(a, fromIndex, toIndex, key, compareS);
}

bool *Arrays::copyOf(bool *original, int length, int newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength);
}

char *Arrays::copyOf(char *original, int length, int newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength);
}

double *Arrays::copyOf(double *original, int length, int newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength);
}

float *Arrays::copyOf(float *original, int length, int newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength);
}

int *Arrays::copyOf(int *original, int length, int newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength);
}

long *Arrays::copyOf(long *original, int length, int newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength);
}

short *Arrays::copyOf(short *original, int length, int newLength) {
    return copyOfRangeGeneric(original, length, 0, newLength);
}

bool *Arrays::copyOfRange(bool *original, int length, int from, int to) {
    return copyOfRangeGeneric(original, length, from, to);
}

char *Arrays::copyOfRange(char *original, int length, int from, int to) {
    return copyOfRangeGeneric(original, length, from, to);
}

double *Arrays::copyOfRange(double *original, int length, int from, int to) {
    return copyOfRangeGeneric(original, length, from, to);
}

float *Arrays::copyOfRange(float *original, int length, int from, int to) {
    return copyOfRangeGeneric(original, length, from, to);
}

int *Arrays::copyOfRange(int *original, int length, int from, int to) {
    return copyOfRangeGeneric(original, length, from, to);
}

long *Arrays::copyOfRange(long *original, int length, int from, int to) {
    return copyOfRangeGeneric(original, length, from, to);
}

short *Arrays::copyOfRange(short *original, int length, int from, int to) {
    return copyOfRangeGeneric(original, length, from, to);
}

bool Arrays::equals(bool *a, int length, bool *a2, int length2) {
    return equalsGeneric(a, length, a2, length2, equalsBool);
}

bool Arrays::equals(char *a, int length, char *a2, int length2) {
    return equalsGeneric(a, length, a2, length2, equalsC);
}

bool Arrays::equals(double *a, int length, double *a2, int length2) {
    return equalsGeneric(a, length, a2, length2, equalsD);
}

bool Arrays::equals(float *a, int length, float *a2, int length2) {
    return equalsGeneric(a, length, a2, length2, equalsF);
}

bool Arrays::equals(int *a, int length, int *a2, int length2) {
    return equalsGeneric(a, length, a2, length2, equalsI);
}

bool Arrays::equals(long *a, int length, long *a2, int length2) {
    return equalsGeneric(a, length, a2, length2, equalsL);
}

bool Arrays::equals(void **a, int length, void **a2, int length2, bool (*equals)(void *, void *)) {
    return equalsGeneric(a, length, a2, length2, equals);
}

bool Arrays::equals(short *a, int length, short *a2, int length2) {
    return equalsGeneric(a, length, a2, length2, equalsS);
}

void Arrays::fill(bool *a, int length, bool val) {
    fillGeneric(a, 0, length, val);
}

void Arrays::fill(bool *a, int fromIndex, int toIndex, bool val) {
    fillGeneric(a, fromIndex, toIndex, val);
}

void Arrays::fill(char *a, int length, char val) {
    fillGeneric(a, 0, length, val);
}

void Arrays::fill(char *a, int fromIndex, int toIndex, char val) {
    fillGeneric(a, fromIndex, toIndex, val);
}

void Arrays::fill(double *a, int length, double val) {
    fillGeneric(a, 0, length, val);
}

void Arrays::fill(double *a, int fromIndex, int toIndex, double val) {
    fillGeneric(a, fromIndex, toIndex, val);
}

void Arrays::fill(float *a, int length, float val) {
    fillGeneric(a, 0, length, val);
}

void Arrays::fill(float *a, int fromIndex, int toIndex, float val) {
    fillGeneric(a, fromIndex, toIndex, val);
}

void Arrays::fill(int *a, int length, int val) {
    fillGeneric(a, 0, length, val);
}

void Arrays::fill(int *a, int fromIndex, int toIndex, int val) {
    fillGeneric(a, fromIndex, toIndex, val);
}

void Arrays::fill(long *a, int length, long val) {
    fillGeneric(a, 0, length, val);
}

void Arrays::fill(long *a, int fromIndex, int toIndex, long val) {
    fillGeneric(a, fromIndex, toIndex, val);
}

void Arrays::fill(void **a, int length, void *val) {
    fillGeneric(a, 0, length, val);
}

void Arrays::fill(void **a, int fromIndex, int toIndex, void *val) {
    fillGeneric(a, fromIndex, toIndex, val);
}

void Arrays::fill(short *a, int length, short val) {
    fillGeneric(a, 0, length, val);
}

void Arrays::fill(short *a, int fromIndex, int toIndex, short val) {
    fillGeneric(a, fromIndex, toIndex, val);
}

void Arrays::sort(char *a, int length) {
    sortGeneric(a, 0, length, compareC);
}

void Arrays::sort(char *a, int fromIndex, int toIndex) {
    sortGeneric(a, fromIndex, toIndex, compareC);
}

void Arrays::sort(double *a, int length) {
    sortGeneric(a, 0, length, compareD);
}

void Arrays::sort(double *a, int fromIndex, int toIndex) {
    sortGeneric(a, fromIndex, toIndex, compareD);
}

void Arrays::sort(float *a, int length) {
    sortGeneric(a, 0, length, compareF);
}

void Arrays::sort(float *a, int fromIndex, int toIndex) {
    sortGeneric(a, fromIndex, toIndex, compareF);
}

void Arrays::sort(int *a, int length) {
    sortGeneric(a, 0, length, compareI);
}

void Arrays::sort(int *a, int fromIndex, int toIndex) {
    sortGeneric(a, fromIndex, toIndex, compareI);
}

void Arrays::sort(long *a, int length) {
    sortGeneric(a, 0, length, compareL);
}

void Arrays::sort(long *a, int fromIndex, int toIndex) {
    sortGeneric(a, fromIndex, toIndex, compareL);
}

void Arrays::sort(void **a, int length, int (*c)(void *, void *)) {
    sortGeneric(a, 0, length, c);
}

void Arrays::sort(void **a, int fromIndex, int toIndex, int (*c)(void *, void *)) {
    sortGeneric(a, fromIndex, toIndex, c);
}

void Arrays::sort(short *a, int length) {
    sortGeneric(a, 0, length, compareS);
}

void Arrays::sort(short *a, int fromIndex, int toIndex) {
    sortGeneric(a, fromIndex, toIndex, compareS);
}

String *Arrays::toString(bool *a, int length) {
    return toStringGeneric(a, length, Boolean::toString);
}

String *Arrays::toString(char *a, int length) {
    return toStringGeneric(a, length, Character::toString);
}

String *Arrays::toString(double *a, int length) {
    return toStringGeneric(a, length, Double::toString);
}

String *Arrays::toString(float *a, int length) {
    return toStringGeneric(a, length, Float::toString);
}

String *Arrays::toString(int *a, int length) {
    return toStringGeneric(a, length, Integer::toString);
}

String *Arrays::toString(long *a, int length) {
    return toStringGeneric(a, length, Long::toString);
}

String *Arrays::toString(void **a, int length, String *(*toString)(void *)) {
    return toStringGeneric(a, length, toString);
}

String *Arrays::toString(short *a, int length) {
    return toStringGeneric(a, length, Short::toString);
}
