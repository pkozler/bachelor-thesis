unit ByteUnit;

{$mode objfpc}{$H+}

interface

uses
  SysUtils, StringUnit;

type
  (**
   * The Byte class wraps a value of primitive type byte in an object.
   *
   * @author Petr Kozler (A13B0359P)
   *)
  Byte_ = class
    private
      var
        v: shortInt;
    public
      const
          (**
           * A constant holding the maximum value a byte can have, 2^7-1.
           *)
           MAX_VALUE = 127;
          (**
           * A constant holding the minimum value a byte can have, -2^7.
           *)
           MIN_VALUE = -128;
      constructor create(value: shortInt);
      destructor destroy(); override;
      function byteValue() : shortInt;
      function compareTo(anotherByte: Byte_) : longInt;
      class function compare(x, y: shortInt) : longInt;
      function equals(obj: TObject) : boolean; override;
      function toString() : String_;
      class function toString(b: shortInt) : String_;
      class function parseByte(s: String_) : shortInt;
      function toString() : ansiString; override;
  end;

implementation

(**
 * Constructs a newly allocated Byte object that represents the specified
 * byte value.
 *
 * @param value the value to be represented by the Byte.
 *)
constructor Byte_.create(value: shortInt);
begin
  v := value;
end;

destructor Byte_.destroy();
begin
  inherited;
end;

(**
 * Returns the value of this Byte as a byte.
 *
 * @return the numeric value represented by this object after conversion to
 * type byte.
 *)
function Byte_.byteValue() : shortInt;
begin
  byteValue := v;
end;

(**
 * Compares two Byte objects numerically.
 *
 * @param anotherByte the Byte to be compared.
 * @return the value 0 if this Byte is equal to the argument Byte; a value
 * less than 0 if this Byte is numerically less than the argument Byte; and
 * a value greater than 0 if this Byte is numerically greater than the
 * argument Byte (signed comparison).
 *)
function Byte_.compareTo(anotherByte: Byte_) : longInt;
begin
  compareTo := compare(v, anotherByte.v);
end;

(**
 * Compares two byte values numerically.
 *
 * @param x the first byte to compare
 * @param y the second byte to compare
 * @return the value 0 if x == y; a value less than 0 if x < y; and a value greater than 0 if x
 * > y
 *)
class function Byte_.compare(x, y: shortInt) : longInt;
begin
  compare := x - y;
end;

(**
 * Compares this object to the specified object.
 *
 * @param obj the object to compare with
 * @return true if the objects are the same; false otherwise.
 *)
function Byte_.equals(obj: TObject) : boolean;
begin
  if obj = nil then begin
    exit(false);
  end;

  if typeOf(self) <> typeOf(obj) then begin
    exit(false);
  end;

  equals := (v = (Byte_(obj)).v);
end;

(**
 * Returns a String object representing this Byte's value.
 *
 * @return a string representation of the value of this object in base 10.
 *)
function Byte_.toString() : String_;
begin
  toString := Byte_.toString(v);
end;

(**
 * Returns a new String object representing the specified byte.
 *
 * @param b the byte to be converted
 * @return the string representation of the specified byte
 *)
class function Byte_.toString(b: shortInt) : String_;
begin
  toString := String_.create(IntToStr(b));
end;

(**
 * Parses the string argument as a signed decimal byte.
 *
 * @param s a String containing the byte representation to be parsed
 * @return the byte value represented by the argument in decimal
 *)
class function Byte_.parseByte(s: String_) : shortInt;
begin
  parseByte := strToInt(s.toString());
end;

function Byte_.toString() : ansiString;
var
  s: String_;
begin
  s := toString();
  toString := s.ToString();
end;

end.

