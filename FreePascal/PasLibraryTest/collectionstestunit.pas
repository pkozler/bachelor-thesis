unit CollectionsTestUnit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, fpcunit, testutils, testregistry, CollectionsUnit,
  ArrayListUnit, StringUnit, TestObjectUnit, TestObjectComparatorUnit;

type

  CollectionsTest = class(TTestCase)
  published
       procedure binarySearchTest;
       procedure binarySearchTest2;
       procedure copyTest;
       procedure fillTest;
       procedure sortTest;
       procedure sortTest2;
  end;

implementation

(**
 * Tests the binarySearch method.
 *)
procedure CollectionsTest.binarySearchTest;
var
    a: ArrayList;
    b: longInt;
begin
    a := ArrayList.create();
    a.add(TestObject.create(String_.create('first'), 3));
    a.add(TestObject.create('second', 2));
    a.add(TestObject.create('third', 8));
    a.add(TestObject.create('fourth', 7));
    a.add(TestObject.create('fifth', 6));
    a.add(TestObject.create('sixth', 3));
    a.add(TestObject.create('seventh', 2));
    a.add(TestObject.create('eighth', 8));
    a.add(TestObject.create('nineth', 7));
    a.add(TestObject.create('tenth', 6));
    Collections.sort(a);
    b := Collections.binarySearch(a, TestObject.create('sixth', 6));
    AssertEquals(4, b);
    b := Collections.binarySearch(a, TestObject.create('sixth', 4));
    AssertEquals(-5, b);
end;

(**
 * Tests the binarySearch method with comparator as a parameter.
 *)
procedure CollectionsTest.binarySearchTest2;
var
    a: ArrayList;
    b: longInt;
    c: TestObjectComparator;
begin
    a := ArrayList.create();
    a.add(TestObject.create('first', 3));
    a.add(TestObject.create('second', 2));
    a.add(TestObject.create('third', 8));
    a.add(TestObject.create('fourth', 7));
    a.add(TestObject.create('fifth', 6));
    a.add(TestObject.create('sixth', 3));
    a.add(TestObject.create('seventh', 2));
    a.add(TestObject.create('eighth', 8));
    a.add(TestObject.create('nineth', 7));
    a.add(TestObject.create('tenth', 6));
    c := TestObjectComparator.create();
    Collections.sort(a);
    b := Collections.binarySearch(a, TestObject.create('sixth', 6), c);
    AssertEquals(4, b);
    b := Collections.binarySearch(a, TestObject.create('sixth', 4), c);
    AssertEquals(-5, b);
end;

(**
 * Tests the copy method.
 *)
procedure CollectionsTest.copyTest;
var
    a, b, c: ArrayList;
    d: boolean;
begin
    // source list
    a := ArrayList.create();
    a.add(TestObject.create('first', 3));
    a.add(TestObject.create('second', 2));
    a.add(TestObject.create('third', 8));
    a.add(TestObject.create('fourth', 7));
    a.add(TestObject.create('fifth', 6));
    // destination list
    b := ArrayList.create();
    b.add(TestObject.create('zeroth', 0));
    b.add(TestObject.create('zeroth', 0));
    b.add(TestObject.create('zeroth', 0));
    b.add(TestObject.create('zeroth', 0));
    b.add(TestObject.create('zeroth', 0));
    b.add(TestObject.create('zeroth', 0));
    Collections.copy(b, a);
    c := ArrayList.create();
    c.add(TestObject.create('first', 3));
    c.add(TestObject.create('second', 2));
    c.add(TestObject.create('third', 8));
    c.add(TestObject.create('fourth', 7));
    c.add(TestObject.create('fifth', 6));
    c.add(TestObject.create('zeroth', 0));
    d := c.equals_(b);
    AssertEquals(true, d);
end;

(**
 * Tests the fill method.
 *)
procedure CollectionsTest.fillTest;
var
    a, b: ArrayList;
    d: boolean;
begin
    a := ArrayList.create();
    a.add(TestObject.create('first', 3));
    a.add(TestObject.create('second', 2));
    a.add(TestObject.create('third', 8));
    a.add(TestObject.create('fourth', 7));
    a.add(TestObject.create('fifth', 6));
    Collections.fill(a, TestObject.create('sixth', 6));
    b := ArrayList.create();
    b.add(TestObject.create('sixth', 6));
    b.add(TestObject.create('sixth', 6));
    b.add(TestObject.create('sixth', 6));
    b.add(TestObject.create('sixth', 6));
    b.add(TestObject.create('sixth', 6));
    d := b.equals_(a);
    AssertEquals(true, d);
end;

(**
 * Tests the sort method.
 *)
procedure CollectionsTest.sortTest;
var
    a, b: ArrayList;
    d: boolean;
begin
    a := ArrayList.create();
    a.add(TestObject.create('first', 3));
    a.add(TestObject.create('second', 2));
    a.add(TestObject.create('third', 8));
    a.add(TestObject.create('fourth', 7));
    a.add(TestObject.create('fifth', 6));
    a.add(TestObject.create('sixth', 3));
    a.add(TestObject.create('seventh', 2));
    a.add(TestObject.create('eighth', 8));
    a.add(TestObject.create('nineth', 7));
    a.add(TestObject.create('tenth', 6));
    Collections.sort(a);
    b := ArrayList.create();
    b.add(TestObject.create('second', 2));
    b.add(TestObject.create('seventh', 2));
    b.add(TestObject.create('first', 3));
    b.add(TestObject.create('sixth', 3));
    b.add(TestObject.create('fifth', 6));
    b.add(TestObject.create('tenth', 6));
    b.add(TestObject.create('fourth', 7));
    b.add(TestObject.create('nineth', 7));
    b.add(TestObject.create('third', 8));
    b.add(TestObject.create('eighth', 8));
    d := b.equals_(a);
    AssertEquals(true, d);
end;

(**
 * Tests the sort method with comparator as a parameter.
 *)
procedure CollectionsTest.sortTest2;
var
    a, b: ArrayList;
    c: TestObjectComparator;
    d: boolean;
begin
    a := ArrayList.create();
    a.add(TestObject.create('first', 3));
    a.add(TestObject.create('second', 2));
    a.add(TestObject.create('third', 8));
    a.add(TestObject.create('fourth', 7));
    a.add(TestObject.create('fifth', 6));
    a.add(TestObject.create('sixth', 3));
    a.add(TestObject.create('seventh', 2));
    a.add(TestObject.create('eighth', 8));
    a.add(TestObject.create('nineth', 7));
    a.add(TestObject.create('tenth', 6));
    c := TestObjectComparator.create();
    Collections.sort(a, c);
    b := ArrayList.create();
    b.add(TestObject.create('second', 2));
    b.add(TestObject.create('seventh', 2));
    b.add(TestObject.create('first', 3));
    b.add(TestObject.create('sixth', 3));
    b.add(TestObject.create('fifth', 6));
    b.add(TestObject.create('tenth', 6));
    b.add(TestObject.create('fourth', 7));
    b.add(TestObject.create('nineth', 7));
    b.add(TestObject.create('third', 8));
    b.add(TestObject.create('eighth', 8));
    d := b.equals_(a);
    AssertEquals(true, d);
end;

initialization

  RegisterTest(CollectionsTest);
end.

