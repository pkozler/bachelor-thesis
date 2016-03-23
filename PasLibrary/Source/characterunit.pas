unit CharacterUnit;

{$mode objfpc}{$H+}

interface

uses
  SysUtils, StringUnit;

type
  (**
   * The Character class wraps a value of the primitive type char in an object.
   *
   * @author Petr Kozler (A13B0359P)
   *)
  Character = class
    private
      var
        v: ansiChar;
    public
      constructor create(value: ansiChar);
      function charValue() : ansiChar;
      function compareTo(anotherCharacter: Character) : longInt;
      class function compare(x, y: ansiChar) : longInt;
      function equals(obj: TObject) : boolean; override;
      function toString_() : String_;
      class function toString_(c: ansiChar) : String_;
      class function isDigit(ch: ansiChar) : boolean;
      class function isLetter(ch: ansiChar) : boolean;
      function toString() : ansiString; override;
  end;

implementation

(**
 * Constructs a newly allocated Character object that represents the
 * specified char value.
 *
 * @param value the value to be represented by the Character object.
 *)
constructor Character.create(value: ansiChar);
begin
  v := value;
end;

(**
 * Returns the value of this Character object.
 *
 * @return the primitive char value represented by this object.
 *)
function Character.charValue() : ansiChar;
begin
  charValue := v;
end;

(**
 * Compares two Character objects numerically.
 *
 * @param anotherCharacter the Character to be compared.
 * @return the value 0 if the argument Character is equal to this Character;
 * a value less than 0 if this Character is numerically less than the
 * Character argument; and a value greater than 0 if this Character is
 * numerically greater than the Character argument (unsigned comparison).
 * Note that this is strictly a numerical comparison; it is not
 * locale-dependent.
 *)
function Character.compareTo(anotherCharacter: Character) : longInt;
begin
  compareTo := compare(v, anotherCharacter.v);
end;

(**
 * Compares two char values numerically.
 *
 * @param x the first char to compare
 * @param y the second char to compare
 * @return the value 0 if x == y; a value less than 0 if x < y; and a value greater than 0 if x
 * > y
 *)
class function Character.compare(x, y: ansiChar) : longInt;
begin
  compare := shortInt(x) - shortInt(y);
end;

(**
 * Compares this object against the specified object.
 *
 * @param obj the object to compare with.
 * @return true if the objects are the same; false otherwise.
 *)
function Character.equals(obj: TObject) : boolean;
begin
  if obj = nil then begin
    exit(false);
  end;

  if typeOf(self) <> typeOf(obj) then begin
    exit(false);
  end;

  equals := (v = (Character(obj)).v);
end;

(**
 * Returns a String object representing this Character's value.
 *
 * @return a string representation of this object.
 *)
function Character.toString_() : String_;
begin
  toString_ := Character.toString_(v);
end;

(**
 * Returns a String object representing the specified char.
 *
 * @param c the char to be converted
 * @return the string representation of the specified char
 *)
class function Character.toString_(c: ansiChar) : String_;
begin
  toString_ := String_.create(c);
end;

(**
 * Determines if the specified character is a digit.
 *
 * @param ch the character to be tested.
 * @return true if the character is a digit; false otherwise.
 *)
class function Character.isDigit(ch: ansiChar) : boolean;
begin
  isDigit := ((ch >= '0') and (ch <= '9'));
end;

(**
 * Determines if the specified character is a letter.
 *
 * @param ch the character to be tested.
 * @return true if the character is a letter; false otherwise.
 *)
class function Character.isLetter(ch: ansiChar) : boolean;
begin
  isLetter := (((ch >= 'A') and (ch <= 'Z'))
               or ((ch >= 'a') and (ch <= 'z')));
end;

function Character.toString() : ansiString;
var
  s: String_;
begin
  s := toString_();
  toString := s.ToString();
end;

operator := (original: ansiChar) s: Character;
begin
  s.create(original);
end;

operator := (original: Character) s: ansiChar;
begin
  s := original.charValue();
end;

end.

