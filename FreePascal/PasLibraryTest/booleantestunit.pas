unit BooleanTestUnit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, fpcunit, testutils, testregistry, BooleanUnit, StringUnit;

type

  (**
   * A Boolean class test suite.
   *
   * @author Petr Kozler (A13B0359P)
   *)
  BooleanTest = class(TTestCase)
  published
       procedure booleanValueTest;
       procedure compareToTest;
       procedure compareTest;
       procedure equalsTest;
       procedure toStringTest;
       procedure toStringTest2;
       procedure parseBooleanTest;
  end;

implementation

(**
 * Tests the booleanValue method.
 *)
procedure BooleanTest.booleanValueTest;
var
    a: Boolean_;
    b: boolean;
begin
    // true value
    a := Boolean_.create(true);
    b := a.booleanValue();
    AssertEquals(true, b);
    // false falue
    a := Boolean_.create(false);
    b := a.booleanValue();
    AssertEquals(false, b);
end;

(**
 * Tests the compareTo method.
 *)
procedure BooleanTest.compareToTest;
var
    a, b: Boolean_;
    c: longInt;
begin
    // true and false
    a := Boolean_.create(true);
    b := Boolean_.create(false);
    c := a.compareTo(b);
    AssertEquals(1, c);
    // false and true
    a := Boolean_.create(false);
    b := Boolean_.create(true);
    c := a.compareTo(b);
    AssertEquals(-1, c);
    // both values are true
    a := Boolean_.create(true);
    b := Boolean_.create(true);
    c := a.compareTo(b);
    AssertEquals(0, c);
    // both values are false
    a := Boolean_.create(false);
    b := Boolean_.create(false);
    c := a.compareTo(b);
    AssertEquals(0, c);
end;

(**
 * Tests the compare method.
 *)
procedure BooleanTest.compareTest;
var
    a, b: boolean;
    c: longInt;
begin
    a := true;
    b := false;
    c := Boolean_.compare(a, b);
    AssertEquals(1, c);
    a := false;
    b := true;
    c := Boolean_.compare(a, b);
    AssertEquals(-1, c);
    a := true;
    b := true;
    c := Boolean_.compare(a, b);
    AssertEquals(0, c);
    a := false;
    b := false;
    c := Boolean_.compare(a, b);
    AssertEquals(0, c);
end;

(**
 * Tests the equals method.
 *)
procedure BooleanTest.equalsTest;
var
    a, b: Boolean_;
    c: boolean;
begin
    a := Boolean_.create(true);
    b := Boolean_.create(false);
    c := a.equals(b);
    AssertEquals(false, c);
    a := Boolean_.create(false);
    b := Boolean_.create(true);
    c := a.equals(b);
    AssertEquals(false, c);
    a := Boolean_.create(true);
    b := Boolean_.create(true);
    c := a.equals(b);
    AssertEquals(true, c);
    a := Boolean_.create(false);
    b := Boolean_.create(false);
    c := a.equals(b);
    AssertEquals(true, c);
end;

(**
 * Tests the toString method.
 *)
procedure BooleanTest.toStringTest;
var
    a: Boolean_;
    b: String_;
begin
    // true value text representation
    a := Boolean_.create(true);
    b := a.toString_();
    AssertEquals('true', b.strProperty);
    // false value text representation
    a := Boolean_.create(false);
    b := a.toString_();
    AssertEquals('false', b.strProperty);
end;

(**
 * Tests the static toString method.
 *)
procedure BooleanTest.toStringTest2;
var
    a: boolean;
    b: String_;
begin
    a := true;
    b := Boolean_.toString_(a);
    AssertEquals('true', b.strProperty);
    a := false;
    b := Boolean_.toString_(a);
    AssertEquals('false', b.strProperty);
end;

(**
 * Tests the parseBoolean method.
 *)
procedure BooleanTest.parseBooleanTest;
var
    a: boolean;
begin
    // true value parsing
    a := Boolean_.parseBoolean('true');
    AssertEquals(true, a);
    // false value parsing
    a := Boolean_.parseBoolean('false');
    AssertEquals(false, a);
end;

initialization

  RegisterTest(BooleanTest);
end.

