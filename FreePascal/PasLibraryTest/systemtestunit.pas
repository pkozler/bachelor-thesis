unit PrintStreamTestUnit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, fpcunit, testutils, testregistry, SystemUnit,
  StringUnit, DoubleUnit, FloatUnit, LongUnit, IntegerUnit, TestObjectUnit;

type

  SystemTest = class(TTestCase)
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
procedure SystemTest.printTest;
var
  a: boolean;
begin
    // print of boolean values
    a := true;
    System_.out_.print(a);
    System_.out_.print('\n');
    a := false;
    System_.out_.print(a);
    System_.out_.print('\n');
end;

(**
 * Tests the print method with a ansiChar value.
 *)
procedure SystemTest.printTest2;
var
  a: ansiChar;
begin
    // print of lowercase letters
    a := 'a';
    System_.out_.print(a);
    System_.out_.print('\n');
    a := 'z';
    System_.out_.print(a);
    System_.out_.print('\n');
    // print of uppercase letters
    a := 'A';
    System_.out_.print(a);
    System_.out_.print('\n');
    a := 'Z';
    System_.out_.print(a);
    System_.out_.print('\n');
    // print of digits
    a := '0';
    System_.out_.print(a);
    System_.out_.print('\n');
    a := '9';
    System_.out_.print(a);
    System_.out_.print('\n');
end;

(**
 * Tests the print method with array of chars.
 *)
procedure SystemTest.printTest3;
var
  a: array of ansiChar;
begin
    // empty ansiChar array
    setLength(a, 0);
    System_.out_.print(a);
    System_.out_.print('\n');
    // ansiChar array with one ansiChar
    setLength(a, 1);
    a[0] :=  'a' ;
    System_.out_.print(a);
    System_.out_.print('\n');
    // ansiChar array with some chars
    setLength(a, 6);
    a[0] :=  'a';
    a[1] := 'z';
    a[2] := 'A';
    a[3] := 'Z';
    a[4] := '0';
    a[5] := '9' ;
    System_.out_.print(a);
    System_.out_.print('\n');
end;

(**
 * Tests the print method with a double value.
 *)
procedure SystemTest.printTest4;
var
  a: double;
begin
    // zeros with and without sign
    a := 0;
    System_.out_.print(a);
    System_.out_.print('\n');
    a := -0;
    System_.out_.print(a);
    System_.out_.print('\n');
    // ones with and without sign
    a := 1;
    System_.out_.print(a);
    System_.out_.print('\n');
    a := -1;
    System_.out_.print(a);
    System_.out_.print('\n');
    // maximal absolute value with and without sign
    a := Double_.MAX_VALUE;
    System_.out_.print(a);
    System_.out_.print('\n');
    a := -Double_.MAX_VALUE;
    System_.out_.print(a);
    System_.out_.print('\n');
    // minimal absolute value with and without sign
    a := Double_.MIN_VALUE;
    System_.out_.print(a);
    System_.out_.print('\n');
    a := -Double_.MIN_VALUE;
    System_.out_.print(a);
    System_.out_.print('\n');
end;

(**
 * Tests the print method with a single value.
 *)
procedure SystemTest.printTest5;
var
  a: single;
begin
    a := 0;
    System_.out_.print(a);
    System_.out_.print('\n');
    a := -0;
    System_.out_.print(a);
    System_.out_.print('\n');
    a := 1;
    System_.out_.print(a);
    System_.out_.print('\n');
    a := -1;
    System_.out_.print(a);
    System_.out_.print('\n');
    a := Float.MAX_VALUE;
    System_.out_.print(a);
    System_.out_.print('\n');
    a := -Float.MAX_VALUE;
    System_.out_.print(a);
    System_.out_.print('\n');
    a := Float.MIN_VALUE;
    System_.out_.print(a);
    System_.out_.print('\n');
    a := -Float.MIN_VALUE;
    System_.out_.print(a);
    System_.out_.print('\n');
end;

(**
 * Tests the print method with an longInt value.
 *)
procedure SystemTest.printTest6;
var
  a: longInt;
begin
    // zero
    a := 0;
    System_.out_.print(a);
    System_.out_.print('\n');
    // ones with and without sign
    a := 1;
    System_.out_.print(a);
    System_.out_.print('\n');
    a := -1;
    System_.out_.print(a);
    System_.out_.print('\n');
    // maximal and minimal value
    a := Integer_.MAX_VALUE;
    System_.out_.print(a);
    System_.out_.print('\n');
    a := Integer_.MIN_VALUE;
    System_.out_.print(a);
    System_.out_.print('\n');
end;

(**
 * Tests the print method with a int64 value.
 *)
procedure SystemTest.printTest7;
var
  a: int64;
begin
    a := 0;
    System_.out_.print(a);
    System_.out_.print('\n');
    a := 1;
    System_.out_.print(a);
    System_.out_.print('\n');
    a := -1;
    System_.out_.print(a);
    System_.out_.print('\n');
    a := Long.MAX_VALUE;
    System_.out_.print(a);
    System_.out_.print('\n');
    a := Long.MIN_VALUE;
    System_.out_.print(a);
    System_.out_.print('\n');
end;

(**
 * Tests the print method with an object.
 *)
procedure SystemTest.printTest8;
var
  a: TestObject;
begin
    // object with an empty ansiString
    a := TestObject.create('', 0);
    System_.out_.print(a);
    System_.out_.print('\n');
    // object with digits
    a := TestObject.create('0', 1);
    System_.out_.print(a);
    System_.out_.print('\n');
    a := TestObject.create('9', -1);
    System_.out_.print(a);
    System_.out_.print('\n');
    // object with letters
    a := TestObject.create('Aa', Integer_.MAX_VALUE);
    System_.out_.print(a);
    System_.out_.print('\n');
    a := TestObject.create('Zz', Integer_.MIN_VALUE);
    System_.out_.print(a);
    System_.out_.print('\n');
end;

(**
 * Tests the print method with a ansiString.
 *)
procedure SystemTest.printTest9;
var
  a: String_;
begin
    // empty ansiString
    a := '';
    System_.out_.print(a);
    System_.out_.print('\n');
    // ansiString with one ansiChar
    a := 'a';
    System_.out_.print(a);
    System_.out_.print('\n');
    // ansiString with some chars
    a := 'azAZ09';
    System_.out_.print(a);
    System_.out_.print('\n');
end;

(**
 * Tests the println method.
 *)
procedure SystemTest.printlnTest;
begin
    // print of an empty line
    System_.out_.println();
end;

(**
 * Tests the println method with a boolean value.
 *)
procedure SystemTest.printlnTest2;
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
procedure SystemTest.printlnTest3;
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
procedure SystemTest.printlnTest4;
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
procedure SystemTest.printlnTest5;
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
procedure SystemTest.printlnTest6;
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
procedure SystemTest.printlnTest7;
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
procedure SystemTest.printlnTest8;
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
procedure SystemTest.printlnTest9;
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
procedure SystemTest.printlnTest10;
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

  //RegisterTest(SystemTest);
end.

