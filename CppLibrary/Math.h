#ifndef MATH_INCLUDED
#define	MATH_INCLUDED

class Math {
    Math();
    ~Math();
public:
    static const int E;
    static const int PI;
    static double abs(double a);
    static float abs(float a);
    static int abs(int a);
    static long abs(long a);
    static double max(double a, double b);
    static float max(float a, float b);
    static int max(int a, int b);
    static long max(long a, long b);
    static double min(double a, double b);
    static float min(float a, float b);
    static int min(int a, int b);
    static long min(long a, long b);
    static double pow(double a, double b);
    static double sqrt(double a);
    static double log(double a);
    static double log10(double a);
    static double sin(double a);
    static double cos(double a);
    static double tan(double a);
    static double asin(double a);
    static double acos(double a);
    static double atan(double a);
    static long round(double a);
    static int round(float a);
};

#endif	// MATH_INCLUDED
