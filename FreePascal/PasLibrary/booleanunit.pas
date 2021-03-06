unit BooleanUnit;

{$mode objfpc}{$H+}

interface

uses
  SysUtils, StringUnit;

type
  (**
   * The Boolean class wraps a value of the primitive type boolean in an object.
   *
   * @author Petr Kozler (A13B0359P)
   *)
  Boolean_ = class(Comparable)
    private
      var
        // an inner value
        v : boolean;
    public
      constructor create(value: boolean);
      function booleanValue() : boolean;
      function compareTo(b: Object_) : longInt; override;
      class function compare(x, y: boolean) : longInt;
      function equals_(obj: Object_) : boolean; override;
      function toString_() : String_; override;
      class function toString_(b: boolean) : String_;
      class function parseBoolean(s: String_) : boolean;
  end;

implementation

(**
 * Allocates a Boolean object representing the value argument.
 *
 * @param value the value of the Boolean.
 *)
constructor Boolean_.create(value: boolean);
begin
  v := value;
end;

(**
 * Returns the value of this Boolean object as a boolean primitive.
 *
 * @return the primitive boolean value of this object.
 *)
function Boolean_.booleanValue() : boolean;
begin
  booleanValue := v;
end;

(**
 * Compares this Boolean instance with another.
 *
 * @param b the Boolean instance to be compared
 * @return zero if this object represents the same boolean value as the
 * argument; a positive value if this object represents true and the
 * argument represents false; and a negative value if this object represents
 * false and the argument represents true
 *)
function Boolean_.compareTo(b: Object_) : longInt;
begin
  compareTo := compare(v, (b as Boolean_).v);
end;

(**
 * Compares two boolean values.
 *
 * @param x the first boolean to compare
 * @param y the second boolean to compare
 * @return the value 0 if x == y; a value less than 0 if !x && y; and a
 * value greater than 0 if x && !y
 *)
class function Boolean_.compare(x, y: boolean) : longInt;
begin
  // 0 if x equals y, 1 if x is TRUE and y is FALSE, -1 otherwise
  if x = y then begin
    compare := 0;
  end
  else if x then begin
    compare := 1;
  end
  else begin
    compare := -1;
  end;
end;

(**
 * Returns true if and only if the argument is not null and is a Boolean
 * object that represents the same boolean value as this object.
 *
 * @param obj the object to compare with.
 * @return true if the Boolean objects represent the same value; false
 * otherwise.
 *)
function Boolean_.equals_(obj: Object_) : boolean;
begin
  // testing another object reference for a NULL value
  if obj = nil then begin
    exit(false);
  end;

  // testing object class equality
  if typeOf(self) <> typeOf(obj) then begin
    exit(false);
  end;

  // testing object fields equality
  equals_ := v = (obj as Boolean_).v;
end;

(**
 * Returns a String object representing this Boolean's value.
 *
 * @return a string representation of this object.
 *)
function Boolean_.toString_() : String_;
begin
  toString_ := Boolean_.toString_(v);
end;

(**
 * Returns a String object representing the specified boolean.
 *
 * @param b the boolean to be converted
 * @return the string representation of the specified boolean
 *)
class function Boolean_.toString_(b: boolean) : String_;
var
  s: ansiString;
begin
  if b then begin
    s := 'true';
  end
  else begin
    s := 'false';
  end;

  toString_ := String_.create(s);
end;

(**
 * Parses the string argument as a boolean.
 *
 * @param s the String containing the boolean representation to be parsed
 * @return the boolean represented by the string argument
 *)
class function Boolean_.parseBoolean(s: String_) : boolean;
var
  str: ansiString;
begin
  // test if the string is equal to "true"
  str := lowerCase(trim(s.strProperty));
  if ansiCompareStr(str, 'true') = 0 then begin
    exit(true);
  end;

  // return false otherwise
  parseBoolean := false;
end;

operator := (original: boolean) s: Boolean_;
begin
  s.create(original);
end;

end.
