unit StringTestUnit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, fpcunit, testutils, testregistry, StringUnit;

type

  StringTest = class(TTestCase)
  published
       procedure stringTest;
       procedure stringTest2;
       procedure stringTest3;
       procedure compareToTest;
       procedure equalsTest;
       procedure substringTest;
       procedure substringTest2;
       procedure indexOfTest;
       procedure indexOfTest2;
       procedure indexOfTest3;
       procedure indexOfTest4;
       procedure lengthTest;
       procedure trimTest;
       procedure toLowerCaseTest;
       procedure toUpperCaseTest;
       procedure charAtTest;
       procedure replaceTest;
       procedure startsWithTest;
       procedure endsWithTest;
       procedure isEmptyTest;
  end;

implementation

(**
 * Tests the constructor with standard ansiString as a parameter.
 *)
procedure StringTest.stringTest;
var
    a: String_;
begin
    // a ansiString with whitespaces
    a := 'This is a test.';
    AssertEquals('This is a test.', a.strProperty);
    // letters
    a := 'test';
    AssertEquals('test', a.strProperty);
    // digits
    a := '1234';
    AssertEquals('1234', a.strProperty);
    // one ansiChar
    a := 'a';
    AssertEquals('a', a.strProperty);
    // empty ansiString
    a := '';
    AssertEquals('', a.strProperty);
end;

(**
 * Tests the constructor with array of bytes as a parameter.
 *)
procedure StringTest.stringTest2;
var
    a: array of shortInt;
    b: String_;
begin
    // array with some whitespaces
    setLength(a, 15);
    a[0] := shortInt('T');
    a[1] := shortInt('h');
    a[2] := shortInt('i');
    a[3] := shortInt('s');
    a[4] := shortInt(' ');
    a[5] := shortInt('i');
    a[6] := shortInt('s');
    a[7] := shortInt(' ');
    a[8] := shortInt('a');
    a[9] := shortInt(' ');
    a[10] := shortInt('t');
    a[11] := shortInt('e');
    a[12] := shortInt('s');
    a[13] := shortInt('t');
    a[14] := shortInt('.');
    b := String_.create(a);
    AssertEquals('This is a test.', b.strProperty);
    // array without whitespaces
    setLength(a, 4);
    a[0] := shortInt('1');
    a[1] := shortInt('2');
    a[2] := shortInt('3');
    a[3] := shortInt('4');
    b := String_.create(a);
    AssertEquals('1234', b.strProperty);
    // empty array
    setLength(a, 0);
    b := String_.create(a);
    AssertEquals('', b.strProperty);
end;

(**
 * Tests the constructor with array of bytes and indexes as parameters.
 *)
procedure StringTest.stringTest3;
var
    a: array of shortInt;
    b: String_;
begin
    // choosing a part of array with some chars
    setLength(a, 15);
    a[0] := shortInt('T');
    a[1] := shortInt('h');
    a[2] := shortInt('i');
    a[3] := shortInt('s');
    a[4] := shortInt(' ');
    a[5] := shortInt('i');
    a[6] := shortInt('s');
    a[7] := shortInt(' ');
    a[8] := shortInt('a');
    a[9] := shortInt(' ');
    a[10] := shortInt('t');
    a[11] := shortInt('e');
    a[12] := shortInt('s');
    a[13] := shortInt('t');
    a[14] := shortInt('.');
    b := String_.create(a, 10, 4);
    AssertEquals('test', b.strProperty);
end;

(**
 * Tests the compareTo method.
 *)
procedure StringTest.compareToTest;
var
    a, b: String_;
    c: longInt;
begin
    // differens strings at the beginning
    a := 'aaa';
    b := 'bbb';
    c := a.compareTo(b);
    AssertEquals(-1, c);
    // different strings at the end
    a := 'aaaa';
    b := 'aaab';
    c := a.compareTo(b);
    AssertEquals(-1, c);
    // differens strings at the beginning (swapped)
    a := 'bbb';
    b := 'aaa';
    c := a.compareTo(b);
    AssertEquals(1, c);
    // different strings at the end (swapped)
    a := 'aaab';
    b := 'aaaa';
    c := a.compareTo(b);
    AssertEquals(1, c);
    // equal strings
    a := 'aaa';
    b := 'aaa';
    c := a.compareTo(b);
    AssertEquals(0, c);
end;

(**
 * Tests the equals method.
 *)
procedure StringTest.equalsTest;
var
    a, b: String_;
    c: boolean;
begin
    a := 'aaa';
    b := 'bbb';
    c := a.equals(b);
    AssertEquals(false, c);
    a := 'aaaa';
    b := 'aaab';
    c := a.equals(b);
    AssertEquals(false, c);
    a := 'bbb';
    b := 'aaa';
    c := a.equals(b);
    AssertEquals(false, c);
    a := 'aaab';
    b := 'aaaa';
    c := a.equals(b);
    AssertEquals(false, c);
    a := 'aaa';
    b := 'aaa';
    c := a.equals(b);
    AssertEquals(true, c);
end;

(**
 * Tests the substring method.
 *)
procedure StringTest.substringTest;
var
    a, b: String_;
begin
    a := 'This is a test.';
    // ansiString from the beginning
    b := a.substring(0);
    AssertEquals('This is a test.', b.strProperty);
    // ansiString from some other position
    b := a.substring(10);
    AssertEquals('test.', b.strProperty);
end;

(**
 * Tests the substring method with end index as a parameter.
 *)
procedure StringTest.substringTest2;
var
    a, b: String_;
begin
    a := 'This is a test.';
    // ansiString from the beginning to the position near the beginning
    b := a.substring(0, 4);
    AssertEquals('This', b.strProperty);
    // ansiString from the beginning to the position far from the beginning
    b := a.substring(10, 14);
    AssertEquals('test', b.strProperty);
    // ansiString from the end
    b := a.substring(14, 15);
    AssertEquals('.', b.strProperty);
    // equal indexes
    b := a.substring(10, 10);
    AssertEquals('', b.strProperty);
end;

(**
 * Tests the indexOf method with a ansiChar value.
 *)
procedure StringTest.indexOfTest;
var
    a: String_;
    b: longInt;
begin
    a := 'This is a test.';
    // ansiChar occurring once
    b := a.indexOf('a');
    AssertEquals(8, b);
    // ansiChar occuring more times
    b := a.indexOf('t');
    AssertEquals(10, b);
    // ansiChar occurring once (at the beginning)
    b := a.indexOf('T');
    AssertEquals(0, b);
    // ansiChar occurring once (at the end)
    b := a.indexOf('.');
    AssertEquals(14, b);
    // ansiChar not occurring
    b := a.indexOf('_');
    AssertEquals(-1, b);
end;

(**
 * Tests the indexOf method with a ansiChar value and end index as a parameter.
 *)
procedure StringTest.indexOfTest2;
var
    a: String_;
    b: longInt;
begin
    a := 'This is a test.';
    b := a.indexOf('a', 10);
    AssertEquals(-1, b);
    b := a.indexOf('t', 10);
    AssertEquals(10, b);
    b := a.indexOf('i', 0);
    AssertEquals(2, b);
    b := a.indexOf('i', 4);
    AssertEquals(5, b);
    b := a.indexOf('i', 10);
    AssertEquals(-1, b);
end;

(**
 * Tests the indexOf method with a ansiString.
 *)
procedure StringTest.indexOfTest3;
var
    a: String_;
    b: longInt;
begin
    a := 'This is a test.';
    // occurring ansiString (at the beginning)
    b := a.indexOf('This');
    AssertEquals(0, b);
    // occurring ansiString (at the end)
    b := a.indexOf('test');
    AssertEquals(10, b);
    // non-occurring ansiString
    b := a.indexOf('aaa');
    AssertEquals(-1, b);
end;

(**
 * Tests the indexOf method with a ansiString and end index as a parameter.
 *)
procedure StringTest.indexOfTest4;
var
    a: String_;
    b: longInt;
begin
    a := 'This is a test.';
    b := a.indexOf('This', 0);
    AssertEquals(0, b);
    b := a.indexOf('test', 4);
    AssertEquals(10, b);
    b := a.indexOf('This', 10);
    AssertEquals(-1, b);
end;

(**
 * Tests the length method.
 *)
procedure StringTest.lengthTest;
var
    a: String_;
    b: longInt;
begin
    // ansiString with multiple chars
    a := 'This is a test.';
    b := a.length();
    AssertEquals(15, b);
    // ansiString with one ansiChar
    a := '.';
    b := a.length();
    AssertEquals(1, b);
    // empty ansiString
    a := '';
    b := a.length();
    AssertEquals(0, b);
end;

(**
 * Tests the trim method.
 *)
procedure StringTest.trimTest;
var
    a, b: String_;
begin
    // ansiString without whitespaces
    a := 'test';
    b := a.trim();
    AssertEquals('test', b.strProperty);
    // whitespaces on the left side
    a := '   test';
    b := a.trim();
    AssertEquals('test', b.strProperty);
    // whitespaces on the right side
    a := 'test   ';
    b := a.trim();
    AssertEquals('test', b.strProperty);
    // whitespaces on bots sides
    a := ' test ';
    b := a.trim();
    AssertEquals('test', b.strProperty);
    // whitespaces inside
    a := 't e s t';
    b := a.trim();
    AssertEquals('t e s t', b.strProperty);
end;

(**
 * Tests the toLower method.
 *)
procedure StringTest.toLowerCaseTest;
var
    a, b: String_;
begin
    // all letters lowercase
    a := 'test';
    b := a.toLowerCase();
    AssertEquals('test', b.strProperty);
    // all letters uppercase
    a := 'TEST';
    b := a.toLowerCase();
    AssertEquals('test', b.strProperty);
    // different cases
    a := 'TesT';
    b := a.toLowerCase();
    AssertEquals('test', b.strProperty);
end;

(**
 * Tests the toUpper method.
 *)
procedure StringTest.toUpperCaseTest;
var
    a, b: String_;
begin
    a := 'test';
    b := a.toUpperCase();
    AssertEquals('TEST', b.strProperty);
    a := 'TEST';
    b := a.toUpperCase();
    AssertEquals('TEST', b.strProperty);
    a := 'TesT';
    b := a.toUpperCase();
    AssertEquals('TEST', b.strProperty);
end;

(**
 * Tests the charAt method.
 *)
procedure StringTest.charAtTest;
var
    a: String_;
    b: ansiChar;
begin
    a := 'This is a test.';
    // at the beginning
    b := a.charAt(0);
    AssertEquals('T', b);
    // in the middle
    b := a.charAt(10);
    AssertEquals('t', b);
    // at the end
    b := a.charAt(14);
    AssertEquals('.', b);
end;

(**
 * Tests the replace method.
 *)
procedure StringTest.replaceTest;
var
    a, b: String_;
begin
    a := 'This is a test.';
    // replacing chars inside the ansiString
    b := a.replace(' ', '_');
    AssertEquals('This_is_a_test.', b.strProperty);
    // replacing chars in the beginning of the ansiString
    b := a.replace('T', 't');
    AssertEquals('this is a test.', b.strProperty);
    // replacing chars in the end of the ansiString
    b := a.replace('.', '!');
    AssertEquals('This is a test!', b.strProperty);
    // replacing of the non-existent chars
    b := a.replace('?', ':');
    AssertEquals('This is a test.', b.strProperty);
end;

(**
 * Tests the startsWith method.
 *)
procedure StringTest.startsWithTest;
var
    a, b: String_;
    c: boolean;
begin
    a := 'This is a test.';
    // ansiString at the beginning
    b := 'This ';
    c := a.startsWith(b);
    AssertEquals(true, c);
    // ansiString inside
    b := 'is';
    c := a.startsWith(b);
    AssertEquals(false, c);
    // ansiString at the end
    b := 'test.';
    c := a.startsWith(b);
    AssertEquals(false, c);
end;

(**
 * Tests the endsWith method.
 *)
procedure StringTest.endsWithTest;
var
    a, b: String_;
    c: boolean;
begin
    a := 'This is a test.';
    b := 'This ';
    c := a.endsWith(b);
    AssertEquals(false, c);
    b := 'is';
    c := a.endsWith(b);
    AssertEquals(false, c);
    b := 'test.';
    c := a.endsWith(b);
    AssertEquals(true, c);
end;

(**
 * Tests the isEmpty method.
 *)
procedure StringTest.isEmptyTest;
var
    a: String_;
    b: boolean;
begin
    // non-empty ansiString
    a := 'This is a test.';
    b := a.isEmpty();
    AssertEquals(false, b);
    // non-empty ansiString with a single ansiChar
    a := '.';
    b := a.isEmpty();
    AssertEquals(false, b);
    // empty ansiString
    a := '';
    b := a.isEmpty();
    AssertEquals(true, b);
end;

initialization

  RegisterTest(StringTest);
end.

