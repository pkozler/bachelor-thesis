unit FloatUnit;

{$mode objfpc}{$H+}

interface

uses
  SysUtils, StringUnit;

type
  Float = class
    private
      var
        v: single;
    public
      const
           MAX_VALUE = 3.4028235e+38;
           MIN_VALUE = 1.4e-45;
      constructor create(value: single);
      destructor destroy(); override;
      function floatValue() : single;
      function compareTo(anotherFloat: Float) : longInt;
      function equals(obj: TObject) : boolean; override;
      function toString() : ansiString; override;
      function toString() : String_;
      class function toString(f: single) : String_;
      class function parseFloat(s: String_) : single;
  end;

implementation

uses
  Math;

constructor Float.create(value: single);
begin
  v := value;
end;

destructor Float.destroy();
begin
  inherited;
end;

function Float.floatValue() : single;
begin
  floatValue := v;
end;

function Float.compareTo(anotherFloat: Float) : longInt;
var
  cmp : longInt;
  val : single;
begin
  val := v - anotherFloat.v;

  if val > 0 then begin
    cmp := ceil(val);
  end
  else if val < 0 then begin
    cmp := floor(val);
  end
  else begin
    cmp := 0;
  end;

  compareTo := cmp;
end;

function Float.equals(obj: TObject) : boolean;
begin
  if obj = nil then begin
    equals := false;
  end;

  equals := (v = (Float(obj)).v);
end;

function Float.toString() : ansiString;
var
  s: String_;
begin
  s := toString();
  toString := s.ToString();
end;

function Float.toString() : String_;
begin
  toString := Float.toString(v);
end;

class function Float.toString(f: single) : String_;
begin
  toString := String_.create(FloatToStr(f));
end;

class function Float.parseFloat(s: String_) : single;
begin
  parseFloat := strToFloat(s.toString());
end;

end.

