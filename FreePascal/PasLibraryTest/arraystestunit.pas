unit ArraysTestUnit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, fpcunit, testutils, testregistry, ArraysUnit, StringUnit, TestObjectUnit, TestObjectComparatorUnit;

type

  (**
   * An Arrays class test suite.
   *
   * @author Petr Kozler (A13B0359P)
   *)
  ArraysTest = class(TTestCase)
  published
       procedure binarySearchTest;
       procedure binarySearchTest2;
       procedure binarySearchTest3;
       procedure binarySearchTest4;
       procedure binarySearchTest5;
       procedure binarySearchTest6;
       procedure binarySearchTest7;
       procedure binarySearchTest8;
       procedure binarySearchTest9;
       procedure binarySearchTest10;
       procedure binarySearchTest11;
       procedure binarySearchTest12;
       procedure binarySearchTest13;
       procedure binarySearchTest14;
       procedure binarySearchTest15;
       procedure binarySearchTest16;
       procedure binarySearchTest17;
       procedure binarySearchTest18;
       procedure copyOfTest;
       procedure copyOfTest2;
       procedure copyOfTest3;
       procedure copyOfTest4;
       procedure copyOfTest5;
       procedure copyOfTest6;
       procedure copyOfTest7;
       procedure copyOfTest8;
       procedure copyOfTest9;
       procedure copyOfRangeTest;
       procedure copyOfRangeTest2;
       procedure copyOfRangeTest3;
       procedure copyOfRangeTest4;
       procedure copyOfRangeTest5;
       procedure copyOfRangeTest6;
       procedure copyOfRangeTest7;
       procedure copyOfRangeTest8;
       procedure copyOfRangeTest9;
       procedure equalsTest;
       procedure equalsTest2;
       procedure equalsTest3;
       procedure equalsTest4;
       procedure equalsTest5;
       procedure equalsTest6;
       procedure equalsTest7;
       procedure equalsTest8;
       procedure equalsTest9;
       procedure fillTest;
       procedure fillTest2;
       procedure fillTest3;
       procedure fillTest4;
       procedure fillTest5;
       procedure fillTest6;
       procedure fillTest7;
       procedure fillTest8;
       procedure fillTest9;
       procedure fillTest10;
       procedure fillTest11;
       procedure fillTest12;
       procedure fillTest13;
       procedure fillTest14;
       procedure fillTest15;
       procedure fillTest16;
       procedure fillTest17;
       procedure fillTest18;
       procedure sortTest;
       procedure sortTest2;
       procedure sortTest3;
       procedure sortTest4;
       procedure sortTest5;
       procedure sortTest6;
       procedure sortTest7;
       procedure sortTest8;
       procedure sortTest9;
       procedure sortTest10;
       procedure sortTest11;
       procedure sortTest12;
       procedure sortTest13;
       procedure sortTest14;
       procedure sortTest15;
       procedure sortTest16;
       procedure sortTest17;
       procedure sortTest18;
       procedure toStringTest;
       procedure toStringTest2;
       procedure toStringTest3;
       procedure toStringTest4;
       procedure toStringTest5;
       procedure toStringTest6;
       procedure toStringTest7;
       procedure toStringTest8;
       procedure toStringTest9;
  end;

implementation

(**
 * Tests the binarySearch method with array of bytes.
 *)
procedure ArraysTest.binarySearchTest;
var
    a: array of shortInt;
    b: longInt;
begin
    setLength(a, 5);
    a[0] :=  shortInt(3);
    a[1] := shortInt(2);
    a[2] := shortInt(8);
    a[3] := shortInt(7);
    a[4] := shortInt(6) ;
    Arrays.sort(a);
    // existing element search
    b := Arrays.binarySearch(a, shortInt(8));
    AssertEquals(4, b);
    // non-existent element search
    b := Arrays.binarySearch(a, shortInt(4));
    AssertEquals(-3, b);
end;

(**
 * Tests the binarySearch method with array of bytes and indexes as
 * parameters.
 *)
procedure ArraysTest.binarySearchTest2;
var
    a: array of shortInt;
    b: longInt;
begin
    setLength(a, 5);
    a[0] :=  shortInt(3);
    a[1] := shortInt(2);
    a[2] := shortInt(8);
    a[3] := shortInt(7);
    a[4] := shortInt(6) ;
    Arrays.sort(a);
    // existing element search
    b := Arrays.binarySearch(a, 1, 4, shortInt(8));
    AssertEquals(-5, b);
    // non-existent element search in a part of array
    b := Arrays.binarySearch(a, 1, 4, shortInt(4));
    AssertEquals(-3, b);
end;

(**
 * Tests the binarySearch method with array of chars.
 *)
procedure ArraysTest.binarySearchTest3;
var
    a: array of ansiChar;
    b: longInt;
begin
    setLength(a, 5);
    a[0] :=  'c';
    a[1] := 'b';
    a[2] := 'h';
    a[3] := 'g';
    a[4] := 'f' ;
    Arrays.sort(a);
    b := Arrays.binarySearch(a, 'h');
    AssertEquals(4, b);
    b := Arrays.binarySearch(a, 'd');
    AssertEquals(-3, b);
end;

(**
 * Tests the binarySearch method with array of chars and indexes as
 * parameters.
 *)
procedure ArraysTest.binarySearchTest4;
var
    a: array of ansiChar;
    b: longInt;
begin
    setLength(a, 5);
    a[0] :=  'c';
    a[1] := 'b';
    a[2] := 'h';
    a[3] := 'g';
    a[4] := 'f' ;
    Arrays.sort(a);
    b := Arrays.binarySearch(a, 1, 4, 'h');
    AssertEquals(-5, b);
    b := Arrays.binarySearch(a, 1, 4, 'd');
    AssertEquals(-3, b);
end;

(**
 * Tests the binarySearch method with array of doubles.
 *)
procedure ArraysTest.binarySearchTest5;
var
    a: array of double;
    b: longInt;
begin
    setLength(a, 5);
    a[0] :=  3.0;
    a[1] := 2.0;
    a[2] := 8.0;
    a[3] := 7.0;
    a[4] := 6.0 ;
    Arrays.sort(a);
    b := Arrays.binarySearch(a, 8.0);
    AssertEquals(4, b);
    b := Arrays.binarySearch(a, 4.0);
    AssertEquals(-3, b);
end;

(**
 * Tests the binarySearch method with array of doubles and indexes as
 * parameters.
 *)
procedure ArraysTest.binarySearchTest6;
var
    a: array of double;
    b: longInt;
begin
    setLength(a, 5);
    a[0] :=  3.0;
    a[1] := 2.0;
    a[2] := 8.0;
    a[3] := 7.0;
    a[4] := 6.0 ;
    Arrays.sort(a);
    b := Arrays.binarySearch(a, 1, 4, 8.0);
    AssertEquals(-5, b);
    b := Arrays.binarySearch(a, 1, 4, 4.0);
    AssertEquals(-3, b);
end;

(**
 * Tests the binarySearch method with array of floats.
 *)
procedure ArraysTest.binarySearchTest7;
var
    a: array of single;
    b: longInt;
begin
    setLength(a, 5);
    a[0] :=  3.0;
    a[1] := 2.0;
    a[2] := 8.0;
    a[3] := 7.0;
    a[4] := 6.0 ;
    Arrays.sort(a);
    b := Arrays.binarySearch(a, 8.0);
    AssertEquals(4, b);
    b := Arrays.binarySearch(a, 4.0);
    AssertEquals(-3, b);
end;

(**
 * Tests the binarySearch method with array of floats and indexes as
 * parameters.
 *)
procedure ArraysTest.binarySearchTest8;
var
    a: array of single;
    b: longInt;
begin
    setLength(a, 5);
    a[0] :=  3.0;
    a[1] := 2.0;
    a[2] := 8.0;
    a[3] := 7.0;
    a[4] := 6.0 ;
    Arrays.sort(a);
    b := Arrays.binarySearch(a, 1, 4, 8.0);
    AssertEquals(-5, b);
    b := Arrays.binarySearch(a, 1, 4, 4.0);
    AssertEquals(-3, b);
end;

(**
 * Tests the binarySearch method with array of ints.
 *)
procedure ArraysTest.binarySearchTest9;
var
    a: array of longInt;
    b: longInt;
begin
    setLength(a, 5);
    a[0] :=  3;
    a[1] := 2;
    a[2] := 8;
    a[3] := 7;
    a[4] := 6 ;
    Arrays.sort(a);
    b := Arrays.binarySearch(a, 8);
    AssertEquals(4, b);
    b := Arrays.binarySearch(a, 4);
    AssertEquals(-3, b);
end;

(**
 * Tests the binarySearch method with array of ints and indexes as
 * parameters.
 *)
procedure ArraysTest.binarySearchTest10;
var
    a: array of longInt;
    b: longInt;
begin
    setLength(a, 5);
    a[0] :=  3;
    a[1] := 2;
    a[2] := 8;
    a[3] := 7;
    a[4] := 6 ;
    Arrays.sort(a);
    b := Arrays.binarySearch(a, 1, 4, 8);
    AssertEquals(-5, b);
    b := Arrays.binarySearch(a, 1, 4, 4);
    AssertEquals(-3, b);
end;

(**
 * Tests the binarySearch method with array of longs.
 *)
procedure ArraysTest.binarySearchTest11;
var
    a: array of int64;
    b: longInt;
begin
    setLength(a, 5);
    a[0] :=  3;
    a[1] := 2;
    a[2] := 8;
    a[3] := 7;
    a[4] := 6 ;
    Arrays.sort(a);
    b := Arrays.binarySearch(a, 8);
    AssertEquals(4, b);
    b := Arrays.binarySearch(a, 4);
    AssertEquals(-3, b);
end;

(**
 * Tests the binarySearch method with array of longs and indexes as
 * parameters.
 *)
procedure ArraysTest.binarySearchTest12;
var
    a: array of int64;
    b: longInt;
begin
    setLength(a, 5);
    a[0] :=  3;
    a[1] := 2;
    a[2] := 8;
    a[3] := 7;
    a[4] := 6 ;
    Arrays.sort(a);
    b := Arrays.binarySearch(a, 1, 4, 8);
    AssertEquals(-5, b);
    b := Arrays.binarySearch(a, 1, 4, 4);
    AssertEquals(-3, b);
end;

(**
 * Tests the binarySearch method with array of objects.
 *)
procedure ArraysTest.binarySearchTest13;
var
    a: array of Object_;
    b: longInt;
begin
    setLength(a, 10);
    a[0] := TestObject.create(String_.create('first'), 3);
    a[1] := TestObject.create(String_.create('second'), 2);
    a[2] := TestObject.create(String_.create('third'), 8);
    a[3] := TestObject.create(String_.create('fourth'), 7);
    a[4] := TestObject.create(String_.create('fifth'), 6);
    a[5] := TestObject.create(String_.create('sixth'), 3);
    a[6] := TestObject.create(String_.create('seventh'), 2);
    a[7] := TestObject.create(String_.create('eighth'), 8);
    a[8] := TestObject.create(String_.create('nineth'), 7);
    a[9] := TestObject.create(String_.create('tenth'), 6);
    Arrays.sort(a);
    b := Arrays.binarySearch(a, TestObject.create('sixth', 6));
    AssertEquals(4, b);
    b := Arrays.binarySearch(a, TestObject.create('sixth', 4));
    AssertEquals(-5, b);
end;

(**
 * Tests the binarySearch method with array of objects and indexes as
 * parameters.
 *)
procedure ArraysTest.binarySearchTest14;
var
    a: array of Object_;
    b: longInt;
begin
    setLength(a, 10);
    a[0] := TestObject.create(String_.create('first'), 3);
    a[1] := TestObject.create(String_.create('second'), 2);
    a[2] := TestObject.create(String_.create('third'), 8);
    a[3] := TestObject.create(String_.create('fourth'), 7);
    a[4] := TestObject.create(String_.create('fifth'), 6);
    a[5] := TestObject.create(String_.create('sixth'), 3);
    a[6] := TestObject.create(String_.create('seventh'), 2);
    a[7] := TestObject.create(String_.create('eighth'), 8);
    a[8] := TestObject.create(String_.create('nineth'), 7);
    a[9] := TestObject.create(String_.create('tenth'), 6);
    Arrays.sort(a);
    b := Arrays.binarySearch(a, 1, 4, TestObject.create('sixth', 6));
    AssertEquals(-5, b);
    b := Arrays.binarySearch(a, 1, 4, TestObject.create('sixth', 4));
    AssertEquals(-5, b);
end;

(**
 * Tests the binarySearch method with array of shorts.
 *)
procedure ArraysTest.binarySearchTest15;
var
    a: array of smallInt;
    b: longInt;
begin
    setLength(a, 5);
    a[0] :=  smallInt(3);
    a[1] := smallInt(2);
    a[2] := smallInt(8);
    a[3] := smallInt(7);
    a[4] := smallInt(6) ;
    Arrays.sort(a);
    b := Arrays.binarySearch(a, smallInt(8));
    AssertEquals(4, b);
    b := Arrays.binarySearch(a, smallInt(4));
    AssertEquals(-3, b);
end;

(**
 * Tests the binarySearch method with array of shorts and indexes as
 * parameters.
 *)
procedure ArraysTest.binarySearchTest16;
var
    a: array of smallInt;
    b: longInt;
begin
    setLength(a, 5);
    a[0] :=  smallInt(3);
    a[1] := smallInt(2);
    a[2] := smallInt(8);
    a[3] := smallInt(7);
    a[4] := smallInt(6) ;
    Arrays.sort(a);
    b := Arrays.binarySearch(a, 1, 4, smallInt(8));
    AssertEquals(-5, b);
    b := Arrays.binarySearch(a, 1, 4, smallInt(4));
    AssertEquals(-3, b);
end;

(**
 * Tests the binarySearch method with array of objects and comparator as a
 * parameter.
 *)
procedure ArraysTest.binarySearchTest17;
var
    a: array of Object_;
    b: longInt;
    c: TestObjectComparator;
begin
    setLength(a, 10);
    a[0] := TestObject.create(String_.create('first'), 3);
    a[1] := TestObject.create(String_.create('second'), 2);
    a[2] := TestObject.create(String_.create('third'), 8);
    a[3] := TestObject.create(String_.create('fourth'), 7);
    a[4] := TestObject.create(String_.create('fifth'), 6);
    a[5] := TestObject.create(String_.create('sixth'), 3);
    a[6] := TestObject.create(String_.create('seventh'), 2);
    a[7] := TestObject.create(String_.create('eighth'), 8);
    a[8] := TestObject.create(String_.create('nineth'), 7);
    a[9] := TestObject.create(String_.create('tenth'), 6);
    c := TestObjectComparator.create();
    Arrays.sort(a, c);
    b := Arrays.binarySearch(a, TestObject.create('sixth', 6), c);
    AssertEquals(4, b);
    b := Arrays.binarySearch(a, TestObject.create('sixth', 4), c);
    AssertEquals(-5, b);
end;

(**
 * Tests the binarySearch method with array of shorts and indexes and
 * comparator as parameters.
 *)
procedure ArraysTest.binarySearchTest18;
var
    a: array of Object_;
    b: longInt;
    c: TestObjectComparator;
begin
    setLength(a, 10);
    a[0] := TestObject.create(String_.create('first'), 3);
    a[1] := TestObject.create(String_.create('second'), 2);
    a[2] := TestObject.create(String_.create('third'), 8);
    a[3] := TestObject.create(String_.create('fourth'), 7);
    a[4] := TestObject.create(String_.create('fifth'), 6);
    a[5] := TestObject.create(String_.create('sixth'), 3);
    a[6] := TestObject.create(String_.create('seventh'), 2);
    a[7] := TestObject.create(String_.create('eighth'), 8);
    a[8] := TestObject.create(String_.create('nineth'), 7);
    a[9] := TestObject.create(String_.create('tenth'), 6);
    c := TestObjectComparator.create();
    Arrays.sort(a, c);
    b := Arrays.binarySearch(a, 1, 4, TestObject.create('sixth', 6), c);
    AssertEquals(-5, b);
    b := Arrays.binarySearch(a, 1, 4, TestObject.create('sixth', 4), c);
    AssertEquals(-5, b);
end;

(**
 * Tests the copyOf method with array of booleans.
 *)
procedure ArraysTest.copyOfTest;
var
    a, b, c: array of boolean;
    d: boolean;
begin
    setLength(a, 5);
    a[0] :=  true;
    a[1] := false;
    a[2] := false;
    a[3] := false;
    a[4] := true ;
    // new array is smaller
    b := Arrays.copyOf(a, 3);
    setLength(c, 3);
    c[0] := true;
    c[1] := false;
    c[2] := false;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    // new array has the same length
    b := Arrays.copyOf(a, 5);
    setLength(c, 5);
    c[0] := true;
    c[1] := false;
    c[2] := false;
    c[3] := false;
    c[4] := true;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    // new array is bigger
    b := Arrays.copyOf(a, 7);
    setLength(c, 7);
    c[0] := true;
    c[1] := false;
    c[2] := false;
    c[3] := false;
    c[4] := true;
    c[5] := false;
    c[6] := false;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
end;

(**
 * Tests the copyOf method with array of bytes.
 *)
procedure ArraysTest.copyOfTest2;
var
    a, b, c: array of shortInt;
    d: boolean;
begin
    setLength(a, 5);
    a[0] :=  shortInt(3);
    a[1] := shortInt(2);
    a[2] := shortInt(8);
    a[3] := shortInt(7);
    a[4] := shortInt(6) ;
    b := Arrays.copyOf(a, 3);
    setLength(c, 3);
    c[0] := 3;
    c[1] := 2;
    c[2] := 8;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOf(a, 5);
    setLength(c, 5);
    c[0] := 3;
    c[1] := 2;
    c[2] := 8;
    c[3] := 7;
    c[4] := 6;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOf(a, 7);
    setLength(c, 7);
    c[0] := 3;
    c[1] := 2;
    c[2] := 8;
    c[3] := 7;
    c[4] := 6;
    c[5] := 0;
    c[6] := 0;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
end;

(**
 * Tests the copyOf method with array of chars.
 *)
procedure ArraysTest.copyOfTest3;
var
    a, b, c: array of ansiChar;
    d: boolean;
begin
    setLength(a, 5);
    a[0] :=  'd';
    a[1] := 'b';
    a[2] := 'h';
    a[3] := 'g';
    a[4] := 'f' ;
    b := Arrays.copyOf(a, 3);
    setLength(c, 3);
    c[0] := 'd';
    c[1] := 'b';
    c[2] := 'h';
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOf(a, 5);
    setLength(c, 5);
    c[0] := 'd';
    c[1] := 'b';
    c[2] := 'h';
    c[3] := 'g';
    c[4] := 'f';
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOf(a, 7);
    setLength(c, 7);
    c[0] := 'd';
    c[1] := 'b';
    c[2] := 'h';
    c[3] := 'g';
    c[4] := 'f';
    c[5] := #0;
    c[6] := #0;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
end;

(**
 * Tests the copyOf method with array of doubles.
 *)
procedure ArraysTest.copyOfTest4;
var
    a, b, c: array of double;
    d: boolean;
begin
    setLength(a, 5);
    a[0] :=  3.0;
    a[1] := 2.0;
    a[2] := 8.0;
    a[3] := 7.0;
    a[4] := 6.0 ;
    b := Arrays.copyOf(a, 3);
    setLength(c, 3);
    c[0] := 3.0;
    c[1] := 2.0;
    c[2] := 8.0;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOf(a, 5);
    setLength(c, 5);
    c[0] := 3.0;
    c[1] := 2.0;
    c[2] := 8.0;
    c[3] := 7.0;
    c[4] := 6.0;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOf(a, 7);
    setLength(c, 7);
    c[0] := 3.0;
    c[1] := 2.0;
    c[2] := 8.0;
    c[3] := 7.0;
    c[4] := 6.0;
    c[5] := 0.0;
    c[6] := 0.0;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
end;

(**
 * Tests the copyOf method with array of floats.
 *)
procedure ArraysTest.copyOfTest5;
var
    a, b, c: array of single;
    d: boolean;
begin
    setLength(a, 5);
    a[0] :=  3.0;
    a[1] := 2.0;
    a[2] := 8.0;
    a[3] := 7.0;
    a[4] := 6.0 ;
    b := Arrays.copyOf(a, 3);
    setLength(c, 3);
    c[0] := 3.0;
    c[1] := 2.0;
    c[2] := 8.0;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOf(a, 5);
    setLength(c, 5);
    c[0] := 3.0;
    c[1] := 2.0;
    c[2] := 8.0;
    c[3] := 7.0;
    c[4] := 6.0;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOf(a, 7);
    setLength(c, 7);
    c[0] := 3.0;
    c[1] := 2.0;
    c[2] := 8.0;
    c[3] := 7.0;
    c[4] := 6.0;
    c[5] := 0.0;
    c[6] := 0.0;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
end;

(**
 * Tests the copyOf method with array of ints.
 *)
procedure ArraysTest.copyOfTest6;
var
    a, b, c: array of longInt;
    d: boolean;
begin
    setLength(a, 5);
    a[0] :=  3;
    a[1] := 2;
    a[2] := 8;
    a[3] := 7;
    a[4] := 6;
    b := Arrays.copyOf(a, 3);
    setLength(c, 3);
    c[0] := 3;
    c[1] := 2;
    c[2] := 8;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOf(a, 5);
    setLength(c, 5);
    c[0] := 3;
    c[1] := 2;
    c[2] := 8;
    c[3] := 7;
    c[4] := 6;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOf(a, 7);
    setLength(c, 7);
    c[0] := 3;
    c[1] := 2;
    c[2] := 8;
    c[3] := 7;
    c[4] := 6;
    c[5] := 0;
    c[6] := 0;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
end;

(**
 * Tests the copyOf method with array of longs.
 *)
procedure ArraysTest.copyOfTest7;
var
    a, b, c: array of int64;
    d: boolean;
begin
    setLength(a, 5);
    a[0] :=  3;
    a[1] := 2;
    a[2] := 8;
    a[3] := 7;
    a[4] := 6 ;
    b := Arrays.copyOf(a, 3);
    setLength(c, 3);
    c[0] := 3;
    c[1] := 2;
    c[2] := 8;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOf(a, 5);
    setLength(c, 5);
    c[0] := 3;
    c[1] := 2;
    c[2] := 8;
    c[3] := 7;
    c[4] := 6;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOf(a, 7);
    setLength(c, 7);
    c[0] := 3;
    c[1] := 2;
    c[2] := 8;
    c[3] := 7;
    c[4] := 6;
    c[5] := 0;
    c[6] := 0;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
end;

(**
 * Tests the copyOf method with array of shorts.
 *)
procedure ArraysTest.copyOfTest8;
var
    a, b, c: array of smallInt;
    d: boolean;
begin
    setLength(a, 5);
    a[0] :=  smallInt(3);
    a[1] := smallInt(2);
    a[2] := smallInt(8);
    a[3] := smallInt(7);
    a[4] := smallInt(6) ;
    b := Arrays.copyOf(a, 3);
    setLength(c, 3);
    c[0] := 3;
    c[1] := 2;
    c[2] := 8;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOf(a, 5);
    setLength(c, 5);
    c[0] := 3;
    c[1] := 2;
    c[2] := 8;
    c[3] := 7;
    c[4] := 6;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOf(a, 7);
    setLength(c, 7);
    c[0] := 3;
    c[1] := 2;
    c[2] := 8;
    c[3] := 7;
    c[4] := 6;
    c[5] := 0;
    c[6] := 0;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
end;

(**
 * Tests the copyOf method with array of objects.
 *)
procedure ArraysTest.copyOfTest9;
var
    a, b, c: array of Object_;
    d: boolean;
begin
    setLength(a, 5);
    a[0] := TestObject.create('first', 3);
    a[1] := TestObject.create('second', 2);
    a[2] := TestObject.create('third', 8);
    a[3] := TestObject.create('fourth', 7);
    a[4] := TestObject.create('fifth', 6);
    b := Arrays.copyOf(a, 3);
    setLength(c, 3);
    c[0] := TestObject.create('first', 3);
    c[1] := TestObject.create('second', 2);
    c[2] := TestObject.create('third', 8);
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOf(a, 5);
    setLength(c, 5);
    c[0] := TestObject.create('first', 3);
    c[1] := TestObject.create('second', 2);
    c[2] := TestObject.create('third', 8);
    c[3] := TestObject.create('fourth', 7);
    c[4] := TestObject.create('fifth', 6);
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOf(a, 7);
    setLength(c, 7);
    c[0] := TestObject.create('first', 3);
    c[1] := TestObject.create('second', 2);
    c[2] := TestObject.create('third', 8);
    c[3] := TestObject.create('fourth', 7);
    c[4] := TestObject.create('fifth', 6);
    c[5] := nil;
    c[6] := nil;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
end;

(**
 * Tests the copyOfRange method with array of booleans.
 *)
procedure ArraysTest.copyOfRangeTest;
var
    a, b, c: array of boolean;
    d: boolean;
begin
    setLength(a, 5);
    a[0] :=  true;
    a[1] := false;
    a[2] := false;
    a[3] := false;
    a[4] := true;
    // copy from the beginning
    b := Arrays.copyOfRange(a, 0, 3);
    setLength(c, 3);
    c[0] := true;
    c[1] := false;
    c[2] := false;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    // copy from the middle
    b := Arrays.copyOfRange(a, 2, 5);
    setLength(c, 3);
    c[0] := false;
    c[1] := false;
    c[2] := true;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    // copy from the end
    b := Arrays.copyOfRange(a, 4, 7);
    setLength(c, 3);
    c[0] := true;
    c[1] := false;
    c[2] := false;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
end;

(**
 * Tests the copyOfRange method with array of bytes.
 *)
procedure ArraysTest.copyOfRangeTest2;
var
    a, b, c: array of shortInt;
    d: boolean;
begin
    setLength(a, 5);
    a[0] :=  shortInt(3);
    a[1] := shortInt(2);
    a[2] := shortInt(8);
    a[3] := shortInt(7);
    a[4] := shortInt(6) ;
    b := Arrays.copyOfRange(a, 0, 3);
    setLength(c, 3);
    c[0] := 3;
    c[1] := 2;
    c[2] := 8;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOfRange(a, 2, 5);
    setLength(c, 3);
    c[0] := 8;
    c[1] := 7;
    c[2] := 6;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOfRange(a, 4, 7);
    setLength(c, 3);
    c[0] := 6;
    c[1] := 0;
    c[2] := 0;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
end;

(**
 * Tests the copyOfRange method with array of chars.
 *)
procedure ArraysTest.copyOfRangeTest3;
var
    a, b, c: array of ansiChar;
    d: boolean;
begin
    setLength(a, 5);
    a[0] :=  'd';
    a[1] := 'b';
    a[2] := 'h';
    a[3] := 'g';
    a[4] := 'f';
    b := Arrays.copyOfRange(a, 0, 3);
    setLength(c, 3);
    c[0] := 'd';
    c[1] := 'b';
    c[2] := 'h';
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOfRange(a, 2, 5);
    setLength(c, 3);
    c[0] := 'h';
    c[1] := 'g';
    c[2] := 'f';
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOfRange(a, 4, 7);
    setLength(c, 3);
    c[0] := 'f';
    c[1] := #0;
    c[2] := #0;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
end;

(**
 * Tests the copyOfRange method with array of doubles.
 *)
procedure ArraysTest.copyOfRangeTest4;
var
    a, b, c: array of double;
    d: boolean;
begin
    setLength(a, 5);
    a[0] :=  3.0;
    a[1] := 2.0;
    a[2] := 8.0;
    a[3] := 7.0;
    a[4] := 6.0;
    b := Arrays.copyOfRange(a, 0, 3);
    setLength(c, 3);
    c[0] := 3.0;
    c[1] := 2.0;
    c[2] := 8.0;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOfRange(a, 2, 5);
    setLength(c, 3);
    c[0] := 8.0;
    c[1] := 7.0;
    c[2] := 6.0;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOfRange(a, 4, 7);
    setLength(c, 3);
    c[0] := 6.0;
    c[1] := 0.0;
    c[2] := 0.0;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
end;

(**
 * Tests the copyOfRange method with array of floats.
 *)
procedure ArraysTest.copyOfRangeTest5;
var
    a, b, c: array of single;
    d: boolean;
begin
    setLength(a, 5);
    a[0] := 3.0;
    a[1] := 2.0;
    a[2] := 8.0;
    a[3] := 7.0;
    a[4] := 6.0;
    b := Arrays.copyOfRange(a, 0, 3);
    setLength(c, 3);
    c[0] := 3.0;
    c[1] := 2.0;
    c[2] := 8.0;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOfRange(a, 2, 5);
    setLength(c, 3);
    c[0] := 8.0;
    c[1] := 7.0;
    c[2] := 6.0;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOfRange(a, 4, 7);
    setLength(c, 3);
    c[0] := 6.0;
    c[1] := 0.0;
    c[2] := 0.0;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
end;

(**
 * Tests the copyOfRange method with array of ints.
 *)
procedure ArraysTest.copyOfRangeTest6;
var
    a, b, c: array of longInt;
    d: boolean;
begin
    setLength(a, 5);
    a[0] := 3;
    a[1] := 2;
    a[2] := 8;
    a[3] := 7;
    a[4] := 6;
    b := Arrays.copyOfRange(a, 0, 3);
    setLength(c, 3);
    c[0] := 3;
    c[1] := 2;
    c[2] := 8;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOfRange(a, 2, 5);
    setLength(c, 3);
    c[0] := 8;
    c[1] := 7;
    c[2] := 6;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOfRange(a, 4, 7);
    setLength(c, 3);
    c[0] := 6;
    c[1] := 0;
    c[2] := 0;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
end;

(**
 * Tests the copyOfRange method with array of longs.
 *)
procedure ArraysTest.copyOfRangeTest7;
var
    a, b, c: array of int64;
    d: boolean;
begin
    setLength(a, 5);
    a[0] := 3;
    a[1] := 2;
    a[2] := 8;
    a[3] := 7;
    a[4] := 6 ;
    b := Arrays.copyOfRange(a, 0, 3);
    setLength(c, 3);
    c[0] := 3;
    c[1] := 2;
    c[2] := 8;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOfRange(a, 2, 5);
    setLength(c, 3);
    c[0] := 8;
    c[1] := 7;
    c[2] := 6;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOfRange(a, 4, 7);
    setLength(c, 3);
    c[0] := 6;
    c[1] := 0;
    c[2] := 0;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
end;

(**
 * Tests the copyOfRange method with array of shorts.
 *)
procedure ArraysTest.copyOfRangeTest8;
var
    a, b, c: array of smallInt;
    d: boolean;
begin
    setLength(a, 5);
    a[0] := smallInt(3);
    a[1] := smallInt(2);
    a[2] := smallInt(8);
    a[3] := smallInt(7);
    a[4] := smallInt(6);
    b := Arrays.copyOfRange(a, 0, 3);
    setLength(c, 3);
    c[0] := 3;
    c[1] := 2;
    c[2] := 8;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOfRange(a, 2, 5);
    setLength(c, 3);
    c[0] := 8;
    c[1] := 7;
    c[2] := 6;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOfRange(a, 4, 7);
    setLength(c, 3);
    c[0] := 6;
    c[1] := 0;
    c[2] := 0;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
end;

(**
 * Tests the copyOfRange method with array of objects.
 *)
procedure ArraysTest.copyOfRangeTest9;
var
    a, b, c: array of Object_;
    d: boolean;
begin
    setLength(a, 5);
    a[0] := TestObject.create('first', 3);
    a[1] := TestObject.create('second', 2);
    a[2] := TestObject.create('third', 8);
    a[3] := TestObject.create('fourth', 7);
    a[4] := TestObject.create('fifth', 6);
    b := Arrays.copyOfRange(a, 0, 3);
    setLength(c, 3);
    c[0] := TestObject.create('first', 3);
    c[1] := TestObject.create('second', 2);
    c[2] := TestObject.create('third', 8);
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOfRange(a, 2, 5);
    setLength(c, 3);
    c[0] := TestObject.create('third', 8);
    c[1] := TestObject.create('fourth', 7);
    c[2] := TestObject.create('fifth', 6);
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
    b := Arrays.copyOfRange(a, 4, 7);
    setLength(c, 3);
    c[0] := TestObject.create('fifth', 6);
    c[1] := nil;
    c[2] := nil;
    d := Arrays.equals(b, c);
    AssertEquals(true, d);
end;

(**
 * Tests the equals method with array of booleans.
 *)
procedure ArraysTest.equalsTest;
var
    a, b: array of boolean;
    c: boolean;
begin
    setLength(a, 5);
    a[0] := true;
    a[1] := false;
    a[2] := false;
    a[3] := false;
    a[4] := true;
    // reference to the second array is null
    b := nil;
    c := Arrays.equals(a, b);
    AssertEquals(false, c);
    // arrays do not have the same length
    setLength(b, 1);
    b[0] := true ;
    c := Arrays.equals(a, b);
    AssertEquals(false, c);
    // arrays have the same length but different elements
    setLength(b, 5);
    b[0] := true;
    b[1] := false;
    b[2] := false;
    b[3] := false;
    b[4] := false;
    c := Arrays.equals(a, b);
    AssertEquals(false, c);
    // arrays have the same length and elements
    setLength(b, 5);
    b[0] := true;
    b[1] := false;
    b[2] := false;
    b[3] := false;
    b[4] := true;
    c := Arrays.equals(a, b);
    AssertEquals(true, c);
    // references are equal
    b := a;
    c := Arrays.equals(a, b);
    AssertEquals(true, c);
end;

(**
 * Tests the equals method with array of bytes.
 *)
procedure ArraysTest.equalsTest2;
var
    a, b: array of shortInt;
    c: boolean;
begin
    setLength(a, 5);
    a[0] := shortInt(3);
    a[1] := shortInt(2);
    a[2] := shortInt(8);
    a[3] := shortInt(7);
    a[4] := shortInt(6);
    b := nil;
    c := Arrays.equals(a, b);
    AssertEquals(false, c);
    setLength(b, 1);
    b[0] := shortInt(3) ;
    c := Arrays.equals(a, b);
    AssertEquals(false, c);
    setLength(b, 5);
    b[0] := shortInt(3);
    b[1] := shortInt(2);
    b[2] := shortInt(8);
    b[3] := shortInt(7);
    b[4] := shortInt(3);
    c := Arrays.equals(a, b);
    AssertEquals(false, c);
    setLength(b, 5);
    b[0] := shortInt(3);
    b[1] := shortInt(2);
    b[2] := shortInt(8);
    b[3] := shortInt(7);
    b[4] := shortInt(6);
    c := Arrays.equals(a, b);
    AssertEquals(true, c);
    b := a;
    c := Arrays.equals(a, b);
    AssertEquals(true, c);
end;

(**
 * Tests the equals method with array of chars.
 *)
procedure ArraysTest.equalsTest3;
var
    a, b: array of ansiChar;
    c: boolean;
begin
    setLength(a, 5);
    a[0] := 'c';
    a[1] := 'b';
    a[2] := 'h';
    a[3] := 'g';
    a[4] := 'f';
    b := nil;
    c := Arrays.equals(a, b);
    AssertEquals(false, c);
    setLength(b, 1);
    b[0] := 'c';
    c := Arrays.equals(a, b);
    AssertEquals(false, c);
    setLength(b, 5);
    b[0] := 'c';
    b[1] := 'b';
    b[2] := 'h';
    b[3] := 'g';
    b[4] := 'c';
    c := Arrays.equals(a, b);
    AssertEquals(false, c);
    setLength(b, 5);
    b[0] := 'c';
    b[1] := 'b';
    b[2] := 'h';
    b[3] := 'g';
    b[4] := 'f';
    c := Arrays.equals(a, b);
    AssertEquals(true, c);
    b := a;
    c := Arrays.equals(a, b);
    AssertEquals(true, c);
end;

(**
 * Tests the equals method with array of doubles.
 *)
procedure ArraysTest.equalsTest4;
var
    a, b: array of double;
    c: boolean;
begin
    setLength(a, 5);
    a[0] := 3.0;
    a[1] := 2.0;
    a[2] := 8.0;
    a[3] := 7.0;
    a[4] := 6.0;
    b := nil;
    c := Arrays.equals(a, b);
    AssertEquals(false, c);
    setLength(b, 1);
    b[0] := 3.0 ;
    c := Arrays.equals(a, b);
    AssertEquals(false, c);
    setLength(b, 5);
    b[0] := 3.0;
    b[1] := 2.0;
    b[2] := 8.0;
    b[3] := 7.0;
    b[4] := 3.0;
    c := Arrays.equals(a, b);
    AssertEquals(false, c);
    setLength(b, 5);
    b[0] := 3.0;
    b[1] := 2.0;
    b[2] := 8.0;
    b[3] := 7.0;
    b[4] := 6.0;
    c := Arrays.equals(a, b);
    AssertEquals(true, c);
    b := a;
    c := Arrays.equals(a, b);
    AssertEquals(true, c);
end;

(**
 * Tests the equals method with array of floats.
 *)
procedure ArraysTest.equalsTest5;
var
    a, b: array of single;
    c: boolean;
begin
    setLength(a, 5);
    a[0] := 3.0;
    a[1] := 2.0;
    a[2] := 8.0;
    a[3] := 7.0;
    a[4] := 6.0;
    b := nil;
    c := Arrays.equals(a, b);
    AssertEquals(false, c);
    setLength(b, 1);
    b[0] := 3.0;
    c := Arrays.equals(a, b);
    AssertEquals(false, c);
    setLength(b, 5);
    b[0] := 3.0;
    b[1] := 2.0;
    b[2] := 8.0;
    b[3] := 7.0;
    b[4] := 3.0;
    c := Arrays.equals(a, b);
    AssertEquals(false, c);
    setLength(b, 5);
    b[0] := 3.0;
    b[1] := 2.0;
    b[2] := 8.0;
    b[3] := 7.0;
    b[4] := 6.0;
    c := Arrays.equals(a, b);
    AssertEquals(true, c);
    b := a;
    c := Arrays.equals(a, b);
    AssertEquals(true, c);
end;

(**
 * Tests the equals method with array of ints.
 *)
procedure ArraysTest.equalsTest6;
var
    a, b: array of longInt;
    c: boolean;
begin
    setLength(a, 5);
    a[0] := 3;
    a[1] := 2;
    a[2] := 8;
    a[3] := 7;
    a[4] := 6;
    b := nil;
    c := Arrays.equals(a, b);
    AssertEquals(false, c);
    setLength(b, 1);
    b[0] := 3;
    c := Arrays.equals(a, b);
    AssertEquals(false, c);
    setLength(b, 5);
    b[0] := 3;
    b[1] := 2;
    b[2] := 8;
    b[3] := 7;
    b[4] := 3;
    c := Arrays.equals(a, b);
    AssertEquals(false, c);
    setLength(b, 5);
    b[0] := 3;
    b[1] := 2;
    b[2] := 8;
    b[3] := 7;
    b[4] := 6;
    c := Arrays.equals(a, b);
    AssertEquals(true, c);
    b := a;
    c := Arrays.equals(a, b);
    AssertEquals(true, c);
end;

(**
 * Tests the equals method with array of longs.
 *)
procedure ArraysTest.equalsTest7;
var
    a, b: array of int64;
    c: boolean;
begin
    setLength(a, 5);
    a[0] := 3;
    a[1] := 2;
    a[2] := 8;
    a[3] := 7;
    a[4] := 6;
    b := nil;
    c := Arrays.equals(a, b);
    AssertEquals(false, c);
    setLength(b, 1);
    b[0] := 3;
    c := Arrays.equals(a, b);
    AssertEquals(false, c);
    setLength(b, 5);
    b[0] := 3;
    b[1] := 2;
    b[2] := 8;
    b[3] := 7;
    b[4] := 3;
    c := Arrays.equals(a, b);
    AssertEquals(false, c);
    setLength(b, 5);
    b[0] := 3;
    b[1] := 2;
    b[2] := 8;
    b[3] := 7;
    b[4] := 6;
    c := Arrays.equals(a, b);
    AssertEquals(true, c);
    b := a;
    c := Arrays.equals(a, b);
    AssertEquals(true, c);
end;

(**
 * Tests the equals method with array of objects.
 *)
procedure ArraysTest.equalsTest8;
var
    a, b: array of Object_;
    c: boolean;
begin
    setLength(a, 5);
    a[0] := TestObject.create('first', 3);
    a[1] := TestObject.create('second', 2);
    a[2] := TestObject.create('third', 8);
    a[3] := TestObject.create('fourth', 7);
    a[4] := TestObject.create('fifth', 6);
    b := nil;
    c := Arrays.equals(a, b);
    AssertEquals(false, c);
    setLength(b, 1);
    b[0] := TestObject.create('first', 3);
    c := Arrays.equals(a, b);
    AssertEquals(false, c);
    setLength(b, 5);
    b[0] := TestObject.create('first', 3);
    b[1] := TestObject.create('second', 2);
    b[2] := TestObject.create('third', 8);
    b[3] := TestObject.create('fourth', 7);
    b[4] := TestObject.create('fifth', 3);
    c := Arrays.equals(a, b);
    AssertEquals(false, c);
    setLength(b, 5);
    b[0] := TestObject.create('sixth', 3);
    b[1] := TestObject.create('seventh', 2);
    b[2] := TestObject.create('eighth', 8);
    b[3] := TestObject.create('nineth', 7);
    b[4] := TestObject.create('tenth', 6);
    c := Arrays.equals(a, b);
    AssertEquals(true, c);
    b := a;
    c := Arrays.equals(a, b);
    AssertEquals(true, c);
end;

(**
 * Tests the equals method with array of shorts.
 *)
procedure ArraysTest.equalsTest9;
var
    a, b: array of smallInt;
    c: boolean;
begin
    setLength(a, 5);
    a[0] := smallInt(3);
    a[1] := smallInt(2);
    a[2] := smallInt(8);
    a[3] := smallInt(7);
    a[4] := smallInt(6);
    b := nil;
    c := Arrays.equals(a, b);
    AssertEquals(false, c);
    setLength(b, 1);
    b[0] := smallInt(3);
    c := Arrays.equals(a, b);
    AssertEquals(false, c);
    setLength(b, 5);
    b[0] := smallInt(3);
    b[1] := smallInt(2);
    b[2] := smallInt(8);
    b[3] := smallInt(7);
    b[4] := smallInt(3);
    c := Arrays.equals(a, b);
    AssertEquals(false, c);
    setLength(b, 5);
    b[0] := smallInt(3);
    b[1] := smallInt(2);
    b[2] := smallInt(8);
    b[3] := smallInt(7);
    b[4] := smallInt(6);
    c := Arrays.equals(a, b);
    AssertEquals(true, c);
    b := a;
    c := Arrays.equals(a, b);
    AssertEquals(true, c);
end;

(**
 * Tests the fill method with array of booleans.
 *)
procedure ArraysTest.fillTest;
var
    a, c: array of boolean;
    b: boolean;
begin
    // the array for filling
    setLength(a, 5);
    Arrays.fill(a, true);
    setLength(c, 5);
    c[0] := true;
    c[1] := true;
    c[2] := true;
    c[3] := true;
    c[4] := true;
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the fill method with array of booleans and indexes as parameters.
 *)
procedure ArraysTest.fillTest2;
var
    a, c: array of boolean;
    b: boolean;
begin
    // the array for partial filling
    setLength(a, 5);
    Arrays.fill(a, 1, 4, true);
    setLength(c, 5);
    c[0] := false;
    c[1] := true;
    c[2] := true;
    c[3] := true;
    c[4] := false;
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the fill method with array of bytes.
 *)
procedure ArraysTest.fillTest3;
var
    a, c: array of shortInt;
    b: boolean;
begin
    setLength(a, 5);
    Arrays.fill(a, shortInt(8));
    setLength(c, 5);
    c[0] := 8;
    c[1] := 8;
    c[2] := 8;
    c[3] := 8;
    c[4] := 8;
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the fill method with array of bytes and indexes as parameters.
 *)
procedure ArraysTest.fillTest4;
var
    a, c: array of shortInt;
    b: boolean;
begin
    setLength(a, 5);
    Arrays.fill(a, 1, 4, shortInt(8));
    setLength(c, 5);
    c[0] := 0;
    c[1] := 8;
    c[2] := 8;
    c[3] := 8;
    c[4] := 0;
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the fill method with array of chars.
 *)
procedure ArraysTest.fillTest5;
var
    a, c: array of ansiChar;
    b: boolean;
begin
    setLength(a, 5);
    Arrays.fill(a, 'h');
    setLength(c, 5);
    c[0] := 'h';
    c[1] := 'h';
    c[2] := 'h';
    c[3] := 'h';
    c[4] := 'h';
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the fill method with array of chars and indexes as parameters.
 *)
procedure ArraysTest.fillTest6;
var
    a, c: array of ansiChar;
    b: boolean;
begin
    setLength(a, 5);
    Arrays.fill(a, 1, 4, 'h');
    setLength(c, 5);
    c[0] := #0;
    c[1] := 'h';
    c[2] := 'h';
    c[3] := 'h';
    c[4] := #0;
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the fill method with array of doubles.
 *)
procedure ArraysTest.fillTest7;
var
    a, c: array of double;
    b: boolean;
begin
    setLength(a, 5);
    Arrays.fill(a, 8.0);
    setLength(c, 5);
    c[0] := 8.0;
    c[1] := 8.0;
    c[2] := 8.0;
    c[3] := 8.0;
    c[4] := 8.0;
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the fill method with array of doubles and indexes as parameters.
 *)
procedure ArraysTest.fillTest8;
var
    a, c: array of double;
    b: boolean;
begin
    setLength(a, 5);
    Arrays.fill(a, 1, 4, 8.0);
    setLength(c, 5);
    c[0] := 0.0;
    c[1] := 8.0;
    c[2] := 8.0;
    c[3] := 8.0;
    c[4] := 0.0;
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the fill method with array of floats.
 *)
procedure ArraysTest.fillTest9;
var
    a, c: array of single;
    b: boolean;
begin
    setLength(a, 5);
    Arrays.fill(a, 8.0);
    setLength(c, 5);
    c[0] := 8.0;
    c[1] := 8.0;
    c[2] := 8.0;
    c[3] := 8.0;
    c[4] := 8.0;
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the fill method with array of floats and indexes as parameters.
 *)
procedure ArraysTest.fillTest10;
var
    a, c: array of single;
    b: boolean;
begin
    setLength(a, 5);
    Arrays.fill(a, 1, 4, 8.0);
    setLength(c, 5);
    c[0] := 0.0;
    c[1] := 8.0;
    c[2] := 8.0;
    c[3] := 8.0;
    c[4] := 0.0;
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the fill method with array of ints.
 *)
procedure ArraysTest.fillTest11;
var
    a, c: array of longInt;
    b: boolean;
begin
    setLength(a, 5);
    Arrays.fill(a, 8);
    setLength(c, 5);
    c[0] := 8;
    c[1] := 8;
    c[2] := 8;
    c[3] := 8;
    c[4] := 8;
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the fill method with array of ints and indexes as parameters.
 *)
procedure ArraysTest.fillTest12;
var
    a, c: array of longInt;
    b: boolean;
begin
    setLength(a, 5);
    Arrays.fill(a, 1, 4, 8);
    setLength(c, 5);
    c[0] := 0;
    c[1] := 8;
    c[2] := 8;
    c[3] := 8;
    c[4] := 0;
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the fill method with array of longs.
 *)
procedure ArraysTest.fillTest13;
var
    a, c: array of int64;
    b: boolean;
begin
    setLength(a, 5);
    Arrays.fill(a, 8);
    setLength(c, 5);
    c[0] := 8;
    c[1] := 8;
    c[2] := 8;
    c[3] := 8;
    c[4] := 8;
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the fill method with array of longs and indexes as parameters.
 *)
procedure ArraysTest.fillTest14;
var
    a, c: array of int64;
    b: boolean;
begin
    setLength(a, 5);
    Arrays.fill(a, 1, 4, 8);
    setLength(c, 5);
    c[0] := 0;
    c[1] := 8;
    c[2] := 8;
    c[3] := 8;
    c[4] := 0;
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the fill method with array of objects.
 *)
procedure ArraysTest.fillTest15;
var
    a, c: array of Object_;
    b: boolean;
begin
    setLength(a, 5);
    Arrays.fill(a, TestObject.create('sixth', 6));
    setLength(c, 5);
    c[0] := TestObject.create('sixth', 6);
    c[1] := TestObject.create('sixth', 6);
    c[2] := TestObject.create('sixth', 6);
    c[3] := TestObject.create('sixth', 6);
    c[4] := TestObject.create('sixth', 6);
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the fill method with array of objects and indexes as parameters.
 *)
procedure ArraysTest.fillTest16;
var
    a, c: array of Object_;
    b: boolean;
begin
    setLength(a, 5);
    Arrays.fill(a, 1, 4, TestObject.create('sixth', 6));
    setLength(c, 5);
    c[0] := nil;
    c[1] := TestObject.create('sixth', 6);
    c[2] := TestObject.create('sixth', 6);
    c[3] := TestObject.create('sixth', 6);
    c[4] := nil;
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the fill method with array of shorts.
 *)
procedure ArraysTest.fillTest17;
var
    a, c: array of smallInt;
    b: boolean;
begin
    setLength(a, 5);
    Arrays.fill(a, smallInt(8));
    setLength(c, 5);
    c[0] := 8;
    c[1] := 8;
    c[2] := 8;
    c[3] := 8;
    c[4] := 8;
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the fill method with array of shorts and indexes as parameters.
 *)
procedure ArraysTest.fillTest18;
var
    a, c: array of smallInt;
    b: boolean;
begin
    setLength(a, 5);
    Arrays.fill(a, 1, 4, smallInt(8));
    setLength(c, 5);
    c[0] := 0;
    c[1] := 8;
    c[2] := 8;
    c[3] := 8;
    c[4] := 0;
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the sort method with array of bytes.
 *)
procedure ArraysTest.sortTest;
var
    a, c: array of shortInt;
    b: boolean;
begin
    // the array for sorting
    setLength(a, 5);
    a[0] := shortInt(3);
    a[1] := shortInt(2);
    a[2] := shortInt(8);
    a[3] := shortInt(7);
    a[4] := shortInt(6);
    Arrays.sort(a);
    setLength(c, 5);
    c[0] := 2;
    c[1] := 3;
    c[2] := 6;
    c[3] := 7;
    c[4] := 8;
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the sort method with array of bytes and indexes as parameters.
 *)
procedure ArraysTest.sortTest2;
var
    a, c: array of shortInt;
    b: boolean;
begin
    // the array for partial sorting
    setLength(a, 5);
    a[0] := shortInt(3);
    a[1] := shortInt(2);
    a[2] := shortInt(8);
    a[3] := shortInt(7);
    a[4] := shortInt(6);
    Arrays.sort(a, 1, 4);
    setLength(c, 5);
    c[0] := 3;
    c[1] := 2;
    c[2] := 7;
    c[3] := 8;
    c[4] := 6;
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the sort method with array of chars.
 *)
procedure ArraysTest.sortTest3;
var
    a, c: array of ansiChar;
    b: boolean;
begin
    setLength(a, 5);
    a[0] := 'c';
    a[1] := 'b';
    a[2] := 'h';
    a[3] := 'g';
    a[4] := 'f';
    Arrays.sort(a);
    setLength(c, 5);
    c[0] := 'b';
    c[1] := 'c';
    c[2] := 'f';
    c[3] := 'g';
    c[4] := 'h';
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the sort method with array of chars and indexes as parameters.
 *)
procedure ArraysTest.sortTest4;
var
    a, c: array of ansiChar;
    b: boolean;
begin
    setLength(a, 5);
    a[0] := 'c';
    a[1] := 'b';
    a[2] := 'h';
    a[3] := 'g';
    a[4] := 'f';
    Arrays.sort(a, 1, 4);
    setLength(c, 5);
    c[0] := 'c';
    c[1] := 'b';
    c[2] := 'g';
    c[3] := 'h';
    c[4] := 'f';
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the sort method with array of doubles.
 *)
procedure ArraysTest.sortTest5;
var
    a, c: array of double;
    b: boolean;
begin
    setLength(a, 5);
    a[0] := 3.0;
    a[1] := 2.0;
    a[2] := 8.0;
    a[3] := 7.0;
    a[4] := 6.0;
    Arrays.sort(a);
    setLength(c, 5);
    c[0] := 2.0;
    c[1] := 3.0;
    c[2] := 6.0;
    c[3] := 7.0;
    c[4] := 8.0;
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the sort method with array of doubles and indexes as parameters.
 *)
procedure ArraysTest.sortTest6;
var
    a, c: array of double;
    b: boolean;
begin
    setLength(a, 5);
    a[0] := 3.0;
    a[1] := 2.0;
    a[2] := 8.0;
    a[3] := 7.0;
    a[4] := 6.0;
    Arrays.sort(a, 1, 4);
    setLength(c, 5);
    c[0] := 3.0;
    c[1] := 2.0;
    c[2] := 7.0;
    c[3] := 8.0;
    c[4] := 6.0;
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the sort method with array of floats.
 *)
procedure ArraysTest.sortTest7;
var
    a, c: array of single;
    b: boolean;
begin
    setLength(a, 5);
    a[0] := 3.0;
    a[1] := 2.0;
    a[2] := 8.0;
    a[3] := 7.0;
    a[4] := 6.0;
    Arrays.sort(a);
    setLength(c, 5);
    c[0] := 2.0;
    c[1] := 3.0;
    c[2] := 6.0;
    c[3] := 7.0;
    c[4] := 8.0;
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the sort method with array of floats and indexes as parameters.
 *)
procedure ArraysTest.sortTest8;
var
    a, c: array of single;
    b: boolean;
begin
    setLength(a, 5);
    a[0] := 3.0;
    a[1] := 2.0;
    a[2] := 8.0;
    a[3] := 7.0;
    a[4] := 6.0 ;
    Arrays.sort(a, 1, 4);
    setLength(c, 5);
    c[0] := 3.0;
    c[1] := 2.0;
    c[2] := 7.0;
    c[3] := 8.0;
    c[4] := 6.0;
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the sort method with array of ints.
 *)
procedure ArraysTest.sortTest9;
var
    a, c: array of longInt;
    b: boolean;
begin
    setLength(a, 5);
    a[0] := 3;
    a[1] := 2;
    a[2] := 8;
    a[3] := 7;
    a[4] := 6;
    Arrays.sort(a);
    setLength(c, 5);
    c[0] := 2;
    c[1] := 3;
    c[2] := 6;
    c[3] := 7;
    c[4] := 8;
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the sort method with array of ints and indexes as parameters.
 *)
procedure ArraysTest.sortTest10;
var
    a, c: array of longInt;
    b: boolean;
begin
    setLength(a, 5);
    a[0] := 3;
    a[1] := 2;
    a[2] := 8;
    a[3] := 7;
    a[4] := 6;
    Arrays.sort(a, 1, 4);
    setLength(c, 5);
    c[0] := 3;
    c[1] := 2;
    c[2] := 7;
    c[3] := 8;
    c[4] := 6;
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the sort method with array of longs.
 *)
procedure ArraysTest.sortTest11;
var
    a, c: array of int64;
    b: boolean;
begin
    setLength(a, 5);
    a[0] := 3;
    a[1] := 2;
    a[2] := 8;
    a[3] := 7;
    a[4] := 6 ;
    Arrays.sort(a);
    setLength(c, 5);
    c[0] := 2;
    c[1] := 3;
    c[2] := 6;
    c[3] := 7;
    c[4] := 8;
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the sort method with array of longs and indexes as parameters.
 *)
procedure ArraysTest.sortTest12;
var
    a, c: array of int64;
    b: boolean;
begin
    setLength(a, 5);
    a[0] := 3;
    a[1] := 2;
    a[2] := 8;
    a[3] := 7;
    a[4] := 6 ;
    Arrays.sort(a, 1, 4);
    setLength(c, 5);
    c[0] := 3;
    c[1] := 2;
    c[2] := 7;
    c[3] := 8;
    c[4] := 6;
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the sort method with array of objects.
 *)
procedure ArraysTest.sortTest13;
var
    a, c: array of Object_;
    b: boolean;
begin
    setLength(a, 10);
    a[0] := TestObject.create('first', 3);
    a[1] := TestObject.create('second', 2);
    a[2] := TestObject.create('third', 8);
    a[3] := TestObject.create('fourth', 7);
    a[4] := TestObject.create('fifth', 6);
    a[5] := TestObject.create('sixth', 3);
    a[6] := TestObject.create('seventh', 2);
    a[7] := TestObject.create('eighth', 8);
    a[8] := TestObject.create('nineth', 7);
    a[9] := TestObject.create('tenth', 6);
    Arrays.sort(a);
    setLength(c, 10);
    c[0] := TestObject.create('second', 2);
    c[1] := TestObject.create('seventh', 2);
    c[2] := TestObject.create('first', 3);
    c[3] := TestObject.create('sixth', 3);
    c[4] := TestObject.create('fifth', 6);
    c[5] := TestObject.create('tenth', 6);
    c[6] := TestObject.create('fourth', 7);
    c[7] := TestObject.create('nineth', 7);
    c[8] := TestObject.create('third', 8);
    c[9] := TestObject.create('eighth', 8);
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the sort method with array of objects and indexes as parameters.
 *)
procedure ArraysTest.sortTest14;
var
    a, c: array of Object_;
    b: boolean;
begin
    setLength(a, 10);
    a[0] := TestObject.create('first', 3);
    a[1] := TestObject.create('second', 2);
    a[2] := TestObject.create('third', 8);
    a[3] := TestObject.create('fourth', 7);
    a[4] := TestObject.create('fifth', 6);
    a[5] := TestObject.create('sixth', 3);
    a[6] := TestObject.create('seventh', 2);
    a[7] := TestObject.create('eighth', 8);
    a[8] := TestObject.create('nineth', 7);
    a[9] := TestObject.create('tenth', 6);
    Arrays.sort(a, 1, 4);
    setLength(c, 10);
    c[0] := TestObject.create('first', 3);
    c[1] := TestObject.create('second', 2);
    c[2] := TestObject.create('fourth', 7);
    c[3] := TestObject.create('third', 8);
    c[4] := TestObject.create('fifth', 6);
    c[5] := TestObject.create('sixth', 3);
    c[6] := TestObject.create('seventh', 2);
    c[7] := TestObject.create('eighth', 8);
    c[8] := TestObject.create('nineth', 7);
    c[9] := TestObject.create('tenth', 6);
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the sort method with array of shorts.
 *)
procedure ArraysTest.sortTest15;
var
    a, c: array of smallInt;
    b: boolean;
begin
    setLength(a, 5);
    a[0] := smallInt(3);
    a[1] := smallInt(2);
    a[2] := smallInt(8);
    a[3] := smallInt(7);
    a[4] := smallInt(6);
    Arrays.sort(a);
    setLength(c, 5);
    c[0] := 2;
    c[1] := 3;
    c[2] := 6;
    c[3] := 7;
    c[4] := 8;
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the sort method with array of shorts and indexes as parameters.
 *)
procedure ArraysTest.sortTest16;
var
    a, c: array of smallInt;
    b: boolean;
begin
    setLength(a, 5);
    a[0] := smallInt(3);
    a[1] := smallInt(2);
    a[2] := smallInt(8);
    a[3] := smallInt(7);
    a[4] := smallInt(6);
    Arrays.sort(a, 1, 4);
    setLength(c, 5);
    c[0] := 3;
    c[1] := 2;
    c[2] := 7;
    c[3] := 8;
    c[4] := 6;
    b := Arrays.equals(a, c);
    AssertEquals(true, b);
end;

(**
 * Tests the sort method with array of objects and comparator as a
 * parameter.
 *)
procedure ArraysTest.sortTest17;
var
    a, d: array of Object_;
    b: boolean;
    c: TestObjectComparator;
begin
    setLength(a, 10);
    a[0] := TestObject.create('first', 3);
    a[1] := TestObject.create('second', 2);
    a[2] := TestObject.create('third', 8);
    a[3] := TestObject.create('fourth', 7);
    a[4] := TestObject.create('fifth', 6);
    a[5] := TestObject.create('sixth', 3);
    a[6] := TestObject.create('seventh', 2);
    a[7] := TestObject.create('eighth', 8);
    a[8] := TestObject.create('nineth', 7);
    a[9] := TestObject.create('tenth', 6);
    c := TestObjectComparator.create();
    Arrays.sort(a, c);
    setLength(d, 10);
    d[0] := TestObject.create('second', 2);
    d[1] := TestObject.create('seventh', 2);
    d[2] := TestObject.create('first', 3);
    d[3] := TestObject.create('sixth', 3);
    d[4] := TestObject.create('fifth', 6);
    d[5] := TestObject.create('tenth', 6);
    d[6] := TestObject.create('fourth', 7);
    d[7] := TestObject.create('nineth', 7);
    d[8] := TestObject.create('third', 8);
    d[9] := TestObject.create('eighth', 8);
    b := Arrays.equals(a, d);
    AssertEquals(true, b);
end;

(**
 * Tests the sort method with array of objects and indexes and comparator as
 * parameters.
 *)
procedure ArraysTest.sortTest18;
var
    a, d: array of Object_;
    b: boolean;
    c: TestObjectComparator;
begin
    setLength(a, 10);
    a[0] := TestObject.create('first', 3);
    a[1] := TestObject.create('second', 2);
    a[2] := TestObject.create('third', 8);
    a[3] := TestObject.create('fourth', 7);
    a[4] := TestObject.create('fifth', 6);
    a[5] := TestObject.create('sixth', 3);
    a[6] := TestObject.create('seventh', 2);
    a[7] := TestObject.create('eighth', 8);
    a[8] := TestObject.create('nineth', 7);
    a[9] := TestObject.create('tenth', 6);
    c := TestObjectComparator.create();
    Arrays.sort(a, 1, 4, c);
    setLength(d, 10);
    d[0] := TestObject.create('first', 3);
    d[1] := TestObject.create('second', 2);
    d[2] := TestObject.create('fourth', 7);
    d[3] := TestObject.create('third', 8);
    d[4] := TestObject.create('fifth', 6);
    d[5] := TestObject.create('sixth', 3);
    d[6] := TestObject.create('seventh', 2);
    d[7] := TestObject.create('eighth', 8);
    d[8] := TestObject.create('nineth', 7);
    d[9] := TestObject.create('tenth', 6);
    b := Arrays.equals(a, d);
    AssertEquals(true, b);
end;

(**
 * Tests the toString method with array of booleans.
 *)
procedure ArraysTest.toStringTest;
var
    a: array of boolean;
    b: String_;
begin
    // the text represenation of an empty array
    setLength(a, 0);
    b := Arrays.toString(a);
    AssertEquals('[]', b.strProperty);
    // the text represenation of an array with one element
    setLength(a, 1);
    a[0] := true ;
    b := Arrays.toString(a);
    AssertEquals('[true]', b.strProperty);
    // the text represenation of an array with some elements
    setLength(a, 5);
    a[0] := true;
    a[1] := false;
    a[2] := false;
    a[3] := false;
    a[4] := true;
    b := Arrays.toString(a);
    AssertEquals('[true, false, false, false, true]', b.strProperty);
end;

(**
 * Tests the toString method with array of bytes.
 *)
procedure ArraysTest.toStringTest2;
var
    a: array of shortInt;
    b: String_;
begin
    setLength(a, 0);
    b := Arrays.toString(a);
    AssertEquals('[]', b.strProperty);
    setLength(a, 1);
    a[0] := shortInt(3);
    b := Arrays.toString(a);
    AssertEquals('[3]', b.strProperty);
    setLength(a, 5);
    a[0] := shortInt(3);
    a[1] := shortInt(2);
    a[2] := shortInt(8);
    a[3] := shortInt(7);
    a[4] := shortInt(6);
    b := Arrays.toString(a);
    AssertEquals('[3, 2, 8, 7, 6]', b.strProperty);
end;

(**
 * Tests the toString method with array of chars.
 *)
procedure ArraysTest.toStringTest3;
var
    a: array of ansiChar;
    b: String_;
begin
    setLength(a, 0);
    b := Arrays.toString(a);
    AssertEquals('[]', b.strProperty);
    setLength(a, 1);
    a[0] := 'c';
    b := Arrays.toString(a);
    AssertEquals('[c]', b.strProperty);
    setLength(a, 5);
    a[0] := 'c';
    a[1] := 'b';
    a[2] := 'h';
    a[3] := 'g';
    a[4] := 'f';
    b := Arrays.toString(a);
    AssertEquals('[c, b, h, g, f]', b.strProperty);
end;

(**
 * Tests the toString method with array of doubles.
 *)
procedure ArraysTest.toStringTest4;
var
    a: array of double;
    b: String_;
begin
    setLength(a, 0);
    b := Arrays.toString(a);
    AssertEquals('[]', b.strProperty);
    setLength(a, 1);
    a[0] := 3.0;
    b := Arrays.toString(a);
    AssertEquals('[3.0]', b.strProperty);
    setLength(a, 5);
    a[0] := 3.0;
    a[1] := 2.0;
    a[2] := 8.0;
    a[3] := 7.0;
    a[4] := 6.0;
    b := Arrays.toString(a);
    AssertEquals('[3.0, 2.0, 8.0, 7.0, 6.0]', b.strProperty);
end;

(**
 * Tests the toString method with array of floats.
 *)
procedure ArraysTest.toStringTest5;
var
    a: array of single;
    b: String_;
begin
    setLength(a, 0);
    b := Arrays.toString(a);
    AssertEquals('[]', b.strProperty);
    setLength(a, 1);
    a[0] := 3.0;
    b := Arrays.toString(a);
    AssertEquals('[3.0]', b.strProperty);
    setLength(a, 5);
    a[0] := 3.0;
    a[1] := 2.0;
    a[2] := 8.0;
    a[3] := 7.0;
    a[4] := 6.0 ;
    b := Arrays.toString(a);
    AssertEquals('[3.0, 2.0, 8.0, 7.0, 6.0]', b.strProperty);
end;

(**
 * Tests the toString method with array of ints.
 *)
procedure ArraysTest.toStringTest6;
var
    a: array of longInt;
    b: String_;
begin
    setLength(a, 0);
    b := Arrays.toString(a);
    AssertEquals('[]', b.strProperty);
    setLength(a, 1);
    a[0] := 3;
    b := Arrays.toString(a);
    AssertEquals('[3]', b.strProperty);
    setLength(a, 5);
    a[0] := 3;
    a[1] := 2;
    a[2] := 8;
    a[3] := 7;
    a[4] := 6;
    b := Arrays.toString(a);
    AssertEquals('[3, 2, 8, 7, 6]', b.strProperty);
end;

(**
 * Tests the toString method with array of longs.
 *)
procedure ArraysTest.toStringTest7;
var
    a: array of int64;
    b: String_;
begin
    setLength(a, 0);
    b := Arrays.toString(a);
    AssertEquals('[]', b.strProperty);
    setLength(a, 1);
    a[0] := 3;
    b := Arrays.toString(a);
    AssertEquals('[3]', b.strProperty);
    setLength(a, 5);
    a[0] := 3;
    a[1] := 2;
    a[2] := 8;
    a[3] := 7;
    a[4] := 6;
    b := Arrays.toString(a);
    AssertEquals('[3, 2, 8, 7, 6]', b.strProperty);
end;

(**
 * Tests the toString method with array of objects.
 *)
procedure ArraysTest.toStringTest8;
var
    a: array of Object_;
    b: String_;
begin
    setLength(a, 0);
    b := Arrays.toString(a);
    AssertEquals('[]', b.strProperty);
    setLength(a, 1);
    a[0] := TestObject.create('first', 1);
    b := Arrays.toString(a);
    AssertEquals('[TestObject [str=first, i=1]]', b.strProperty);
    setLength(a, 1);
    a[0] := nil;
    b := Arrays.toString(a);
    AssertEquals('[null]', b.strProperty);
    setLength(a, 3);
    a[0] := TestObject.create('first', 1);
    a[1] := TestObject.create('second', 2);
    a[2] := TestObject.create('third', 3);
    b := Arrays.toString(a);
    AssertEquals('[TestObject [str=first, i=1], TestObject [str=second, i=2], TestObject [str=third, i=3]]', b.strProperty);
    setLength(a, 3);
    a[0] := TestObject.create('first', 1);
    a[1] := nil;
    a[2] := TestObject.create('third', 3);
    b := Arrays.toString(a);
    AssertEquals('[TestObject [str=first, i=1], null, TestObject [str=third, i=3]]', b.strProperty);
    setLength(a, 3);
    a[0] := nil;
    a[1] := nil;
    a[2] := nil;
    b := Arrays.toString(a);
    AssertEquals('[null, null, null]', b.strProperty);
end;

(**
 * Tests the toString method with array of shorts.
 *)
procedure ArraysTest.toStringTest9;
var
    a: array of smallInt;
    b: String_;
begin
    setLength(a, 0);
    b := Arrays.toString(a);
    AssertEquals('[]', b.strProperty);
    setLength(a, 1);
    a[0] := smallInt(3);
    b := Arrays.toString(a);
    AssertEquals('[3]', b.strProperty);
    setLength(a, 5);
    a[0] := smallInt(3);
    a[1] := smallInt(2);
    a[2] := smallInt(8);
    a[3] := smallInt(7);
    a[4] := smallInt(6);
    b := Arrays.toString(a);
    AssertEquals('[3, 2, 8, 7, 6]', b.strProperty);
end;

initialization

  RegisterTest(ArraysTest);
end.

