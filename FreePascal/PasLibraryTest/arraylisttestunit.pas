unit ArrayListTestUnit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, fpcunit, testutils, testregistry, ArrayListUnit, StringUnit, TestObjectUnit;

type

  ArrayListTest = class(TTestCase)
  private
       function toList(arr: array of TestObject): ArrayList;
  published
       procedure arrayListTest;
       procedure arrayListTest2;
       procedure addTest;
       procedure addTest2;
       procedure equalsTest;
       procedure getTest;
       procedure setTest;
       procedure removeTest;
       procedure sizeTest;
       procedure isEmptyTest;
       procedure clearTest;
       procedure toStringTest;
  end;

implementation

(*
    Creates the array list from array.
*)
function ArrayListTest.toList(arr: array of TestObject): ArrayList;
var
    list: ArrayList;
    len, i: longInt;
begin
    list := ArrayList.create();
    len := length(arr);

    for i := 0 to len - 1 do begin
        list.add(arr[i]);
    end;

    toList := list;
end;

(**
 * Tests the constructor.
 *)
procedure ArrayListTest.arrayListTest;
var
    a: ArrayList;
    b: boolean;
    c: array of TestObject;
begin
    // empty list
    a := ArrayList.create();
    setLength(c, 0);
    b := a.equals(toList(c));
    AssertEquals(true, b);
end;

(**
 * Tests the constructor with ArrayList as a parameter.
 *)
procedure ArrayListTest.arrayListTest2;
var
    a, b: ArrayList;
    c: TestObject;
    d: boolean;
    e: array of TestObject;
begin
    // creating the list from an empty list
    a := ArrayList.create();
    b := ArrayList.create(a);
    setLength(e, 0);
    d := b.equals(toList(e));
    AssertEquals(true, d);
    // creating the list from a list with one element
    a := ArrayList.create();
    c := TestObject.create('first', 1);
    a.add(c);
    b := ArrayList.create(a);
    setLength(e, 1);
    e[0] :=  TestObject.create('first', 1);
    d := b.equals(toList(e));
    AssertEquals(true, d);
    // creating the list from a list with some elements
    a := ArrayList.create();
    c := TestObject.create('first', 1);
    a.add(c);
    c := TestObject.create('second', 2);
    a.add(c);
    c := TestObject.create('third', 3);
    a.add(c);
    b := ArrayList.create(a);
    setLength(e, 3);
    e[0] :=  TestObject.create('first', 1);
    e[1] := TestObject.create('second', 2);
    e[2] := TestObject.create('third', 3);
    d := b.equals(toList(e));
    AssertEquals(true, d);
end;

(**
 * Tests the add method.
 *)
procedure ArrayListTest.addTest;
var
    a: ArrayList;
    b: TestObject;
    c: boolean;
    d: array of TestObject;
begin
    // adding some elements at the end of the list
    a := ArrayList.create();
    b := TestObject.create('first', 1);
    a.add(b);
    setLength(d, 1);
    d[0] :=  TestObject.create('first', 1);
    c := a.equals(toList(d));
    AssertEquals(true, c);
    b := TestObject.create('second', 2);
    a.add(b);
    setLength(d, 2);
    d[0] :=  TestObject.create('first', 1);
    d[1] := TestObject.create('second', 2);
    c := a.equals(toList(d));
    AssertEquals(true, c);
    b := TestObject.create('first', 2);
    a.add(b);
    setLength(d, 3);
    d[0] :=  TestObject.create('first', 1);
    d[1] := TestObject.create('second', 2);
    d[2] := TestObject.create('first', 2);
    c := a.equals(toList(d));
    AssertEquals(true, c);
    b := TestObject.create('second', 1);
    a.add(b);
    setLength(d, 4);
    d[0] :=  TestObject.create('first', 1);
    d[1] := TestObject.create('second', 2);
    d[2] := TestObject.create('first', 2);
    d[3] := TestObject.create('second', 1);
    c := a.equals(toList(d));
    AssertEquals(true, c);
    b := TestObject.create('first', 1);
    a.add(b);
    setLength(d, 5);
    d[0] :=  TestObject.create('first', 1);
    d[1] := TestObject.create('second', 2);
    d[2] := TestObject.create('first', 2);
    d[3] := TestObject.create('second', 1);
    d[4] := TestObject.create('first', 1);
    c := a.equals(toList(d));
    AssertEquals(true, c);
end;

(**
 * Tests the add method with index as a parameter.
 *)
procedure ArrayListTest.addTest2;
var
    a: ArrayList;
    b: TestObject;
    c: boolean;
    d: array of TestObject;
begin
    a := ArrayList.create();
    // adding an element at the beginning
    b := TestObject.create('first', 1);
    a.add(0, b);
    setLength(d, 1);
    d[0] :=  TestObject.create('first', 1);
    c := a.equals(toList(d));
    AssertEquals(true, c);
    // adding an element at the end
    b := TestObject.create('second', 2);
    a.add(1, b);
    setLength(d, 2);
    d[0] :=  TestObject.create('first', 1);
    d[1] := TestObject.create('second', 2);
    c := a.equals(toList(d));
    AssertEquals(true, c);
    // adding an element at the beginning
    b := TestObject.create('third', 3);
    a.add(0, b);
    setLength(d, 3);
    d[0] :=  TestObject.create('third', 3);
    d[1] := TestObject.create('first', 1);
    d[2] := TestObject.create('second', 2);
    c := a.equals(toList(d));
    AssertEquals(true, c);
    // adding an element in the middle
    b := TestObject.create('fourth', 4);
    a.add(1, b);
    setLength(d, 4);
    d[0] :=  TestObject.create('third', 3);
    d[1] := TestObject.create('fourth', 4);
    d[2] := TestObject.create('first', 1);
    d[3] := TestObject.create('second', 2);
    c := a.equals(toList(d));
    AssertEquals(true, c);
    // adding an element in the middle
    b := TestObject.create('fifth', 5);
    a.add(2, b);
    setLength(d, 5);
    d[0] :=  TestObject.create('third', 3);
    d[1] := TestObject.create('fourth', 4);
    d[2] := TestObject.create('fifth', 5);
    d[3] := TestObject.create('first', 1);
    d[4] := TestObject.create('second', 2);
    c := a.equals(toList(d));
    AssertEquals(true, c);
end;

(**
 * Tests the equals method.
 *)
procedure ArrayListTest.equalsTest;
var
    a, b: ArrayList;
    c: boolean;
    d: array of TestObject;
begin
    setLength(d, 5);
    d[0] := TestObject.create('first', 3);
    d[1] := TestObject.create('second', 2);
    d[2] := TestObject.create('third', 8);
    d[3] := TestObject.create('fourth', 7);
    d[4] := TestObject.create('fifth', 6);
    a := toList(d);
    b := nil;
    c := a.equals(b);
    AssertEquals(false, c);
    setLength(d, 1);
    d[0] := TestObject.create('first', 3);
    b := toList(d);
    c := a.equals(b);
    AssertEquals(false, c);
    setLength(d, 5);
    d[0] := TestObject.create('first', 3);
    d[1] := TestObject.create('second', 2);
    d[2] := TestObject.create('third', 8);
    d[3] := TestObject.create('fourth', 7);
    d[4] := TestObject.create('fifth', 3);
    b := toList(d);
    c := a.equals(b);
    AssertEquals(false, c);
    setLength(d, 5);
    d[0] := TestObject.create('sixth', 3);
    d[1] := TestObject.create('seventh', 2);
    d[2] := TestObject.create('eighth', 8);
    d[3] := TestObject.create('nineth', 7);
    d[4] := TestObject.create('tenth', 6);
    b := toList(d);
    c := a.equals(b);
    AssertEquals(false, c);
    b := a;
    c := a.equals(b);
    AssertEquals(true, c);
end;

(**
 * Tests the get method.
 *)
procedure ArrayListTest.getTest;
var
    a: ArrayList;
    b: TestObject;
    c: boolean;
begin
    a := ArrayList.create();
    // getting an element from the beginning
    b := TestObject.create('first', 1);
    a.add(b);
    b := a.get(0) as TestObject;
    c := b.equals(TestObject.create('first', 1));
    AssertEquals(true, c);
    // getting an element from the beginning (more elements in the list)
    b := TestObject.create('second', 2);
    a.add(b);
    b := a.get(0) as TestObject;
    c := b.equals(TestObject.create('first', 1));
    AssertEquals(true, c);
    // getting an element from the end
    b := a.get(1) as TestObject;
    c := b.equals(TestObject.create('second', 2));
    AssertEquals(true, c);
    b := TestObject.create('third', 3);
    a.add(b);
    b := TestObject.create('fourth', 4);
    a.add(b);
    b := TestObject.create('fifth', 5);
    a.add(b);
    // getting an element from the beginning
    b := a.get(0) as TestObject;
    c := b.equals(TestObject.create('first', 1));
    AssertEquals(true, c);
    // getting an element from the end
    b := a.get(4) as TestObject;
    c := b.equals(TestObject.create('fifth', 5));
    AssertEquals(true, c);
end;

(**
 * Tests the set method.
 *)
procedure ArrayListTest.setTest;
var
    a: ArrayList;
    b: TestObject;
    c: boolean;
    d: array of TestObject;
begin
    a := ArrayList.create();
    b := TestObject.create('first', 1);
    a.add(b);
    b := TestObject.create('second', 2);
    a.add(b);
    b := TestObject.create('third', 3);
    a.add(b);
    b := TestObject.create('fourth', 4);
    a.add(b);
    b := TestObject.create('fifth', 5);
    a.add(b);
    b := TestObject.create('sixth', 6);
    // replacing an element at the beginning
    a.set_(0, b);
    setLength(d, 5);
    d[0] :=  TestObject.create('sixth', 6);
    d[1] := TestObject.create('second', 2);
    d[2] := TestObject.create('third', 3);
    d[3] := TestObject.create('fourth', 4);
    d[4] := TestObject.create('fifth', 5);
    c := a.equals(toList(d));
    AssertEquals(true, c);
    // replacing an element in the middle
    b := TestObject.create('seventh', 7);
    a.set_(2, b);
    setLength(d, 5);
    d[0] :=  TestObject.create('sixth', 6);
    d[1] := TestObject.create('second', 2);
    d[2] := TestObject.create('seventh', 7);
    d[3] := TestObject.create('fourth', 4);
    d[4] := TestObject.create('fifth', 5);
    c := a.equals(toList(d));
    AssertEquals(true, c);
    // replacing an element at the end
    b := TestObject.create('eighth', 8);
    a.set_(4, b);
    setLength(d, 5);
    d[0] :=  TestObject.create('sixth', 6);
    d[1] := TestObject.create('second', 2);
    d[2] := TestObject.create('seventh', 7);
    d[3] := TestObject.create('fourth', 4);
    d[4] := TestObject.create('eighth', 8);
    c := a.equals(toList(d));
    AssertEquals(true, c);
end;

(**
 * Tests the remove method.
 *)
procedure ArrayListTest.removeTest;
var
    a: ArrayList;
    b: TestObject;
    c: boolean;
    d: array of TestObject;
begin
    a := ArrayList.create();
    b := TestObject.create('first', 1);
    a.add(b);
    b := TestObject.create('second', 2);
    a.add(b);
    b := TestObject.create('third', 3);
    a.add(b);
    b := TestObject.create('fourth', 4);
    a.add(b);
    b := TestObject.create('fifth', 5);
    // removing an element from the beginning
    a.add(b);
    a.remove(0);
    setLength(d, 4);
    d[0] :=  TestObject.create('second', 2);
    d[1] := TestObject.create('third', 3);
    d[2] := TestObject.create('fourth', 4);
    d[3] := TestObject.create('fifth', 5);
    c := a.equals(toList(d));
    AssertEquals(true, c);
    // removing the element from the middle
    a.remove(1);
    setLength(d, 3);
    d[0] :=  TestObject.create('second', 2);
    d[1] := TestObject.create('fourth', 4);
    d[2] := TestObject.create('fifth', 5);
    c := a.equals(toList(d));
    AssertEquals(true, c);
    // removing an element from the end
    a.remove(2);
    setLength(d, 2);
    d[0] :=  TestObject.create('second', 2);
    d[1] := TestObject.create('fourth', 4);
    c := a.equals(toList(d));
    AssertEquals(true, c);
end;

(**
 * Tests the size method.
 *)
procedure ArrayListTest.sizeTest;
var
    a: ArrayList;
    b: TestObject;
    c: longInt;
begin
    a := ArrayList.create();
    // size in the beginning
    c := a.size();
    AssertEquals(0, c);
    b := TestObject.create('first', 1);
    // size after adding one element
    a.add(b);
    c := a.size();
    AssertEquals(1, c);
    // size after adding more elements
    b := TestObject.create('second', 2);
    a.add(b);
    b := TestObject.create('third', 3);
    a.add(b);
    c := a.size();
    AssertEquals(3, c);
    // size after removing one element
    a.remove(0);
    c := a.size();
    AssertEquals(2, c);
    // size after removing more elements
    a.remove(0);
    a.remove(0);
    c := a.size();
    AssertEquals(0, c);
end;

(**
 * Tests the isEmpty method.
 *)
procedure ArrayListTest.isEmptyTest;
var
    a: ArrayList;
    b: TestObject;
    c: boolean;
begin
    a := ArrayList.create();
    c := a.isEmpty();
    AssertEquals(true, c);
    b := TestObject.create('first', 1);
    a.add(b);
    c := a.isEmpty();
    AssertEquals(false, c);
    b := TestObject.create('second', 2);
    a.add(b);
    b := TestObject.create('third', 3);
    a.add(b);
    c := a.isEmpty();
    AssertEquals(false, c);
    a.remove(0);
    c := a.isEmpty();
    AssertEquals(false, c);
    a.remove(0);
    a.remove(0);
    c := a.isEmpty();
    AssertEquals(true, c);
end;

(**
 * Tests the clear method.
 *)
procedure ArrayListTest.clearTest;
var
    a: ArrayList;
    b: TestObject;
    c: boolean;
    d: array of TestObject;
begin
    a := ArrayList.create();
    // clear in the beginning
    a.clear();
    setLength(d, 0);
    c := a.equals(toList(d));
    AssertEquals(true, c);
    // clear after adding one element
    b := TestObject.create('first', 1);
    a.add(b);
    a.clear();
    c := a.equals(toList(d));
    AssertEquals(true, c);
    // clear after adding more elements
    b := TestObject.create('first', 1);
    a.add(b);
    b := TestObject.create('second', 2);
    a.add(b);
    b := TestObject.create('third', 3);
    a.add(b);
    a.clear();
    c := a.equals(toList(d));
    AssertEquals(true, c);
end;

(**
 * Tests the toString method.
 *)
procedure ArrayListTest.toStringTest;
var
    a: ArrayList;
    b: TestObject;
    c: String_;
begin
    // the text representation of an empty list
    a := ArrayList.create();
    c := a.toString_();
    AssertEquals('[]', c.strProperty);
    // the text representation of a list with one element
    b := TestObject.create('first', 1);
    a.add(b);
    c := a.toString_();
    AssertEquals('[TestObject [str:=first, i:=1]]', c.strProperty);
    // the text representation of a list with some elements
    b := TestObject.create('second', 2);
    a.add(b);
    b := TestObject.create('third', 3);
    a.add(b);
    c := a.toString_();
    AssertEquals('[TestObject [str:=first, i:=1], TestObject [str:=second, i:=2], TestObject [str:=third, i:=3]]', c.strProperty);
end;

initialization

  RegisterTest(ArrayListTest);
end.

