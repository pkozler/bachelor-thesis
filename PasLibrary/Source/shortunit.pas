unit ShortUnit;

{$mode objfpc}{$H+}

interface

uses
  SysUtils, StringUnit;

type
  Short = class
    private
      var
        v: smallInt;
    public
      const
           MAX_VALUE = 32767;
           MIN_VALUE = -32768;
      constructor create(value: smallInt);
      destructor destroy(); override;
      function shortValue() : smallInt;
      function compareTo(anotherShort: Short) : longInt;
      function equals(obj: TObject) : boolean; override;
      function toString() : ansiString; override;
      function toString() : String_;
      class function toString(s: smallInt) : String_;
      class function parseShort(s: String_) : smallInt;
  end;

implementation

constructor Short.create(value: smallInt);
begin
  v := value;
end;

destructor Short.destroy();
begin
  inherited;
end;

function Short.shortValue() : smallInt;
begin
  shortValue := v;
end;

function Short.compareTo(anotherShort: Short) : longInt;
begin
  compareTo := v - anotherShort.v;
end;

function Short.equals(obj: TObject) : boolean;
begin
  if obj = nil then begin
    equals := false;
  end;

  equals := (v = (Short(obj)).v);
end;

function Short.toString() : ansiString;
var
  s: String_;
begin
  s := toString();
  toString := s.ToString();
end;

function Short.toString() : String_;
begin
  toString := Short.toString(v);
end;

class function Short.toString(s: smallInt) : String_;
begin
  toString := String_.create(IntToStr(s));
end;

class function Short.parseShort(s: String_) : smallInt;
begin
  parseShort := strToInt(s.toString());
end;

end.

