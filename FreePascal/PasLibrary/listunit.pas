unit ListUnit;

{$mode objfpc}{$H+}

interface

uses
  StringUnit;

type
  (**
   * An ordered collection (also known as a sequence).
   *
   * @param E the type of elements in this list
   * @author Petr Kozler (A13B0359P)
   *)
  List = class(Object_)
    public
      function add(e: Object_) : boolean; virtual; abstract;
      procedure add(index: longInt; element: Object_); virtual; abstract;
      function equals_(o: Object_) : boolean; override;
      function get(index: longInt) : Object_; virtual; abstract;
      function set_(index: longInt; element: Object_) : Object_; virtual; abstract;
      function remove(index: longInt) : Object_; virtual; abstract;
      function size() : longInt; virtual; abstract;
      function isEmpty() : boolean; virtual;
      procedure clear(); virtual; abstract;
      function toString_() : String_; virtual; abstract;
  end;

implementation

(**
 * Compares the specified object with this list for equality.
 *
 * @param o the object to be compared for equality with this list
 * @return true if the specified object is equal to this list
 *)
function List.equals_(o: Object_) : boolean;
var
  other: List;
  o1, o2: Object_;
  length, i: longInt;
  e: boolean;
begin
  // comparing references
  if self = o then begin
    exit(true);
  end;

  // testing the reference for a NULL value
  if o = nil then begin
    exit(false);
  end;

  other := List(o);
  length := size();

  // comparing the list sizes
  if other.size() <> length then begin
    exit(false);
  end;

  // comparing the corresponding elements of the lists
  for i := 0 to length - 1 do begin
    o1 := get(i);
    o2 := other.get(i);

    if o1 = nil then begin
      e := o2 = nil;
    end
    else begin
      e := o1.equals_(o2);
    end;

    if not e then begin
      exit(false);
    end;
  end;

  equals_ := true;
end;

(**
 * Returns true if this list contains no elements.
 *
 * @return true if this list contains no elements
 *)
function List.isEmpty() : boolean;
begin
  isEmpty := size() = 0;
end;

end.

