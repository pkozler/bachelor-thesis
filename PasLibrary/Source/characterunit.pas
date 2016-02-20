unit CharacterUnit;

{$mode objfpc}{$H+}

interface

uses
  SysUtils, StringUnit;

type
  Character = class
    private
      var
        v: ansiChar;
    public
      constructor create(value: ansiChar);
      destructor destroy(); override;
      function charValue() : ansiChar;
      function compareTo(anotherCharacter: Character) : longInt;
      function equals(obj: TObject) : boolean; override;
      function toString() : ansiString; override;
      function toString() : String_;
      class function toString(c: ansiChar) : String_;
      class function isDigit(ch: ansiChar) : boolean;
      class function isLetter(ch: ansiChar) : boolean;
  end;

implementation

constructor Character.create(value: ansiChar);
begin
  v := value;
end;

destructor Character.destroy();
begin
  inherited;
end;

function Character.charValue() : ansiChar;
begin
  charValue := v;
end;

function Character.compareTo(anotherCharacter: Character) : longInt;
begin
  compareTo := shortInt(v) - shortInt(anotherCharacter.v);
end;

function Character.equals(obj: TObject) : boolean;
begin
  if obj = nil then begin
    equals := false;
  end;

  equals := (v = (Character(obj)).v);
end;

function Character.toString() : ansiString;
var
  s: String_;
begin
  s := toString();
  toString := s.ToString();
end;

function Character.toString() : String_;
begin
  toString := Character.toString(v);
end;

class function Character.toString(c: ansiChar) : String_;
begin
  toString := String_.create(c);
end;

class function Character.isDigit(ch: ansiChar) : boolean;
begin
  isDigit := ((ch >= '0') and (ch <= '9'));
end;

class function Character.isLetter(ch: ansiChar) : boolean;
begin
  isLetter := (((ch >= 'A') and (ch <= 'Z'))
               or ((ch >= 'a') and (ch <= 'z')));
end;

end.

