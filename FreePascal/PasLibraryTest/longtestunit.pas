unit LongTestUnit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, fpcunit, testutils, testregistry, LongUnit, StringUnit;

type

  LongTest = class(TTestCase)
  published
       procedure longValueTest;
       procedure compareToTest;
       procedure compareTest;
       procedure equalsTest;
       procedure toStringTest;
       procedure toStringTest2;
       procedure parseLongTest;
  end;

implementation

(**
 * Tests the longValue method.
 *)
procedure LongTest.longValueTest;
var
    a: Long;
    b: int64;
begin
    a := Long.create(Long.MIN_VALUE);
    b := a.longValue();
    AssertEquals(-9223372036854775808, b);
    a := Long.create(int64(0));
    b := a.longValue();
    AssertEquals(0, b);
    a := Long.create(Long.MAX_VALUE);
    b := a.longValue();
    AssertEquals(9223372036854775807, b);
end;

(**
 * Tests the compareTo method.
 *)
procedure LongTest.compareToTest;
var
    a, b: Long;
    c: longInt;
begin
    a := Long.create(Long.MIN_VALUE);
    b := Long.create(int64(-1));
    c := a.compareTo(b);
    AssertEquals(-1, c);
    a := Long.create(Long.MAX_VALUE);
    b := Long.create(int64(1));
    c := a.compareTo(b);
    AssertEquals(1, c);
    a := Long.create(int64(0));
    b := Long.create(int64(1));
    c := a.compareTo(b);
    AssertEquals(-1, c);
    a := Long.create(int64(0));
    b := Long.create(int64(-1));
    c := a.compareTo(b);
    AssertEquals(1, c);
    a := Long.create(int64(1));
    b := Long.create(int64(1));
    c := a.compareTo(b);
    AssertEquals(0, c);
    a := Long.create(int64(-1));
    b := Long.create(int64(-1));
    c := a.compareTo(b);
    AssertEquals(0, c);
end;

(**
 * Tests the compare method.
 *)
procedure LongTest.compareTest;
var
    a, b: int64;
    c: longInt;
begin
    a := Long.MIN_VALUE;
    b := int64(-1);
    c := Long.compare(a, b);
    AssertEquals(-1, c);
    a := Long.MAX_VALUE;
    b := int64(1);
    c := Long.compare(a, b);
    AssertEquals(1, c);
    a := int64(0);
    b := int64(1);
    c := Long.compare(a, b);
    AssertEquals(-1, c);
    a := int64(0);
    b := int64(-1);
    c := Long.compare(a, b);
    AssertEquals(1, c);
    a := int64(1);
    b := int64(1);
    c := Long.compare(a, b);
    AssertEquals(0, c);
    a := int64(-1);
    b := int64(-1);
    c := Long.compare(a, b);
    AssertEquals(0, c);
end;

(**
 * Tests the equals method.
 *)
procedure LongTest.equalsTest;
var
    a, b: Long;
    c: boolean;
begin
    a := Long.create(Long.MIN_VALUE);
    b := Long.create(int64(-1));
    c := a.equals(b);
    AssertEquals(false, c);
    a := Long.create(Long.MAX_VALUE);
    b := Long.create(int64(1));
    c := a.equals(b);
    AssertEquals(false, c);
    a := Long.create(int64(0));
    b := Long.create(int64(1));
    c := a.equals(b);
    AssertEquals(false, c);
    a := Long.create(int64(0));
    b := Long.create(int64(-1));
    c := a.equals(b);
    AssertEquals(false, c);
    a := Long.create(int64(1));
    b := Long.create(int64(1));
    c := a.equals(b);
    AssertEquals(true, c);
    a := Long.create(int64(-1));
    b := Long.create(int64(-1));
    c := a.equals(b);
    AssertEquals(true, c);
end;

(**
 * Tests the toString method.
 *)
procedure LongTest.toStringTest;
var
    a: Long;
    b: String_;
begin
    a := Long.create(int64(10000000000));
    b := a.toString_();
    AssertEquals('10000000000', b.strProperty);
    a := Long.create(int64(0));
    b := a.toString_();
    AssertEquals('0', b.strProperty);
    a := Long.create(int64(-10000000000));
    b := a.toString_();
    AssertEquals('-10000000000', b.strProperty);
end;

(**
 * Tests the static toString method.
 *)
procedure LongTest.toStringTest2;
var
    a: int64;
    b: String_;
begin
    a := int64(10000000000);
    b := Long.toString_(a);
    AssertEquals('10000000000', b.strProperty);
    a := int64(0);
    b := Long.toString_(a);
    AssertEquals('0', b.strProperty);
    a := int64(-10000000000);
    b := Long.toString_(a);
    AssertEquals('-10000000000', b.strProperty);
end;

(**
 * Tests the parseLong method.
 *)
procedure LongTest.parseLongTest;
var
    a: int64;
begin
    a := Long.parseLong('10000000000');
    AssertEquals(10000000000, a);
    a := Long.parseLong('0');
    AssertEquals(0, a);
    a := Long.parseLong('-10000000000');
    AssertEquals(-10000000000, a);
end;

initialization

  RegisterTest(LongTest);
end.

