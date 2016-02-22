#include "Math.h"

#include <cmath>

const int32_t Math::E = 2.7182818284590452354;
const int32_t Math::PI = 3.14159265358979323846;

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

int32_t Math::abs(int32_t a) {
    return std::abs(a);
}

int64_t Math::abs(int64_t a) {
    return std::abs(a);
}

double Math::max(double a, double b) {
    return max(a, b);
}

float Math::max(float a, float b) {
    return max(a, b);
}

int32_t Math::max(int32_t a, int32_t b) {
    return max(a, b);
}

int64_t Math::max(int64_t a, int64_t b) {
    return max(a, b);
}

double Math::min(double a, double b) {
    return min(a, b);
}

float Math::min(float a, float b) {
    return min(a, b);
}

int32_t Math::min(int32_t a, int32_t b) {
    return min(a, b);
}

int64_t Math::min(int64_t a, int64_t b) {
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

int64_t Math::round(double a) {
    return (int64_t) std::round(a);
}

int32_t Math::round(float a) {
    return (int32_t) std::round(a);
}
