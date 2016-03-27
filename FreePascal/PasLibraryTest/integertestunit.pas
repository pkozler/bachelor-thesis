unit IntegerTestUnit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, fpcunit, testutils, testregistry, IntegerUnit, StringUnit;

type

  IntegerTest = class(TTestCase)
  published
       procedure intValueTest;
       procedure compareToTest;
       procedure compareTest;
       procedure equalsTest;
       procedure toStringTest;
       procedure toStringTest2;
       procedure parseIntTest;
  end;

implementation

(**
 * Tests the intValue method.
 *)
procedure IntegerTest.intValueTest;
var
    a: Integer_;
    b: longInt;
begin
    a := Integer_.create(Integer_.MIN_VALUE);
    b := a.intValue();
    AssertEquals(-2147483648, b);
    a := Integer_.create(longInt(0));
    b := a.intValue();
    AssertEquals(0, b);
    a := Integer_.create(Integer_.MAX_VALUE);
    b := a.intValue();
    AssertEquals(2147483647, b);
end;

(**
 * Tests the compareTo method.
 *)
procedure IntegerTest.compareToTest;
var
    a, b: Integer_;
    c: longInt;
begin
    a := Integer_.create(Integer_.MIN_VALUE);
    b := Integer_.create(longInt(-1));
    c := a.compareTo(b);
    AssertEquals(-1, c);
    a := Integer_.create(Integer_.MAX_VALUE);
    b := Integer_.create(longInt(1));
    c := a.compareTo(b);
    AssertEquals(1, c);
    a := Integer_.create(longInt(0));
    b := Integer_.create(longInt(1));
    c := a.compareTo(b);
    AssertEquals(-1, c);
    a := Integer_.create(longInt(0));
    b := Integer_.create(longInt(-1));
    c := a.compareTo(b);
    AssertEquals(1, c);
    a := Integer_.create(longInt(1));
    b := Integer_.create(longInt(1));
    c := a.compareTo(b);
    AssertEquals(0, c);
    a := Integer_.create(longInt(-1));
    b := Integer_.create(longInt(-1));
    c := a.compareTo(b);
    AssertEquals(0, c);
end;

(**
 * Tests the compare method.
 *)
procedure IntegerTest.compareTest;
var
    a, b: longInt;
    c: longInt;
begin
    a := Integer_.MIN_VALUE;
    b := longInt(-1);
    c := Integer_.compare(a, b);
    AssertEquals(-1, c);
    a := Integer_.MAX_VALUE;
    b := longInt(1);
    c := Integer_.compare(a, b);
    AssertEquals(1, c);
    a := longInt(0);
    b := longInt(1);
    c := Integer_.compare(a, b);
    AssertEquals(-1, c);
    a := longInt(0);
    b := longInt(-1);
    c := Integer_.compare(a, b);
    AssertEquals(1, c);
    a := longInt(1);
    b := longInt(1);
    c := Integer_.compare(a, b);
    AssertEquals(0, c);
    a := longInt(-1);
    b := longInt(-1);
    c := Integer_.compare(a, b);
    AssertEquals(0, c);
end;

(**
 * Tests the equals method.
 *)
procedure IntegerTest.equalsTest;
var
    a, b: Integer_;
    c: boolean;
begin
    a := Integer_.create(Integer_.MIN_VALUE);
    b := Integer_.create(longInt(-1));
    c := a.equals(b);
    AssertEquals(false, c);
    a := Integer_.create(Integer_.MAX_VALUE);
    b := Integer_.create(longInt(1));
    c := a.equals(b);
    AssertEquals(false, c);
    a := Integer_.create(longInt(0));
    b := Integer_.create(longInt(1));
    c := a.equals(b);
    AssertEquals(false, c);
    a := Integer_.create(longInt(0));
    b := Integer_.create(longInt(-1));
    c := a.equals(b);
    AssertEquals(false, c);
    a := Integer_.create(longInt(1));
    b := Integer_.create(longInt(1));
    c := a.equals(b);
    AssertEquals(true, c);
    a := Integer_.create(longInt(-1));
    b := Integer_.create(longInt(-1));
    c := a.equals(b);
    AssertEquals(true, c);
end;

(**
 * Tests the toString method.
 *)
procedure IntegerTest.toStringTest;
var
    a: Integer_;
    b: String_;
begin
    a := Integer_.create(longInt(100000));
    b := a.toString_();
    AssertEquals('100000', b.strProperty);
    a := Integer_.create(longInt(0));
    b := a.toString_();
    AssertEquals('0', b.strProperty);
    a := Integer_.create(longInt(-100000));
    b := a.toString_();
    AssertEquals('-100000', b.strProperty);
end;

(**
 * Tests the static toString method.
 *)
procedure IntegerTest.toStringTest2;
var
    a: longInt;
    b: String_;
begin
    a := longInt(100000);
    b := Integer_.toString_(a);
    AssertEquals('100000', b.strProperty);
    a := longInt(0);
    b := Integer_.toString_(a);
    AssertEquals('0', b.strProperty);
    a := longInt(-100000);
    b := Integer_.toString_(a);
    AssertEquals('-100000', b.strProperty);
end;

(**
 * Tests the parseInt method.
 *)
procedure IntegerTest.parseIntTest;
var
    a: longInt;
begin
    a := Integer_.parseInt('100000');
    AssertEquals(100000, a);
    a := Integer_.parseInt('0');
    AssertEquals(0, a);
    a := Integer_.parseInt('-100000');
    AssertEquals(-100000, a);
end;

initialization

  RegisterTest(IntegerTest);
end.

