unit ArrayListUnit;

{$mode objfpc}{$H+}

interface

uses
  StringUnit, ListUnit;

type
  ObjectArray = array of Object_;

  (**
   * Resizable-array implementation of the List abstract class.
   *
   * @param E the type of elements in this list
   * @author Petr Kozler (A13B0359P)
   *)
  ArrayList = class(List)
    private
      const
        // initial length of the inner dynamically resized array
        DEFAULT_CAPACITY = 10;
        // coefficient for increasing or decreasing the capacity of inner array
        RESIZE_COEF = 2;
      var
        // dynamically resized array
        dynamicArray: array of Object_;
        // current element count
        count: longInt;
      procedure expand();
      procedure shrink();
    public
      property arrProperty: ObjectArray read dynamicArray;
      constructor create();
      constructor create(c: ArrayList);
      function add(e: Object_) : boolean; override;
      procedure add(index: longInt; element: Object_); override;
      function get(index: longInt) : Object_; override;
      function set_(index: longInt; element: Object_) : Object_; override;
      function remove(index: longInt) : Object_; override;
      function size() : longInt; override;
      procedure clear(); override;
      function toString_() : String_; override;
  end;

implementation

uses
  StringBuilderUnit, Classes, SysUtils;

(**
 * Constructs an empty list with an initial capacity of ten.
 *)
constructor ArrayList.create();
begin
  // setting the inner array length to the default capacity
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
  // setting the inner array length to the specified list capacity
  setLength(dynamicArray, length(c.dynamicArray));
  count := c.count;

  // copying all elements from the specified list
  for i := 0 to count - 1 do begin
    dynamicArray[i] := c.dynamicArray[i];
  end;
end;

(*
    Increases the capacity of the inner array if the element count
    reaches the current capacity.
 *)
procedure ArrayList.expand();
var
  len: longInt;
begin
  inc(count);
  len := length(dynamicArray);

  // expanding the array by the resize coefficient
  if count = len then begin
    setLength(dynamicArray, len * RESIZE_COEF);
  end;
end;

(*
    Decreases the capacity of the inner array if the element count reaches the half
    of the current capacity (and the current capacity is greater than the default capacity).
 *)
procedure ArrayList.shrink();
var
  len: longInt;
begin
  dec(count);
  len := length(dynamicArray);

  if (count < len div RESIZE_COEF) and (len >= DEFAULT_CAPACITY * RESIZE_COEF) then begin
    // shrinking the array by the resize coefficient
    setLength(dynamicArray, len div RESIZE_COEF);
  end;
end;

(**
 * Appends the specified element to the end of this list.
 *
 * @param e element to be appended to this list
 * @return true
 *)
function ArrayList.add(e: Object_) : boolean;
begin
  // storing the element on the index specified by the current element count
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
procedure ArrayList.add(index: longInt; element: Object_);
var
  i: longInt;
begin
  // moving the elements with greater index than specified by 1 away from the beginning of array
  for i := count downto index + 1 do begin
    dynamicArray[i] := dynamicArray[i - 1];
  end;

  // storing the element on the specified index
  dynamicArray[index] := element;
  expand();
end;

(**
 * Returns the element at the specified position in this list.
 *
 * @param index index of the element to return
 * @return the element at the specified position in this list
 *)
function ArrayList.get(index: longInt) : Object_;
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
function ArrayList.set_(index: longInt; element: Object_) : Object_;
var
  original: Object_;
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
function ArrayList.remove(index: longInt) : Object_;
var
  removed: Object_;
  i: longInt;
begin
  removed := dynamicArray[index];

  // moving the elements with greater index than removed by 1 towards the beginning of array
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
 * Removes all of the elements from this list.
 *)
procedure ArrayList.clear();
begin
  setLength(dynamicArray, 0);
  count := 0;
  // resizing the inner array to the default capacity
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
  // create StringBuilder for appending the text
  sb := StringBuilder.create();
  str := String_.create('[');
  sb.append(str);
  freeAndNil(str);

  // append first element string representation
  if count > 0 then begin
    if dynamicArray[0] = nil then begin
      str := String_.create('null');
    end
    else begin
      str := dynamicArray[0].toString_();
    end;

    sb.append(str);
    freeAndNil(str);
  end;

  // append another elements string representation
  for i := 1 to count - 1 do begin
    str := String_.create(', ');
    sb.append(str);
    freeAndNil(str);

    if dynamicArray[i] = nil then begin
      str := String_.create('null');
    end
    else begin
      str := dynamicArray[i].toString_();
    end;

    sb.append(str);
    freeAndNil(str);
  end;

  // create Java-like string
  str := String_.create(']');
  sb.append(str);
  freeAndNil(str);
  str := sb.toString_();
  freeAndNil(sb);
  toString_ := str;
end;

end.

