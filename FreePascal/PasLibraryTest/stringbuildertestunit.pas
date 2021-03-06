unit StringBuilderTestUnit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, fpcunit, testutils, testregistry, StringBuilderUnit, StringUnit;

type

  (**
   * A StringBuilder class test suite.
   *
   * @author Petr Kozler (A13B0359P)
   *)
  StringBuilderTest = class(TTestCase)
  published
       procedure stringBuilderTest;
       procedure appendTest;
       procedure toStringTest;
  end;

implementation

(**
 * Tests the constructor.
 *)
procedure StringBuilderTest.stringBuilderTest;
var
    a: StringBuilder;
    b: String_;
begin
    // new empty stringbuilder
    a := StringBuilder.create();
    b := a.toString_();
    AssertEquals('', b.strProperty);
end;

(**
 * Tests the append method.
 *)
procedure StringBuilderTest.appendTest;
var
    a: StringBuilder;
    b: String_;
begin
    // appending of empty ansiString
    a := StringBuilder.create();
    a.append('');
    b := a.toString_();
    AssertEquals('', b.strProperty);
    // appending of one ansiChar
    a := StringBuilder.create();
    a.append('.');
    b := a.toString_();
    AssertEquals('.', b.strProperty);
    // appending of more chars
    a := StringBuilder.create();
    a.append('test');
    b := a.toString_();
    AssertEquals('test', b.strProperty);
    // multiple appendings (empty ansiString at the beginning)
    a := StringBuilder.create();
    a.append('test');
    a.append('.');
    a.append('');
    b := a.toString_();
    AssertEquals('test.', b.strProperty);
    // multiple appendings (empty ansiString in the middle)
    a := StringBuilder.create();
    a.append('.');
    a.append('');
    a.append('test');
    b := a.toString_();
    AssertEquals('.test', b.strProperty);
    // multiple appendings (empty ansiString at the end)
    a := StringBuilder.create();
    a.append('');
    a.append('test');
    a.append('.');
    b := a.toString_();
    AssertEquals('test.', b.strProperty);
end;

(**
 * Tests the toString method.
 *)
procedure StringBuilderTest.toStringTest;
var
    a: StringBuilder;
    b: String_;
begin
    // appending a ansiString at once
    a := StringBuilder.create();
    a.append('This is a test');
    b := a.toString_();
    AssertEquals('This is a test', b.strProperty);
    // appending a ansiString piecewise
    a := StringBuilder.create();
    a.append('This').append(' is').append(' a').append(' test.');
    b := a.toString_();
    AssertEquals('This is a test.', b.strProperty);
    // appending a ansiString piecewise (more pieces)
    a := StringBuilder.create();
    a.append('This').append(' ').append('is').append(' ').append('a').append(' ').append('test').append('.');
    b := a.toString_();
    AssertEquals('This is a test.', b.strProperty);
end;

initialization

  RegisterTest(StringBuilderTest);
end.

