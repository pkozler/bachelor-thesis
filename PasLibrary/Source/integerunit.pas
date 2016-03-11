unit IntegerUnit;

{$mode objfpc}{$H+}

interface

uses
  SysUtils, StringUnit;

type
  (**
   * The Integer class wraps a value of the primitive type int in an object.
   *
   * @author Petr Kozler (A13B0359P)
   *)
  Integer_ = class
    private
      var
        v: longInt;
    public
      const
          (**
           * A constant holding the maximum value an int can have, 2^31-1.
           *)
           MAX_VALUE = 2147483647;
          (**
           * A constant holding the minimum value an int can have, -2^31.
           *)
           MIN_VALUE = -2147483648;
      constructor create(value: longInt);
      function intValue() : longInt;
      function compareTo(anotherInteger: Integer_) : longInt;
      class function compare(x, y: longInt) : longInt;
      function equals(obj: TObject) : boolean; override;
      function toString_() : String_;
      class function toString_(i: longInt) : String_;
      class function parseInt(s: String_) : longInt;
      function toString() : ansiString; override;
  end;

implementation

(**
 * Constructs a newly allocated Integer object that represents the specified
 * int value.
 *
 * @param value the value to be represented by the Integer object.
 *)
constructor Integer_.create(value: longInt);
begin
  v := value;
end;

(**
 * Returns the value of this Integer as an int.
 *
 * @return the numeric value represented by this object after conversion to
 * type int.
 *)
function Integer_.intValue() : longInt;
begin
  intValue := v;
end;

(**
 * Compares two Integer objects numerically.
 *
 * @param anotherInteger the Integer to be compared.
 * @return the value 0 if this Integer is equal to the argument Integer; a
 * value less than 0 if this Integer is numerically less than the argument
 * Integer; and a value greater than 0 if this Integer is numerically
 * greater than the argument Integer (signed comparison).
 *)
function Integer_.compareTo(anotherInteger: Integer_) : longInt;
begin
  compareTo := compare(v, anotherInteger.v);
end;

(**
 * Compares two int values numerically.
 *
 * @param x the first int to compare
 * @param y the second int to compare
 * @return the value 0 if x == y; a value less than 0 if x < y; and a value greater than 0 if x
 * > y
 *)
class function Integer_.compare(x, y: longInt) : longInt;
begin
  if x < y then begin
     compare := -1;
  end
  else if x = y then begin
     compare := 0;
  end
  else begin
    compare := 1;
  end;
end;

(**
 * Compares this object to the specified object.
 *
 * @param obj the object to compare with.
 * @return true if the objects are the same; false otherwise.
 *)
function Integer_.equals(obj: TObject) : boolean;
begin
  if obj = nil then begin
    exit(false);
  end;

  if typeOf(self) <> typeOf(obj) then begin
    exit(false);
  end;

  equals := (v = (Integer_(obj)).v);
end;

(**
 * Returns a String object representing this Integer's value.
 *
 * @return a string representation of the value of this object in base 10.
 *)
function Integer_.toString_() : String_;
begin
  toString_ := Integer_.toString_(v);
end;

(**
 * Returns a String object representing the specified integer.
 *
 * @param i an integer to be converted.
 * @return a string representation of the argument in base 10.
 *)
class function Integer_.toString_(i: longInt) : String_;
begin
  toString_ := String_.create(IntToStr(i));
end;

(**
 * Parses the string argument as a signed decimal integer.
 *
 * @param s a String containing the int representation to be parsed
 * @return the integer value represented by the argument in decimal.
 *)
class function Integer_.parseInt(s: String_) : longInt;
begin
  parseInt := strToInt(s.toString());
end;

function Integer_.toString() : ansiString;
var
  s: String_;
begin
  s := toString();
  toString := s.ToString();
end;

end.

