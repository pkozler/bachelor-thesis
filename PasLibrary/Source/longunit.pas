unit LongUnit;

{$mode objfpc}{$H+}

interface

uses
  SysUtils, StringUnit;

type
  Long = class
    private
      var
        v: int64;
    public
      const
           MAX_VALUE = 9223372036854775807;
           MIN_VALUE = -9223372036854775808;
      constructor create(value: int64);
      destructor destroy(); override;
      function longValue() : int64;
      function compareTo(anotherLong: Long) : longInt;
      function equals(obj: TObject) : boolean; override;
      function toString() : ansiString; override;
      function toString() : String_;
      class function toString(l: int64) : String_;
      class function parseLong(s: String_) : int64;
  end;

implementation

constructor Long.create(value: int64);
begin
  v := value;
end;

destructor Long.destroy();
begin
  inherited;
end;

function Long.longValue() : int64;
begin
  longValue := v;
end;

function Long.compareTo(anotherLong: Long) : longInt;
begin
  compareTo := v - anotherLong.v;
end;

function Long.equals(obj: TObject) : boolean;
begin
  if obj = nil then begin
    equals := false;
  end;

  equals := (v = (Long(obj)).v);
end;

function Long.toString() : ansiString;
var
  s: String_;
begin
  s := toString();
  toString := s.ToString();
end;

function Long.toString() : String_;
begin
  toString := Long.toString(v);
end;

class function Long.toString(l: int64) : String_;
begin
  toString := String_.create(IntToStr(l));
end;

class function Long.parseLong(s: String_) : int64;
begin
  parseLong := strToInt64(s.toString());
end;

end.

