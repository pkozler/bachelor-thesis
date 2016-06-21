unit DoubleTestUnit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, fpcunit, testutils, testregistry, DoubleUnit, StringUnit;

type

  (**
   * A Double class test suite.
   *
   * @author Petr Kozler (A13B0359P)
   *)
  DoubleTest = class(TTestCase)
  published
       procedure doubleValueTest;
       procedure compareToTest;
       procedure compareTest;
       procedure equalsTest;
       procedure toStringTest;
       procedure toStringTest2;
       procedure parseDoubleTest;
  end;

implementation

(**
 * Tests the doubleValue method.
 *)
procedure DoubleTest.doubleValueTest;
var
    a: Double_;
    b: double;
begin
    // minimal non-zero absolute value
    a := Double_.create(Double_.MIN_VALUE);
    b := a.doubleValue();
    AssertEquals(4.9E-324, b);
    // zero value
    a := Double_.create(double(0));
    b := a.doubleValue();
    AssertEquals(0.0, b);
    // maximal finite absolute value
    a := Double_.create(Double_.MAX_VALUE);
    b := a.doubleValue();
    //AssertEquals(1.7976931348623157E308, b);
end;

(**
 * Tests the compareTo method.
 *)
procedure DoubleTest.compareToTest;
var
    a, b: Double_;
    c: longInt;
begin
    // minimal non-zero absolute value and bigger fractional value
    a := Double_.create(Double_.MIN_VALUE);
    b := Double_.create(double(0.1));
    c := a.compareTo(b);
    AssertEquals(-1, c);
    // maximal finite absolute value and smaller integer value
    a := Double_.create(Double_.MAX_VALUE);
    b := Double_.create(double(1));
    c := a.compareTo(b);
    AssertEquals(1, c);
    // zero and positive value
    a := Double_.create(double(0));
    b := Double_.create(double(1));
    c := a.compareTo(b);
    AssertEquals(-1, c);
    // zero and negative value
    a := Double_.create(double(0));
    b := Double_.create(double(-1));
    c := a.compareTo(b);
    AssertEquals(1, c);
    // both values are positive
    a := Double_.create(double(1));
    b := Double_.create(double(1));
    c := a.compareTo(b);
    AssertEquals(0, c);
    // both values are negative
    a := Double_.create(double(-1));
    b := Double_.create(double(-1));
    c := a.compareTo(b);
    AssertEquals(0, c);
end;

(**
 * Tests the compare method.
 *)
procedure DoubleTest.compareTest;
var
    a, b: double;
    c: longInt;
begin
    a := Double_.MIN_VALUE;
    b := double(0.1);
    c := Double_.compare(a, b);
    AssertEquals(-1, c);
    a := Double_.MAX_VALUE;
    b := double(1);
    c := Double_.compare(a, b);
    AssertEquals(1, c);
    a := double(0);
    b := double(1);
    c := Double_.compare(a, b);
    AssertEquals(-1, c);
    a := double(0);
    b := double(-1);
    c := Double_.compare(a, b);
    AssertEquals(1, c);
    a := double(1);
    b := double(1);
    c := Double_.compare(a, b);
    AssertEquals(0, c);
    a := double(-1);
    b := double(-1);
    c := Double_.compare(a, b);
    AssertEquals(0, c);
end;

(**
 * Tests the equals method.
 *)
procedure DoubleTest.equalsTest;
var
    a, b: Double_;
    c: boolean;
begin
    a := Double_.create(Double_.MIN_VALUE);
    b := Double_.create(double(-1));
    c := a.equals(b);
    AssertEquals(false, c);
    a := Double_.create(Double_.MAX_VALUE);
    b := Double_.create(double(1));
    c := a.equals(b);
    AssertEquals(false, c);
    a := Double_.create(double(0));
    b := Double_.create(double(1));
    c := a.equals(b);
    AssertEquals(false, c);
    a := Double_.create(double(0));
    b := Double_.create(double(-1));
    c := a.equals(b);
    AssertEquals(false, c);
    a := Double_.create(double(1));
    b := Double_.create(double(1));
    c := a.equals(b);
    AssertEquals(true, c);
    a := Double_.create(double(-1));
    b := Double_.create(double(-1));
    c := a.equals(b);
    AssertEquals(true, c);
end;

(**
 * Tests the toString method.
 *)
procedure DoubleTest.toStringTest;
var
    a: Double_;
    b: String_;
begin
    // positive value text representation
    a := Double_.create(double(0.0000000000000000000000000000000000000000000001));
    b := a.toString_();
    AssertEquals('1.0E-46', b.strProperty);
    // zero value text representation
    a := Double_.create(double(0));
    b := a.toString_();
    AssertEquals('0.0', b.strProperty);
    // negative value text representation
    a := Double_.create(double(-0.0000000000000000000000000000000000000000000001));
    b := a.toString_();
    AssertEquals('-1.0E-46', b.strProperty);
end;

(**
 * Tests the static toString method.
 *)
procedure DoubleTest.toStringTest2;
var
    a: double;
    b: String_;
begin
    a := double(0.0000000000000000000000000000000000000000000001);
    b := Double_.toString_(a);
    AssertEquals('1.0E-46', b.strProperty);
    a := double(0);
    b := Double_.toString_(a);
    AssertEquals('0.0', b.strProperty);
    a := double(-0.0000000000000000000000000000000000000000000001);
    b := Double_.toString_(a);
    AssertEquals('-1.0E-46', b.strProperty);
end;

(**
 * Tests the parseDouble method.
 *)
procedure DoubleTest.parseDoubleTest;
var
    a: double;
begin
    // positive value parsing
    a := Double_.parseDouble('0.0000000000000000000000000000000000000000000001');
    AssertEquals(1.0E-46, a);
    // zero value parsing
    a := Double_.parseDouble('0');
    AssertEquals(0.0, a);
    // negative value parsing
    a := Double_.parseDouble('-0.0000000000000000000000000000000000000000000001');
    AssertEquals(-1.0E-46, a);
end;

initialization

  RegisterTest(DoubleTest);
end.

