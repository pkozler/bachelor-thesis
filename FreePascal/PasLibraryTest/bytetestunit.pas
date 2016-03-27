unit ByteTestUnit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, fpcunit, testutils, testregistry, ByteUnit, StringUnit;

type

  ByteTest = class(TTestCase)
  published
       procedure byteValueTest;
       procedure compareToTest;
       procedure compareTest;
       procedure equalsTest;
       procedure toStringTest;
       procedure toStringTest2;
       procedure parseByteTest;
  end;

implementation

(**
 * Tests the byteValue method.
 *)
procedure ByteTest.byteValueTest;
var
    a: Byte_;
    b: shortInt;
begin
    // minimal value
    a := Byte_.create(Byte_.MIN_VALUE);
    b := a.byteValue();
    AssertEquals(-128, b);
    // zero value
    a := Byte_.create(shortInt(0));
    b := a.byteValue();
    AssertEquals(0, b);
    // maximal value
    a := Byte_.create(Byte_.MAX_VALUE);
    b := a.byteValue();
    AssertEquals(127, b);
end;

(**
 * Tests the compareTo method.
 *)
procedure ByteTest.compareToTest;
var
    a, b: Byte_;
    c: longInt;
begin
    // minimal and bigger negative value
    a := Byte_.create(Byte_.MIN_VALUE);
    b := Byte_.create(shortInt(-1));
    c := a.compareTo(b);
    AssertEquals(-127, c);
    // maximal and smaller positive value
    a := Byte_.create(Byte_.MAX_VALUE);
    b := Byte_.create(shortInt(1));
    c := a.compareTo(b);
    AssertEquals(126, c);
    // zero and positive value
    a := Byte_.create(shortInt(0));
    b := Byte_.create(shortInt(1));
    c := a.compareTo(b);
    AssertEquals(-1, c);
    // zero and negative value
    a := Byte_.create(shortInt(0));
    b := Byte_.create(shortInt(-1));
    c := a.compareTo(b);
    AssertEquals(1, c);
    // both values are positive
    a := Byte_.create(shortInt(1));
    b := Byte_.create(shortInt(1));
    c := a.compareTo(b);
    AssertEquals(0, c);
    // both values are negative
    a := Byte_.create(shortInt(-1));
    b := Byte_.create(shortInt(-1));
    c := a.compareTo(b);
    AssertEquals(0, c);
end;

(**
 * Tests the compare method.
 *)
procedure ByteTest.compareTest;
var
    a, b: shortInt;
    c: longInt;
begin
    a := Byte_.MIN_VALUE;
    b := shortInt(-1);
    c := Byte_.compare(a, b);
    AssertEquals(-127, c);
    a := Byte_.MAX_VALUE;
    b := shortInt(1);
    c := Byte_.compare(a, b);
    AssertEquals(126, c);
    a := shortInt(0);
    b := shortInt(1);
    c := Byte_.compare(a, b);
    AssertEquals(-1, c);
    a := shortInt(0);
    b := shortInt(-1);
    c := Byte_.compare(a, b);
    AssertEquals(1, c);
    a := shortInt(1);
    b := shortInt(1);
    c := Byte_.compare(a, b);
    AssertEquals(0, c);
    a := shortInt(-1);
    b := shortInt(-1);
    c := Byte_.compare(a, b);
    AssertEquals(0, c);
end;

(**
 * Tests the equals method.
 *)
procedure ByteTest.equalsTest;
var
    a, b: Byte_;
    c: boolean;
begin
    a := Byte_.create(Byte_.MIN_VALUE);
    b := Byte_.create(shortInt(-1));
    c := a.equals(b);
    AssertEquals(false, c);
    a := Byte_.create(Byte_.MAX_VALUE);
    b := Byte_.create(shortInt(1));
    c := a.equals(b);
    AssertEquals(false, c);
    a := Byte_.create(shortInt(0));
    b := Byte_.create(shortInt(1));
    c := a.equals(b);
    AssertEquals(false, c);
    a := Byte_.create(shortInt(0));
    b := Byte_.create(shortInt(-1));
    c := a.equals(b);
    AssertEquals(false, c);
    a := Byte_.create(shortInt(1));
    b := Byte_.create(shortInt(1));
    c := a.equals(b);
    AssertEquals(true, c);
    a := Byte_.create(shortInt(-1));
    b := Byte_.create(shortInt(-1));
    c := a.equals(b);
    AssertEquals(true, c);
end;

(**
 * Tests the toString method.
 *)
procedure ByteTest.toStringTest;
var
    a: Byte_;
    b: String_;
begin
    // positive value text representation
    a := Byte_.create(shortInt(100));
    b := a.toString_();
    AssertEquals('100', b.strProperty);
    // zero value text representation
    a := Byte_.create(shortInt(0));
    b := a.toString_();
    AssertEquals('0', b.strProperty);
    // negative value text representation
    a := Byte_.create(shortInt(-100));
    b := a.toString_();
    AssertEquals('-100', b.strProperty);
end;

(**
 * Tests the static toString method.
 *)
procedure ByteTest.toStringTest2;
var
    a: shortInt;
    b: String_;
begin
    a := shortInt(100);
    b := Byte_.toString_(a);
    AssertEquals('100', b.strProperty);
    a := shortInt(0);
    b := Byte_.toString_(a);
    AssertEquals('0', b.strProperty);
    a := shortInt(-100);
    b := Byte_.toString_(a);
    AssertEquals('-100', b.strProperty);
end;

(**
 * Tests the parseByte method.
 *)
procedure ByteTest.parseByteTest;
var
    a: shortInt;
begin
    // positive value parsing
    a := Byte_.parseByte('100');
    AssertEquals(100, a);
    // zero value parsing
    a := Byte_.parseByte('0');
    AssertEquals(0, a);
    // negative value parsing
    a := Byte_.parseByte('-100');
    AssertEquals(-100, a);
end;

initialization

  RegisterTest(ByteTest);
end.

