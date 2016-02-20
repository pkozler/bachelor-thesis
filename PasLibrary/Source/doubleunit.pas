unit DoubleUnit;

{$mode objfpc}{$H+}

interface

uses
  SysUtils, StringUnit;

type
  Double_ = class
    private
      var
        v: double;
    public
      const
           MAX_VALUE = 1.7976931348623157e+308;
           MIN_VALUE = 4.9e-324;
      constructor create(value: double);
      destructor destroy(); override;
      function doubleValue() : double;
      function compareTo(anotherDouble: Double_) : longInt;
      function equals(obj: TObject) : boolean; override;
      function toString() : ansiString; override;
      function toString() : String_;
      class function toString(d: double) : String_;
      class function parseDouble(s: String_) : double;
  end;

implementation

uses
  Math;

constructor Double_.create(value: double);
begin
  v := value;
end;

destructor Double_.destroy();
begin
  inherited;
end;

function Double_.doubleValue() : double;
begin
  doubleValue := v;
end;

function Double_.compareTo(anotherDouble: Double_) : longInt;
var
  cmp : longInt;
  val : double;
begin
  val := v - anotherDouble.v;

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

function Double_.equals(obj: TObject) : boolean;
begin
  if obj = nil then begin
    equals := false;
  end;

  equals := (v = (Double_(obj)).v);
end;

function Double_.toString() : ansiString;
var
  s: String_;
begin
  s := toString();
  toString := s.ToString();
end;

function Double_.toString() : String_;
begin
  toString := Double_.toString(v);
end;

class function Double_.toString(d: double) : String_;
begin
  toString := String_.create(FloatToStr(d));
end;

class function Double_.parseDouble(s: String_) : double;
begin
  parseDouble := strToFloat(s.toString());
end;

end.

