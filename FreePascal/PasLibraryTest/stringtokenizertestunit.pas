unit StringTokenizerTestUnit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, fpcunit, testutils, testregistry, StringTokenizerUnit, StringUnit, ArraysUnit;

type
  ObjectArray = array of Object_;

  (**
   * A StringTokenizer class test suite.
   *
   * @author Petr Kozler (A13B0359P)
   *)
  StringTokenizerTest = class(TTestCase)
  private
       function toStringArray(a: StringTokenizer): ObjectArray;
  published
       procedure stringTokenizerTest;
       procedure stringTokenizerTest2;
       procedure countTokensTest;
       procedure hasMoreTokensTest;
       procedure nextTokenTest;
  end;

implementation

(*
 Creates the ansiString representation of the array of tokens which are created
 from tokenized ansiString.
 *)
function StringTokenizerTest.toStringArray(a: StringTokenizer): ObjectArray;
var
    b: array of Object_;
    c, i: longInt;
begin
    c := a.countTokens();
    setLength(b, c);

    for i := 0 to c - 1 do begin
        b[i] := a.nextToken() as Object_;
    end;

    toStringArray := b;
end;

(**
 * Tests the constructor.
 *)
procedure StringTokenizerTest.stringTokenizerTest;
var
    a: StringTokenizer;
    b, c: array of Object_;
    d: boolean;
begin
    // whitespaces inside the ansiString
    a := StringTokenizer.create('This is a test.');
    b := toStringArray(a);
    setLength(c, 4);
    c[0] := String_.create('This');
    c[1] := String_.create('is');
    c[2] := String_.create('a');
    c[3] := String_.create('test.');
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    // whitespaces inside and outside the ansiString
    a := StringTokenizer.create(' This is   a test. ');
    b := toStringArray(a);
    setLength(c, 4);
    c[0] := String_.create('This');
    c[1] := String_.create('is');
    c[2] := String_.create('a');
    c[3] := String_.create('test.');
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    // without whitespaces
    a := StringTokenizer.create('This_is_a_test.');
    b := toStringArray(a);
    setLength(c, 1);
    c[0] := String_.create('This_is_a_test.');
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    // one character
    a := StringTokenizer.create('_');
    b := toStringArray(a);
    setLength(c, 1);
    c[0] := String_.create('_');
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    // empty ansiString
    a := StringTokenizer.create('');
    b := toStringArray(a);
    setLength(c, 0);
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
end;

(**
 * Tests the constructor with a set of delimiters as a parameter.
 *)
procedure StringTokenizerTest.stringTokenizerTest2;
var
    a: StringTokenizer;
    b, c: array of Object_;
    d: boolean;
begin
    // non-white delimiter (non-existent in ansiString)
    a := StringTokenizer.create('This is a test.', '_');
    b := toStringArray(a);
    setLength(c, 1);
    c[0] := String_.create('This is a test.');
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    // non-white delimiter (inside the ansiString)
    a := StringTokenizer.create('This_is_a_test.', '_');
    b := toStringArray(a);
    setLength(c, 4);
    c[0] := String_.create('This');
    c[1] := String_.create('is');
    c[2] := String_.create('a');
    c[3] := String_.create('test.');
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    // non-white delimiter (also the whitespaces inside the ansiString)
    a := StringTokenizer.create('This_is_ a _test.', '_');
    b := toStringArray(a);
    setLength(c, 4);
    c[0] := String_.create('This');
    c[1] := String_.create('is');
    c[2] := String_.create(' a ');
    c[3] := String_.create('test.');
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    // non-white delimiter (also the whitespaces inside and outside the ansiString)
    a := StringTokenizer.create('_This_is___a_test._', '_');
    b := toStringArray(a);
    setLength(c, 4);
    c[0] := String_.create('This');
    c[1] := String_.create('is');
    c[2] := String_.create('a');
    c[3] := String_.create('test.');
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    // more delimiters (existing in the ansiString)
    a := StringTokenizer.create('This is_a test.', ' _');
    b := toStringArray(a);
    setLength(c, 4);
    c[0] := String_.create('This');
    c[1] := String_.create('is');
    c[2] := String_.create('a');
    c[3] := String_.create('test.');
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    // more delimiters (non-existent in the ansiString)
    a := StringTokenizer.create('Thisisatest.', ' _');
    b := toStringArray(a);
    setLength(c, 1);
    c[0] := String_.create('Thisisatest.');
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
end;

(**
 * Tests the countTokens method.
 *)
procedure StringTokenizerTest.countTokensTest;
var
    a: StringTokenizer;
    b: longInt;
begin
    // tokenize with whitespaces as delimiters
    a := StringTokenizer.create('This is a test.');
    b := a.countTokens();
    AssertEquals(4, b);
    // tokenize with whitespaces as delimiters (more whitespaces)
    a := StringTokenizer.create(' This is   a test. ');
    b := a.countTokens();
    AssertEquals(4, b);
    // tokenize with whitespaces as delimiters (no whitespaces)
    a := StringTokenizer.create('This_is_a_test.');
    b := a.countTokens();
    AssertEquals(1, b);
    // tokenize with non-white characters as delimiters
    a := StringTokenizer.create('This_is_a_test.', '_');
    b := a.countTokens();
    AssertEquals(4, b);
    // tokenize an empty ansiString
    a := StringTokenizer.create('');
    b := a.countTokens();
    AssertEquals(0, b);
end;

(**
 * Tests the hasMoreTokens method.
 *)
procedure StringTokenizerTest.hasMoreTokensTest;
var
    a: StringTokenizer;
    b: boolean;
begin
    a := StringTokenizer.create('This is a test.');
    b := a.hasMoreTokens();
    AssertEquals(true, b);
    a := StringTokenizer.create(' This is   a test. ');
    b := a.hasMoreTokens();
    AssertEquals(true, b);
    a := StringTokenizer.create('This_is_a_test.');
    b := a.hasMoreTokens();
    AssertEquals(true, b);
    a := StringTokenizer.create('This_is_a_test.', '_');
    b := a.hasMoreTokens();
    AssertEquals(true, b);
    a := StringTokenizer.create('');
    b := a.hasMoreTokens();
    AssertEquals(false, b);
end;

(**
 * Tests the nextToken method.
 *)
procedure StringTokenizerTest.nextTokenTest;
var
    a: StringTokenizer;
    b: String_;
begin
    // a test ansiString
    a := StringTokenizer.create('This is a test.');
    b := a.nextToken();
    AssertEquals('This', b.strProperty);
    b := a.nextToken();
    AssertEquals('is', b.strProperty);
    b := a.nextToken();
    AssertEquals('a', b.strProperty);
    b := a.nextToken();
    AssertEquals('test.', b.strProperty);
end;

initialization

  RegisterTest(StringTokenizerTest);
end.

