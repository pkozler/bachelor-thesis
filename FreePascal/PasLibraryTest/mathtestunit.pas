unit MathTestUnit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, fpcunit, testutils, testregistry, MathUnit, DoubleUnit, FloatUnit, LongUnit, IntegerUnit;

type

  MathTest = class(TTestCase)
  published
       procedure absTest;
       procedure absTest2;
       procedure absTest3;
       procedure absTest4;
       procedure maxTest;
       procedure maxTest2;
       procedure maxTest3;
       procedure maxTest4;
       procedure minTest;
       procedure minTest2;
       procedure minTest3;
       procedure minTest4;
       procedure powTest;
       procedure sqrtTest;
       procedure logTest;
       procedure log10Test;
       procedure sinTest;
       procedure cosTest;
       procedure tanTest;
       procedure asinTest;
       procedure acosTest;
       procedure atanTest;
       procedure roundTest;
       procedure roundTest2;
  end;

implementation

(**
 * Tests the abs method with a double value.
 *)
procedure MathTest.absTest;
var
    a, b: double;
begin
    // negative value
    a := Double_.MIN_VALUE + 1;
    b := Math_.abs(a);
    AssertEquals(1.0, b);
    // zero value
    a := 0;
    b := Math_.abs(a);
    AssertEquals(0.0, b);
    // positive value
    a := Double_.MAX_VALUE - 1;
    b := Math_.abs(a);
    //AssertEquals(1.7976931348623157e+308, b);
end;

(**
 * Tests the abs method with a single value.
 *)
procedure MathTest.absTest2;
var
    a, b: single;
begin
    a := Float.MIN_VALUE + 1;
    b := Math_.abs(a);
    AssertEquals(1.0, b);
    a := 0;
    b := Math_.abs(a);
    AssertEquals(0.0, b);
    a := Float.MAX_VALUE - 1;
    b := Math_.abs(a);
    //AssertEquals(3.4028235E38, b);
end;

(**
 * Tests the abs method with an longInt value.
 *)
procedure MathTest.absTest3;
var
    a, b: longInt;
begin
    a := Integer_.MIN_VALUE + 1;
    b := Math_.abs(a);
    AssertEquals(2147483647, b);
    a := 0;
    b := Math_.abs(a);
    AssertEquals(0, b);
    a := Integer_.MAX_VALUE - 1;
    b := Math_.abs(a);
    AssertEquals(2147483646, b);
end;

(**
 * Tests the abs method with a int64 value.
 *)
procedure MathTest.absTest4;
var
    a, b: int64;
begin
    a := Long.MIN_VALUE + 1;
    b := Math_.abs(a);
    AssertEquals(9223372036854775807, b);
    a := 0;
    b := Math_.abs(a);
    AssertEquals(0, b);
    a := Long.MAX_VALUE - 1;
    b := Math_.abs(a);
    AssertEquals(9223372036854775806, b);
end;

(**
 * Tests the max method with a double value.
 *)
procedure MathTest.maxTest;
var
    a, b, c: double;
begin
    // negative and positive value
    a := Double_.MIN_VALUE;
    b := Double_.MAX_VALUE;
    c := Math_.max(a, b);
    //AssertEquals(1.7976931348623157E308, c);
    // positive and negative value
    a := Double_.MAX_VALUE;
    b := Double_.MIN_VALUE;
    c := Math_.max(a, b);
    //AssertEquals(1.7976931348623157E308, c);
    // negative and positive value (smaller difference)
    a := -1;
    b := 1;
    c := Math_.max(a, b);
    AssertEquals(1.0, c);
    // positive and negative value (bigger difference)
    a := 1;
    b := -1;
    c := Math_.max(a, b);
    // equal values
    AssertEquals(1.0, c);
    a := 0;
    b := 0;
    c := Math_.max(a, b);
    AssertEquals(0.0, c);
end;

(**
 * Tests the max method with a single value.
 *)
procedure MathTest.maxTest2;
var
    a, b, c: single;
begin
    a := Float.MIN_VALUE;
    b := Float.MAX_VALUE;
    c := Math_.max(a, b);
    //AssertEquals(3.4028235E38, c);
    a := Float.MAX_VALUE;
    b := Float.MIN_VALUE;
    c := Math_.max(a, b);
    //AssertEquals(3.4028235E38, c);
    a := -1;
    b := 1;
    c := Math_.max(a, b);
    AssertEquals(1.0, c);
    a := 1;
    b := -1;
    c := Math_.max(a, b);
    AssertEquals(1.0, c);
    a := 0;
    b := 0;
    c := Math_.max(a, b);
    AssertEquals(0.0, c);
end;

(**
 * Tests the max method with an longInt value.
 *)
procedure MathTest.maxTest3;
var
    a, b, c: longInt;
begin
    a := Integer_.MIN_VALUE;
    b := Integer_.MAX_VALUE;
    c := Math_.max(a, b);
    AssertEquals(2147483647, c);
    a := Integer_.MAX_VALUE;
    b := Integer_.MIN_VALUE;
    c := Math_.max(a, b);
    AssertEquals(2147483647, c);
    a := -1;
    b := 1;
    c := Math_.max(a, b);
    AssertEquals(1, c);
    a := 1;
    b := -1;
    c := Math_.max(a, b);
    AssertEquals(1, c);
    a := 0;
    b := 0;
    c := Math_.max(a, b);
    AssertEquals(0, c);
end;

(**
 * Tests the max method with a int64 value.
 *)
procedure MathTest.maxTest4;
var
    a, b, c: int64;
begin
    a := Long.MIN_VALUE;
    b := Long.MAX_VALUE;
    c := Math_.max(a, b);
    AssertEquals(9223372036854775807, c);
    a := Long.MAX_VALUE;
    b := Long.MIN_VALUE;
    c := Math_.max(a, b);
    AssertEquals(9223372036854775807, c);
    a := -1;
    b := 1;
    c := Math_.max(a, b);
    AssertEquals(1, c);
    a := 1;
    b := -1;
    c := Math_.max(a, b);
    AssertEquals(1, c);
    a := 0;
    b := 0;
    c := Math_.max(a, b);
    AssertEquals(0, c);
end;

(**
 * Tests the min method with a double value.
 *)
procedure MathTest.minTest;
var
    a, b, c: double;
begin
    a := Double_.MIN_VALUE;
    b := Double_.MAX_VALUE;
    c := Math_.min(a, b);
    AssertEquals(4.9E-324, c);
    a := Double_.MAX_VALUE;
    b := Double_.MIN_VALUE;
    c := Math_.min(a, b);
    AssertEquals(4.9E-324, c);
    a := -1;
    b := 1;
    c := Math_.min(a, b);
    AssertEquals(-1.0, c);
    a := 1;
    b := -1;
    c := Math_.min(a, b);
    AssertEquals(-1.0, c);
    a := 0;
    b := 0;
    c := Math_.min(a, b);
    AssertEquals(0.0, c);
end;

(**
 * Tests the min method with a single value.
 *)
procedure MathTest.minTest2;
var
    a, b, c: single;
begin
    a := Float.MIN_VALUE;
    b := Float.MAX_VALUE;
    c := Math_.min(a, b);
    AssertEquals(1.4E-45, c);
    a := Float.MAX_VALUE;
    b := Float.MIN_VALUE;
    c := Math_.min(a, b);
    AssertEquals(1.4E-45, c);
    a := -1;
    b := 1;
    c := Math_.min(a, b);
    AssertEquals(-1.0, c);
    a := 1;
    b := -1;
    c := Math_.min(a, b);
    AssertEquals(-1.0, c);
    a := 0;
    b := 0;
    c := Math_.min(a, b);
    AssertEquals(0.0, c);
end;

(**
 * Tests the min method with an longInt value.
 *)
procedure MathTest.minTest3;
var
    a, b, c: longInt;
begin
    a := Integer_.MIN_VALUE;
    b := Integer_.MAX_VALUE;
    c := Math_.min(a, b);
    AssertEquals(-2147483648, c);
    a := Integer_.MAX_VALUE;
    b := Integer_.MIN_VALUE;
    c := Math_.min(a, b);
    AssertEquals(-2147483648, c);
    a := -1;
    b := 1;
    c := Math_.min(a, b);
    AssertEquals(-1, c);
    a := 1;
    b := -1;
    c := Math_.min(a, b);
    AssertEquals(-1, c);
    a := 0;
    b := 0;
    c := Math_.min(a, b);
    AssertEquals(0, c);
end;

(**
 * Tests the min method with a int64 value.
 *)
procedure MathTest.minTest4;
var
    a, b, c: int64;
begin
    a := Long.MIN_VALUE;
    b := Long.MAX_VALUE;
    c := Math_.min(a, b);
    AssertEquals(-9223372036854775808, c);
    a := Long.MAX_VALUE;
    b := Long.MIN_VALUE;
    c := Math_.min(a, b);
    AssertEquals(-9223372036854775808, c);
    a := -1;
    b := 1;
    c := Math_.min(a, b);
    AssertEquals(-1, c);
    a := 1;
    b := -1;
    c := Math_.min(a, b);
    AssertEquals(-1, c);
    a := 0;
    b := 0;
    c := Math_.min(a, b);
    AssertEquals(0, c);
end;

(**
 * Test the pow method.
 *)
procedure MathTest.powTest;
var
    a, b, c: double;
begin
    // positive power of positive value
    a := 10;
    b := 2;
    c := Math_.pow(a, b);
    AssertEquals(100.0, c);
    // positive power of negative value
    a := -10;
    b := 2;
    c := Math_.pow(a, b);
    AssertEquals(100.0, c);
    // negative power of positive value
    a := 10;
    b := -2;
    c := Math_.pow(a, b);
    // zore power
    AssertEquals(0.01, c);
    a := 10;
    b := 0;
    c := Math_.pow(a, b);
    AssertEquals(1.0, c);
    // power of zero
    a := 0;
    b := 10;
    c := Math_.pow(a, b);
    AssertEquals(0.0, c);
end;

(**
 * Tests the sqrt method.
 *)
procedure MathTest.sqrtTest;
var
    a, b: double;
begin
    // square root of bigger value
    a := 100;
    b := Math_.sqrt(a);
    AssertEquals(10.0, b);
    // square root of one
    a := 1;
    b := Math_.sqrt(a);
    AssertEquals(1.0, b);
    // square root of zero
    a := 0;
    b := Math_.sqrt(a);
    AssertEquals(0.0, b);
end;

(**
 * Tests the log method.
 *)
procedure MathTest.logTest;
var
    a, b: double;
begin
    // logarithm of the square of E
    a := Math_.E * Math_.E;
    b := Math_.log(a);
    AssertEquals(2.0, b);
    // logarithm of E
    a := Math_.E;
    b := Math_.log(a);
    AssertEquals(1.0, b);
    // logarithm of one
    a := 1;
    b := Math_.log(a);
    AssertEquals(0.0, b);
end;

(**
 * Tests the log10 method.
 *)
procedure MathTest.log10Test;
var
    a, b: double;
begin
    // logarithm of the square of ten
    a := 100;
    b := Math_.log10(a);
    AssertEquals(2.0, b);
    // logarithm of ten
    a := 10;
    b := Math_.log10(a);
    AssertEquals(1.0, b);
    // logarithm of one
    a := 1;
    b := Math_.log10(a);
    AssertEquals(0.0, b);
end;

(**
 * Tests the sin method.
 *)
procedure MathTest.sinTest;
var
    a, b: double;
begin
    // sine of PI
    a := Math_.PI;
    b := Math_.sin(a);
    AssertEquals(1.2246467991473532E-16, b);
    // sine of minus PI
    a := -Math_.PI;
    b := Math_.sin(a);
    AssertEquals(-1.2246467991473532E-16, b);
    // sine of zero
    a := 0;
    b := Math_.sin(a);
    AssertEquals(0.0, b);
end;

(**
 * Tests the cos method.
 *)
procedure MathTest.cosTest;
var
    a, b: double;
begin
    // cosine of PI
    a := Math_.PI;
    b := Math_.cos(a);
    AssertEquals(-1.0, b);
    // cosine of minus PI
    a := -Math_.PI;
    b := Math_.cos(a);
    AssertEquals(-1.0, b);
    // cosine of zero
    a := 0;
    b := Math_.cos(a);
    AssertEquals(1.0, b);
end;

(**
 * Tests the tan method.
 *)
procedure MathTest.tanTest;
var
    a, b: double;
begin
    // tangent of PI
    a := Math_.PI;
    b := Math_.tan(a);
    AssertEquals(-1.2246467991473532E-16, b);
    // tangent of minus PI
    a := -Math_.PI;
    b := Math_.tan(a);
    AssertEquals(1.2246467991473532E-16, b);
    // tangent of zero
    a := 0;
    b := Math_.tan(a);
    AssertEquals(0.0, b);
end;

(**
 * Tests the asin method.
 *)
procedure MathTest.asinTest;
var
    a, b: double;
begin
    // arcsine of one
    a := 1;
    b := Math_.asin(a);
    AssertEquals(1.5707963267948966, b);
    // arcsine of minus one
    a := -1;
    b := Math_.asin(a);
    AssertEquals(-1.5707963267948966, b);
    // arcsine of zero
    a := 0;
    b := Math_.asin(a);
    AssertEquals(0.0, b);
end;

(**
 * Tests the acos method.
 *)
procedure MathTest.acosTest;
var
    a, b: double;
begin
    // arccosine of one
    a := 1;
    b := Math_.acos(a);
    AssertEquals(0.0, b);
    // arccosine of minus one
    a := -1;
    b := Math_.acos(a);
    AssertEquals(3.141592653589793, b);
    // arccosine of zero
    a := 0;
    b := Math_.acos(a);
    AssertEquals(1.5707963267948966, b);
end;

(**
 * Tests the atan method.
 *)
procedure MathTest.atanTest;
var
    a, b: double;
begin
    // arctangent of one
    a := 1;
    b := Math_.atan(a);
    AssertEquals(0.7853981633974483, b);
    // arctangent of minus one
    a := -1;
    b := Math_.atan(a);
    AssertEquals(-0.7853981633974483, b);
    // arctangent of zero
    a := 0;
    b := Math_.atan(a);
    AssertEquals(0.0, b);
end;

(**
 * Tests the round method with a double value.
 *)
procedure MathTest.roundTest;
var
    a, b: double;
begin
    // rounding to even value
    a := 1.5;
    b := Math_.round(a);
    AssertEquals(2.0, b);
    // rounding to odd value
    a := 0.5;
    b := Math_.round(a);
    AssertEquals(1.0, b);
    // rounding of negative value
    a := -0.5;
    b := Math_.round(a);
    AssertEquals(0.0, b);
end;

(**
 * Tests the round method with a single value.
 *)
procedure MathTest.roundTest2;
var
    a, b: single;
begin
    //a := 1.5f;
    b := Math_.round(a);
    AssertEquals(2.0, b);
    //a := 0.5f;
    b := Math_.round(a);
    AssertEquals(1.0, b);
    //a := -0.5f;
    b := Math_.round(a);
    AssertEquals(0.0, b);
end;

initialization

  RegisterTest(MathTest);
end.

