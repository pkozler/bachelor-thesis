unit LinkedListTestUnit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, fpcunit, testutils, testregistry, LinkedListUnit, StringUnit, TestObjectUnit;

type

  LinkedListTest = class(TTestCase)
  private
       function toList(arr: array of TestObject): LinkedList;
  published
       procedure linkedListTest;
       procedure linkedListTest2;
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
function LinkedListTest.toList(arr: array of TestObject): LinkedList;
var
    list: LinkedList;
    len, i: longInt;
begin
    list := LinkedList.create();
    len := length(arr);

    for i := 0 to len - 1 do begin
        list.add(arr[i]);
    end;

    toList := list;
end;

(**
 * Tests the constructor.
 *)
procedure LinkedListTest.LinkedListTest;
var
    a: LinkedList;
    b: boolean;
    c: array of TestObject;
begin
    // empty list
    a := LinkedList.create();
    setLength(c, 0);
    b := a.equals(toList(c));
    AssertTrue(b);
end;

(**
 * Tests the constructor with LinkedList as a parameter.
 *)
procedure LinkedListTest.LinkedListTest2;
var
    a, b: LinkedList;
    c: TestObject;
    d: boolean;
    e: array of TestObject;
begin
    // creating the list from an empty list
    a := LinkedList.create();
    b := LinkedList.create(a);
    setLength(e, 0);
    d := b.equals(toList(e));
    AssertTrue(d);
    // creating the list from a list with one element
    a := LinkedList.create();
    c := TestObject.create('first', 1);
    a.add(c);
    b := LinkedList.create(a);
    setLength(e, 1);
    e[0] :=  TestObject.create('first', 1);
    d := b.equals(toList(e));
    AssertTrue(d);
    // creating the list from a list with some elements
    a := LinkedList.create();
    c := TestObject.create('first', 1);
    a.add(c);
    c := TestObject.create('second', 2);
    a.add(c);
    c := TestObject.create('third', 3);
    a.add(c);
    b := LinkedList.create(a);
    setLength(e, 3);
    e[0] :=  TestObject.create('first', 1);
    e[1] := TestObject.create('second', 2);
    e[2] := TestObject.create('third', 3);
    d := b.equals(toList(e));
    AssertTrue(d);
end;

(**
 * Tests the add method.
 *)
procedure LinkedListTest.addTest;
var
    a: LinkedList;
    b: TestObject;
    c: boolean;
    d: array of TestObject;
begin
    // adding some elements at the end of the list
    a := LinkedList.create();
    b := TestObject.create('first', 1);
    a.add(b);
    setLength(d, 1);
    d[0] :=  TestObject.create('first', 1);
    c := a.equals(toList(d));
    AssertTrue(c);
    b := TestObject.create('second', 2);
    a.add(b);
    setLength(d, 2);
    d[0] :=  TestObject.create('first', 1);
    d[1] := TestObject.create('second', 2);
    c := a.equals(toList(d));
    AssertTrue(c);
    b := TestObject.create('first', 2);
    a.add(b);
    setLength(d, 3);
    d[0] :=  TestObject.create('first', 1);
    d[1] := TestObject.create('second', 2);
    d[2] := TestObject.create('first', 2);
    c := a.equals(toList(d));
    AssertTrue(c);
    b := TestObject.create('second', 1);
    a.add(b);
    setLength(d, 4);
    d[0] :=  TestObject.create('first', 1);
    d[1] := TestObject.create('second', 2);
    d[2] := TestObject.create('first', 2);
    d[3] := TestObject.create('second', 1);
    c := a.equals(toList(d));
    AssertTrue(c);
    b := TestObject.create('first', 1);
    a.add(b);
    setLength(d, 5);
    d[0] :=  TestObject.create('first', 1);
    d[1] := TestObject.create('second', 2);
    d[2] := TestObject.create('first', 2);
    d[3] := TestObject.create('second', 1);
    d[4] := TestObject.create('first', 1);
    c := a.equals(toList(d));
    AssertTrue(c);
end;

(**
 * Tests the add method with index as a parameter.
 *)
procedure LinkedListTest.addTest2;
var
    a: LinkedList;
    b: TestObject;
    c: boolean;
    d: array of TestObject;
begin
    a := LinkedList.create();
    // adding an element at the beginning
    b := TestObject.create('first', 1);
    a.add(0, b);
    setLength(d, 1);
    d[0] :=  TestObject.create('first', 1);
    c := a.equals(toList(d));
    AssertTrue(c);
    // adding an element at the end
    b := TestObject.create('second', 2);
    a.add(1, b);
    setLength(d, 2);
    d[0] :=  TestObject.create('first', 1);
    d[1] := TestObject.create('second', 2);
    c := a.equals(toList(d));
    AssertTrue(c);
    // adding an element at the beginning
    b := TestObject.create('third', 3);
    a.add(0, b);
    setLength(d, 3);
    d[0] :=  TestObject.create('third', 3);
    d[1] := TestObject.create('first', 1);
    d[2] := TestObject.create('second', 2);
    c := a.equals(toList(d));
    AssertTrue(c);
    // adding an element in the middle
    b := TestObject.create('fourth', 4);
    a.add(1, b);
    setLength(d, 4);
    d[0] :=  TestObject.create('third', 3);
    d[1] := TestObject.create('fourth', 4);
    d[2] := TestObject.create('first', 1);
    d[3] := TestObject.create('second', 2);
    c := a.equals(toList(d));
    AssertTrue(c);
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
    AssertTrue(c);
end;

(**
 * Tests the equals method.
 *)
procedure LinkedListTest.equalsTest;
var
    a, b: LinkedList;
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
    AssertFalse(c);
    setLength(d, 1);
    d[0] := TestObject.create('first', 3);
    b := toList(d);
    c := a.equals(b);
    AssertFalse(c);
    setLength(d, 5);
    d[0] := TestObject.create('first', 3);
    d[1] := TestObject.create('second', 2);
    d[2] := TestObject.create('third', 8);
    d[3] := TestObject.create('fourth', 7);
    d[4] := TestObject.create('fifth', 3);
    b := toList(d);
    c := a.equals(b);
    AssertFalse(c);
    setLength(d, 5);
    d[0] := TestObject.create('sixth', 3);
    d[1] := TestObject.create('seventh', 2);
    d[2] := TestObject.create('eighth', 8);
    d[3] := TestObject.create('nineth', 7);
    d[4] := TestObject.create('tenth', 6);
    b := toList(d);
    c := a.equals(b);
    AssertTrue(c);
    b := a;
    c := a.equals(b);
    AssertTrue(c);
end;

(**
 * Tests the get method.
 *)
procedure LinkedListTest.getTest;
var
    a: LinkedList;
    b: TestObject;
    c: boolean;
begin
    a := LinkedList.create();
    // getting an element from the beginning
    b := TestObject.create('first', 1);
    a.add(b);
    b := a.get(0) as TestObject;
    c := b.equals(TestObject.create('first', 1));
    AssertTrue(c);
    // getting an element from the beginning (more elements in the list)
    b := TestObject.create('second', 2);
    a.add(b);
    b := a.get(0) as TestObject;
    c := b.equals(TestObject.create('first', 1));
    AssertTrue(c);
    // getting an element from the end
    b := a.get(1) as TestObject;
    c := b.equals(TestObject.create('second', 2));
    AssertTrue(c);
    b := TestObject.create('third', 3);
    a.add(b);
    b := TestObject.create('fourth', 4);
    a.add(b);
    b := TestObject.create('fifth', 5);
    a.add(b);
    // getting an element from the beginning
    b := a.get(0) as TestObject;
    c := b.equals(TestObject.create('first', 1));
    AssertTrue(c);
    // getting an element from the end
    b := a.get(4) as TestObject;
    c := b.equals(TestObject.create('fifth', 5));
    AssertTrue(c);
end;

(**
 * Tests the set method.
 *)
procedure LinkedListTest.setTest;
var
    a: LinkedList;
    b: TestObject;
    c: boolean;
    d: array of TestObject;
begin
    a := LinkedList.create();
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
    AssertTrue(c);
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
    AssertTrue(c);
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
    AssertTrue(c);
end;

(**
 * Tests the remove method.
 *)
procedure LinkedListTest.removeTest;
var
    a: LinkedList;
    b: TestObject;
    c: boolean;
    d: array of TestObject;
begin
    a := LinkedList.create();
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
    AssertTrue(c);
    // removing the element from the middle
    a.remove(1);
    setLength(d, 3);
    d[0] :=  TestObject.create('second', 2);
    d[1] := TestObject.create('fourth', 4);
    d[2] := TestObject.create('fifth', 5);
    c := a.equals(toList(d));
    AssertTrue(c);
    // removing an element from the end
    a.remove(2);
    setLength(d, 2);
    d[0] :=  TestObject.create('second', 2);
    d[1] := TestObject.create('fourth', 4);
    c := a.equals(toList(d));
    AssertTrue(c);
end;

(**
 * Tests the size method.
 *)
procedure LinkedListTest.sizeTest;
var
    a: LinkedList;
    b: TestObject;
    c: longInt;
begin
    a := LinkedList.create();
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
procedure LinkedListTest.isEmptyTest;
var
    a: LinkedList;
    b: TestObject;
    c: boolean;
begin
    a := LinkedList.create();
    c := a.isEmpty();
    AssertTrue(c);
    b := TestObject.create('first', 1);
    a.add(b);
    c := a.isEmpty();
    AssertFalse(c);
    b := TestObject.create('second', 2);
    a.add(b);
    b := TestObject.create('third', 3);
    a.add(b);
    c := a.isEmpty();
    AssertFalse(c);
    a.remove(0);
    c := a.isEmpty();
    AssertFalse(c);
    a.remove(0);
    a.remove(0);
    c := a.isEmpty();
    AssertTrue(c);
end;

(**
 * Tests the clear method.
 *)
procedure LinkedListTest.clearTest;
var
    a: LinkedList;
    b: TestObject;
    c: boolean;
    d: array of TestObject;
begin
    a := LinkedList.create();
    // clear in the beginning
    a.clear();
    setLength(d, 0);
    c := a.equals(toList(d));
    AssertTrue(c);
    // clear after adding one element
    b := TestObject.create('first', 1);
    a.add(b);
    a.clear();
    c := a.equals(toList(d));
    AssertTrue(c);
    // clear after adding more elements
    b := TestObject.create('first', 1);
    a.add(b);
    b := TestObject.create('second', 2);
    a.add(b);
    b := TestObject.create('third', 3);
    a.add(b);
    a.clear();
    c := a.equals(toList(d));
    AssertTrue(c);
end;

(**
 * Tests the toString method.
 *)
procedure LinkedListTest.toStringTest;
var
    a: LinkedList;
    b: TestObject;
    c: String_;
begin
    // the text representation of an empty list
    a := LinkedList.create();
    c := a.toString_();
    AssertEquals('[]', c.strProperty);
    // the text representation of a list with one element
    b := TestObject.create('first', 1);
    a.add(b);
    c := a.toString_();
    AssertEquals('[TestObject [str=first, i=1]]', c.strProperty);
    // the text representation of a list with some elements
    b := TestObject.create('second', 2);
    a.add(b);
    b := TestObject.create('third', 3);
    a.add(b);
    c := a.toString_();
    AssertEquals('[TestObject [str=first, i=1], TestObject [str=second, i=2], TestObject [str=third, i=3]]', c.strProperty);
end;

initialization

  RegisterTest(LinkedListTest);
end.

