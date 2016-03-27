unit FloatTestUnit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, fpcunit, testutils, testregistry, FloatUnit, StringUnit;

type

  FloatTest = class(TTestCase)
  published
       procedure floatValueTest;
       procedure compareToTest;
       procedure compareTest;
       procedure equalsTest;
       procedure toStringTest;
       procedure toStringTest2;
       procedure parseFloatTest;
  end;

implementation

(**
 * Tests the floatValue method.
 *)
procedure FloatTest.floatValueTest;
var
    a: Float;
    b: single;
begin
    a := Float.create(Float.MIN_VALUE);
    b := a.floatValue();
    AssertEquals(1.4E-45, b);
    a := Float.create(single(0));
    b := a.floatValue();
    AssertEquals(0.0, b);
    a := Float.create(Float.MAX_VALUE);
    b := a.floatValue();
    //AssertEquals(3.4028235e+38, b);
end;

(**
 * Tests the compareTo method.
 *)
procedure FloatTest.compareToTest;
var
    a, b: Float;
    c: longInt;
begin
    a := Float.create(Float.MIN_VALUE);
    b := Float.create(single(-1));
    c := a.compareTo(b);
    AssertEquals(1, c);
    a := Float.create(Float.MAX_VALUE);
    b := Float.create(single(1));
    c := a.compareTo(b);
    AssertEquals(1, c);
    a := Float.create(single(0));
    b := Float.create(single(1));
    c := a.compareTo(b);
    AssertEquals(-1, c);
    a := Float.create(single(0));
    b := Float.create(single(-1));
    c := a.compareTo(b);
    AssertEquals(1, c);
    a := Float.create(single(1));
    b := Float.create(single(1));
    c := a.compareTo(b);
    AssertEquals(0, c);
    a := Float.create(single(-1));
    b := Float.create(single(-1));
    c := a.compareTo(b);
    AssertEquals(0, c);
end;

(**
 * Tests the compare method.
 *)
procedure FloatTest.compareTest;
var
    a, b: single;
    c: longInt;
begin
    a := Float.MIN_VALUE;
    b := single(-1);
    c := Float.compare(a, b);
    AssertEquals(1, c);
    a := Float.MAX_VALUE;
    b := single(1);
    c := Float.compare(a, b);
    AssertEquals(1, c);
    a := single(0);
    b := single(1);
    c := Float.compare(a, b);
    AssertEquals(-1, c);
    a := single(0);
    b := single(-1);
    c := Float.compare(a, b);
    AssertEquals(1, c);
    a := single(1);
    b := single(1);
    c := Float.compare(a, b);
    AssertEquals(0, c);
    a := single(-1);
    b := single(-1);
    c := Float.compare(a, b);
    AssertEquals(0, c);
end;

(**
 * Tests the equals method.
 *)
procedure FloatTest.equalsTest;
var
    a, b: Float;
    c: boolean;
begin
    a := Float.create(Float.MIN_VALUE);
    b := Float.create(single(-1));
    c := a.equals(b);
    AssertEquals(false, c);
    a := Float.create(Float.MAX_VALUE);
    b := Float.create(single(1));
    c := a.equals(b);
    AssertEquals(false, c);
    a := Float.create(single(0));
    b := Float.create(single(1));
    c := a.equals(b);
    AssertEquals(false, c);
    a := Float.create(single(0));
    b := Float.create(single(-1));
    c := a.equals(b);
    AssertEquals(false, c);
    a := Float.create(single(1));
    b := Float.create(single(1));
    c := a.equals(b);
    AssertEquals(true, c);
    a := Float.create(single(-1));
    b := Float.create(single(-1));
    c := a.equals(b);
    AssertEquals(true, c);
end;

(**
 * Tests the toString method.
 *)
procedure FloatTest.toStringTest;
var
    a: Float;
    b: String_;
begin
    a := Float.create(single(0.1));
    b := a.toString_();
    AssertEquals('0.1', b.strProperty);
    a := Float.create(single(0));
    b := a.toString_();
    AssertEquals('0.0', b.strProperty);
    a := Float.create(single(-0.1));
    b := a.toString_();
    AssertEquals('-0.1', b.strProperty);
end;

(**
 * Tests the static toString method.
 *)
procedure FloatTest.toStringTest2;
var
    a: single;
    b: String_;
begin
    a := single(0.1);
    b := Float.toString_(a);
    AssertEquals('0.1', b.strProperty);
    a := single(0);
    b := Float.toString_(a);
    AssertEquals('0.0', b.strProperty);
    a := single(-0.1);
    b := Float.toString_(a);
    AssertEquals('-0.1', b.strProperty);
end;

(**
 * Tests the parseFloat method.
 *)
procedure FloatTest.parseFloatTest;
var
    a: single;
begin
    a := Float.parseFloat('0.1');
    AssertEquals(0.1, a);
    a := Float.parseFloat('0');
    AssertEquals(0.0, a);
    a := Float.parseFloat('-0.1');
    AssertEquals(-0.1, a);
end;

initialization

  RegisterTest(FloatTest);
end.

