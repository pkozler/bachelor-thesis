unit TestObjectUnit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, StringUnit;

type
  (**
   * The {@code TestObject} class represents a simple object that serves
   * for demonstration the functionality of libraries working with objects.
   *
   * @author Petr Kozler
   *)
  TestObject = class(Comparable)
    private
      var
         str: String_;
         i: longInt;
    public
      constructor create(newStr: String_; newI: longInt);
      function getStr(): String_;
      procedure setStr(newStr: String_);
      function getI(): longInt;
      procedure setI(newI: longInt);
      function equals_(obj: Object_): boolean; override;
      function toString_(): String_; override;
      function compareTo(o: Object_): longInt; override;
  end;

implementation

(**
 * Creates a new object.
 *
 * @param str string value
 * @param i integer value
 *)
constructor TestObject.create(newStr: String_; newI: longInt);
begin
  str := newStr;
  i := newI;
end;

(**
 * Returns a value of the string field.
 *
 * @return string value
 *)
function TestObject.getStr(): String_;
begin
  getStr := str;
end;

(**
 * Changes a value of the string field.
 *
 * @param str string value
 *)
procedure TestObject.setStr(newStr: String_);
begin
  str := newStr;
end;

(**
 * Returns a value of the integer field.
 *
 * @return integer value
 *)
function TestObject.getI(): longInt;
begin
  getI := i;
end;

(**
 * Changes a value of the integer field.
 *
 * @param i integer value
 *)
procedure TestObject.setI(newI: longInt);
begin
  i := newI;
end;

(**
 * Indicates whether some other object is equal to this one.
 *
 * @param obj another object
 * @return TRUE if objects are equal, FALSE otherwise
 *)
function TestObject.equals_(obj: Object_): boolean;
begin
  if obj = nil then begin
    exit(false);
  end;

  if typeOf(self) <> typeOf(obj) then begin
    exit(false);
  end;

  equals_ := i = (obj as TestObject).i;
end;

(**
 * Returns a string representation of the object.
 *
 * @return string representation
 *)
function TestObject.toString_(): String_;
begin
  toString_ := String_('TestObject [str=' + str.strProperty + ', i=' + intToStr(i) + ']');
end;

(**
 * Compares this object with the specified object for order.
 *
 * @param o another object
 * @return comparison result
 *)
function TestObject.compareTo(o: Object_): longInt;
begin
  compareTo := i - (o as TestObject).i;
end;

end.

