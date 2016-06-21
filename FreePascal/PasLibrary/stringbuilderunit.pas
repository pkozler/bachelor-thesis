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
        // initial capacity for the inner dynamically resized string buffer
        DEFAULT_CAPACITY = 16;
        // coefficient for increasing the string buffer capacity
        RESIZE_COEF = 2;
      var
        // char pointer used as a string buffer
        buffer: ^ansiChar;
        // current appended character count
        count: longInt;
        // current buffer capacity
        capacity: longInt;
    public
      constructor create();
      destructor destroy(); override;
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
  // allocating the inner buffer to the default capacity
  buffer := getMem(capacity);
  buffer[0] := #0;
end;

(*
    Destructs the StringBuilder.
 *)
destructor StringBuilder.destroy();
begin
  freeMem(buffer);
  inherited;
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

  // converting the string into the null-terminated char array for appending it to the buffer
  cStr := getMem(len + 1);
  strPCopy(cStr, str.strProperty);

  // increasing the buffer capacity if the new string length reaches the current capacity
  if count + len >= capacity then begin
    capacity := count + len * RESIZE_COEF;
    // reallocating the memory (expanding the allocated memory by the resize coefficient)
    buffer := reAllocMem(buffer, capacity);
  end;

  // concatenating the new string
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
  // converting the null-terminated char array into string
  toString_ := String_.create(strPas(buffer));
end;

end.

