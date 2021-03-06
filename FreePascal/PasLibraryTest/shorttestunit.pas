unit ShortTestUnit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, fpcunit, testutils, testregistry, ShortUnit, StringUnit;

type

  (**
   * A Short class test suite.
   *
   * @author Petr Kozler (A13B0359P)
   *)
  ShortTest = class(TTestCase)
  published
       procedure shortValueTest;
       procedure compareToTest;
       procedure compareTest;
       procedure equalsTest;
       procedure toStringTest;
       procedure toStringTest2;
       procedure parseShortTest;
  end;

implementation

(**
 * Tests the shortValue method.
 *)
procedure ShortTest.shortValueTest;
var
    a: Short;
    b: smallInt;
begin
    a := Short.create(Short.MIN_VALUE);
    b := a.shortValue();
    AssertEquals(-32768, b);
    a := Short.create(smallInt(0));
    b := a.shortValue();
    AssertEquals(0, b);
    a := Short.create(Short.MAX_VALUE);
    b := a.shortValue();
    AssertEquals(32767, b);
end;

(**
 * Tests the compareTo method.
 *)
procedure ShortTest.compareToTest;
var
    a, b: Short;
    c: longInt;
begin
    a := Short.create(Short.MIN_VALUE);
    b := Short.create(smallInt(-1));
    c := a.compareTo(b);
    AssertEquals(-32767, c);
    a := Short.create(Short.MAX_VALUE);
    b := Short.create(smallInt(1));
    c := a.compareTo(b);
    AssertEquals(32766, c);
    a := Short.create(smallInt(0));
    b := Short.create(smallInt(1));
    c := a.compareTo(b);
    AssertEquals(-1, c);
    a := Short.create(smallInt(0));
    b := Short.create(smallInt(-1));
    c := a.compareTo(b);
    AssertEquals(1, c);
    a := Short.create(smallInt(1));
    b := Short.create(smallInt(1));
    c := a.compareTo(b);
    AssertEquals(0, c);
    a := Short.create(smallInt(-1));
    b := Short.create(smallInt(-1));
    c := a.compareTo(b);
    AssertEquals(0, c);
end;

(**
 * Tests the compare method.
 *)
procedure ShortTest.compareTest;
var
    a, b: smallInt;
    c: longInt;
begin
    a := Short.MIN_VALUE;
    b := smallInt(-1);
    c := Short.compare(a, b);
    AssertEquals(-32767, c);
    a := Short.MAX_VALUE;
    b := smallInt(1);
    c := Short.compare(a, b);
    AssertEquals(32766, c);
    a := smallInt(0);
    b := smallInt(1);
    c := Short.compare(a, b);
    AssertEquals(-1, c);
    a := smallInt(0);
    b := smallInt(-1);
    c := Short.compare(a, b);
    AssertEquals(1, c);
    a := smallInt(1);
    b := smallInt(1);
    c := Short.compare(a, b);
    AssertEquals(0, c);
    a := smallInt(-1);
    b := smallInt(-1);
    c := Short.compare(a, b);
    AssertEquals(0, c);
end;

(**
 * Tests the equals method.
 *)
procedure ShortTest.equalsTest;
var
    a, b: Short;
    c: boolean;
begin
    a := Short.create(Short.MIN_VALUE);
    b := Short.create(smallInt(-1));
    c := a.equals(b);
    AssertEquals(false, c);
    a := Short.create(Short.MAX_VALUE);
    b := Short.create(smallInt(1));
    c := a.equals(b);
    AssertEquals(false, c);
    a := Short.create(smallInt(0));
    b := Short.create(smallInt(1));
    c := a.equals(b);
    AssertEquals(false, c);
    a := Short.create(smallInt(0));
    b := Short.create(smallInt(-1));
    c := a.equals(b);
    AssertEquals(false, c);
    a := Short.create(smallInt(1));
    b := Short.create(smallInt(1));
    c := a.equals(b);
    AssertEquals(true, c);
    a := Short.create(smallInt(-1));
    b := Short.create(smallInt(-1));
    c := a.equals(b);
    AssertEquals(true, c);
end;

(**
 * Tests the toString method.
 *)
procedure ShortTest.toStringTest;
var
    a: Short;
    b: String_;
begin
    a := Short.create(smallInt(1000));
    b := a.toString_();
    AssertEquals('1000', b.strProperty);
    a := Short.create(smallInt(0));
    b := a.toString_();
    AssertEquals('0', b.strProperty);
    a := Short.create(smallInt(-1000));
    b := a.toString_();
    AssertEquals('-1000', b.strProperty);
end;

(**
 * Tests the static toString method.
 *)
procedure ShortTest.toStringTest2;
var
    a: smallInt;
    b: String_;
begin
    a := smallInt(1000);
    b := Short.toString_(a);
    AssertEquals('1000', b.strProperty);
    a := smallInt(0);
    b := Short.toString_(a);
    AssertEquals('0', b.strProperty);
    a := smallInt(-1000);
    b := Short.toString_(a);
    AssertEquals('-1000', b.strProperty);
end;

(**
 * Tests the parseShort method.
 *)
procedure ShortTest.parseShortTest;
var
    a: smallInt;
begin
    a := Short.parseShort('1000');
    AssertEquals(1000, a);
    a := Short.parseShort('0');
    AssertEquals(0, a);
    a := Short.parseShort('-1000');
    AssertEquals(-1000, a);
end;

initialization

  RegisterTest(ShortTest);
end.

