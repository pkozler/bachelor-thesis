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
  Boolean_ = class
    private
      var
        v : boolean;
    public
      constructor create(value: boolean);
      function booleanValue() : boolean;
      function compareTo(b: Boolean_) : longInt;
      class function compare(x, y: boolean) : longInt;
      function equals(obj: TObject) : boolean; override;
      function toString_() : String_;
      class function toString_(b: boolean) : String_;
      class function parseBoolean(s: String_) : boolean;
      function toString() : ansiString; override;
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
function Boolean_.compareTo(b: Boolean_) : longInt;
begin
  compareTo := compare(v, anotherBoolean.v);
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
function Boolean_.equals(obj: TObject) : boolean;
begin
  if obj = nil then begin
    exit(false);
  end;

  if typeOf(self) <> typeOf(obj) then begin
    exit(false);
  end;

  equals := (v = (Boolean_(obj)).v);
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
begin
  toString_ := String_.create(BoolToStr(b));
end;

(**
 * Parses the string argument as a boolean.
 *
 * @param s the String containing the boolean representation to be parsed
 * @return the boolean represented by the string argument
 *)
class function Boolean_.parseBoolean(s: String_) : boolean;
begin
  parseBoolean := strToBool(s.toString());
end;

function Boolean_.toString() : ansiString;
var
  s: String_;
begin
  s := toString();
  toString := s.ToString();
end;

end.
