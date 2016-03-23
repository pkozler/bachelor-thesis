unit ShortUnit;

{$mode objfpc}{$H+}

interface

uses
  SysUtils, StringUnit;

type
  (**
   * The Short class wraps a value of primitive type short in an object.
   *
   * @author Petr Kozler (A13B0359P)
   *)
  Short = class
    private
      var
        v: smallInt;
    public
      const
          (**
           * A constant holding the maximum value a short can have, 2^15-1.
           *)
           MAX_VALUE = 32767;
          (**
           * A constant holding the minimum value a short can have, -2^15.
           *)
           MIN_VALUE = -32768;
      constructor create(value: smallInt);
      function shortValue() : smallInt;
      function compareTo(anotherShort: Short) : longInt;
      class function compare(x, y: smallInt) : longInt;
      function equals(obj: TObject) : boolean; override;
      function toString_() : String_;
      class function toString_(s: smallInt) : String_;
      class function parseShort(s: String_) : smallInt;
      function toString() : ansiString; override;
  end;

implementation

(**
 * Constructs a newly allocated Short object that represents the specified
 * short value.
 *
 * @param value the value to be represented by the Short.
 *)
constructor Short.create(value: smallInt);
begin
  v := value;
end;

(**
 * Returns the value of this Short as a short.
 *
 * @return the numeric value represented by this object after conversion to
 * type short.
 *)
function Short.shortValue() : smallInt;
begin
  shortValue := v;
end;

(**
 * Compares two Short objects numerically.
 *
 * @param anotherShort the Short to be compared.
 * @return the value 0 if this Short is equal to the argument Short; a value
 * less than 0 if this Short is numerically less than the argument Short;
 * and a value greater than 0 if this Short is numerically greater than the
 * argument Short (signed comparison).
 *)
function Short.compareTo(anotherShort: Short) : longInt;
begin
  compareTo := compare(v, anotherShort.v);
end;

(**
 * Compares two short values numerically.
 *
 * @param x the first short to compare
 * @param y the second short to compare
 * @return the value 0 if x == y; a value less than 0 if x < y; and a value greater than 0 if x
 * > y
 *)
class function Short.compare(x, y: smallInt) : longInt;
begin
  compare := x - y;
end;

(**
 * Compares this object to the specified object.
 *
 * @param obj the object to compare with
 * @return true if the objects are the same; false otherwise.
 *)
function Short.equals(obj: TObject) : boolean;
begin
  if obj = nil then begin
    exit(false);
  end;

  if typeOf(self) <> typeOf(obj) then begin
    exit(false);
  end;

  equals := (v = (Short(obj)).v);
end;

(**
 * Returns a String object representing this Short's value.
 *
 * @return a string representation of the value of this object in base 10.
 *)
function Short.toString_() : String_;
begin
  toString_ := Short.toString_(v);
end;

(**
 * Returns a new String object representing the specified short.
 *
 * @param s the short to be converted
 * @return the string representation of the specified short
 *)
class function Short.toString_(s: smallInt) : String_;
begin
  toString_ := String_.create(IntToStr(s));
end;

(**
 * Parses the string argument as a signed decimal short.
 *
 * @param s a String containing the short representation to be parsed
 * @return the short value represented by the argument in decimal.
 *)
class function Short.parseShort(s: String_) : smallInt;
begin
  parseShort := strToInt(s.toString());
end;

function Short.toString() : ansiString;
var
  s: String_;
begin
  s := toString_();
  toString := s.ToString();
end;

operator := (original: smallInt) s: Short;
begin
  s.create(original);
end;

operator := (original: Short) s: smallInt;
begin
  s := original.shortValue();
end;

end.

