unit PrintStreamTestUnit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, fpcunit, testutils, testregistry, SystemUnit,
  StringUnit, DoubleUnit, FloatUnit, LongUnit, IntegerUnit, TestObjectUnit;

type

  (**
   * A PrintStream class test suite.
   *
   * @author Petr Kozler (A13B0359P)
   *)
  PrintStreamTest = class(TTestCase)
  public
    procedure printTest;
    procedure printTest2;
    procedure printTest3;
    procedure printTest4;
    procedure printTest5;
    procedure printTest6;
    procedure printTest7;
    procedure printTest8;
    procedure printTest9;
    procedure printlnTest;
    procedure printlnTest2;
    procedure printlnTest3;
    procedure printlnTest4;
    procedure printlnTest5;
    procedure printlnTest6;
    procedure printlnTest7;
    procedure printlnTest8;
    procedure printlnTest9;
    procedure printlnTest10;
  end;

implementation

(**
 * Tests the print method with a boolean value.
 *)
procedure PrintStreamTest.printTest;
var
  a: boolean;
begin
    // print of boolean values
    a := true;
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    a := false;
    System_.out_.print(a);
    System_.out_.print(lineEnding);
end;

(**
 * Tests the print method with a ansiChar value.
 *)
procedure PrintStreamTest.printTest2;
var
  a: ansiChar;
begin
    // print of lowercase letters
    a := 'a';
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    a := 'z';
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    // print of uppercase letters
    a := 'A';
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    a := 'Z';
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    // print of digits
    a := '0';
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    a := '9';
    System_.out_.print(a);
    System_.out_.print(lineEnding);
end;

(**
 * Tests the print method with array of chars.
 *)
procedure PrintStreamTest.printTest3;
var
  a: array of ansiChar;
begin
    // empty ansiChar array
    setLength(a, 0);
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    // ansiChar array with one ansiChar
    setLength(a, 1);
    a[0] :=  'a' ;
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    // ansiChar array with some chars
    setLength(a, 6);
    a[0] :=  'a';
    a[1] := 'z';
    a[2] := 'A';
    a[3] := 'Z';
    a[4] := '0';
    a[5] := '9' ;
    System_.out_.print(a);
    System_.out_.print(lineEnding);
end;

(**
 * Tests the print method with a double value.
 *)
procedure PrintStreamTest.printTest4;
var
  a: double;
begin
    // zeros with and without sign
    a := 0;
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    a := -0;
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    // ones with and without sign
    a := 1;
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    a := -1;
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    // maximal absolute value with and without sign
    a := Double_.MAX_VALUE;
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    a := -Double_.MAX_VALUE;
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    // minimal absolute value with and without sign
    a := Double_.MIN_VALUE;
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    a := -Double_.MIN_VALUE;
    System_.out_.print(a);
    System_.out_.print(lineEnding);
end;

(**
 * Tests the print method with a single value.
 *)
procedure PrintStreamTest.printTest5;
var
  a: single;
begin
    a := 0;
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    a := -0;
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    a := 1;
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    a := -1;
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    a := Float.MAX_VALUE;
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    a := -Float.MAX_VALUE;
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    a := Float.MIN_VALUE;
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    a := -Float.MIN_VALUE;
    System_.out_.print(a);
    System_.out_.print(lineEnding);
end;

(**
 * Tests the print method with an longInt value.
 *)
procedure PrintStreamTest.printTest6;
var
  a: longInt;
begin
    // zero
    a := 0;
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    // ones with and without sign
    a := 1;
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    a := -1;
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    // maximal and minimal value
    a := Integer_.MAX_VALUE;
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    a := Integer_.MIN_VALUE;
    System_.out_.print(a);
    System_.out_.print(lineEnding);
end;

(**
 * Tests the print method with a int64 value.
 *)
procedure PrintStreamTest.printTest7;
var
  a: int64;
begin
    a := 0;
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    a := 1;
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    a := -1;
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    a := Long.MAX_VALUE;
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    a := Long.MIN_VALUE;
    System_.out_.print(a);
    System_.out_.print(lineEnding);
end;

(**
 * Tests the print method with an object.
 *)
procedure PrintStreamTest.printTest8;
var
  a: TestObject;
begin
    // object with an empty ansiString
    a := TestObject.create('', 0);
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    // object with digits
    a := TestObject.create('0', 1);
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    a := TestObject.create('9', -1);
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    // object with letters
    a := TestObject.create('Aa', Integer_.MAX_VALUE);
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    a := TestObject.create('Zz', Integer_.MIN_VALUE);
    System_.out_.print(a);
    System_.out_.print(lineEnding);
end;

(**
 * Tests the print method with a ansiString.
 *)
procedure PrintStreamTest.printTest9;
var
  a: String_;
begin
    // empty ansiString
    a := '';
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    // ansiString with one ansiChar
    a := 'a';
    System_.out_.print(a);
    System_.out_.print(lineEnding);
    // ansiString with some chars
    a := 'azAZ09';
    System_.out_.print(a);
    System_.out_.print(lineEnding);
end;

(**
 * Tests the println method.
 *)
procedure PrintStreamTest.printlnTest;
begin
    // print of an empty line
    System_.out_.println();
end;

(**
 * Tests the println method with a boolean value.
 *)
procedure PrintStreamTest.printlnTest2;
var
  a: boolean;
begin
    a := true;
    System_.out_.println(a);
    a := false;
    System_.out_.println(a);
end;

(**
 * Tests the println method with a ansiChar value.
 *)
procedure PrintStreamTest.printlnTest3;
var
  a: ansiChar;
begin
    a := 'a';
    System_.out_.println(a);
    a := 'z';
    System_.out_.println(a);
    a := 'A';
    System_.out_.println(a);
    a := 'Z';
    System_.out_.println(a);
    a := '0';
    System_.out_.println(a);
    a := '9';
    System_.out_.println(a);
end;

(**
 * Tests the println method with array of chars.
 *)
procedure PrintStreamTest.printlnTest4;
var
  a: array of ansiChar;
begin
    setLength(a, 0);
    System_.out_.println(a);
    setLength(a, 1);
    a[0] :=  'a' ;
    System_.out_.println(a);
    setLength(a, 6);
    a[0] :=  'a';
    a[1] := 'z';
    a[2] := 'A';
    a[3] := 'Z';
    a[4] := '0';
    a[5] := '9' ;
    System_.out_.println(a);
end;

(**
 * Tests the println method with a double value.
 *)
procedure PrintStreamTest.printlnTest5;
var
  a: double;
begin
    a := 0;
    System_.out_.println(a);
    a := -0;
    System_.out_.println(a);
    a := 1;
    System_.out_.println(a);
    a := -1;
    System_.out_.println(a);
    a := Double_.MAX_VALUE;
    System_.out_.println(a);
    a := -Double_.MAX_VALUE;
    System_.out_.println(a);
    a := Double_.MIN_VALUE;
    System_.out_.println(a);
    a := -Double_.MIN_VALUE;
    System_.out_.println(a);
end;

(**
 * Tests the println method with a single value.
 *)
procedure PrintStreamTest.printlnTest6;
var
  a: single;
begin
    a := 0;
    System_.out_.println(a);
    a := -0;
    System_.out_.println(a);
    a := 1;
    System_.out_.println(a);
    a := -1;
    System_.out_.println(a);
    a := Float.MAX_VALUE;
    System_.out_.println(a);
    a := -Float.MAX_VALUE;
    System_.out_.println(a);
    a := Float.MIN_VALUE;
    System_.out_.println(a);
    a := -Float.MIN_VALUE;
    System_.out_.println(a);
end;

(**
 * Tests the println method with an longInt value.
 *)
procedure PrintStreamTest.printlnTest7;
var
  a: longInt;
begin
    a := 0;
    System_.out_.println(a);
    a := 1;
    System_.out_.println(a);
    a := -1;
    System_.out_.println(a);
    a := Integer_.MAX_VALUE;
    System_.out_.println(a);
    a := Integer_.MIN_VALUE;
    System_.out_.println(a);
end;

(**
 * Tests the println method with a int64 value.
 *)
procedure PrintStreamTest.printlnTest8;
var
  a: int64;
begin
    a := 0;
    System_.out_.println(a);
    a := 1;
    System_.out_.println(a);
    a := -1;
    System_.out_.println(a);
    a := Long.MAX_VALUE;
    System_.out_.println(a);
    a := Long.MIN_VALUE;
    System_.out_.println(a);
end;

(**
 * Tests the println method with an object.
 *)
procedure PrintStreamTest.printlnTest9;
var
  a: TestObject;
begin
    a := TestObject.create('', 0);
    System_.out_.println(a);
    a := TestObject.create('0', 1);
    System_.out_.println(a);
    a := TestObject.create('9', -1);
    System_.out_.println(a);
    a := TestObject.create('Aa', Integer_.MAX_VALUE);
    System_.out_.println(a);
    a := TestObject.create('Zz', Integer_.MIN_VALUE);
    System_.out_.println(a);
end;

(**
 * Tests the println method with a ansiString.
 *)
procedure PrintStreamTest.printlnTest10;
var
  a: String_;
begin
    a := '';
    System_.out_.println(a);
    a := 'a';
    System_.out_.println(a);
    a := 'azAZ09';
    System_.out_.println(a);
end;

initialization

  //RegisterTest(PrintStreamTest);
end.

