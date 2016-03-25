unit StringBuilderUnit;

{$mode objfpc}{$H+}

interface

uses
  Classes, StringUnit;

type
  (**
   * A mutable sequence of characters.
   *
   * @author Petr Kozler (A13B0359P)
   *)
  StringBuilder = class(Object_)
    private
      const
        DEFAULT_CAPACITY = 16;
        RESIZE_COEF = 2;
      var
        buffer: ^ansiChar;
        count, capacity: longInt;
    public
      constructor create();
      function append(str: String_) : StringBuilder;
      function toString_() : String_;
  end;

implementation

uses
  SysUtils;

(**
 * Constructs a string builder with no characters in it and an initial
 * capacity of 16 characters.
 *)
constructor StringBuilder.create();
begin
  count := 0;
  capacity := DEFAULT_CAPACITY;
  buffer := getMem(capacity);
  buffer[0] := #0;
end;

(**
 * Appends the specified string to this character sequence.
 *
 * @param str a string.
 * @return a reference to this object.
 *)
function StringBuilder.append(str: String_) : StringBuilder;
var
  cStr: ^ansiChar;
  len: longInt;
begin
  len := str.length();
  cStr := getMem(len + 1);
  strPCopy(cStr, str.toString());

  if count + len >= capacity then begin
    capacity := count + len * RESIZE_COEF;
    buffer := reAllocMem(buffer, capacity);
  end;

  strcat(buffer, cStr);
  count := count + len;
  append := self;
end;

(**
 * Returns a string representing the data in this sequence.
 *
 * @return a string representation of this sequence of characters.
 *)
function StringBuilder.toString_() : String_;
begin
  toString_ := String_.create(strPas(buffer));
end;

end.

