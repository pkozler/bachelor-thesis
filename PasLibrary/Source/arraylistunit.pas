unit ArrayListUnit;

{$mode objfpc}{$H+}

interface

uses
  StringUnit;

type
  TObjectArray = array of TObject;

  (**
   * Resizable-array implementation of the List interface.
   *
   * @author Petr Kozler (A13B0359P)
   *)
  ArrayList = class
    private
      const
        DEFAULT_CAPACITY = 10;
        RESIZE_COEF = 2;
      var
        dynamicArray: array of TObject;
        count: longInt;
      procedure expand();
      procedure shrink();
    public
      constructor create();
      constructor create(c: ArrayList);
      function getArray() : TObjectArray;
      function add(e: TObject) : boolean;
      procedure add(index: longInt; element: TObject);
      function get(index: longInt) : TObject;
      function set_(index: longInt; element: TObject) : TObject;
      function remove(index: longInt) : TObject;
      function size() : longInt;
      function isEmpty() : boolean;
      procedure clear();
      function toString_() : String_;
      function toString() : ansiString; override;
  end;

implementation

uses
  StringBuilderUnit, Classes, SysUtils;

(**
 * Constructs an empty list with an initial capacity of ten.
 *)
constructor ArrayList.create();
begin
  setLength(dynamicArray, DEFAULT_CAPACITY);
  count := 0;
end;

(**
 * Constructs a list containing the elements of the specified collection, in
 * the order they are returned by the collection's iterator.
 *
 * @param c the collection whose elements are to be placed into this list
 *)
constructor ArrayList.create(c: ArrayList);
var
  i: longInt;
begin
  setLength(dynamicArray, length(c.dynamicArray));
  count := c.count;

  for i := 0 to count - 1 do begin
    dynamicArray[i] := c.dynamicArray[i];
  end;
end;

procedure ArrayList.expand();
var
  len: longInt;
begin
  inc(count);
  len := length(dynamicArray);

  if count = len then begin
    setLength(dynamicArray, len * RESIZE_COEF);
  end;
end;

procedure ArrayList.shrink();
var
  len: longInt;
begin
  dec(count);
  len := length(dynamicArray);

  if (count < len div RESIZE_COEF) and (len >= DEFAULT_CAPACITY * RESIZE_COEF) then begin
    setLength(dynamicArray, len div RESIZE_COEF);
  end;
end;

function ArrayList.getArray() : TObjectArray;
begin
  getArray := dynamicArray;
end;

(**
 * Appends the specified element to the end of this list.
 *
 * @param e element to be appended to this list
 * @return true (as specified by Collection.add(E))
 *)
function ArrayList.add(e: TObject) : boolean;
begin
  dynamicArray[count] := e;
  expand();
  add := true;
end;

(**
 * Inserts the specified element at the specified position in this list.
 *
 * @param index index at which the specified element is to be inserted
 * @param element element to be inserted
 *)
procedure ArrayList.add(index: longInt; element: TObject);
var
  i: longInt;
begin
  for i := count downto index + 1 do begin
    dynamicArray[i] := dynamicArray[i - 1];
  end;

  dynamicArray[index] := element;
  expand();
end;

(**
 * Returns the element at the specified position in this list.
 *
 * @param index index of the element to return
 * @return the element at the specified position in this list
 *)
function ArrayList.get(index: longInt) : TObject;
begin
  get := dynamicArray[index];
end;

(**
 * Replaces the element at the specified position in this list with the
 * specified element.
 *
 * @param index index of the element to replace
 * @param element element to be stored at the specified position
 * @return the element previously at the specified position
 *)
function ArrayList.set_(index: longInt; element: TObject) : TObject;
var
  original: TObject;
begin
  original := dynamicArray[index];
  dynamicArray[index] := element;
  set_ := original;
end;

(**
 * Removes the element at the specified position in this list.
 *
 * @param index the index of the element to be removed
 * @return the element that was removed from the list
 *)
function ArrayList.remove(index: longInt) : TObject;
var
  removed: TObject;
  i: longInt;
begin
  removed := dynamicArray[index];

  for i := index to count - 1 do begin
    dynamicArray[i] := dynamicArray[i + 1];
  end;

  shrink();
  remove := removed;
end;

(**
 * Returns the number of elements in this list.
 *
 * @return the number of elements in this list
 *)
function ArrayList.size() : longInt;
begin
  size := count;
end;

(**
 * Returns true if this list contains no elements.
 *
 * @return true if this list contains no elements
 *)
function ArrayList.isEmpty() : boolean;
begin
  isEmpty := (count = 0);
end;

(**
 * Removes all of the elements from this list.
 *)
procedure ArrayList.clear();
begin
  setLength(dynamicArray, 0);
  count := 0;
  setLength(dynamicArray, DEFAULT_CAPACITY);
end;

(**
 * Returns a string representation of the object.
 *
 * @return a string representation of the object.
 *)
function ArrayList.toString_() : String_;
var
  sb: StringBuilder;
  str: String_;
  i: longInt;
begin
  sb := StringBuilder.create();
  str := '[';
  sb.append(str);
  freeAndNil(str);

  if count > 0 then begin
    str := dynamicArray[0].toString();
    sb.append(str);
    freeAndNil(str);
  end;

  for i := 1 to count - 1 do begin
    str := ', ';
    sb.append(str);
    freeAndNil(str);
    str := dynamicArray[i].toString();
    sb.append(str);
    freeAndNil(str);
  end;

  str := ']';
  sb.append(str);
  freeAndNil(str);
  str := sb.toString();
  freeAndNil(sb);
  toString_ := str;
end;

function ArrayList.toString() : ansiString;
begin
  toString := toString_().toString();
end;

end.

