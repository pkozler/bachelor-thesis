unit LongUnit;

{$mode objfpc}{$H+}

interface

uses
  SysUtils, StringUnit;

type
  (**
   * The Long class wraps a value of the primitive type long in an object.
   *
   * @author Petr Kozler (A13B0359P)
   *)
  Long = class(Comparable)
    private
      var
        v: int64;
    public
      const
          (**
           * A constant holding the maximum value a long can have, 2^63-1.
           *)
           MAX_VALUE = 9223372036854775807;
          (**
           * A constant holding the minimum value a long can have, -2^63.
           *)
           MIN_VALUE = -9223372036854775808;
      constructor create(value: int64);
      function longValue() : int64;
      function compareTo(anotherLong: Object_) : longInt; override;
      class function compare(x, y: int64) : longInt;
      function equals_(obj: Object_) : boolean; override;
      function toString_() : String_; override;
      class function toString_(l: int64) : String_;
      class function parseLong(s: String_) : int64;
  end;

implementation

(**
 * Constructs a newly allocated Long object that represents the specified
 * long argument.
 *
 * @param value the value to be represented by the Long object.
 *)
constructor Long.create(value: int64);
begin
  v := value;
end;

(**
 * Returns the value of this Long as a long value.
 *
 * @return the numeric value represented by this object after conversion to
 * type long.
 *)
function Long.longValue() : int64;
begin
  longValue := v;
end;

(**
 * Compares two Long objects numerically.
 *
 * @param anotherLong the Long to be compared.
 * @return the value 0 if this Long is equal to the argument Long; a value
 * less than 0 if this Long is numerically less than the argument Long; and
 * a value greater than 0 if this Long is numerically greater than the
 * argument Long (signed comparison).
 *)
function Long.compareTo(anotherLong: Object_) : longInt;
begin
  compareTo := compare(v, (anotherLong as Long).v);
end;

(**
 * Compares two long values numerically.
 *
 * @param x the first long to compare
 * @param y the second long to compare
 * @return the value 0 if x == y; a value less than 0 if x < y; and a value greater than 0 if x
 * > y
 *)
class function Long.compare(x, y: int64) : longInt;
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
function Long.equals_(obj: Object_) : boolean;
begin
  if obj = nil then begin
    exit(false);
  end;

  if typeOf(self) <> typeOf(obj) then begin
    exit(false);
  end;

  equals_ := v = (obj as Long).v;
end;

(**
 * Returns a String object representing this Long's value.
 *
 * @return a string representation of the value of this object in base 10.
 *)
function Long.toString_() : String_;
begin
  toString_ := Long.toString_(v);
end;

(**
 * Returns a String object representing the specified long.
 *
 * @param l a long to be converted.
 * @return a string representation of the argument in base 10.
 *)
class function Long.toString_(l: int64) : String_;
begin
  toString_ := String_.create(IntToStr(l));
end;

(**
 * Parses the string argument as a signed long in the radix specified by the
 * second argument.
 *
 * @param s a String containing the long representation to be parsed
 * @return the long represented by the argument in decimal.
 *)
class function Long.parseLong(s: String_) : int64;
begin
  parseLong := strToInt64(s.toString());
end;

operator := (original: int64) s: Long;
begin
  s.create(original);
end;

end.

