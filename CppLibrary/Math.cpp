#include "Math.h"

#include <cmath>

const int Math::E = 2.7182818284590452354;
const int Math::PI = 3.14159265358979323846;

Math::Math() {
}

Math::~Math() {
}

double Math::abs(double a) {
    return std::fabs(a);
}

float Math::abs(float a) {
    return std::fabs(a);
}

int Math::abs(int a) {
    return std::abs(a);
}

long Math::abs(long a) {
    return std::abs(a);
}

double Math::max(double a, double b) {
    return max(a, b);
}

float Math::max(float a, float b) {
    return max(a, b);
}

int Math::max(int a, int b) {
    return max(a, b);
}

long Math::max(long a, long b) {
    return max(a, b);
}

double Math::min(double a, double b) {
    return min(a, b);
}

float Math::min(float a, float b) {
    return min(a, b);
}

int Math::min(int a, int b) {
    return min(a, b);
}

long Math::min(long a, long b) {
    return min(a, b);
}

double Math::pow(double a, double b) {
    return std::pow(a, b);
}

double Math::sqrt(double a) {
    return std::sqrt(a);
}

double Math::log(double a) {
    return std::log(a);
}

double Math::log10(double a) {
    return std::log10(a);
}

double Math::sin(double a) {
    return std::sin(a);
}

double Math::cos(double a) {
    return std::cos(a);
}

double Math::tan(double a) {
    return std::tan(a);
}

double Math::asin(double a) {
    return std::asin(a);
}

double Math::acos(double a) {
    return std::acos(a);
}

double Math::atan(double a) {
    return std::atan(a);
}

long Math::round(double a) {
    return (long) std::round(a);
}

int Math::round(float a) {
    return (int) std::round(a);
}
