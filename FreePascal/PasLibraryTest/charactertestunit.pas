unit CharacterTestUnit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, fpcunit, testutils, testregistry, CharacterUnit, StringUnit;

type

  (**
   * A Character class test suite.
   *
   * @author Petr Kozler (A13B0359P)
   *)
  CharacterTest = class(TTestCase)
  published
       procedure charValueTest;
       procedure compareToTest;
       procedure compareTest;
       procedure equalsTest;
       procedure toStringTest;
       procedure toStringTest2;
       procedure isDigitTest;
       procedure isLetterTest;
  end;

implementation

(**
 * Tests the charValue method.
 *)
procedure CharacterTest.charValueTest;
var
    a: Character;
    b: ansiChar;
begin
    // uppercase letter
    a := Character.create('A');
    b := a.charValue();
    AssertEquals('A', b);
    // lowercase letter
    a := Character.create('a');
    b := a.charValue();
    AssertEquals('a', b);
    // digit
    a := Character.create('0');
    b := a.charValue();
    AssertEquals('0', b);
end;

(**
 * Tests the compareTo method.
 *)
procedure CharacterTest.compareToTest;
var
    a, b: Character;
    c: longInt;
begin
    // digit and uppercase letter
    a := Character.create('9');
    b := Character.create('Z');
    c := a.compareTo(b);
    AssertEquals(-33, c);
    // lowercase letter and digit
    a := Character.create('z');
    b := Character.create('9');
    c := a.compareTo(b);
    AssertEquals(65, c);
    // lowercase and uppercase letters
    a := Character.create('z');
    b := Character.create('A');
    c := a.compareTo(b);
    AssertEquals(57, c);
    // uppercase and lowercase letters
    a := Character.create('Z');
    b := Character.create('a');
    c := a.compareTo(b);
    AssertEquals(-7, c);
    // both chars are uppercase letters
    a := Character.create('Z');
    b := Character.create('Z');
    c := a.compareTo(b);
    AssertEquals(0, c);
    // both chars are lowercase letters
    a := Character.create('a');
    b := Character.create('a');
    c := a.compareTo(b);
    AssertEquals(0, c);
end;

(**
 * Tests the compare method.
 *)
procedure CharacterTest.compareTest;
var
    a, b: ansiChar;
    c: longInt;
begin
    a := '9';
    b := 'Z';
    c := Character.compare(a, b);
    AssertEquals(-33, c);
    a := 'z';
    b := '9';
    c := Character.compare(a, b);
    AssertEquals(65, c);
    a := 'z';
    b := 'A';
    c := Character.compare(a, b);
    AssertEquals(57, c);
    a := 'Z';
    b := 'a';
    c := Character.compare(a, b);
    AssertEquals(-7, c);
    a := 'Z';
    b := 'Z';
    c := Character.compare(a, b);
    AssertEquals(0, c);
    a := 'a';
    b := 'a';
    c := Character.compare(a, b);
    AssertEquals(0, c);
end;

(**
 * Tests the equals method.
 *)
procedure CharacterTest.equalsTest;
var
    a, b: Character;
    c: boolean;
begin
    a := Character.create('9');
    b := Character.create('Z');
    c := a.equals(b);
    AssertEquals(false, c);
    a := Character.create('z');
    b := Character.create('9');
    c := a.equals(b);
    AssertEquals(false, c);
    a := Character.create('z');
    b := Character.create('A');
    c := a.equals(b);
    AssertEquals(false, c);
    a := Character.create('Z');
    b := Character.create('a');
    c := a.equals(b);
    AssertEquals(false, c);
    a := Character.create('Z');
    b := Character.create('Z');
    c := a.equals(b);
    AssertEquals(true, c);
    a := Character.create('a');
    b := Character.create('a');
    c := a.equals(b);
    AssertEquals(true, c);
end;

(**
 * Tests the toString method.
 *)
procedure CharacterTest.toStringTest;
var
    a: Character;
    b: String_;
begin
    // digit text representation
    a := Character.create('0');
    b := a.toString_();
    AssertEquals('0', b.strProperty);
    // uppercase letter text representation
    a := Character.create('A');
    b := a.toString_();
    AssertEquals('A', b.strProperty);
    // lowercase letter text representation
    a := Character.create('a');
    b := a.toString_();
    AssertEquals('a', b.strProperty);
end;

(**
 * Tests the static toString method.
 *)
procedure CharacterTest.toStringTest2;
var
    a: ansiChar;
    b: String_;
begin
    a := '0';
    b := Character.toString_(a);
    AssertEquals('0', b.strProperty);
    a := 'A';
    b := Character.toString_(a);
    AssertEquals('A', b.strProperty);
    a := 'a';
    b := Character.toString_(a);
    AssertEquals('a', b.strProperty);
end;

(**
 * Tests the isDigit method.
 *)
procedure CharacterTest.isDigitTest;
var
    a: ansiChar;
    b: boolean;
begin
    // lowercase letter
    a := 'a';
    b := Character.isDigit(a);
    AssertEquals(false, b);
    // uppercase letter
    a := 'Z';
    b := Character.isDigit(a);
    AssertEquals(false, b);
    // digit
    a := '0';
    b := Character.isDigit(a);
    AssertEquals(true, b);
    // another digit
    a := '9';
    b := Character.isDigit(a);
    AssertEquals(true, b);
    // whitespace
    a := ' ';
    b := Character.isDigit(a);
    AssertEquals(false, b);
end;

(**
 * Tests the isLetter method.
 *)
procedure CharacterTest.isLetterTest;
var
    a: ansiChar;
    b: boolean;
begin
    a := 'a';
    b := Character.isLetter(a);
    AssertEquals(true, b);
    a := 'Z';
    b := Character.isLetter(a);
    AssertEquals(true, b);
    a := '0';
    b := Character.isLetter(a);
    AssertEquals(false, b);
    a := '9';
    b := Character.isLetter(a);
    AssertEquals(false, b);
    a := ' ';
    b := Character.isLetter(a);
    AssertEquals(false, b);
end;

initialization

  RegisterTest(CharacterTest);
end.

