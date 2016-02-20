unit ByteUnit;

{$mode objfpc}{$H+}

interface

uses
  SysUtils, StringUnit;

type
  Byte_ = class
    private
      var
        v: shortInt;
    public
      const
           MAX_VALUE = 127;
           MIN_VALUE = -128;
      constructor create(value: shortInt);
      destructor destroy(); override;
      function byteValue() : shortInt;
      function compareTo(anotherByte: Byte_) : longInt;
      function equals(obj: TObject) : boolean; override;
      function toString() : ansiString; override;
      function toString() : String_;
      class function toString(b: shortInt) : String_;
      class function parseByte(s: String_) : shortInt;
  end;

implementation

constructor Byte_.create(value: shortInt);
begin
  v := value;
end;

destructor Byte_.destroy();
begin
  inherited;
end;

function Byte_.byteValue() : shortInt;
begin
  byteValue := v;
end;

function Byte_.compareTo(anotherByte: Byte_) : longInt;
begin
  compareTo := v - anotherByte.v;
end;

function Byte_.equals(obj: TObject) : boolean;
begin
  if obj = nil then begin
    equals := false;
  end;

  equals := (v = (Byte_(obj)).v);
end;

function Byte_.toString() : ansiString;
var
  s: String_;
begin
  s := toString();
  toString := s.ToString();
end;

function Byte_.toString() : String_;
begin
  toString := Byte_.toString(v);
end;

class function Byte_.toString(b: shortInt) : String_;
begin
  toString := String_.create(IntToStr(b));
end;

class function Byte_.parseByte(s: String_) : shortInt;
begin
  parseByte := strToInt(s.toString());
end;

end.

